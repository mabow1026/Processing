#include <stdio.h>

#include "fact.h"

int main() {
    int x, y;
    fprintf(stderr, "整数を一つ入力して下さい");
    scanf("%d", &x);
    y = fact(x);
    if (x < 0) {
        printf("0 未満の階乗は計算できません¥n");
    } else {
        printf("%d の階乗は %d です\n", x, y);
    }
    return 0;
}