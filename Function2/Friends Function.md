# 프렌드 함수

프렌드 명령어는 클래스의 외부 함수가 해당 클래스의 멤버에 접근할 수 있도록 해준다. 여러 클래스에서 한 함수를 프렌드로 선언해 사용할 수도 있고 다른 클래스의 
멤버 함수도 프렌드 명령어를 사용해 사용할 수 있다. 따라서 외부 함수에 클래스 접근 권한을 부여할 수 있다. 프렌드 명령어는 오직 함수에만 사용할 수 있고 프렌드 명령어로
선언된 함수를 프렌드 함수라고 한다. 

+ ## 프렌드 함수의 구현

다음은 프렌드 명령어르 통해 클래스에서 외부 함수를 할용하는 예이다.


```c++
class Man {
	int money;
public:
	Man(int money) { this->money = money; }
	friend bool rich(Man a, Man b);         // 함수 rich를 Man 클래스의 프렌드로 선언
};

bool rich(Man a, Man b) {                 // 외부 함수 rich, Man의 private 멤버에 접근 가능
	if (a.money > b.money) return true;     // a의 money가 b보다 많을 경우 1을 반환
	else return false;                      // 아닐 경우 0을 반환
}

int main(int argc, const char* argv[]) {

	Man Jinho(100);
	Man Donghun(200);

	if (rich(Jinho, Donghun)) cout << "rich : Jinho" << endl; // Jinho가 더 money가 많은 경우
	else cout << "rich : Donghun" << endl;                   // Donghun이 더 money가 많은 경우

	return 0;
}
```
실행 결과
```c++
rich : Donghun
```

해당 결과를 통해 프렌드 명령어로 외부 함수에서 클래스의 private 멤버까지 접근이 가능함을 알 수 있다.


+ ## 다른 클래스의 멤버 함수를 프렌드 함수로 선언

마찬가지로 다른 클래스의 멤버 함수에도 프렌드 명령어를 통해 클래스 멤버 접근이 가능하다. 다음은 그 예시이다.

```c++
class Man; // MantoMan 클래스에서 Man의 객체를 먼저 활용하므로 Man을 선언해 미리 알려줌

class MantoMan {
public:
	bool fight(Man a, Man b);
};

class Man {
	int power;
public:
	Man(int power) { this->power = power; }
	int getPower() { return power; }
	friend bool MantoMan::fight(Man a, Man b);
};

bool MantoMan::fight(Man a, Man b) {
	if (a.power > b.power) return true;
	else return false;
}


int main(int argc, const char* argv[]) {

	Man Donghun(50);
	Man Jinho(1000);
	MantoMan a;

	if (a.fight(Donghun, Jinho) == 1) cout << "Donghun Win" << endl;
	else cout << "Jinho Win" << endl;

	return 0;
}
```
실행 결과
```c++
jinho Win
```

프렌드 선언된 멤버는 자신의 클래스와 프렌드된 클래스의 멤버를 모두 사용할 수 있다는 점이 있다. 주의할 점으로는 어떤 클래스의 멤버에서 다른 클래스의 멤버를
활용하는 문장을 작성할 때, 활용되는 클래스를 활용할 클래스보다 앞에 선언되어야 한다는 것이다. 따라서 위의 맨 첫 문장에 class Man을 작성한 것이다.
이는 함수의 원형 선언과 같은 원리이다.


+ ## 다른 클래스 전체를 프렌드로 선언

다른 클래스의 모든 멤버 함수를 프렌드로 선언할 수 있다. 다음은 그 예이다.
```c++
class Man;

class MantoMan {
public:
	bool fight(Man a, Man b);
	void training(Man& a, Man& b);
};

class Man {
	int power;
public:
	Man(int power) { this->power = power; }
	int getPower() { return power; }
	void setPower(int power) { this->power = power; }
	friend MantoMan; // MantoMan 클래스의 모든 멤버 함수를 프렌드 선언
};

bool MantoMan::fight(Man a, Man b) {
	if (a.power > b.power) return true;
	else return false;
}

void MantoMan::training(Man& a, Man& b) {
	a.setPower(1000);
	b.setPower(1010);
}


int main(int argc, const char* argv[]) {

	Man Jinho(1000);
	Man Donghun(100);
	MantoMan vs;

	if (vs.fight(Jinho, Donghun) == 1) cout << "Jinho Win" << endl;
	else cout << "Donghun Win" << endl;

	vs.training(Jinho, Donghun);
	cout << endl << "Re Match" << endl << endl;

	if (vs.fight(Jinho, Donghun) == 1) cout << "Jinho Win" << endl;
	else cout << "Donghun Win" << endl;


	return 0;
}
```
실행 결과
```c++
Jinho Win

Re Match

Donghun Win
```




















