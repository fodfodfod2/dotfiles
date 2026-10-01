#include "system.h"

double get_battery_percentage_nocache() {
  double charge_now = get_double_from_cli("cat /sys/class/power_supply/BAT1/charge_now");
  double charge_full = get_double_from_cli("cat /sys/class/power_supply/BAT1/charge_full");
  double result = 100 * charge_now / charge_full;
  return result;
}

double get_battery_capacity_nocache() {
  double charge_full = get_double_from_cli("cat /sys/class/power_supply/BAT1/charge_now");
  double voltage_min = get_double_from_cli("cat /sys/class/power_supply/BAT1/voltage_min_design");
  double result = charge_full * voltage_min * 0.000000000001;
  return result;
}

void get_datestring_nocache(char *dest) {
  get_str_from_cli(dest, "date +\"%a %0m/%0d/%0y %0H:%0M:%0S\"");
}

char get_str_from_cli(char *dest, char *command) {
  FILE *output = popen(command, "r");
  if (output == NULL) {
    printf("output is null from command %s\n", command);
    return -1;
  }
  int status = fscanf(output, "%[^\n]", dest);
  if (status != 1) {
    printf("failed to read from %s\n", command);
    return -1;
  }
  pclose(output);
  return 0;
}

double get_double_from_cli(char *command) {
  double result = -10;
  char output[50];
  get_str_from_cli(output, command);
  int status = sscanf(output, "%lf", &result);
  if (status != 1) {
    printf("failed to read from %s\n", command);
    return -1;
  }
  return result;
}


double get_cpu_usage_nocache() {
  return get_double_from_cli("cat /proc/stat | head -n 1 | awk '{total=$2+$3+$4+$5+$6+$7+$8+$9+$10+$11; print 100 * (1 - $5/total)}'");
}

int get_cpu_temp_nocache() {
  char output[50];
  int temp = -1;
  get_str_from_cli(output, "cat /sys/class/hwmon/hwmon6/temp1_input");
  sscanf(output, "%d", &temp);
  return temp / 1000;
}

double get_ram_usage_nocache() {
  return get_double_from_cli("free | grep Mem | awk '{printf \"%.1f\", ($3/$2)*100}'");
}


double get_battery_pull_nocache() {
  return get_double_from_cli("cat /sys/class/power_supply/BAT1/current_now /sys/class/power_supply/BAT1/voltage_now 2>/dev/null | awk '{if(NR==1) c=$1; if(NR==2) v=$1} END {print (c * v) / 10^12}'");
}

char is_gpu_awake() {
  char output[50];
  get_str_from_cli(output, "cat /sys/bus/pci/devices/0000:c1:00.0/power/runtime_status");
  if (strcmp(output, "active") == 0) {
    return 1;
  }
  return 0;
}

char is_battery_charging_nocache() {
  char output[50];
  get_str_from_cli(output, "cat /sys/class/power_supply/BAT1/status");
  if (strcmp(output, "Discharging") == 0) {
    return 0;
  }
  return 1;
}

double get_vram_usage_nocache() {
  if (is_gpu_awake()) {
    char output[50];
    int used = -1;
    int total = -1;
    get_str_from_cli(output, "nvidia-smi | grep \"MiB /\" | awk '{print $9 $11}'nvidia-smi");
    sscanf(output, "%dMiB%dMiB", &used, &total);
    return 100 * used/((double)(total));
  }
  return 0.0;
}

int get_gpu_temp_nocache() {
  if (is_gpu_awake()) {
    char output[50];
    int temp = -1;
    get_str_from_cli(output, "nvidia-smi | grep \"| N/A\" | awk '{print $3}'");
    sscanf(output, "%dC", &temp);
    return temp;

  }
  return 0;
}

double get_gpu_usage_nocache() {
  if (is_gpu_awake()) {
    return get_double_from_cli("nvidia-smi | grep \"Default |\" | awk '{print substr($13, 1, length($13) - 1)}'");
  }
  return 0.0;
}
