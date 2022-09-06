# C++ 표준 템플릿 라이브러리(STL)


**표준 템플릿 라이브러리(STL)** 란 제네릭 프로그래밍으로 손쉬운 C++ 프로그램 구현을 위해 템플릿으로 작성된 많은 제네릭 클래스와 함수 라이브러리이다. 여러 객체 지향 언어에서
제네릭 프로그래밍을 지원하는 만큼 많은 템플릿 라이브러리가 사용되고 있다. STL에는 다음 3가지 종류의 제네릭 클래스와 함수들이 있다.

+ ## 컨테이너(container) - 템플릿 클래스

> 데이터의 저장과 검색을 위해 담아두는 자료 구조를 구현한 클래스. 대표적으로 *리스트(list), 큐(queue), 스택(stack), 맵(map), 셋(set), 벡터(vector)* 등이 있으며, 이들을
> **컨테이너**라고 부른다.


+ ## iterator - 컨테이너 원소에 대한 포인터

> iterator는 **반복자**라고 불리며 컨테이너에 저장된 원소들을 각각 순회 접근하기 위해 만들어진 **컨테이너 원소에 대한 포인터이다.** iterator는 컨테이너의 
> 원소를 읽을 때, 원소를 기록할 때, 둘 다 필요할 때 등 각 용도에 맞는 iterator가 있으며 개발자는 자신이 원하는 상황에 맞는 iterator를 사용하면 된다.

+ ## 알고리즘 - 템플릿 함수

> 컨테이너의 원소에 대한 *복사(copy), 검색(find, search), 삭제(remove), 정렬(sort)* 등의 기능을 구현한 **템플릿 함수**로서 통칭하여 **알고리즘**이라고 부른다. 이들 함수는
> 컨테이너 클래스의 멤버 함수가 아니다.

STL을 사용하여 프로그램을 사용할 때, 보통 세 가지 종류를 함께 사용하기에 각 개념의 숙지가 필요하다.

#

+ ### STL 컨테이너의 종류(클래스 이름 : 설명 : 헤더 파일)

  ![image](https://user-images.githubusercontent.com/101240036/188643494-02642d0a-bf5c-4650-b6a1-6f83975d388c.png)
  
  사진 출처 : https://mayple.tistory.com/entry/CSTL-4%EC%9E%A5-%EC%BB%A8%ED%85%8C%EC%9D%B4%EB%84%88container-%ED%81%B4%EB%9E%98%EC%8A%A4
  
+ ### STL iterator의 종류

  ![image](https://user-images.githubusercontent.com/101240036/188644110-dd5c5da0-03bc-4129-8a1f-2c206895164a.png)
  
  사진 출처 : https://inpages.tistory.com/135#:~:text=%EB%B0%98%EB%B3%B5%EC%9E%90%EC%9D%98%20%EC%A2%85%EB%A5%98%201%20%EC%9E%85%EB%A0%A5%20%EB%B0%98%EB%B3%B5%EC%9E%90%20%28input%20iterator%29%20%3A,%28%2B%2B%29%EC%9D%B4%20%EA%B0%80%EB%8A%A5%ED%95%9C%20%EC%9E%AC%ED%95%A0%EB%8B%B9%EB%90%A0%20%EC%88%98%20%EC%9E%88%EB%8A%94%20%EB%B0%98%EB%B3%B5%EC%9E%90%20%EA%B8%B0%ED%83%80%20%ED%95%AD%EB%AA%A9
  
+ ### STL 알고리즘 함수들

  ![image](https://user-images.githubusercontent.com/101240036/188644983-ae8407ad-a28b-49f6-b6e8-c187b8f2ca68.png)

  사진 출처 : https://codingcoding.tistory.com/960
  
  
  #
  
  STL은 *std 네임스페이스*에 작성되어있기 때문에, STL을 사용하기 위해서는 소스 파일 상단에 *using namespace std;* 코드가 필요하다. 또한 컨테이너 클래스를
  사용하고자 할 때, include 지시어를 통해 해당 클래스를 소스 파일에 포함시켜야 한다. 예를 들어 *vector* 클래스를 사용할려 한다면 소스 파일 상단에 다음과 같이 작성한다.
  ```c++
  #include <vector>
  ```
  알고리즘 함수를 사용하고자 한다면 다음과 같이 작성한다.
  
  ```c++
  #include <algorithm>
  ```
  
  




