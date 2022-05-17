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

int main() {
    testGetSeconds();
    testErrorCheck();
    return 0;
}