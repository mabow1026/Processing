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

int main() {
    testGetSeconds();
    testGetSecondsFromTime();
    testMakeTimeFromSeconds();  // ここを増やす
    testErrorCheck();
    return 0;
}