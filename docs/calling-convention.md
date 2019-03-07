# Calling convention

## 함수 호출 규약?

함수 호출 규약이라는 것은 함수가 호출될 때 파라미터를 어떻게 전달해 줄것이고 스택프레임을 누가 정리할 것이며 반환값은 어떻게 전달해 줄 것인지를 정해놓은 것이다

## 함수 호출 규약 비교

### __cdecl

C언어에서 사용하는 호출 규약이다

- caller가 스택프레임 정리
- 스택프레임으로 파라미터 전달 (R→L)

### __stdcall

- callee가 스택프레임 정리 (ret)
- 스택프레임으로 파라미터 전달

### __fastcall

- 파라미터를 전달할 때 레지스터를 사용하여 값을 전달하는 방식 (속도 upup, 앞의 두 파라미터만)
- callee가 스택프레임 정리

### 실제로 비교해보자!

fastcall을 무시해버린다;; → 32bit만 취급한다, `-m32` 옵션 주니까 해결 된다

![](../resources/-69ac650c-a1ac-4087-94ce-fd5469f68281untitled)

fastcall은 확실히 register에 담아서 전달하고 있다

![](../resources/-33554c98-b2c7-4618-81e8-241fd543e2ceuntitled)

정리할 때는 레지스터는 제외하고 4만큼만 정리해준다

![](../resources/-cb98a950-f69e-4dda-8104-a4f7852db33euntitled)

stdcall은 스택프레임을 통해서 전달해 주고 있다

![](../resources/-5b14eb2d-d6ba-482e-955e-807f798dcd29untitled)

그리고 12만큼 자체 정리를 해주고 있는 것이 보인다

![](../resources/-862474ab-9e85-474e-a7bd-50f8b5cca03duntitled)

cdecl은 caller가 따로 add esp로 정리해주는 것이 보인다