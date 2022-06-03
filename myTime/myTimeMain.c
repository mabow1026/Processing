#include <stdio.h>
#include <stdlib.h>

#include "myTime.h"

void q1() {
    //
    int lectureTime[N], restTime[N], launchTime[N], start[N], end[N];
    printf("Q1\n");
    makeTime(lectureTime, 0, 90, 0);
    makeTime(restTime, 0, 15, 0);
    makeTime(launchTime, 0, 50, 0);
    makeTime(start, 8, 40, 0);
    for (int i = 1; i < 9; i += 2) {
        addTime(end, start, lectureTime);
        printf("%d%d限", i, i + 1);
        printHourMinute(start);
        printf(" - ");
        printHourMinute(end);
        printf("\n");
        addTime(start, end, i == 3 ? launchTime : restTime);
    }
    printf("---\n\n");
}

void q2() {
    //
    int examTime[N], restTime[N], launchTime[N], start[N], end[N];
    printf("Q2\n");
    makeTime(examTime, 0, 50, 0);
    makeTime(restTime, 0, 20, 0);
    makeTime(launchTime, 0, 60, 0);
    makeTime(start, 9, 0, 0);
    for (int i = 1; i < 4 + 1; i++) {
        addTime(end, start, examTime);
        printf("%d限", i);
        printHourMinute(start);
        printf(" - ");
        printHourMinute(end);
        printf("\n");
        addTime(start, end, i == 3 ? launchTime : restTime);
    }
    printf("---\n\n");
}

void q3() {
    //

    int expTime[N], lookBackTime[N], changeTime[N], presentationTime[N];
    printf("Q3\n");
    makeTime(expTime, 0, 90 * 2, 0);
    makeTime(lookBackTime, 0, 30, 0);
    makeTime(changeTime, 0, 10 - 1, 0);
    subTime(expTime, expTime, lookBackTime);
    subTime(expTime, expTime, changeTime);
    divTime(presentationTime, expTime, 10);
    printMinuteSecond(presentationTime);
    printf("\n");

    printf("---\n\n");
}

void q4() {
    //
    int announceTime[N], lookBackTime[N], changeTime[N], presentationTime[N];
    printf("Q4\n");
    makeTime(announceTime, 0, 90 * 4, 0);
    makeTime(lookBackTime, 0, 30, 0);
    makeTime(changeTime, 0, 40 - 2, 0);
    subTime(announceTime, announceTime, lookBackTime);
    subTime(announceTime, announceTime, changeTime);
    divTime(presentationTime, announceTime, 40);
    printMinuteSecond(presentationTime);
    printf("\n");
    printf("---\n\n");
}

int main() {
    q1();
    q2();
    q3();
    q4();
    return 0;
}