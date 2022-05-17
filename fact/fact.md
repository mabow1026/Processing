# 提出シート

## 結果1: 最初のコンパイル
- 結果貼付欄
```
change:testFact.c
gcc -Wall -g   -c -o testFact.o testFact.c
chcp 65001
Active code page: 65001
gcc -o testFact.exe -Wall -g testFact.o fact.o  testCommon.o -lm
./testFact.exe
== Test abs ==
All tests are Ok. [# of Tests = 1, # of pass = 1 (100%)]
```
- 考察記入欄
- すべてのテストが通過している

## 結果2: 最初のテスト
- 結果貼付欄
```
change:testFact.c
gcc -Wall -g   -c -o testFact.o testFact.c
In file included from testFact.c:4:
testFact.c: In function 'testFact':
testFact.c:8:21: warning: implicit declaration of function 'fact' [-Wimplicit-function-declaration]
      |                                                   ^
chcp 65001
Active code page: 65001
gcc -o testFact.exe -Wall -g testFact.o fact.o  testCommon.o -lm
C:/tools/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.3.0/../../../../x86_64-w64-mingw32/bin/ld.exe: testFact.o: in function `testFact':
C:\Users\mabow\Documents\Processing\fact/testFact.c:8: undefined reference to `fact'    
collect2.exe: error: ld returned 1 exit statusmake: *** [Makefile:62: testFact.exe] エラー 1
```
- 考察記入欄
- 明示的に定義されていない関数を呼び出しているのでコンパイラが勝手にintを引数にintを返り値とする関数と解釈した。

## 結果3: プロトタイプ宣言記入後
- 結果貼付欄
```
change:testFact.c
gcc -Wall -g   -c -o testFact.o testFact.c
chcp 65001
Active code page: 65001
gcc -o testFact.exe -Wall -g testFact.o fact.o  testCommon.o -lm
C:/tools/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.3.0/../../../../x86_64-w64-mingw32/bin/ld.exe: testFact.o: in function `testFact':
C:\Users\mabow\Documents\Processing\fact/testFact.c:8: undefined reference to `fact'
collect2.exe: error: ld returned 1 exit status
make: *** [Makefile:62: testFact.exe] エラー 1
```
- 考察記入欄
- 先ほどの結果２とは異なり、プロトタイプ宣言を記述したため、コンパイルエラーの内容がimplicit declationではなくundefined referenceとなっている。明示的宣言はしたが、関数の実体がないためである。

## 結果4: 関数の雛形を作成
- 結果貼付欄
```
change:fact.c
gcc -Wall -g   -c -o fact.o fact.c
chcp 65001
Active code page: 65001
gcc -o testFact.exe -Wall -g testFact.o fact.o  testCommon.o -lm
./testFact.exe
== Test fact ==
Error in testFact.c(8): a != b (0 != 1)
###### Error exist!!!! [# of Tests = 1, # of pass = 0 (0%)] ######
make: *** [Makefile:63: testFact.exe] エラー 1

```
- 考察記入欄


## 結果5: 辻褄合わせの成功
- 結果貼付欄
```
change:fact.c
gcc -Wall -g   -c -o fact.o fact.c
chcp 65001
Active code page: 65001
gcc -o testFact.exe -Wall -g testFact.o fact.o  testCommon.o -lm
./testFact.exe
== Test fact ==
All tests are Ok. [# of Tests = 1, # of pass = 1 (100%)]

```
- 考察記入欄


## 結果6: テストを追加
- 結果貼付欄
```
change:testFact.c
gcc -Wall -g   -c -o testFact.o testFact.c
chcp 65001
Active code page: 65001
gcc -o testFact.exe -Wall -g testFact.o fact.o  testCommon.o -lm
./testFact.exe
== Test fact ==
Error in testFact.c(9): a != b (1 != 2)
Error in testFact.c(10): a != b (1 != 6)
Error in testFact.c(11): a != b (1 != 720)
###### Error exist!!!! [# of Tests = 4, # of pass = 1 (25%)] ######
make: *** [Makefile:63: testFact.exe] エラー 1
```
- 考察記入欄
- 入力に関わらず静的に１を返しているのでテストを通過できていない。

## 結果7: ちゃんとした実装
- 結果貼付欄
```
change:fact.c
gcc -Wall -g   -c -o fact.o fact.c
chcp 65001
Active code page: 65001
gcc -o testFact.exe -Wall -g testFact.o fact.o  testCommon.o -lm
./testFact.exe
== Test fact ==
All tests are Ok. [# of Tests = 4, # of pass = 4 (100%)]

```
- 考察記入欄
- 階乗のプログラムを実装し、入力に応じて階乗を計算して値を返しているので、テストを通過している。

## 結果8: 0の階乗、負の階乗のテスト
- 結果貼付欄
```
change:testFact.c
gcc -Wall -g   -c -o testFact.o testFact.c
chcp 65001
Active code page: 65001
gcc -o testFact.exe -Wall -g testFact.o fact.o  testCommon.o -lm
./testFact.exe
== Test fact ==
Error in testFact.c(13): a != b (-1 != -4)
Error in testFact.c(14): a != b (-1 != -6)
###### Error exist!!!! [# of Tests = 7, # of pass = 5 (71%)] ######
make: *** [Makefile:63: testFact.exe] エラー 1
```
- 考察記入欄
- 負の値ではループが動かないので、デフォルトの-１が帰ってきた。


## 結果9: 完成
- 結果貼付欄
```
change:testFact.c
gcc -Wall -g   -c -o testFact.o testFact.c
chcp 65001
Active code page: 65001
gcc -o testFact.exe -Wall -g testFact.o fact.o  testCommon.o -lm
./testFact.exe
== Test fact ==
All tests are Ok. [# of Tests = 7, # of pass = 7 (100%)]

```
- 考察記入欄
- すべて負の階乗の例外処理まで記述したので、テストを通過した。
