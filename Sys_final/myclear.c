#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    write(1, "\33[H\33[J", 6); // 이스케이프 시퀀스: 터미널에 특정 명령을 전달하기 위해 사용되는 제어 문자열
                               // \33 : 이스케이프 문자를 나타내는 ASCII 코드
                               // [H : 커서를 화면 상단 왼쪽으로 이동
                               // \33[J : 화면을 지움
}
