#include "cachemaster.h"
#include "system.h"
#include <time.h>
#include <unistd.h>
#include <pthread.h>

double g_cpu_usage = -1;
int g_cpu_temp = -1;

double g_bat_pull = -1;
double g_bat_percentage = -1;
char g_bat_charging = -1;

double g_gpu_usage = -1;
int g_gpu_temp = -1;


double g_ram_usage = -1;

double g_vram_usage = -1;

char g_cycler_running = 0;

double get_cpu_usage() {return g_cpu_usage;}
int get_cpu_temp() {return g_cpu_temp;}

double get_ram_usage() {return g_ram_usage;}

double get_battery_pull() {return g_bat_pull;}
double get_battery_percentage() {return g_bat_percentage;}
double get_battery_capacity() {return get_battery_capacity_nocache();}
char is_battery_charging() {return g_bat_charging;}

double get_gpu_usage() {return g_gpu_usage;}
int get_gpu_temp() {return g_gpu_temp;}
double get_vram_usage() {return g_vram_usage;}

void get_datestring(char *dest) {get_datestring_nocache(dest);}


void *refresh_cpu_usage_cache(void *arg) {g_cpu_usage = get_cpu_usage_nocache(); return NULL;}
void *refresh_cpu_temp_cache(void *arg) {g_cpu_temp = get_cpu_temp_nocache(); return NULL;}

void *refresh_ram_usage_cache(void *arg) {g_ram_usage = get_ram_usage_nocache(); return NULL;}

void *refresh_battery_pull_cache(void *arg) {g_bat_pull = get_battery_pull_nocache(); return NULL;}
void *refresh_battery_percentage_cache(void *arg) {g_bat_percentage = get_battery_percentage_nocache(); return NULL;}
void *refresh_is_battery_charging_cache(void *arg) {g_bat_charging = is_battery_charging_nocache(); return NULL;}

void *refresh_gpu_usage_cache(void *arg) {g_gpu_usage = get_gpu_usage_nocache(); return NULL;}
void *refresh_gpu_temp_cache(void *arg) {g_gpu_temp = get_gpu_temp_nocache(); return NULL;}
void *refresh_vram_usage_cache(void *arg) {g_vram_usage = get_vram_usage_nocache(); return NULL;}


void *start_cycle(void *arg) {
  updater_t *updater = (updater_t *)(arg);
  while (true) {
    updater->func(NULL);
    sleep(updater->cooldown);
  }
}

void stop_cycler(int arg) {
  g_cycler_running = 0;
}

void *run_cycler(void *arg) {
  g_cycler_running = 1;

  updater_t cpu_usage_updater = {.func = refresh_cpu_usage_cache, .cooldown = CPU_USAGE_REF_FREQ};
  pthread_t cpu_usage_pthread;
  pthread_create(&cpu_usage_pthread, NULL, start_cycle, (void *)&cpu_usage_updater);
  printf("cpu_usage started\n");

  updater_t cpu_temp_updater = {.func = refresh_cpu_temp_cache, .cooldown = CPU_TEMP_REF_FREQ};
  pthread_t cpu_temp_pthread;
  pthread_create(&cpu_temp_pthread, NULL, start_cycle, (void *)&cpu_temp_updater);
  printf("cpu_temp started\n");

  updater_t gpu_usage_updater = {.func = refresh_gpu_usage_cache, .cooldown = GPU_USAGE_REF_FREQ};
  pthread_t gpu_usage_pthread;
  pthread_create(&gpu_usage_pthread, NULL, start_cycle, (void *)&gpu_usage_updater);
  printf("gpu_usage started\n");

  updater_t gpu_temp_updater = {.func = refresh_gpu_temp_cache, .cooldown = GPU_TEMP_REF_FREQ};
  pthread_t gpu_temp_pthread;
  pthread_create(&gpu_temp_pthread, NULL, start_cycle, (void *)&gpu_temp_updater);
  printf("gpu_temp started\n");

  printf("thing started\n");

  updater_t ram_usage_updater = {.func = refresh_ram_usage_cache, .cooldown = RAM_USAGE_REF_FREQ};
  pthread_t ram_usage_pthread;
  pthread_create(&ram_usage_pthread, NULL, start_cycle, (void *)&ram_usage_updater);
  printf("ram_usage started\n");

  updater_t vram_usage_updater = {.func = refresh_vram_usage_cache, .cooldown = VRAM_USAGE_REF_FREQ};
  pthread_t vram_usage_pthread;
  pthread_create(&vram_usage_pthread, NULL, start_cycle, (void *)&vram_usage_updater);
  printf("vram_usage started\n");


  updater_t battery_percentage_updater = {.func = refresh_battery_percentage_cache, .cooldown = BAT_PERCENTAGE_REF_FREQ};
  pthread_t battery_percentage_pthread;
  pthread_create(&battery_percentage_pthread, NULL, start_cycle, (void *)&battery_percentage_updater);
  printf("battery_percentage started\n");

  updater_t battery_pull_updater = {.func = refresh_battery_pull_cache, .cooldown = BAT_PULL_REF_FREQ};
  pthread_t battery_pull_pthread;
  pthread_create(&battery_pull_pthread, NULL, start_cycle, (void *)&battery_pull_updater);
  printf("battery_pull started\n");

  updater_t is_battery_charging_updater = {.func = refresh_is_battery_charging_cache, .cooldown = BAT_CHARGING_REF_FREQ};
  pthread_t is_battery_charging_pthread;
  pthread_create(&is_battery_charging_pthread, NULL, start_cycle, (void *)&is_battery_charging_updater);
  printf("is_battery_charging started\n");



  pthread_join(is_battery_charging_pthread, NULL);
  return NULL;
}

