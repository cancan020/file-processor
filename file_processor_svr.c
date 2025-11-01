
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

#define MAXLINE 256


int count_words(const char *line) {
    int count = 0, in_word = 0;
    while (*line) {
        if (isspace(*line)) {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            count++;
        }
        line++;
    }
    return count;
}
void reverse_string(char *str, char *output) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        output[i] = str[len - 1 - i];
    }
    output[len] = '\0';
}


int main() {
    int fd1, fd2;
    char msg[MAXLINE];
    char result_msg[MAXLINE];
    char mode[20];
    int line_count = 0;


    unlink("./chatfifo1");
    unlink("./chatfifo2");
    if (mkfifo("./chatfifo1", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }
    if (mkfifo("./chatfifo2", 0666) == -1) {
        perror("mkfifo");
        exit(2);
    }

    printf("서버: 클라이언트를 기다리는 중...\n");
	//이제 클라이언트 쪽도 파이포를 열어야 다음 실행 현재는 대기중


    fd1 = open("./chatfifo1", O_WRONLY);
    fd2 = open("./chatfifo2", O_RDONLY);

    if (fd1 == -1 || fd2 == -1) {
        perror("open");
        exit(3);
    }

    printf("서버: 클라이언트 연결됨.\n");


    if (read(fd2, mode, sizeof(mode)) <= 0) {
        perror("read(mode)");
        exit(1);
    }
    printf("서버: 처리 모드 수신 [%s]\n", mode);


    while (read(fd2, msg, MAXLINE) > 0) {
        if (strcmp(msg, "END") == 0) {
            printf("서버: 'END' 메시지 수신. 종료합니다.\n");
            break;
        }

        line_count++;
        printf("%d번째 줄 처리 중...\n", line_count);


        if (strcmp(mode, "count") == 0) {
            int chars = strlen(msg);
            int words = count_words(msg);
            sprintf(result_msg, "%d chars, %d words", chars, words);
        } else if (strcmp(mode, "upper") == 0) {
            for (int i = 0; i <= strlen(msg); i++)
				result_msg[i] = toupper(msg[i]);
        }
		  else if (strcmp(mode, "lower") == 0) {
            for (int i = 0; i <= strlen(msg); i++)
				result_msg[i] = tolower(msg[i]);
        }
		  else if (strcmp(mode, "reverse") == 0) {
            reverse_string(msg, result_msg);
        }


        write(fd1, result_msg, strlen(result_msg) + 1);
    }


    close(fd1);
    close(fd2);
    unlink("./chatfifo1");
    unlink("./chatfifo2");

    return 0;
}