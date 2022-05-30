#define N 3
#define HH 0
#define MM 1
#define SS 2

int getSeconds(int h, int m, int s);
int getSecondsFromTime(int *tp);
void makeTimeFromSeconds(int *ansp, int seconds);
void makeTime(int *ansp, int h, int m, int s);
int timeCmp(int *t1p, int *t2p);
void addTime(int *ansp, int *t1p, int *t2p);
void mulTime(int *ansp, int *tp, int n);
void divTime(int *ansp, int *tp, int n);
int divTimeByTime(int *t1p, int *t2p);
void subTime(int *ansp, int *t1p, int *t2p);
void printHourMinute(int *tp);
void printMinuteSecond(int *tp);