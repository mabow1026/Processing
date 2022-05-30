#include <stdio.h>

#include "myTime.h"
#include "testCommon.h"

void testGetSeconds() {
    int ans;
    testStart("getSeconds");
    ans = getSeconds(2, 34, 56);
    assertEqualsInt(ans, 2 * 3600 + 34 * 60 + 56);
    ans = getSeconds(11, 59, 59);
    assertEqualsInt(ans, 12 * 3600 - 1);
}

void testGetSecondsFromTime() {
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59};
    int ans;
    testStart("getSecondsFromTime");
    ans = getSecondsFromTime(jikoku1);
    assertEqualsInt(ans, 2 * 3600 + 34 * 60 + 56);
    ans = getSecondsFromTime(jikoku2);
    assertEqualsInt(ans, 12 * 3600 - 1);
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

void testMakeTime() {
    int jikoku[N];
    testStart("makeTimeFromSeconds");
    makeTime(jikoku, 1, 77, 90);
    assertEqualsInt(jikoku[HH], 2);
    assertEqualsInt(jikoku[MM], 18);
    assertEqualsInt(jikoku[SS], 30);
    makeTime(jikoku, 10, 99, 94);
    assertEqualsInt(jikoku[HH], 11);
    assertEqualsInt(jikoku[MM], 40);
    assertEqualsInt(jikoku[SS], 34);
}

void testTimeCmp() {
    int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59};
    assertEqualsInt(timeCmp(jikoku1, jikoku2), -1);
    assertEqualsInt(timeCmp(jikoku2, jikoku1), 1);
    assertEqualsInt(timeCmp(jikoku1, jikoku1), 0);
}

// void testAddTime() {
//     testStart("testAddTime");
//     int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59},
//         jikoku3[N] = {0, 0, 0};
//     addTime(jikoku3, jikoku1, jikoku2);
//     assertEqualsInt(jikoku3[HH], 2 + 12);
//     assertEqualsInt(jikoku3[MM], 34);
//     assertEqualsInt(jikoku3[SS], 56 - 1);
//     addTime(jikoku2, jikoku1, jikoku3);
//     assertEqualsInt(jikoku2[HH], 14 + 2 + 1);
//     assertEqualsInt(jikoku2[MM], 34 + 34 + 1 - 60);
//     assertEqualsInt(jikoku2[SS], 55 + 56 - 60);
// }
// void testMulTime() {
//     testStart("testMulTime");
//     int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59},
//         jikoku3[N] = {0, 0, 0};
//     mulTime(jikoku3, jikoku1, 2);
//     assertEqualsInt(jikoku3[HH], 2 * 2 + 1 * 1);
//     assertEqualsInt(jikoku3[MM], (34 * 2 + 1 * 1) % 60);
//     assertEqualsInt(jikoku3[SS], (56 * 2) % 60);
//     mulTime(jikoku3, jikoku2, 3);
//     assertEqualsInt(jikoku3[HH], 11 * 3 + 1 * 2);
//     assertEqualsInt(jikoku3[MM], (59 * 3 + 1 * 2) % 60);
//     assertEqualsInt(jikoku3[SS], (59 * 3) % 60);
// }
// void testDivTime() {
//     testStart("testDivTime");
//     int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {10, 30, 12},
//         jikoku3[N] = {0, 0, 0};
//     divTime(jikoku3, jikoku1, 2);
//     assertEqualsInt(jikoku3[HH], 1);
//     assertEqualsInt(jikoku3[MM], 17);
//     assertEqualsInt(jikoku3[SS], 28);
//     divTime(jikoku3, jikoku2, 4);
//     assertEqualsInt(jikoku3[HH], 2);
//     assertEqualsInt(jikoku3[MM], 37);
//     assertEqualsInt(jikoku3[SS], 33);
// }
// void testDivTimeByTime() {
//     testStart("testDivTimeByTime");
//     int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59},
//         jikoku3[N] = {0, 0, 0};
//     assertEqualsInt(divTimeByTime(jikoku2, jikoku1), 4);
//     assertEqualsInt(divTimeByTime(jikoku1, jikoku3), -1);
// }
// void testSubTime() {
//     testStart("testSubTime");
//     int jikoku1[N] = {2, 34, 56}, jikoku2[N] = {11, 59, 59},
//         jikoku3[N] = {0, 0, 0};
//     subTime(jikoku3, jikoku1, jikoku2);
//     assertEqualsInt(jikoku3[HH], 11 - 2);
//     assertEqualsInt(jikoku3[MM], 59 - 34);
//     assertEqualsInt(jikoku3[SS], 59 - 56);
//     subTime(jikoku2, jikoku1, jikoku3);
//     assertEqualsInt(jikoku2[HH], 9 - 2 - 1);
//     assertEqualsInt(jikoku2[MM], 25 - 34 + 60 - 1);
//     assertEqualsInt(jikoku2[SS], 3 - 56 + 60);
// }

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