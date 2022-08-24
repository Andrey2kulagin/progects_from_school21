#include <stdio.h>
#include <unistd.h>

void print_matrix(char matrix[25][80]);
void clearScreen(void);
void set_empty_arr(char b[25][80]);
void logic(int count, char a[25][80], char b[25][80], int i, int j);
void change_a(char a[25][80], char b[25][80]);
void print_initial(char a[25][80], char str[10]);
void get_figure(int x, char a[25][80]);
void cure_sleep(int a);
int finish_for_spase(char a[25][80]);
int finish_for_stay(char a[25][80], char b[25][80]);


int main() {
    char a[25][80];
    char b[25][80];
    char c[25][80];
    int fig, speed, flag = 0;
    printf("Chose number of speed mod:\n 1.fast\n 2.medium \n 3.slowly\n");
    scanf("%d", &speed);
    printf("Choose number of the figure:\n1.Spider\n2.Line\n3.Mazing\n4.Keys\n5.Bipole\n");
    scanf("%d", &fig);
    set_empty_arr(a);
    get_figure(fig, a);
    set_empty_arr(b);
    print_matrix(a);
    set_empty_arr(c);
    while (1) {
        int count;
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                count = 0;
                for (int p = -1; p < 2; p++) {
                    for (int l = -1; l < 2; l++) {
                        if ((p != 0 || l != 0)  && a[(i + p + 25) % 25][(j + l + 80) % 80] != ' ') {
                            count++;
                        }
                    }
                }
                logic(count, a, b, i, j);
            }
        }
        if (finish_for_stay(a, b) == 0) {
            printf("GAME OVER!!!");
            break;
        }
        change_a(a, b);
        cure_sleep(speed);
        clearScreen();
        print_matrix(a);
        if (flag == 1) {
            if (finish_for_stay(a, c) == 0) {
                printf("GAME OVER!!!");
                break;
            }
        }
        if (flag == 0) {
            change_a(c, b);
            flag = 1;
        }
        if (finish_for_spase(a) == 0) {
            printf("GAME OVER!!!");
            break;
        }
    }
    return 0;
}

int finish_for_stay(char a[25][80], char b[25][80]) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (a[i][j] != b[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}
int finish_for_spase(char a[25][80]) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (a[i][j] != ' ') {
                return 1;
            }
        }
    }
    return 0;
}
void cure_sleep(int a) {
    if (a == 1) {
        usleep(10000);
    }
    if (a == 2) {
       usleep(100000);
    }
    if (a == 3) {
        usleep(1000000);
    }
}

void print_initial(char a[25][80], char str[20]) {
    FILE * ptr = fopen(str, "r");
    int x, y;
    while (fscanf(ptr, "%d %d", &x, &y) == 2) {
        a[x][y]='*';
    }
}

void print_matrix(char matrix[25][80]) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

void clearScreen(void) {
    printf("\33[0d\33[2J");
}


void set_empty_arr(char b[25][80]) {
       for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            b[i][j] = ' ';
        }
    }
}

void logic(int count, char a[25][80], char b[25][80], int i, int j) {
    if (a[i][j] == ' ') {
        if (count == 3) {
            b[i][j] = '*';
        } else {
            b[i][j] = ' ';
        }
    } else {
        if (count == 3 || count == 2) {
            b[i][j] = '*';
        } else {
            b[i][j] = ' ';
        }
    }
}
void change_a(char a[25][80], char b[25][80]) {
    for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                a[i][j] = b[i][j];
            }
        }
}

void get_figure(int x, char a[25][80]) {
    if (x == 1) {
        print_initial(a, "spider.txt");
    } else if (x == 2) {
        print_initial(a, "line.txt");
    } else if (x == 3) {
        print_initial(a, "mazing.txt");
    } else if (x == 4) {
        print_initial(a, "keys.txt");
    } else if (x == 5) {
        print_initial(a, "bipole.txt");
    }
}
