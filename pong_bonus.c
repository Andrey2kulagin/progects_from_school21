#include <stdio.h>
#include <ncurses.h>

void print(int ball_x, int ball_y, int rocket_left_x, int rocket_left_y,
           int rocket_right_x, int rocket_right_y, int points_left,
           int points_right) {
  for (int y = 0; y < 25; y++) {
    for (int x = 0; x < 80; x++) {
      if (y != 0 && y != 24) {
        if ((x == rocket_right_x && y == rocket_right_y) ||
            (x == rocket_left_x && y == rocket_left_y) ||
            (x == rocket_right_x && y == rocket_right_y - 1) ||
            (x == rocket_left_x && y == rocket_left_y - 1) ||
            (x == rocket_right_x && y == rocket_right_y + 1) ||
            (x == rocket_left_x && y == rocket_left_y + 1)) {
          printw("|");
        } else {
          if (x == ball_x && y == ball_y) {
            printw("*");
          } else {
            if (x == 0 || x == 79 || x == 40) {
              if (y == 13 && x == 79) {
                printw("|  %d : %d", points_right, points_left);
              } else {
                printw("|");
              }
            } else {
              printw(" ");
            }
          }
        }
      } else {
        printw("_");
      }
    }
    printw("\n");
  }
}
int main() {
  initscr();
  int ball_x = 2;
  int ball_y = 13;
  int rocket_left_x = 1;
  int rocket_left_y = 13;
  int rocket_right_x = 78;
  int rocket_right_y = 13;
  int points_right = 0;
  int points_left = 0;
  int ball_direction = 1;
  print(ball_x, ball_y, rocket_left_x, rocket_left_y, rocket_right_x,
        rocket_right_y, points_left, points_right);
  while ((points_left < 21 && points_right < 21)) {
    char symb = getch();
    // счётчик
    if (1 == ball_x) {
      points_right++;
      ball_x = 41;
      ball_y = 13;
      ball_direction = 1;
    }
    if (78 == ball_x) {
      points_left++;
      ball_x = 41;
      ball_y = 13;
      ball_direction = 4;
    }
    // раздел регулировки направления
    if ((rocket_left_x == ball_x - 1) && (rocket_left_y == ball_y)) {
      ball_direction = 1;  // вправо
    }
    if ((rocket_left_x == ball_x - 1) && (rocket_left_y - 1 == ball_y)) {
      ball_direction = 2;  // вправо вверх
    }
    if ((rocket_left_x == ball_x - 1) && (rocket_left_y + 1 == ball_y)) {
      ball_direction = 3;  // вправо вниз
    }
    if ((rocket_right_x == ball_x + 1) && (rocket_right_y == ball_y)) {
      ball_direction = 4;  // влево
    }
    if ((rocket_right_x == ball_x + 1) && (rocket_right_y - 1 == ball_y)) {
      ball_direction = 5;  // влево вверх
    }
    if ((rocket_right_x == ball_x + 1) && (rocket_right_y + 1 == ball_y)) {
      ball_direction = 6;  // влево вниз
    }
    if (ball_direction == 2 && ball_y == 1) {
      ball_direction = 3;
    }
    if (ball_direction == 3 && ball_y == 23) {
      ball_direction = 2;
    }
    if (ball_direction == 5 && ball_y == 1) {
      ball_direction = 6;
    }
    if (ball_direction == 6 && ball_y == 23) {
      ball_direction = 5;
    }
    switch (ball_direction) {
    case 1:
      switch (symb) {
      case 'a':
        rocket_left_y--;
        ball_x++;
        break;
      case 'z':
        rocket_left_y++;
        ball_x++;
        break;
      case 'k':
        rocket_right_y--;
        ball_x++;
        break;
      case 'm':
        rocket_right_y++;
        ball_x++;
        break;
      case ' ':
        ball_x++;
        break;
      }
      break;
    case 2:
      switch (symb) {
      case 'a':
        rocket_left_y--;
        ball_x++;
        ball_y--;
        break;
      case 'z':
        rocket_left_y++;
        ball_x++;
        ball_y--;
        break;
      case 'k':
        rocket_right_y--;
        ball_x++;
        ball_y--;
        break;
      case 'm':
        rocket_right_y++;
        ball_x++;
        ball_y--;
        break;
      case ' ':
        ball_x++;
        ball_y--;
        break;
      }
      break;
    case 3:
      switch (symb) {
      case 'a':
        rocket_left_y--;
        ball_x++;
        ball_y++;
        break;
      case 'z':
        rocket_left_y++;
        ball_x++;
        ball_y++;
        break;
      case 'k':
        rocket_right_y--;
        ball_x++;
        ball_y++;
        break;
      case 'm':
        rocket_right_y++;
        ball_x++;
        ball_y++;
        break;
      case ' ':
        ball_x++;
        ball_y++;
        break;
      }
      break;
    case 4:
      switch (symb) {
      case 'a':
        rocket_left_y--;
        ball_x--;
        break;
      case 'z':
        rocket_left_y++;
        ball_x--;
        break;
      case 'k':
        rocket_right_y--;
        ball_x--;
        break;
      case 'm':
        rocket_right_y++;
        ball_x--;
        break;
      case ' ':
        ball_x--;
        break;
      }
      break;
    case 5:
      switch (symb) {
      case 'a':
        rocket_left_y--;
        ball_x--;
        ball_y--;
        break;
      case 'z':
        rocket_left_y++;
        ball_x--;
        ball_y--;
        break;
      case 'k':
        rocket_right_y--;
        ball_x--;
        ball_y--;
        break;
      case 'm':
        rocket_right_y++;
        ball_x--;
        ball_y--;
        break;
      case ' ':
        ball_x--;
        ball_y--;
        break;
      }
      break;
    case 6:
      switch (symb) {
      case 'a':
        rocket_left_y--;
        ball_x--;
        ball_y++;
        break;
      case 'z':
        rocket_left_y++;
        ball_x--;
        ball_y++;
        break;
      case 'k':
        rocket_right_y--;
        ball_x--;
        ball_y++;
        break;
      case 'm':
        rocket_right_y++;
        ball_x--;
        ball_y++;
        break;
      case ' ':
        ball_x--;
        ball_y++;
        break;
      }
      break;
    }
    // управление границами ракеток
    if (rocket_left_y > 22) {
      rocket_left_y = 22;
    }
    if (rocket_left_y < 2) {
      rocket_left_y = 2;
    }
    if (rocket_right_y > 22) {
      rocket_right_y = 22;
    }
    if (rocket_right_y < 2) {
      rocket_right_y = 2;
    }
    erase();
    print(ball_x, ball_y, rocket_left_x, rocket_left_y, rocket_right_x,
          rocket_right_y, points_right, points_left);
  }
  if (points_left > points_right) {
    printw("GAME OVER!\n");
    printw("LEFT PLEER VIN!");
  } else {
    printw("GAME OVER!\n");
    printw("RIGHT PLEER VIN!");
  }
  endwin();
  return 0;
}
