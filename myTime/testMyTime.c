#include <stdio.h>

#include "myTime.h"
#include "testCommon.h"

void testGetSeconds() {
    int ans;
    testStart("getSeconds");
    ans = getSeconds(2, 34, 56);
    assertEqualsInt(ans, 9296);
    ans = getSeconds(11, 59, 59);
    assertEqualsInt(ans, 43199);
}

void testGetSecondsFromTime() {
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59};
    int ans;
    testStart("getSecondsFromTime");
    ans = getSecondsFromTime(jikoku1);
    assertEqualsInt(ans, 9296);
    ans = getSecondsFromTime(jikoku2);
    assertEqualsInt(ans, 43199);
}

void testMakeTimeFromSeconds() {
    int jikoku[N];
    testStart("makeTimeFromSeconds");
    makeTimeFromSeconds(jikoku, 2 * 3600 + 34 * 60 + 56);
    assertEqualsInt(jikoku[HH], 2);
    assertEqualsInt(jikoku[MM], 34);
    assertEqualsInt(jikoku[SS], 56);
    makeTimeFromSeconds(jikoku, 12 * 3600 - 1);
    assertEqualsInt(jikoku[HH], 11);
    assertEqualsInt(jikoku[MM], 59);
    assertEqualsInt(jikoku[SS], 59);
}

void testTimeCmp() {
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59};
    assertEqualsInt(timeCmp(jikoku1, jikoku2), -1);
    assertEqualsInt(timeCmp(jikoku2, jikoku1), 1);
    assertEqualsInt(timeCmp(jikoku1, jikoku1), 0);
}

void testAddTime() {
    testStart("addTime");
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59}, jikoku3[N] = {0, 0, 0};
    addTime(jikoku3, jikoku1, jikoku2);
    assertEqualsInt(jikoku3[HH], 2 + 12);
    assertEqualsInt(jikoku3[MM], 34);
    assertEqualsInt(jikoku3[SS], 56 - 1);
    addTime(jikoku1, jikoku2, jikoku3);
    assertEqualsInt(jikoku1[HH], 2 + 12 + 12);
    assertEqualsInt(jikoku1[MM], 34);
    assertEqualsInt(jikoku1[SS], 56 - 2);
}

void testMulTime() {
    testStart("mulTime");
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {0, 0, 0};
    mulTime(jikoku2, jikoku1, 5);
    assertEqualsInt(jikoku2[HH], 12);
    assertEqualsInt(jikoku2[MM], 54);
    assertEqualsInt(jikoku2[SS], 40);
    mulTime(jikoku2, jikoku1, 3);
    assertEqualsInt(jikoku2[HH], 7);
    assertEqualsInt(jikoku2[MM], 44);
    assertEqualsInt(jikoku2[SS], 48);
}

void testDivTime() {
    testStart("divTime");
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {0, 0, 0};
    mulTime(jikoku2, jikoku1, 4);
    assertEqualsInt(jikoku2[HH], 10);
    assertEqualsInt(jikoku2[MM], 19);
    assertEqualsInt(jikoku2[SS], 44);
    mulTime(jikoku2, jikoku1, 2);
    assertEqualsInt(jikoku2[HH], 5);
    assertEqualsInt(jikoku2[MM], 9);
    assertEqualsInt(jikoku2[SS], 52);
}
void testDivTimeByTime() {
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59};
    assertEqualsInt(divTimeByTime(jikoku1, jikoku2), 0);
    assertEqualsInt(divTimeByTime(jikoku2, jikoku1), 4);
}

void testSubTime() {
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59}, jikoku3[N] = {0, 0, 0};
    subTime(jikoku3, jikoku1, jikoku2);
    assertEqualsInt(jikoku3[HH], 9);
    assertEqualsInt(jikoku3[MM], 25);
    assertEqualsInt(jikoku3[SS], 3);
    subTime(jikoku3, jikoku2, jikoku1);
    assertEqualsInt(jikoku3[HH], 9);
    assertEqualsInt(jikoku3[MM], 25);
    assertEqualsInt(jikoku3[SS], 3);
}

int main() {
    testGetSeconds();
    testGetSecondsFromTime();
    testMakeTimeFromSeconds();
    testTimeCmp();
    testAddTime();
    testMulTime();
    testDivTime();
    testDivTimeByTime();
    testSubTime();
    testErrorCheck();
    return 0;
}