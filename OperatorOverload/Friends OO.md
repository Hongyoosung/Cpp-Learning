# 프렌드를 이용한 연산자 오버로드

연산자 오버로드는 그 범용성으로 여러 곳에서 다양하게 활용될 수 있다. 따라서 한 클래스의 멤버로 보단, 클래스 외부의 전역 함수로 선언한 다음, 사용할 클래스에서
프렌드로 선언해 연산자 함수의 멤버 접근을 가능하게 하는 것이 좋다.


+ ## '+' 연산자 함수 프렌드 구현

먼저 객체의 + 연산을 위한 함수를 클래스 외부에 구현하고, 클래스에서 프렌드로 선언한다.
```c++
class Man {
	int age;
	int money;
public:
	Man(int age = 0, int money = 0) {
		this->age = age;
		this->money = money;
	}
	void show() {
		cout << "age : " << age << endl << "money : " << money << endl;
	}

	friend Man operator+ (Man op1, Man op2);    // 프렌드 선언
};

Man operator+ (Man op1, Man op2) {
	Man a; // 임시 객체를 생성 후 해당 객체의 멤버에 값을 저장
	a.age = op1.age + op2.age;
	a.money = op1.money + op2.money;
	return a;
}

int main(int argc, const char* argv[]) {

	Man Jinho(26, 100), Dohyeon(23, 150), b;
	b = Jinho + Dohyeon;

	Jinho.show();
	Dohyeon.show();
	b.show();

	           

	return 0;
}
```
실행 결과
```c++
age : 26
money : 100
age : 23
money : 150
age : 49
money : 250
```


+ ## '++' 연산자 함수 프렌드 구현

외부 함수로 구현하지 않을 때와의 차이점으로, 연산자 함수에 클래스 객체를 전달받을 수 있는 매개 변수가 생겼다.

```c++
class Man {
	int age;
	int money;
public:
	Man(int age = 0, int money = 0) {
		this->age = age;
		this->money = money;
	}
	void show() {
		cout << "age : " << age << endl << "money : " << money << endl;
	}

	friend Man& operator++ (Man& op);       // 전위 연산자, 참조를 리턴
	friend Man operator++ (Man& op, int x);   // 후위 연산자
};

Man& operator++ (Man& op) {                 // 전위 연산 구현, 객체를 참조로 전달받음
	op.age++;
	op.money++;

	return op;
}
 
Man operator++ (Man& op, int x) {             // 후위 연산 구현
	Man a = op;
	op.age++;
	op.money++;

	return a;
}

int main(int argc, const char* argv[]) {

	Man Jinho(26, 100), Dohyeon(23, 150), b;
	
	Dohyeon = Jinho++;

	Jinho.show();
	Dohyeon.show();

	++Dohyeon;

	Jinho.show();
	Dohyeon.show();

	return 0;
}
```
실행 결과
```c++
age : 27
money : 101
age : 26
money : 100
age : 27
money : 101
age : 27
money : 101
```

+ ## '<<' 연산자를 오버로드로 구현

만약 a << 1 << 2 << 3 이라는 문장이 있을 때, a에 1을 더한 다음 2를 더하고, 다음 3을 더하도록 << 연산자를 오버로드해보자. 알아야 할 것은, 해당 함수가
참조를 리턴하도록 하여 복사본에 값이 전달되지 않도록 해야 한다.

```c++
class Man {
	int age;
	int money;
public:
	Man(int age = 0, int money = 0) {
		this->age = age;
		this->money = money;
	}
	void show() {
		cout << "age : " << age << endl << "money : " << money << endl;
	}

	Man& operator<< (int n);
};

Man& Man::operator<< (int n) {       // 오른쪽 피연산자의 값을 멤버에 더함
	age += n;
	money += n;

	return *this;               // 더한 후 자기 자신을 반환
}
 


int main(int argc, const char* argv[]) {

	Man Jinho(26, 100);
	
	Jinho << 1 << 2 << 3; // 각 멤버에 총 6을 더함

	Jinho.show();

	
	return 0;
}
```
실행 결과
```c++
age : 32
money : 106
```














