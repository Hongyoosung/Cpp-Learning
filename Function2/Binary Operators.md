##  '+' 연산자 오버로드 구현

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
	Man operator+ (Man op); // + 연산자 함수 선언
	
};
Man Man::operator+ (Man op) {     // + 연산자 함수 구현
	Man we;                       // 새로운 객체 생성
	we.age = this->age + op.age;  // we의 age에 다른 두 객체의 age를 더함
	we.money = this->money + op.money; //this는 왼쪽 피연산자 Jinho를 가리킴, op의 값은 오른쪽 피연산자 Dohyeon이 전달

	return we;
}


int main(int argc, const char* argv[]) {

	Man Jinho(26, 100), Dohyeon(23, 50);
	Man sum;

	sum = Jinho + Dohyeon;        // 객체 간의 연산을 실행하는 연산자 함

	cout << "Jinho의 나이와 돈" << endl;
	Jinho.show();
	cout << endl << "Dohyeon의 나이와 돈" << endl;
	Dohyeon.show();
	cout << endl << "둘을 합친 나이와 돈" << endl;
	sum.show();


	return 0;
}
```
실행 결과
```c++
Jinho의 나이와 돈
age : 26
money : 100

Dohyeon의 나이와 돈
age : 23
money : 50

둘을 합친 나이와 돈
age : 49
money : 150
```
연산자 오버로드에 의해 +는 두 객체의 매개 변수를 더하고 새로운 객체에 저장하는 역할을 수행했다. 연산자 함수 선언에서 이항 연산자의 왼쪽 피연산자가 주체가 되어
this를 통해 왼쪽 피연산자의 멤버에 접근할 수 있으며, 매개 변수로 오른쪽 피연산자를 전달받는 것을 알 수 있다.


## '==' 연산자 오버로드 구현

비교 연산자인 '=='을 연산자 함수를 통해 오버로드를 구현한다. '==' 연산자는 true와 false의 두 가지 결과를 반환하므로 bool 자료형을 사용하는 것이 좋다.
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
	bool operator== (Man op); // +와 달리 클래스 자료형이 아니라 bool 형 사용을 주의
	
};
bool Man::operator== (Man op) {     
	if (age == op.age && money == op.money) return true; //클래스 자료형이 아니므로 this를 사용 안함
	else return false;
}


int main(int argc, const char* argv[]) {

	Man Jaehak(23, 50), Dohyeon(23, 50); // +와 달리 새로운 객체 생성할 필요 없음
      

	cout << "Jaehak의 나이와 돈" << endl;
	Jaehak.show();
	cout << endl << "Dohyeon의 나이와 돈" << endl;
	Dohyeon.show();
	
	if (Jaehak == Dohyeon) cout << "둘의 나이와 돈은 같습니다" << endl; // 연산자 함수 호출
	else cout << " 둘의 나이와 돈은 다릅니다" << endl;

	return 0;
}
```
실행 결과
```c++
Jaehak의 나이와 돈
age : 23
money : 50

Dohyeon의 나이와 돈
age : 23
money : 50
둘의 나이와 돈은 같습니다
```


'+=' 연산자 오버로드 구현


'+=' 연산자 함수의 구현은 피연산자의 합을 다시 피연산자에 대입하는 과정이므로, 클래스 자료형을 따르고 반환값은 자기 자신이 된다.

만약 ' (a += b) += b'의 연산이 있다고 가정할 때, ( )안 연산이 끝나고 a의 복사본을 반환하므로, 뒤의 '+=b'는 a의 원본이 아닌 복사본에 
값을 저장하게 된다. 이러한 문제를 막기 위해 '+='의 연산자 함수는 객체의 참조를 반환하도록 한다.

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
	Man& operator+= (Man op); // += 연산자 함수는 참조를 반환
	
};
Man& Man::operator+= (Man op) {
	age = age + op.age;
	money = money + op.money;
	return *this;  // 객체 자기 자신, Jinho를 반환. this는 포인터의 형태이므로 역참조 연산자 *를 사용해 값으로 치환한다.
}


int main(int argc, const char* argv[]) {

	Man Jinho(26, 100), Dohyeon(23, 50);
      

	cout << "Jinho의 나이와 돈" << endl;
	Jinho.show();
	cout << endl << "Dohyeon의 나이와 돈" << endl;
	Dohyeon.show();
	
	Jinho += Dohyeon;         // += 연산자 함수 호출
	cout << endl << "Jinho가 Dohyeon의 나이와 돈을 흡수했습니다" << endl << endl;
	
	cout << "Jinho의 나이와 돈" << endl;
	Jinho.show();

	return 0;
}
```
실행 결과
```c++
Jinho의 나이와 돈
age : 26
money : 100

Dohyeon의 나이와 돈
age : 23
money : 50

Jinho가 Dohyeon의 나이와 돈을 흡수했습니다

Jinho의 나이와 돈
age : 49
money : 150
```

+ ## 'a + 2' 구현하기

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
	Man operator+ (int op); // 오른쪽 피연산자는 정수이므로 int형 매개 변수
	
};
Man Man::operator+ (int op) {
	Man a;
	a.money = this->money - 100;    // + 연산자 함수이지만 멤버마다 다른 연산을 수행할 수 있다
	a.age = this->age + op;         // a는 자기 자신의 age에 전달받은 op값을 더함
	return a;                       // 객체 반환
}


int main(int argc, const char* argv[]) {

	Man Jinho(26, 100), Dohyeon(23, 50);
	

	cout << "Jinho의 나이와 돈" << endl;
	Jinho.show();
	cout << endl << "Dohyeon의 나이와 돈" << endl;
	Dohyeon.show();
	
	cout << endl << "2년의 시간이 흘렀습니다" << endl << endl;

	Man OldJinho = Jinho + 2;
	Man OldDohyeon = Dohyeon + 2;
	
	cout << "Jinho의 나이와 돈" << endl;
	OldJinho.show();
	cout << endl << "Dohyeon의 나이와 돈" << endl;
	OldDohyeon.show();

	return 0;
}
```
실행 결과
```c++
Jinho의 나이와 돈
age : 26
money : 100

Dohyeon의 나이와 돈
age : 23
money : 50

2년의 시간이 흘렀습니다

Jinho의 나이와 돈
age : 28
money : 0

Dohyeon의 나이와 돈
age : 25
money : -50
```

해당 예시를 통해 알 수 있는 것으로, 연산자 함수의 구현은 사용자의 의도대로이기 때문에, + 연산자 함수라 하더라도 각 멤버마다 원하는 연산을 수행할 수 있다.


























