#include "myTime.h"

#include <stdio.h>

int getSeconds(int h, int m, int s) {
    //
    return h * 3600 + m * 60 + s;
}

int getSecondsFromTime(int *tp) {
    //
    return getSeconds(tp[HH], tp[MM], tp[SS]);
}

void makeTimeFromSeconds(int *ansp, int seconds) {
    ansp[HH] = seconds / 3600;
    ansp[MM] = (seconds / 60) % 60;
    ansp[SS] = seconds % 60;
}

void makeTime(int *ansp, int h, int m, int s) {
    makeTimeFromSeconds(ansp, getSeconds(h, m, s));
}

int main() {
    testGetSeconds();
    testGetSecondsFromTime();  // ここを増やす
    testErrorCheck();
    return 0;
}