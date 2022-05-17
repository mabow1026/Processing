#include <stdio.h>
#define IN 5
#define DN 3
int calcIntSumAndInt(int *xp, int n, int base);
double calcDoubleSumAndDouble(double *xp, int n, double base);

int main(int argc, const char *argv[]) {
    int a = 3;
    double b = 3.14;
    int c[IN] = {3, 1, 4, 1, 5};
    double d[DN] = {3.14, 1.59, 2.65};
    int e = calcIntSumAndInt(c, IN, a);
    double f = calcDoubleSumAndDouble(d, DN, b);

    printf("e = %d\n", e);
    printf("f = %f\n", f);
    return 0;
}

int calcIntSumAndInt(int *xp, int n, int base) {
    int i;
    int sum = base;
    for (i = 0; i < n; i++) {
        sum += xp[i];
    }
    return sum;
}

double calcDoubleSumAndDouble(double *xp, int n, double base) {
    int i;
    double sum = base;
    for (i = 0; i < n; i++) {
        sum += xp[i];
    }
    return sum;
}
