int fact(int x) {
    if (x < 0) {
        return -1;
    } else {
        int fact = 1;
        for (int i = 2; i <= x; ++i) {
            fact *= i;
        }
        return fact;
    }
}