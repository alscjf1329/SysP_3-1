# 리눅스 명령어 구현
파일명 작명 패턴 : my"리눅스 명령어".c
## mynl.c
![image](https://github.com/alscjf1329/SysP_3-1/assets/48661310/3b512281-e786-4e26-a949-9584589f4512)

### option
+ w : 행 번호의 너비를 지정할 수 있습니다. 기본값 = 6
  ![image](https://github.com/alscjf1329/SysP_3-1/assets/48661310/eafda3d8-6db3-4c4b-ac97-46a3ce805f5f)
  
+ s : 행 번호와 텍스트 사이의 구분 기호를 지정할 수 있습니다. 기본값 = 탭(\t)
  ![image](https://github.com/alscjf1329/SysP_3-1/assets/48661310/138cc451-96b5-436b-a599-2876c64971d2)
  
+ v : 시작하는 행 번호를 지정합니다. 기본값 = 1
  ![image](https://github.com/alscjf1329/SysP_3-1/assets/48661310/cd3ee6e4-c315-49a8-9872-51bd46b0c84d)

+ i : 행 번호의 증가 값을 지정합니다. 기본값 = 1
  ![image](https://github.com/alscjf1329/SysP_3-1/assets/48661310/ae121042-0912-47dd-a814-34b7aa7e1be4)
  
+w, s, v, i : ./mynl -w 10 -s ".n"  -v 10 -i 5 test.txt
  ![image](https://github.com/alscjf1329/SysP_3-1/assets/48661310/788d6a80-7f0e-43c4-bd83-5f9262f6cb10)
