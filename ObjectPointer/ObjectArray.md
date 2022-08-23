# 객체 배열

클래스를 통해 객체가 요소로 이루어진 배열을 선언할 수 있다. 기존의 배열과 활용 방법은 동일하지만, 각 요소가 클래스의 객체로서 멤버에 접근할 수 있다는 차이점이 있다. 다음은
객체 배열을 생성하고 활용하는 예이다.

```c++
#include <iostream>
using namespace std;

class Man {
	int age;
public:
	Man() { age = 26; }
	Man(int age) { this->age = age; }
	void setAge(int age) { this->age = age; }
	int getAge();
};

int Man::getAge() {
	return age;
}

int main(int argc, const char* argv[]) {

	Man people[3]; // 객체 배열 선언

	// 각 요소의 멤버에 접근하여 요소마다 값을 저장
	people[0].setAge(10);
	people[1].setAge(20);
	people[2].setAge(30);

	// 멤버를 통해 객체 배열에 접근
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " Age : " << people[i].getAge() << endl;
	}

	Man* p; // 객체 포인터 생성
	p = people;

	// 객체 포인터를 통해 객체 배열에 접근
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " Age(pointer) : " << p->getAge() << endl;
		p++; // 배열의 다음 요소로 이동
	}

	return 0;
}
```
실행 결과
```c++
1 Age : 10
2 Age : 20
3 Age : 30
1 Age(pointer) : 10
2 Age(pointer) : 20
3 Age(pointer) : 30
```

객체 포인터를 이용하여 배열에 접근할 때를 보면 p는 처음에 배열의 시작 주소를 가져 첫 번째 인덱스부터 가지는 것을 알 수 있고, 증가연산자를 통해 
p를 증가시켜 다음 인덱스로 넘어간다. 인덱스의 전환은 해당 방법 외에도 몇가지가 존재한다.

```c++
p[0].getAge();
(*p).getAge();
```

배열이 저장된 객체 포인터는 인덱스를 직접 명시할 수 있다. 따라서 인덱스에 변수를 사용하여 처음부터가 아닌 특정 순서의 요소에 접근할 수 있다. 역참조 연산자를 통해
주소를 값으로 변환했을 경우, ->가 . 으로 변했을 뿐, p를 증가시켜 다음 인덱스로 접근하는 원리는 같다. 여기서 알 수 있는 것은 포인터를 통한 주소 접근은 ->, 값을 통한
직접 접근은 . 을 사용하는 것이다.


배열을 통해 생성한 객체는 매개변수가 없으므로 기본 생성자를 따르게 된다. 따라서 매개변수가 있는 생성자를
선언했을 경우, 컴파일러는 기본 생성자를 자동으로 선언하지 않으므로 기본 생성자를 따로 선언해줘야 객체 배열을 생성할 때 컴파일 에러를 일으키지 않는다. 다음은 기본 생성자를
명시하지 않아 객체 배열 생성 시 컴파일 에러를 일으키는 예이다.

```c++
#include <iostream>
using namespace std;

class Man {
	int age;
public:
	Man(int age) { this->age = age; }
	int getAge();
};

int Man::getAge() {
	return age;
}

int main(int argc, const char* argv[]) {

	Man jinho(26);
	Man people[3]; // 기본 생성자가 없으므로 객체 배열 생성 시 컴파일 에러 발생

	return 0;
}
```

다음은 객체 포인터를 활용해 객체 배열을 출력하는 다양한 방법이다.

```c++
#include <iostream>
using namespace std;

class Man {
	int age;
public:
	Man() { age = 26; }
	Man(int age) { this->age = age; }
	int setAge(int age);
	int getAge();
};

void Man::setAge(int age) {
	this->age = age;
}
int Man::getAge() {
	return age;
}

int main(int argc, const char* argv[]) {

  // 객체 배열 초기화, 요소마다 클래스의 이름을 적어주는 것이 특징이다.
	Man people[3] = { Man(10), Man(20), Man(30) }; 

	Man* p = people;
	Man* q = people;

	// 역참조 연산자와 증가연산자를 통해 배열 출력
	for (int i = 0; i < 3; i++) {
		cout << (*p++).getAge() << endl;
	}

	// 객체 포인터에 증가하는 변수를 삽입하여 배열 출력
	for (int i = 0; i < 3; i++) {
		cout << (q + i)->getAge() << endl;
	}

	// 배열의 이름은 시작 주소임을 이용한 출력 방법. p = people
	for (int i = 0; i < 3; i++) {
		cout << (people)->getAge() << endl;
	}

	return 0;
}
```
실행 결과

```c++
10
20
30
10
20
30
10
20
30
```

+ ## 다차원 객체 배열

기존 다차원 배열과 동일하다. 다차원 배열 또한 기본 생성자가 실행되며 다차원 배열의 초기화는 다음과 같이 할 수 있다.

```c++
Man people[2][2]; // 2행 2열의 2차원 객체 배열 생성 

people[0][0].setAge(10);
people[0][1].setAge(20);
people[1][0].setAge(30);
people[1][1].setAge(40);
```
또는
```c++
Man people[2][2] = { { Man(10), Man(20) }, { Man(30), Man(40) } };
```
선언과 같이 초기화하는 경우는 { } 안에 또 다른 { }를 통해 차원을 구분한다.

다음은 2차원 객체 배열을 이중 반복문을 통해 출력하는 예이다. 다차원 배열은 포인터 객체의 사용이 불가하다.

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

	Man people[2][2] = { { Man(10), Man(20) }, { Man(30), Man(40) } };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << i << "줄 " << j << " 번 째 사람의 나이 : " <<
				people[i][j].getAge() << endl;
		}
	}
	
	return 0;
}
```
실행 결과
```c++
0줄 0 번 째 사람의 나이 : 10
0줄 1 번 째 사람의 나이 : 20
1줄 0 번 째 사람의 나이 : 30
1줄 1 번 째 사람의 나이 : 40
```


