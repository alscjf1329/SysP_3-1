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
