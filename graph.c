#include "output.h"
#include "polish.h"

int main() {
  char str[80], new[80];
  input(str);
  to_polish(str, new);
  // output(new);
  // printf("\n%lf\n", from_polish(new, 1));
  int log[80];
  for (int x = 0; x < 80; x++) {
    log[x] = 12.5 * from_polish(new, (4.0 * M_PI / 80.0) * x) + 13;
  }
  outputS(log);

  return 0;
}
