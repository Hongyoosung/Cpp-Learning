# 복사 생성자


프로그래밍에서 복사는 **얕은 복사**와 **깊은 복사**로 이루어져 있다. 얕은 복사란 한 대상을 복사할 때,
전체를 복사하지 않고 일부만을 복사하는 것이다. 단, 이 때 복사된 개체는 원본 개체의 복사되지 않은 부분을
자신의 소유로 인식해 충돌이 발생한다. 깊은 복사는 원본의 전체를 복사하여 충돌이 발생하지 않는다.

이에 대한 예시로, 한 클래스에 멤버 변수로 포인터 변수가 있다고 가정해보자. 이 클래스에 얕은 복사를 실행하여
개체를 복사했다. 하지만, 원본과 사본의 포인터 변수가 같은 저장 공간을 가리켜 충돌이 발생하게 된다.

반면, 깊은 복사를 하면 포인터 변수가 가리키는 저장 공간도 복사되기 때문에 완전한 복사가 이루어진다.
얕은 복사의 경우, 원본과 사본이 같은 저장 공간을 사용하기 때문에 참조 변수처럼 서로에게 영향을 줄 수 있다는
점을 유의해야 한다. 해당 문제는 클래스에 포인터 변수를 사용할 때만 발생한다.

여기서 말하는 복사는 대입 연산자 '='를 통한 복사가 아니라 '복사 생성'이라는 별도의 개념이다.


+ ## 복사 생성자 선언

복사 생성은 객체가 생성될 때 원본 객체를 복사하여 생성된다. 다음은 이러한 복사 생성 시에만 실행되는
복사 생성자를 선언한 예이다.

```c++
class A {
  A(const A& b); // 복사 생성자 선언
};

A::A(const A& b) { // 복사 생성자 구현

};
```

  + ### 복사 생성자 선언의 특징

    + 매개 변수를 한 개만 가진다.
    + 자신의 클래스에 대한 참조로 선언된다.
    + 클래스마다 한 개만 선언할 수 있다.


+ ## 얇은 복사 생성자 구현

다음은 복사 생성자를 통해 객체를 복사하는 예이다.

```c++
class Man {
	int age;
public:
	Man(const Man& a); // 복사 생성자 선언
	Man() { age = 26; }
	Man(int age) { this->age = age; }
	int getAge() { return age; }
};

Man::Man(const Man& a) {   // 복사 생성자 구현
	this->age = a.age;
	cout << "복사 생성자 실행 age : " << age << endl;
}
int main(int argc, const char* argv[]) {

	Man Dohyeon(20);
	Man Jinho(Dohyeon); // 객체 인자에 객체를 전달해 복사 생성자 호출

	cout << "원본의 나이 : " << Dohyeon.getAge() << endl;
	cout << "사본의 나이 : " << Jinho.getAge() << endl;

	return 0;
}
```
실행 결과
```c++
복사 생성자 실행 age : 20
원본의 나이 : 20
사본의 나이 : 20
```
사실 위 예시에서 복사 생성자를 선언하지 않아도 메인 함수에서의 객체 복사는 정상적으로 이루어진다.
그 이유는 클래스에 복사 생성자가 없을 시, 컴파일러가 자동으로 기본 복사 생성자를 삽입하기 때문이다.
위 예시에서 구현된 복사 생성자가 기본 복사 생성자이다.


+ ## 깊은 복사 생성자 작성

깊은 복사 생성자를 사용하면, 객체 복사 시 포인터 변수가 존재해도 문제를 일으키지 않는다.
다음은 그 예시이다.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Man {
	int age;
	char* name;
public:
	Man(int age, const char* name);
	Man(const Man& man); // 복사 생성자 선언
	~Man();              
	void changeName(const char* name); // 이름이 저장된 문자열 변경
	void show() { cout << name << " 나이 : " << age << endl; } // 이름과 나이를 출력
};

Man::Man(int age, const char* name) {
	this->age = age;
	int len = strlen(name);
	this->name = new char[len + 1]; // 동적 배열 생성
	strcpy(this->name, name);       // 문자열 복사
}
Man::Man(const Man& man) {   // 복사 생성자 구현
	this->age = man.age;
	int len = strlen(man.name);
	this->name = new char[len + 1];
	strcpy(this->name, man.name);
	cout << "복사 생성자 실행, 원본 이름 : " << this->name << endl;
}
Man::~Man() {
	if (name) delete[] name; // name에 동적 할당 배열이 있을 시 해지
}

void Man::changeName(const char* name) {
	if (strlen(name) > strlen(this->name)) return; // 기존 이름보다 긴 이름 저장 불가
	strcpy(this->name, name);
}


int main(int argc, const char* argv[]) {

	Man student(20, "Daehong");
	Man teacher(student);         // student 객체를 복사 생성

	cout << "두 객체의 이름을 출력" << endl;
	student.show();
	teacher.show();

	teacher.changeName("Jinho"); // teacher의 이름을 변경

	cout << "이름 변경 후 출력" << endl;
	student.show();
	teacher.show();

	return 0;
}
```
실행 결과
```c++
복사 생성자 실행, 원본 이름 : Daehong
두 객체의 이름을 출력
Daehong 나이 : 20
Daehong 나이 : 20
이름 변경 후 출력
Daehong 나이 : 20
Jinho 나이 : 20
```

이처럼 깊은 복사 생성자는 복사 생성자 구현부에 직접 저장공간을 다시 할당받는 식으로 구현한다. 해당 코드에서 복사 생성자를 작성하지 않고 기본 복사 생성자를
이용할 경우, 프로그램이 비정상적으로 종료된다.

그 이유는 두 객체의 포인터 변수가 같은 저장 공간을 가리키기 때문이며, 객체 소멸 시 먼저 소멸하는 객체가 저장 공간을 반환하고 소멸 후, 다음 객체가 소멸할 때 저장 공간을
반환해야 하지만, 이미 반환되고 없으므로 프로그램 에러를 일으킨다.

이처럼 복사 생성자는 객체가 복사될 때 실행되며 다음의 상황에서 복사 생성자가 실행된다.

+ 값에 의한 호출로 객체가 전달될 때, 생성자가 실행되지 않는 대신 복사 생성자가 실행된다.
+ 함수가 객체를 반환할 때, 반환되는 객체를 복사하여 호출한 곳으로 전달한다. 이 때, 복사 생성자가 실행된다.
+ 대입 연산자를 활용하여 객체를 기존의 객체로 초기화 시 실행된다. Man a = b -> 객체 a를 객체 b로 초기화 -> 복사 생성자 실행










