#include "output.h"
#include <stdio.h>

void outputS(const int *ypos) {
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 80; j++) {
      if (i == ypos[j]) {
        printf("*");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}
