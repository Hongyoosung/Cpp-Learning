# 객체의 동적 생성 및 반환

일반 변수와 배열을 동적으로 다루었듯, 객체 또한 동적으로 생성 및 반환이 가능하다. 
```c+
(클래스이름) *(포인터변수) = new (클래스이름); // 기본 생성자 호출
(클래스이름) *(포인터변수) = new (클래스이름)((생성자 매개변수)); // 매개변수가 있는 생성자 호출
```

new가 자료형의 크기에 맞는 저장공간을 할당받듯, 클래스 크기 만큼의 메모리를 할당 받는다. 동적으로 생성된 객체 또한
객체이므로 클래스 생성자의 영향을 받으며, 소멸자 역시 동적 객체가 delete에 의해 해지될 때, 반환 직전에 실행된다.
다음은 객체의 동적 생성 및 반환을 응용한 예이다.

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
	cout << "기본 생성자 실행 age : " << age << endl;
}
Man::Man(int age) {
	cout << "생성자 2 실행 age : " << age << endl;
	this->age = age;
}
Man::~Man() {
	cout << "소멸자 실행 age : " << age << endl;
}

int main(int argc, const char* argv[]) {

	Man* p, * q;

	p = new Man;
	q = new Man(23);

	cout << p->getAge() << endl << q->getAge() << endl;

	delete p;
	delete q;

	return 0;
}
```
실행 결과
```c++
기본 생성자 실행 age : 26
생성자 2 실행 age : 23
26
23
소멸자 실행 age : 26
소멸자 실행 age : 23
```

+ ## 객체 배열의 동적 생성 및 반환

마찬가지로 동적 배열 생성에서 자료형만 클래스로 바꿔준다.

```c++
(클래스이름) *(포인터변수) = new (클래스이름) [배열 크기];
```

동적 객체 배열 또한, 매개변수를 지정할 수 없으며 초기화 시 다음과 같은 방법을 사용해야 한다.
```c++
Man *p = new Man[3] { Man(1), Man(2), Man(3) }; //3개의 객체를 각 1, 2, 3으로 초기화

deete [] p; // 저장공간 반환
```

동적 객체와 같이 동적 객체 배열 또한, 메모리가 해지되기 직전에 배열의 각 요소 객체의 소멸자를 실행한다.
다음은 동적 객체 배열을 할당받고 해지하는 과정이다.

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
	cout << "기본 생성자 실행 age : " << age << endl;
}
Man::Man(int age) {
	cout << "생성자 2 실행 age : " << age << endl;
	this->age = age;
}
Man::~Man() {
	cout << "소멸자 실행 age : " << age << endl;
}

int main(int argc, const char* argv[]) {

	Man* p = new Man[3]{ Man(20), Man(30), Man(40) }; // 객체 배열 할당, 생성자 실행

	for (int i = 0; i < 3; i++) {
		cout << p[i].getAge() << endl;
	}

	Man* q = p; // 객체 포인터 q에 배열 p의 주소를 저장

	for (int i = 0; i < 3; i++) {
		cout << q->getAge() << endl;
		q++;
	}

	delete [] p; // 객체 배열 반환, 소멸자 실행

	return 0;
}
```
실행 결과
```c++
생성자 2 실행 age : 20
생성자 2 실행 age : 30
생성자 2 실행 age : 40
20
30
40
20
30
40
소멸자 실행 age : 40
소멸자 실행 age : 30
소멸자 실행 age : 20
```













