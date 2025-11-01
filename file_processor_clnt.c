#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAXLINE 256

int main(int argc, char *argv[]) {
    int fd1, fd2;
    char inmsg[MAXLINE];
    char line_buf[MAXLINE];
    FILE *fp;
    int line_count = 0;
    struct timespec start, end;


    if (argc != 3) {
        fprintf(stderr, "사용법: %s <input_file> <mode>\n", argv[0]);
        exit(1);
    }
    char *input_file = argv[1];
    char *mode = argv[2];


    // fd1 : 서버 -> 클라이언트 (O_RDONLY)
    // fd2 : 클라이언트 -> 서버 (O_WRONLY)
    printf("클라이언트: 서버에 연결 시도 중...\n");
    fd1 = open("./chatfifo1", O_RDONLY);
    fd2 = open("./chatfifo2", O_WRONLY);

    if (fd1 == -1 || fd2 == -1) {
        perror("open");
        exit(1);
    }
    printf("클라이언트: 서버 연결됨.\n");


    fp = fopen(input_file, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    clock_gettime(CLOCK_MONOTONIC, &start);


    write(fd2, mode, strlen(mode) + 1); //써도 서버에서 읽으면 어차피 저장x(서버->클라이언트도 마찬가지)


    while (fgets(line_buf, MAXLINE, fp) != NULL) {
        line_count++;
        line_buf[strcspn(line_buf, "\n")] = '\0';

        printf("%d번째 줄 전송...\n", line_count);

        write(fd2, line_buf, strlen(line_buf) + 1);


        if (read(fd1, inmsg, MAXLINE) > 0) {
            printf("%d번째 줄 결과 수신: Line %d: %s\n", line_count, line_count, inmsg);
        }
    }


    write(fd2, "END", strlen("END") + 1);


    fclose(fp);
    close(fd1);
    close(fd2);


    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("\n=== 처리 통계 ===\n");
    printf(" 처리 모드: %s\n", mode);
    printf(" 처리한 줄 수: %d줄\n", line_count);
    printf(" 소요 시간: %.2f초\n", elapsed_time);

    return 0;
}