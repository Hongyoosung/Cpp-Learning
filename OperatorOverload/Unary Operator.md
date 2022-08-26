# 단항 연산자 오버로드


단항 연산자란 피연산자가 하나인 연산자로 전위, 후위의 ++, -- 또는 !, ~ 등이 있다. 

+ ## 전위 ++ 연산자 오버로드 

++연산자 함수에서 객체의 모든 멤버 값을 1 증가시키는 기능을 구현할 때, '+=' 연산자처럼 자기 자신에 대한 참조를 반환하게 한다. 다음은 해당 연산자 함수를 구현한 예이다.

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
	Man& operator++ (); // 참조를 반환하기 위해 기호 '&' 사용, 단순 1을 증가시키므로 매개 변수 없음 
	
};
Man& Man::operator++ () {     // 모든 멤버의 값 1씩 증가
	age++;
	money++;
	return *this;       // 변경된 객체 자기 자신을 반환
}


int main(int argc, const char* argv[]) {

	Man Jinho(26, 100), Dohyeon(23, 150);

	Jinho.show();
	Dohyeon.show();

	++Jinho;          // 전위임을 주의, 후위로 사용할 경우 컴파일 에러가 발생한다.
	++Dohyeon;

	cout << endl << "1년 후.." << endl << endl;

	Jinho.show();
	Dohyeon.show();

	return 0;
}
```
실행 결과
```c++
age : 26
money : 100
age : 23
money : 150

1년 후..

age : 27
money : 101
age : 24
money : 151
```
메인 함수에서 ++ 연산자를 후위로 사용하면 컴파일 에러가 발생한다. 그 이유는 해당 연산자 함수가 멤버의 값을 증가시키고 그 값을 반환하는데, 후위 연산자 특성상
해당 문장에서 변경값이 바로 적용될 수 없기 때문이다. 따라서 변경 이전의 값을 저장해놓고 있어야 하는데, 이러할 저장 공간이 없기 때문에 발생한다고 볼 수 있다.
또한, 하나의 ++ 연산자 함수로는 전위와 후위를 동시에 사용하지 못한다.





+ ## ! 연산자 함수 구현

! 연산자는 해당 값이 0일 때, 1을 반환하고 0이 아니면 0을 반환한다. 해당 기능을 객체에 사용할 수 있도록 함수 형식으로 다음과 같이 사용할 수 있다.
```c++
bool Man::operator! () {
  if(age == 0 && money == 0) return true;
  else return false;
}
```

+ ## 후위 ++ 연산자 오버로드 구현


전위 연산자와의 구분을 위해 매개 변수를 설정한다. 해당 매개 변수는 구분을 위한 용도일 뿐, 사용되지 않는다.

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
	Man& operator++ (int x); // 참조를 반환하기 위해 기호 '&' 사용
	
};
Man& Man::operator++ (int x) {  
	Man c = *this;  // 변경 전 값을 미리 저장, 위의 전위 구현에서처럼 연산자를 후위로 구현할 경우 에러가 발생함을 방지
	age++;
	money++;
	return c;       // 변경 전 객체 자기 자신을 반환
}


int main(int argc, const char* argv[]) {

	Man Jinho(26, 100), Dohyeon(23, 150);

	Jinho.show();
	Dohyeon.show();

	Jinho = Dohyeon++;        // Jinho에 변경 이전 Dohyeon의 값을 저장   
	
	cout << endl << "1년 후.." << endl << endl;

	Jinho.show();             // 기존 Dohyeon의 값 출력
	Dohyeon.show();           // 변경된 Dohyeon의 값 출력

	return 0;
}
```
실행 결과
```c++
age : 26
money : 100
age : 23
money : 150

1년 후..

age : 23
money : 150
age : 24
money : 151
```

여기서 의문점은 연산자 함수의 매개 변수에 값을 전달하지 않았는데도 실행에 문제가 없다는 점이다. 그 이유는 함수의 기능에서 해당 매개 변수를 사용하지 않기 때문이다.
그러면 컴파일러의 전위와 후위 구분은 어떻게 이루어지는가. 전위의 컴파일 에러의 예시처럼, 기존의 값을 저장할 공간이 있다면 후위로, 없다면 전위로 구분한다고 추론할 수 있다.

+ ## 전위와 후위 ++연산자 함수를 같이 사용
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
	Man& operator++ (int x); // 참조를 반환하기 위해 기호 '&' 사용
	Man& operator++ ();
};
Man& Man::operator++ (int x) {  
	Man c = *this;  // 변경 전 값을 미리 저장
	age++;
	money++;
	return c;       // 변경 전 객체 자기 자신을 반환
}
Man& Man::operator++ () {     // 모든 멤버의 값 1씩 증가
	age++;
	money++;
	return *this;       // 변경된 객체 자기 자신을 반환
}

int main(int argc, const char* argv[]) {

	Man Jinho(26, 100), Dohyeon(23, 150);

	Jinho.show();
	Dohyeon.show();

	Jinho = Dohyeon++;        // Jinho에 변경 이전 Dohyeon의 값을 저장   
	++Dohyeon;                // Dohyeon의 값 1 증가
	cout << endl << "1년 후.." << endl << endl;

	Jinho.show();             
	Dohyeon.show();           

	return 0;
}
```
실행 결과
```c++
age : 26
money : 100
age : 23
money : 150

1년 후..

age : 23
money : 150
age : 25
money : 152
```
의도와 맞게 실행됨을 알 수 있다.





 












