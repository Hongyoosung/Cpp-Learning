# 객체 포인터

C++에서는 객체에 대한 멤버에 접근하기 위한 방법으로 포인터 변수가 있다. 객체에 대한 포인터 변수를 선언하고 원하는 객체의 주소를 저장하여 해당 객체의 멤버에 접근할 수 있다.
```c++
Man *p;      // 클래스 Man으로 생성된 객체 포인터
p = &jinho; // 주소연산자를 사용하여 p에 객체 jinho의 주소를 저장
d = p->getAge();  // 객체 포인터를 통해 jinho의 멤버 함수 getAge()에 접근하여 해당 값을 d에 저장
```
객체 포인터는 객체와 마찬가지로 클래스를 명시하고 선언된다. 생성된 객체 포인터는 명시된 클래스로 생성된 다른 객체의 멤버 주소를 저장할 수 있다. 다음은 일반적인 객체를 통한 멤버 
접근의 예와 객체 포인터로 멤버에 접근한 예를 비교한 것이다.
```c++
d = jinho.getAge(); // 객체 뒤에 . 을 작성해 멤버 함수 접근
d = p->getAge(); //객체 jinho의 주소를 가진 객체 포인터를 통해 jinho의 getAge()에 접근
```
두 문장에서 d 에는 같은 값이 저장된다. 차이점으로는 포인터를 통해 멤버에 접근할 때는 ->를 사용한다는 것이다. 위의 문장은 다음과 같이 작성할 수도 있다.
```c++
d = (*p).getAge(); //역참조 연산자 *을 사용하여 p의 주소가 가리키는 저장장소인 jinho로 치환된다.
```

+ ## 객체 포인터의 응용
```c++

#include <iostream>
using namespace std;

class Man {
	int age;
public:
	Man() { age = 26; }
	Man(int age) { this->age = age; }
	int getAge();
};

int Man::getAge() {
	return age;
}

int main(int argc, const char* argv[]) {

	Man jinho;
	Man dohyeon(23);

  // 객체 이름을 통한 멤버 접근
	cout << jinho.getAge() << endl;
  cout << dohyeon.getAge() << endl;
  
	Man* p;       // 객체 포인터 선언
	p = &dohyeon;

  // 객체 포인터로 멤버 접근
	cout << p->getAge() << endl;
	cout << (*p).getAge() << endl;

	p = &jinho;

	cout << p->getAge() << endl;
	cout << (*p).getAge() << endl;

	return 0;
}
```
실행 결과
```c++
26
23
23
23
26
26
```
해당 결과를 통해 객체 포인터를 활용하면 이름을 직접 명시하지 않아도 된다는 점을 알 수 있다.
