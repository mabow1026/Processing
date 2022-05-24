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
    //
    ansp[HH] = seconds / 3600;
    ansp[MM] = (seconds / 60) % 60;
    ansp[SS] = seconds % 60;
}

void makeTime(int *ansp, int h, int m, int s) {
    //
    makeTimeFromSeconds(ansp, getSeconds(h, m, s));
}

int timeCmp(int *t1p, int *t2p) {
    //
    int s1 = getSecondsFromTime(t1p);
    int s2 = getSecondsFromTime(t2p);

    return s1 > s2 ? 1 : s1 < s2 ? -1
                                 : 0;
}

void addTime(int *ansp, int *t1p, int *t2p) {
    //
    int sec = getSecondsFromTime(t1p) + getSecondsFromTime(t2p);
    makeTimeFromSeconds(ansp, sec);
}

void mulTime(int *ansp, int *tp, int n) {
    //
    int sec = getSecondsFromTime(tp);
    makeTimeFromSeconds(ansp, sec * n);
}

void divTime(int *ansp, int *tp, int n) {
    //
    int sec = getSecondsFromTime(tp);
    makeTimeFromSeconds(ansp, sec / n);
}

int divTimeByTime(int *t1p, int *t2p) {
    //
    int s1 = getSecondsFromTime(t1p);
    int s2 = getSecondsFromTime(t2p);
    return s1 / s2;
}

void subTime(int *ansp, int *t1p, int *t2p) {
    //
    int sec;
    if (timeCmp(t1p, t2p) == 1) {
        sec = getSecondsFromTime(t1p) - getSecondsFromTime(t2p);
    } else if (timeCmp(t1p, t2p) == -1) {
        sec = getSecondsFromTime(t2p) - getSecondsFromTime(t1p);
    } else {
        sec = getSecondsFromTime(t1p) - getSecondsFromTime(t2p);
    }
    makeTimeFromSeconds(ansp, sec);
}