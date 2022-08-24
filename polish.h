#ifndef SRC_POLISH_H_
#define SRC_POLISH_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//  #define STACK_MAX_SIZE 20


void input(char *str);
void skob(char *str, char *new, char *oper, int *i1, int *j1, int *position1);
void to_polish(char *str, char *new);
double from_polish(const char *str, double x);

#endif  // SRC_POLISH_H_
