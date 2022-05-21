#include <stdio.h>

#include "fact.h"
#include "testCommon.h"

void testFact() {
    testStart("fact");
    assertEqualsInt(fact(1), 1);
    assertEqualsInt(fact(2), 2);
    assertEqualsInt(fact(3), 6);
    assertEqualsInt(fact(6), 720);
    assertEqualsInt(fact(0), 1);
    assertEqualsInt(fact(-1), -1);
    assertEqualsInt(fact(-3), -1);
}

int main() {
    testFact();
    testErrorCheck();
}
