#include "status_bars.h"
#include <stdio.h>
#include "cachemaster.h"
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include "util.h"




void print_cpu_display() {
  print_status_bar(CPU, "CPU-");
}
void print_gpu_display() {
  print_status_bar(GPU, "GPU-");
}

void print_bat_display() {
  print_status_bar(BAT, "BAT-");
  printf(" [%2.1lfWh %c %2.1lfW]", 
      get_battery_capacity(),
      is_battery_charging() ? '+' : '-',
      get_battery_pull());
}
void print_ram_vram_display() {
  printf("RAM/VRAM-");
  print_double_status_bar(20, get_ram_usage(), get_vram_usage(),
      COLOR_RED, COLOR_GREEN, COLOR_PURPLE);
}
void print_time_date_display() {
  char output[128];
  get_datestring(output);
  printf("%s", output);
}

int main() {
  setvbuf(stdout, NULL, _IOLBF, 0);
  pthread_t cycler_pthread;
  pthread_create(&cycler_pthread, NULL ,run_cycler, NULL);

  if (signal(SIGABRT, stop_cycler) == SIG_ERR) {
    perror("Failed to register signal handler");
    return 1;
  }
  while (1) {
    print_cpu_display();
    printf("; ");
    print_gpu_display();
    printf("; ");
    print_bat_display();
    printf("; ");
    print_ram_vram_display();
    printf("; ");
    print_time_date_display();
    printf("\t\n");
    usleep(1000000);
  }
}
