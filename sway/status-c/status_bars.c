#include "util.h"
#include "cachemaster.h"
#include "constants.h"
#include "status_bars.h"

void print_cpu_status_bar(char *dest) {
  double cpu_usage = get_cpu_usage();
  int cpu_temp = get_cpu_temp();
  char color[256];

  if (cpu_temp >= CPU_HIGH_TEMP_THRESHOLD) {
    strcpy(color, CPU_HIGH_TEMP_COLOR);
  }
  else if (cpu_temp >= CPU_MED_TEMP_THRESHOLD) {
    strcpy(color, CPU_MED_TEMP_COLOR);
  }
  else {
    strcpy(color, CPU_LOW_TEMP_COLOR);
  }

  get_status_bar(dest, CPU_METER_SEGMENTS, cpu_usage, color);
}

void print_gpu_status_bar(char *dest) {
  double gpu_usage = get_gpu_usage();
  int gpu_temp = get_gpu_temp();
  char color[256];

  if (gpu_temp >= GPU_HIGH_TEMP_THRESHOLD) {
    strcpy(color, GPU_HIGH_TEMP_COLOR);
  }
  else if (gpu_temp >= GPU_MED_TEMP_THRESHOLD) {
    strcpy(color, GPU_MED_TEMP_COLOR);
  }
  else {
    strcpy(color, GPU_LOW_TEMP_COLOR);
  }

  get_status_bar(dest, GPU_METER_SEGMENTS, gpu_usage, color);
}

void print_bat_status_bar(char *dest) {
  double bat_percentage = get_battery_percentage();
  double bat_pull = get_battery_pull();
  char is_bat_charging = is_battery_charging();
  char color[256];

  if (bat_pull == 0) {
    strcpy(color, FULL_BATTERY_COLOR);
  }
  else if (is_bat_charging) {
    strcpy(color, CHARGING_BATTERY_COLOR);
  }
  else if (bat_percentage < LOW_BATTERY_THRESHOLD) {
    strcpy(color, LOW_BATTERY_COLOR);
  }
  else {
    strcpy(color, DISCHARGING_BATTERY_COLOR);
  }

  get_status_bar(dest, BAT_METER_SEGMENTS, bat_percentage, color);
}

void print_ram_status_bar(char *dest) {
  double ram_usage = get_ram_usage();
  get_status_bar(dest, BAT_METER_SEGMENTS, ram_usage, RAM_METER_COLOR);
}

void print_vram_status_bar(char *dest) {
  double vram_usage = get_vram_usage();
  get_status_bar(dest, BAT_METER_SEGMENTS, vram_usage, VRAM_METER_COLOR);
}

void get_status_bar_type(char *dest, char type) {
  switch(type) {
    case CPU: print_cpu_status_bar(dest); break;
    case GPU: print_gpu_status_bar(dest); break;
    case BAT: print_bat_status_bar(dest); break;
    case RAM: print_ram_status_bar(dest); break;
    case VRAM: print_vram_status_bar(dest); break;
  }
}

void print_status_bar(char type, char *header) {
  char output[512];
  get_status_bar_type(output, type);
  printf("%s%s", header, output);
}

void print_double_status_bar(int seg, double p1, double p2, char *c1, char *c2, char *c3) {
  char output[512];
  get_double_status_bar(output, seg, p1, p2, c1, c2, c3);
  printf("%s",  output);
}
