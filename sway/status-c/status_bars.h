#ifndef STATUS_BARS_H
#define STATUS_BARS_H

#define CPU (0)
#define GPU (1)
#define BAT (2)
#define RAM (3)
#define VRAM (4)

void print_cpu_status_bar(char *);
void print_gpu_status_bar(char *);
void print_bat_status_bar(char *);
void print_ram_status_bar(char *);
void print_vram_status_bar(char *);

void get_status_bar_type(char *, char);
void print_status_bar(char, char *);
void print_double_status_bar(int seg, double p1, double p2, char *c1, char *c2, char *c3);
#endif
