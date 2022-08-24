#include "polish.h"
#include <string.h>

void input(char *str) {
  int i = 0;
  while (scanf("%c", &str[i]) == 1 && (str[i] != '\n')) {
    i++;
  }
}

void skob(char *str, char *new, char *oper, int *i1, int *j1, int *position1) {
  int i = *i1, j = *j1, position = *position1, cons = *position1;
  i++;
  while (str[i] != '\n') {
    if ((str[i] >= 48 && str[i] <= 57) || str[i] == 'x' || str[i] == '.' ||
        str[i] == '~' || str[i] == '0') {
      new[j] = str[i];
      i++;
      j++;
    } else {
      if (str[i] == '(') {
        oper[position] = str[i];
        // printf("\n%d nach\n", position);
        position++;
        skob(str, new, oper, &i, &j, &position);
      } else {
        if (str[i] == '+' || str[i] == '-') {
          if (position != 0) {
            new[j] = ' ';
            j++;
            new[j] = oper[position - 1];
            j++;
            position--;
          }
        } else {
          if ((str[i] == '/' || str[i] == '*') &&
              (oper[position - 1] == '*' || oper[position - 1] == '/')) {
            new[j] = ' ';
            j++;
            new[j] = oper[position - 1];
            j++;
            position--;
          }
        }
        if (str[i] == 'l' && str[i + 1] == 'n') {
          oper[position] = str[i];
          i += 2;
          position++;
        } else {
          if (str[i] == 's' && str[i + 1] == 'q' && str[i + 2] == 'r' &&
              str[i + 3] == 't') {
            oper[position] = str[i + 1];
            i += 4;
            position++;
          } else {
            if (str[i] == 'c' && str[i + 1] == 't' && str[i + 2] == 'g') {
              oper[position] = str[i + 2];
              i += 3;
              position++;
            } else {
              if (str[i] == 't' && str[i + 1] == 'a' && str[i + 2] == 'n') {
                oper[position] = str[i];
                i += 3;
                position++;
              } else {
                if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's') {
                  oper[position] = str[i];
                  i += 3;
                  position++;
                } else {
                  if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n') {
                    oper[position] = str[i];
                    i += 3;
                    position++;
                  } else {
                    if (str[i] != ')') {
                      new[j] = ' ';
                      j++;
                      oper[position] = str[i];
                      i++;
                      position++;
                    } else {
                        break;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  for (; position >= cons; position--) {
    new[j] = ' ';
    j++;
    new[j] = oper[position - 1];
    j++;
  }
  // while (oper[position] != '(' && position != -1) {
  //   new[j] = ' ';
  //   j++;
  //   new[j] = oper[position - 1];
  //   j++;
  // }

  // printf("\n%d konz\n", position);
  // if (position != -1 && oper[position] == '(') {
  //   printf("\ndfg\n");
  //   oper[position] = ' ';
  //   position--;
  // }
  *i1 = i;
  *j1 = j;
  *position1 = position;
}

void to_polish(char *str, char *new) {
  int i = -1, j = 0, position = 0;
  char oper[80];

  // if(str[i]>=48 && str[i]<=57) {
  //     new[j]=str[i];
  //     i++; j++;
  // } else {
  //     if(new[j-1] != ' '){
  //         new[j]=' ';
  //     }
  //     oper=create_node(str[i]);
  //     i++; j++;
  // }

  skob(str, new, oper, &i, &j, &position);

  // printf("%d", j);
  new[j] = '\0';
  // destroy(oper);
}

double from_polish(const char *str, double x) {
  int i = 0, position = 0;
  double oper[80];
  while (str[i] != '\0') {
    if (str[i] != ' ') {
      if (str[i] == 'l' && str[i + 1] == 'n') {
        oper[position - 1] = log(oper[position - 1]);
      } else {
        if (str[i] == 'q') {
          oper[position - 1] = sqrt(oper[position - 1]);
        } else {
          if (str[i] == 'g') {
            oper[position - 1] = tan(M_PI / 2.0 - oper[position - 1]);
          } else {
            if (str[i] == 't') {
              oper[position - 1] = tan(oper[position - 1]);
            } else {
              if (str[i] == 'c') {
                oper[position - 1] = cos(oper[position - 1]);
              } else {
                if (str[i] == 's') {
                  oper[position - 1] = sin(oper[position - 1]);
                } else {
                  if (str[i] == '*') {
                    oper[position - 2] =
                        oper[position - 2] * oper[position - 1];
                    position--;
                  } else {
                    if (str[i] == '/') {
                      oper[position - 2] =
                          oper[position - 2] / oper[position - 1];
                      position--;
                    } else {
                      if (str[i] == '+') {
                        oper[position - 2] =
                            oper[position - 2] + oper[position - 1];
                        position--;
                      } else {
                        if (str[i] == '-') {
                          oper[position - 2] =
                              oper[position - 2] - oper[position - 1];
                          position--;
                        } else {
                          if ((str[i] <= 57 && str[i] >= 48) || str[i] == '~') {
                            double v = 0;
                            int valuez = 1;
                            if (str[i] == '~') {
                              valuez = -1;
                              i++;
                            }
                            while (str[i] != ' ' && str[i] != '.' &&
                                   str[i] != '\0') {
                              v *= 10.0;
                              v += str[i] - 48;
                              i++;
                            }
                            if (str[i] == '.') {
                              i++;
                              double k = 10;
                              while (str[i] != ' ' && str[i] != '\0') {
                                v += (str[i] - 48) / k;
                                k *= 10.0;
                                i++;
                              }
                            }
                            oper[position] = v * valuez;
                            position++;
                          } else {
                            if (str[i] == 'x') {
                              oper[position] = x;
                              position++;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    i++;
  }
  return oper[position - 1];
}
