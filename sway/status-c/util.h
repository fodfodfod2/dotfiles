#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <string.h>

#define COLOR_BLACK   "<span foreground='#000000'>"
#define COLOR_RED     "<span foreground='#ff0000'>"
#define COLOR_GREEN   "<span foreground='#00ff00'>"
#define COLOR_YELLOW  "<span foreground='#ffff00'>"
#define COLOR_BLUE    "<span foreground='#0000ff'>"
#define COLOR_PURPLE  "<span foreground='#ff00ff'>"
#define COLOR_CYAN    "<span foreground='#ff0000'>"
#define COLOR_WHITE   "<span foreground='#ffffff'>"
#define COLOR_RESET   "</span>"

#define COLOR_LEN strlen(COLOR_BLACK) + 1
#define COLOR_RESET_LEN strlen(COLOR_RESET) + 1



int get_status_bar(char *, int, double, char *);
int get_double_status_bar(char *, int, double, double, char *, char *, char *);

#endif
