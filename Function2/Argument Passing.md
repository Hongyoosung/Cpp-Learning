# 함수의 인자 전달 방식


함수는 호출문으로부터 전달받은 인자를 매개변수를 통하여 기능에 활용한다. 함수는 다음의 세 가지 방식으로
호출문으로부터 인자를 전달받는다.

+ #### **값에 의한 호출(Call by value)**
+ #### **주소에 의한 호출(Call by address)**
+ #### 참조에 의한 호출(Call by reference) (함수 1의 참조 변수 항목)

**값에 의한 호출**은 지금까지 사용했던 일반적인 방법으로, 호출문의 인자에 입력한 실제 값을 함수로 전달하는 것이다.
**주소에 의한 호출**은 호출문의 인자에 값이 아닌 주소를 사용한 것으로, 함수는 전달받은 주소를 통해
해당 주소를 가진 데이터를 활용하게 된다. 함수에 배열을 인자로 전달해야 할 경우, 배열의 이름은 해당 배열의
시작 주소를 의미하므로, 주소에 의한 호출을 통해 전달할 수 있다. 다음은 두 방식에 대한 차이점을 다룬 예이다.


+ **값에 의한 호출**
```c++
void swap(int a, int b) {
	int c;
	c = a;
	a = b;
	b = c;

	cout << "swaped a : " << a << endl;
	cout << "swaped b : " << b << endl;
}
int main(int argc, const char* argv[]) {

	int a = 10, b = 20;

	swap(a, b);

	cout << "Main a : " << a << endl;
	cout << "Main b : " << b << endl;

	return 0;
}
```
실행 결과
```c++
swaped a : 20
swaped b : 10
Main a : 10
Main b : 20
```


+ **주소에 의한 호출**

```c++
#include <iostream>
using namespace std;

void swap(int* a, int* b) {  // (2) a와 b의 주소를 입력 받음
	int c;
	c = *a;    // (3) c에 메인 함수 a와 b에 저장된 값을 복사하여 메인 함수 a와 b의 값을 바꿈
	*a = *b;
	*b = c;

	cout << "swaped a : " << *a << endl;
	cout << "swaped b : " << *b << endl;
}
int main(int argc, const char* argv[]) {

	int a = 10, b = 20;

	swap(&a, &b); // (1) a와 b의 주소를 함수에 전달

	cout << "Main a : " << a << endl;
	cout << "Main b : " << b << endl;

	return 0;
}
```
실행 결과
```c++
swaped a : 20
swaped b : 10
Main a : 20
Main b : 10
```

이처럼 주소에 의한 호출을 사용해 함수가 메인 함수에 선언된 변수의 주소를 전달받아 작업하도록 하여
메인 함수의 변수에 영향을 줄 수 있다. 하지만 함수 외부의 데이터를 실질적으로 변경할 수 있기 때문에
사용에 주의하여야 한다.

참조에 의한 호출은 매개 변수가 새로운 저장공간을 할당받지 않았지만
 주소에 의한 호출은 주소를 전달받기 위한 포인터 변수의 저장공간이 필요하다는 차이점이 있다. 


+ ## 값에 의한 호출을 통해 객체를 전달


객체 또한 사용자 정의 자료형으로 선언된 하나의 변수, 값으로 볼 수 있기 때문에 
함수 전달의 인자로 사용할 수 있다. 다음은 해당 예시이다.

```c++
class Man {
	int age;
public:
	Man() { age = 26; }
	Man(int age) { this->age = age; }
	void setAge(int age) { this->age = age; }
	int getAge() { return age; }
};

void aging(Man a) {            // 객체의 값을 전달 받음
	int Noin = a.getAge();
	a.setAge(Noin + 10);
	cout << a.getAge() << endl;
}



int main(int argc, const char* argv[]) {

	Man Dohyeon(23);
	aging(Dohyeon);        // 객체 전달 시 객체의 이름만 전달


	return 0;
}
```
실행 결과
```c++
33
```

위의 결과를 통해 보면, 객체를 전달받은 함수는 인자 객체와 같은 값의 매개 변수 객체를 생성한다. 따라서
매개 변수 객체 a의 age 값은 Dohyeon과 같은 23이며, a 또한 전달받은 객체의 클래스 기능을 사용할 수 있다.

값에 의한 호출로 함수에 객체를 전달하여 생성된 매개 변수 객체는 생성자가 실행되지 않고 소멸자만 실행된다.
다음은 해당 경우의 예시이다.

```c++
class Man {
	int age;
public:
	Man();
	Man(int age);
	~Man();
	void setAge(int age) { this->age = age; }
	int getAge() { return age; }
};
Man::Man() {
	age = 26;
	cout << "생성자 실행 age : " << age << endl;
}
Man::Man(int age) {
	this->age = age;
	cout << "생성자 실행 age : " << age << endl;
}
Man::~Man() { cout << "소멸자 실행 age : " << age << endl; }

void aging(Man a) {
	int Noin = a.getAge();
	a.setAge(Noin + 10);
	cout << a.getAge() << endl;
}

int main(int argc, const char* argv[]) {

	Man Dohyeon(23);
	aging(Dohyeon);
  cout << Dohyeon.getAge() << endl;

	return 0;
}
```
실행 결과
```c++
생성자 실행 age : 23 // Dohyeon 생성자 실행
33                   // 함수 aging 실행, 매개 변수 객체 생성, 생성자 실행 없음
소멸자 실행 age : 33 // aging 종료 후 매개 변수 객체 소멸, 소멸자 실행
23                   // 물론, 값에 의한 호출이기 때문에 메인 함수의 객체에는 영향이 없다.
소멸자 실행 age : 23 // Dohyeon 소멸자 실행
```

이러한 현상은 의도적인 것으로, 만약 매개 변수 객체 a가 생성될 때, 생성자가 실행된다면 
생성자에서 age의 값을 26으로 다시 초기화하기 때문에 전달한 값이 의미가 없어진다.


+ ## 주소에 의한 호출을 통한 객체 전달

함수에 객체의 주소를 전달하는 방식. 다음은 그 예시이다.

```c++
class Man {
	int age;
public:
	Man();
	Man(int age);
	~Man();
	void setAge(int age) { this->age = age; }
	int getAge() { return age; }
};
Man::Man() {
	age = 26;
	cout << "생성자 실행 age : " << age << endl;
}
Man::Man(int age) {
	this->age = age;
	cout << "생성자 실행 age : " << age << endl;
}
Man::~Man() { cout << "소멸자 실행 age : " << age << endl; }

void aging(Man* a) {
	int Noin = a->getAge();
	a->setAge(Noin + 10);
	cout << a->getAge() << endl;
}

int main(int argc, const char* argv[]) {

	Man Dohyeon(23);

	aging(&Dohyeon);
	cout << Dohyeon.getAge() << endl;

	return 0;
}
```
실행 결과
```c++
생성자 실행 age : 23
33                     // 함수 aging 실행 및 종료, 소멸자가 없다?
33                     // 함수의 결과가 메인 함수에 영향을 끼친다
소멸자 실행 age : 33
```

값에 의한 호출과는 달리 함수가 객체 전체를 복사 생성하지 않는다. aging 함수의 매개 변수는
단순한 포인터 변수이므로 생성자와 소멸자 또한 실행되지 않는다.






