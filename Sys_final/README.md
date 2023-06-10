# 리눅스 명령어 구현
파일명 작명 패턴 : my"리눅스 명령어".c
---
## mynl.c (5개)
+ nl은 "number lines"의 약어
+ 텍스트 파일의 각 행에 번호를 할당하여 출력하는데 사용
+ 이를 통해 파일의 행을 쉽게 추적하고 텍스트의 특정 부분을 참조 가능
<img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/3b512281-e786-4e26-a949-9584589f4512.png" width="400" height="100"/>

### option
+ w : 행 번호의 너비를 지정할 수 있습니다. default = 6
 
  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/eafda3d8-6db3-4c4b-ac97-46a3ce805f5f.png" width="400" height="100"/>
  
+ s : 행 번호와 텍스트 사이의 구분 기호를 지정할 수 있습니다. default = 탭(\t)

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/138cc451-96b5-436b-a599-2876c64971d2.png" width="400" height="100"/>
  
+ v : 시작하는 행 번호를 지정합니다. default = 1

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/df4c9bd4-ba42-4419-ac20-0151b927b102.png" width="400" height="100"/>

+ i : 행 번호의 증가 값을 지정합니다. default = 1

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/802708d3-7a68-4001-ad0a-81741ab8da73.png" width="400" height="100"/>
  
+ w, s, v, i : ./mynl -w 10 -s ".n"  -v 10 -i 5 test.txt

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/fa3592d8-8368-4857-b823-744eefefc4ba.png" width="500" height="50"/>
---
## myhead.c (4개)
+ 텍스트 파일의 앞부분을 출력하는 데 사용
+ 출력할 줄 수 default = 10

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/0f3fd380-17a0-4b73-8b42-887aa6fa063b.png" width="500" height="300"/>
  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/e445b004-0cc6-40a7-83bc-3bfe9a61f3e5.png" width="500" height="300"/>
  
### option
+ n : 출력할 줄의 수를 지정합니다.

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/cb9eaeee-401c-4da8-8bd4-2b5ab7e112dd.png" width="500" height="200"/>
  
+ c : 출력할 바이트 수를 지정합니다. 

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/1ee64d2d-18d8-4e6b-805c-f7c2bf79dfb7.png" width="500" height="50"/>
  
+ q : 파일 이름을 표시하지 않습니다. (파일 2개이상 읽을 시)

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/f639c492-51cd-48a6-8af5-bd6031aff9f8.png" width="500" height="100"/>
---
## mytail.c (4개)
+ 파일의 끝 부분을 출력하는 명령어
+ 로그 파일이나 다른 텍스트 파일의 마지막 몇 줄을 확인하는 데 사용
+ 출력할 줄 수 default = 10

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/3867338b-ea8f-42e1-a108-bc771f392d1d" width="500" height="300"/>
  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/f8fe40c2-9155-4d1c-8990-ae9122e869b8" width="500" height="300"/>

### option  
+ n : 출력할 줄의 수를 지정합니다.

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/9ef12dad-23a8-4d23-8515-f7d0a33a7609" width="500" height="200"/>
  
+ c : 출력할 바이트 수를 지정합니다. 

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/d3c234d9-03d8-45dd-a3e0-6441f577fcd9.png" width="500" height="150"/>
  
+ q : 파일 이름을 표시하지 않습니다. (파일 2개이상 읽을 시)

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/98c55d0a-9894-4396-a87d-07b60e0feb6a.png" width="500" height="250"/>
---
## mycat.c (7개)
+ "concatenate"의 줄임말
+ 파일의 내용을 화면에 출력하거나 여러 파일을 결합하는 데 사용되는 명령어

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/d2597b0a-b11e-421b-8668-34feb715756cd" width="500" height="100"/>
  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/adba529e-bce6-4e05-9d72-1dfde8e60c92" width="500" height="100"/>

### option  
+ n : 각 줄에 번호를 붙여서 출력합니다.

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/ebe65cb0-bb06-4024-b2f2-417f9bbbaa86" width="500" height="100"/>
  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/b281807b-eaa2-4f4d-bbf0-3116fa1a694d" width="500" height="100"/>
  
+ b : -n 옵션과 유사하지만, 빈 줄에는 번호를 붙이지 않습니다. 

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/c95e83c7-636c-4c62-8876-c099e5ba604a" width="500" height="400"/>
  
+ E : 각 줄의 끝에 $ 기호를 추가하여 출력합니다.

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/b27dfcac-b7ee-49a4-af53-9b47f7d9d805" width="500" height="400"/>
  
+ T : 탭 문자를 ^I로 대체하여 출력합니다.

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/5b4b45ba-7c62-4fc5-8e21-63d84a758270" width="500" height="400"/>

+ v : 제어 문자를 가진 줄을 확장하여 출력합니다. 

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/b00909d5-3d2c-4ba7-943e-77ac83ee6765" width="600" height="400"/>
  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/54e4df7e-ec4f-4382-b04f-31e45d29cc53" width="600" height="400"/>

+ s : 연속된 빈 줄을 하나의 빈 줄로 압축하여 출력합니다.

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/1fa832d0-a290-4fd5-b380-1109d67511c2" width="500" height="500"/>
  
---
## myclear.c (1개)
+ 터미널 화면을 지우는 명령어

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/81599425-9086-4a33-a392-b17510b64a5a.png" width="500" height="100"/>
  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/750555ea-47bc-4108-845e-5c6a741f779d.png" width="500" height="100"/>

---
## mybasename.c (1개)
+ 주어진 경로에서 마지막 경로만 추출하는 명령어

  <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/efd2ad4c-42f3-4367-9771-f525234fb602.png" width="500" height="50"/>

---
## myyes.c (1개)
+ 뒤에 들어오는 인자를 계속 출력
+ 인자 default = 'y'

  + `yes SysP` 
    <br/><img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/04ac214a-f5af-472c-8430-2c3668b14f10.png" width="500" height="100"/>
  + `./myyes SysP` 
    <br/><img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/04ac214a-f5af-472c-8430-2c3668b14f10.png" width="500" height="100"/>

---
## mytrue.c (1개)
+ 0을 return해줌
+ echo $? return 값 또는 전 명령어의 성공 여부를 출력 (성공시 0, 오류시 1)

    <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/f0a1baeb-465a-42ee-a07e-6da6e16618ac.png" width="500" height="100"/>

---
## myfalse.c (1개)
+ 1을 return해줌
+ echo $? return 값 또는 전 명령어의 성공 여부를 출력 (성공시 0, 오류시 1)

    <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/ebc19c2d-d859-4f59-8363-b24013af5f0d.png" width="500" height="100"/>

---
## myrev.c (1개)
+ 파일을 받고 파일 내용을 역순으로 출력

    <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/871475c9-12af-4c77-91ee-fd73d171eafc.png" width="500" height="100"/>
    <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/c7322b91-0d25-412e-8c31-f9f9fad9b909.png" width="500" height="100"/>

---
## mydate.c (1개)
+ 현재 시간을 출력

    <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/c88575f4-5385-4970-9e72-f98f8b2c2d95" width="500" height="100"/>
    
---
## myhostname.c (1개)
+ 현재 호스트 이름을 출력

    <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/f0f0faa6-5310-43dc-a325-0a8a4189b5c1" width="500" height="100"/>

---
## myecho.c (1개)
+ 주어진 텍스트나 변수의 값을 출력하는 간단한 방법으로 사용

    <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/f7685510-45a7-4b41-98f4-24528096a5ca" width="500" height="100"/>
    
---
## mypwd.c (1개)
+ 현재 위치 출력

    <img src="https://github.com/alscjf1329/SysP_3-1/assets/48661310/74283a91-1422-41ee-b525-564f63a2622b" width="500" height="100"/>
