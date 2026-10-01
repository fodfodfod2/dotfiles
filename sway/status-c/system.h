#ifndef SYSTEM_H
#define SYSTEM_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char get_str_from_cli(char *, char *);
double get_double_from_cli(char *);

double get_cpu_usage_nocache();
int get_cpu_temp_nocache();

double get_ram_usage_nocache();

double get_battery_pull_nocache();
double get_battery_percentage_nocache();
double get_battery_capacity_nocache();
char is_battery_charging_nocache();

double get_gpu_usage_nocache();
int get_gpu_temp_nocache();
double get_vram_usage_nocache();

void get_datestring_nocache(char *dest);
#endif
