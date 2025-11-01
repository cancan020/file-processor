## 실행결과

### 클라이언트: count

```

./file_processor_clnt test.txt count

 $ ./file_processor_clnt test.txt count
클라이언트: 서버에 연결 시도 중...

클라이언트: 서버 연결됨.

1번째 줄 전송...

1번째 줄 결과 수신: Line 1: 11 chars, 2 words

2번째 줄 전송...

2번째 줄 결과 수신: Line 2: 45 chars, 9 words

3번째 줄 전송...

3번째 줄 결과 수신: Line 3: 19 chars, 4 words

4번째 줄 전송...

4번째 줄 결과 수신: Line 4: 18 chars, 4 words

5번째 줄 전송...

5번째 줄 결과 수신: Line 5: 23 chars, 5 words

6번째 줄 전송...

6번째 줄 결과 수신: Line 6: 3 chars, 1 words

7번째 줄 전송...

7번째 줄 결과 수신: Line 7: 7 chars, 2 words

8번째 줄 전송...

8번째 줄 결과 수신: Line 8: 17 chars, 3 words

9번째 줄 전송...

9번째 줄 결과 수신: Line 9: 19 chars, 4 words

10번째 줄 전송...

10번째 줄 결과 수신: Line 10: 24 chars, 5 words

=== 처리 통계 ===

 처리 모드: count

 처리한 줄 수: 10줄

 소요 시간: 0.00초

```

### 클라이언트: upper

```

./file_processor_clnt test.txt upper

 ./file_processor_clnt test.txt upper
클라이언트: 서버에 연결 시도 중...
클라이언트: 서버 연결됨.
1번째 줄 전송...
1번째 줄 결과 수신: Line 1: HELLO WORLD
2번째 줄 전송...
2번째 줄 결과 수신: Line 2: THIS IS A SAMPLE TEXT FILE FOR THE ASSIGNMENT.
3번째 줄 전송...
3번째 줄 결과 수신: Line 3: C PROGRAMMING IS FUN.
4번째 줄 전송...
4번째 줄 결과 수신: Line 4: USING FIFO FOR IPC.
5번째 줄 전송...
5번째 줄 결과 수신: Line 5: KEEP CALM AND CODE ON.
6번째 줄 전송...
6번째 줄 결과 수신: Line 6: ONE
7번째 줄 전송...
7번째 줄 결과 수신: Line 7: TWO TWO
8번째 줄 전송...
8번째 줄 결과 수신: Line 8: THREE THREE THREE
9번째 줄 전송...
9번째 줄 결과 수신: Line 9: FOUR FOUR FOUR FOUR
10번째 줄 전송...
10번째 줄 결과 수신: Line 10: FIVE FIVE FIVE FIVE FIVE

=== 처리 통계 ===
 처리 모드: upper
 처리한 줄 수: 10줄
 소요 시간: 0.00초


```

 

### 클라이언트: lower

```

./file_processor_clnt test.txt lower

  .

  . <이 부분은 실제 출력 결과로 대체>

  .

```

 

### 클라이언트: reverse

```

./file_processor_clnt test.txt reverse

  .

  . <이 부분은 실제 출력 결과로 대체>

  .

```

 

### 서버

```

  1번째 줄 처리 중...

  2번째 줄 처리 중...

```
