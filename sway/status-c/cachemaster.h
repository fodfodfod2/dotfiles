#ifndef CACHEMASTER_H
#define CACHEMASTER_H
#include <stdio.h>

typedef struct {
  void *(*func)(void *arg);
  int cooldown;
} updater_t;
#define CPU_USAGE_REF_FREQ (1)
#define CPU_TEMP_REF_FREQ (5)
#define GPU_USAGE_REF_FREQ (1)
#define GPU_TEMP_REF_FREQ (5)
#define VRAM_USAGE_REF_FREQ (5)
#define RAM_USAGE_REF_FREQ (5)
#define BAT_PERCENTAGE_REF_FREQ (3)
#define BAT_PULL_REF_FREQ (10)
#define BAT_CHARGING_REF_FREQ (2)


double get_cpu_usage();
int get_cpu_temp();

double get_ram_usage();

double get_battery_pull();
double get_battery_percentage();
char is_battery_charging();
double get_battery_capacity();

double get_gpu_usage();
int get_gpu_temp();
double get_vram_usage();

void get_datestring(char *);

void *refresh_cpu_usage_cache(void *);
void *refresh_cpu_temp_cache(void *);

void *refresh_ram_usage_cache(void *);

void *refresh_battery_pull_cache(void *);
void *refresh_battery_percentage_cache(void *);
void *refresh_is_battery_charging_cache(void *);

void *refresh_gpu_usage_cache(void *);
void *refresh_gpu_temp_cache(void *);
void *refresh_vram_usage_cache(void *);

void stop_cycler(int arg);
void *run_cycler(void *);
#endif
