# 리눅스 명령어 구현
파일명 작명 패턴 : my"리눅스 명령어".c
## mynl.c
<img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/3b512281-e786-4e26-a949-9584589f4512.png" width="400" height="100"/>

### option
+ w : 행 번호의 너비를 지정할 수 있습니다. 기본값 = 6
 
  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/eafda3d8-6db3-4c4b-ac97-46a3ce805f5f.png" width="400" height="100"/>
  
+ s : 행 번호와 텍스트 사이의 구분 기호를 지정할 수 있습니다. 기본값 = 탭(\t)

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/138cc451-96b5-436b-a599-2876c64971d2.png" width="400" height="100"/>
  
+ v : 시작하는 행 번호를 지정합니다. 기본값 = 1

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/df4c9bd4-ba42-4419-ac20-0151b927b102.png" width="400" height="100"/>

+ i : 행 번호의 증가 값을 지정합니다. 기본값 = 1

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/802708d3-7a68-4001-ad0a-81741ab8da73.png" width="400" height="100"/>
  
+ w, s, v, i : ./mynl -w 10 -s ".n"  -v 10 -i 5 test.txt

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/fa3592d8-8368-4857-b823-744eefefc4ba.png" width="400" height="100"/>
  
## myhead.c
+ w
