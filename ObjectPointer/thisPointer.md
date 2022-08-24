# this 포인터

this는 객체 자신을 가리키는 포인터로 클래스의 멤버 함수 내에서만 사용된다. 
this의 특징은 다음과 같다.

+ 객체 자신을 가리키는 포인터이다.
+ 객체마다 존재한다.
+ 클래스의 멤버 함수에서만 사용이 가능하다.
+ static 멤버 함수에서는 사용할 수 없다
+ 컴파일러 몰래 멤버 함수에 삽입된 매개 변수



this의 사용
목적은 크게 2가지이며, 첫 번째로 멤버 변수와 멤버 함수의 매개변수 이름이 같을 때,
멤버 변수 앞에 this를 붙여주어 값이 올바르게 전달되도록 한다.

```c++
class Man {
	int age;
public:
	Man() { this->age = 26; } // 굳이 this를 사용하지 않아도 된다.
	Man(int age) { this->age = age; }
	void setAge(int age) { this->age = age; }
};
```
이는 굳이 this를 사용하지 않고도 매개변수 이름만 바꿔주면 되는 문제이지만, 프로그래밍에서 매개변수의 이름은 그 의도가
정확히 파악되어야 하므로 단어가 겹칠 경우, 이름을 바꾸기보단 this를 사용하는 것이 좋은 습관이다.

this의 두 번째 사용 목적은 멤버 함수에서 객체 자신의 주소를 반환할 때이다.
```c++
class Man {
public :
  Sample* f() {
      return this; // 해당 멤버 함수를 호출 시, 객체의 주소를 반환
     }
};
```

+ ## this의 처리

위의 this의 특징에서 '컴파일러 몰래 삽입한 매개변수'라는 문장이 있다. 해당 문장이 무슨 뜻인가에 대해 다루어 본다.
먼저 this의 사용 예를 본다.

```c++
class Man {
	int age;
public:
	void setAge(int age) { this->age = age; }
};
```
해당 예에서 멤버 함수는 this를 통해 매개 변수 age를 멤버 변수 age에 저장한다. 멤버 함수가 실행될 때, this는
멤버 함수에 임의의 매개 변수 this를 하나 더 생성하며, 생성된 매개 변수 this는 객체 자신의 주소를 담고 있는 포인터 변수이다.
따라서 멤버 함수가 호출될 때, 매개 변수 this에 의해 this->age는 함수가 아닌 객체의 멤버 변수로 접근하게 된다.
다음은 해당 설명을 코드로 표현한 것이다.

```c++
class Man {
	int age;
public:
	void setAge(Man* this, int age) { //매개 변수 this 생성
      this->age = age; 
      } 
};
```












