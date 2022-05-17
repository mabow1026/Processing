#include <stdio.h>

#include "fact.h"
#include "testCommon.h"

void testFact() {
    testStart("fact");
    assertEqualsInt(fact(1), 1);    // 1 の階乗は 1 かどうか?
    assertEqualsInt(fact(2), 2);    // この行を追加
    assertEqualsInt(fact(3), 6);    // この行を追加
    assertEqualsInt(fact(6), 720);  // この行を追加
    assertEqualsInt(fact(0), 1);
    assertEqualsInt(fact(-1), -1);
    assertEqualsInt(fact(-3), -1);
}

int main() {
    testFact();
    testErrorCheck();
}
