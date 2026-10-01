#include "util.h"
#include "mathutil.h"

int get_status_bar(char *dest, int segments, double percent, char *color) {
  if ((dest == NULL) ||
      (segments <= 0) ||
      (color == NULL)) {
    return 1;
  }

  percent = fclamp(percent, 0.0, 100.0);

  dest[0] = '[';
  dest[1] = '\0';

  int seg_filled = (int)((percent * segments / 100.0) + .5);
  strncat(dest, color, COLOR_LEN + 1);

  for (int i = 0; i < segments; i++) {
    if (i < seg_filled) {
      strcat(dest, "#");
    } else {
      if (i == seg_filled) {
        strncat(dest, COLOR_RESET, COLOR_RESET_LEN + 1);
      }
      strcat(dest, "-");
    }
  }
  if (seg_filled == segments) {
    strncat(dest, COLOR_RESET, COLOR_RESET_LEN + 1);
  }
  strcat(dest, "]");
  return 0;
}


int get_double_status_bar(char *dest, int segments, double percent_1, double percent_2,
                          char * color_1, char *color_2, char *color_overlap) {
  if ((dest == NULL) ||
      (segments <= 0) ||
      (color_1 == NULL) ||
      (color_2 == NULL) ||
      (color_overlap == NULL)) {
    return 1;
  }

  percent_1 = fclamp(percent_1, 0.0, 100.0);
  percent_2 = fclamp(percent_2, 0.0, 100.0);

  dest[0] = '[';
  dest[1] = '\0';

  int seg_filled_1 = (int)((percent_1 * segments / 100.0) + .5);
  int seg_filled_2 = (int)((percent_2 * segments / 100.0) + .5);

  strncat(dest, color_overlap, COLOR_LEN + 1);

  for (int i = 0; i < segments; i++) {
    if (i < imax(seg_filled_1, seg_filled_2)) {
      if (i == imin(seg_filled_1, seg_filled_2)) {
        strncat(dest, COLOR_RESET, COLOR_RESET_LEN + 1);
        char *new_color = i == seg_filled_1 ? color_2 : color_1;
        strncat(dest, new_color, COLOR_LEN + 1);
      }
      strcat(dest, i < imin(seg_filled_1, seg_filled_2) ? "#" : "+");

    } else {
      if (i == imax(seg_filled_1, seg_filled_2)) {
        strncat(dest, COLOR_RESET, COLOR_RESET_LEN + 1);
      }
      strcat(dest, "-");
    }
  }
  if ((seg_filled_1 == segments) || (seg_filled_2 == segments)) {
    strncat(dest, COLOR_RESET, COLOR_RESET_LEN + 1);
  }
  strcat(dest, "]");
  return 0;
}
