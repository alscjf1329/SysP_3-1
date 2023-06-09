<<<<<<< HEAD
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm* time_info;
    char time_string[50];

    // 현재 시간 정보를 가져옴
    time(&current_time);
    time_info = localtime(&current_time);

    // 형식화된 시간 문자열로 변환
    strftime(time_string, sizeof(time_string), "%c", time_info);

    // 출력
    printf("%s\n", time_string);

    return 0;
}
=======
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm* time_info;
    char time_buffer[80];

    // 현재 시간 가져오기
    current_time = time(NULL);

    // 지역 시간으로 변환
    time_info = localtime(&current_time);

    // 형식화된 시간 문자열 생성
    strftime(time_buffer, sizeof(time_buffer), "%a %b %e %H:%M:%S KST %Y", time_info);

    // 시간 출력
    printf("%s\n", time_buffer);

    return 0;
}
>>>>>>> 34e2fa90470725649cb1da6c75524f1676c5e646
