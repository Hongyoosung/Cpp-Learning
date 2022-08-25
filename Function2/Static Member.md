# 정적(static) 멤버


클래스를 구현할 때 선언된 멤버들은 각 생성된 객체마다 별도로 저장되고 사용되며, 객체와 함께 생성되고 소멸한다. 이러한 멤버를 비정적(non-static) 멤버로 **인스턴스 멤버** 라고
불린다. 정적 멤버란 동일한 클래스의 모든 객체가 같이 공유하고 사용할 수 있는 멤버를 말하며, **클래스 멤버**라고도 불린다. 클래스 멤버는 클래스 밖에 있는 별도의 저장 공간을 사용하며, 
따라서 객체가 소멸해도 사라지지 않는다. 

+ ## 생명 주기와 사용 범위

변수나 함수 같이 모든 저장 공간은 사용할 수 있는 범위가 정해져 있다. 예를 들어 함수는 호출문에서 저장 공간이 생성되었다가, 기능을 모두 실행 후 다시 소멸되고, 변수는
선언된 범위를 벗어날 시 소멸된다. 이러한 범위는 { }로 지정되며, { }안에서 선언된 변수는 그 { }안에서만 사용이 가능하고
{ }를 벗어날 시 저장 공간이 소멸된다. 이것을 **생명 주기**와 **사용 범위**라고 한다. 

저장 공간의 범위는 크게 **지역(local) 범위**와 **전역(global) 범위**로 이루어져 있고, 해당되는 범위에 생성된 변수를 각 지역 변수, 전역 변수라고 한다.
지역 범위는 { }로 정해지며 지역 범위 안에 또 다른 지역 범위가 존재할 수 있다. 전역 범위는 모든 { }를 벗어난 최외부의 공간이며, 이곳에서 선언된 저장 공간은
프로그램이 실행되는 순간 생성되고 끝날 때 까지 사라지지 않는다.


클래스의 인스턴스 멤버는 객체가 선언된 범위를 벗어날 경우 객체와 함께 소멸되지만, 클래스 멤버는 다른 객체가 여전히 사용할 수 있으므로, 특정한 생명 주기가 주어지면 안된다.
따라서 클래스 멤버의 선언은 전역(global) 공간에서 이루어진다.

+ ## static 멤버의 선언과 활용

```c++
class Man {
	int money;
public:
	Man() { money = 500; }
	void setMoney(int money) { this->money = money; }
	int getMoney() { return money; }

	static int gold;             // static 멤버 구현
	static int useGold(int g) {
		gold -= g;
		return 5 * g;
	}
};

// static 변수는 전역 공간에 생성
int Man::gold = 500;

int main(int argc, const char* argv[]) {

  cout << Man::gold << endl;   // static 멤버 gold 출력
	Man Jaehak;
	Man Donghun;

	
	cout << "Jaehak의 : gold : " << Jaehak.gold << endl;
	cout << "Jaehak의 : money : " << Jaehak.getMoney() << endl;
	cout << "Donghun의 gold : " << Donghun.gold << endl;
	cout << "Donghun의 money: " << Donghun.getMoney() << endl << endl;

	// gold를 사용한 만큼 차감하고 money를 획득
	Donghun.setMoney(Donghun.getMoney() + Donghun.useGold(100)); // -> 클래스 멤버는 Man::useGold()의 형태처럼 클래스 이름으로 사용 가능

	cout << "Jaehak의 : gold : " << Jaehak.gold << endl;
	cout << "Jaehak의 : money : " << Jaehak.getMoney() << endl;
	cout << "Donghun의 gold : " << Donghun.gold << endl;
	cout << "Donghun의 money: " << Donghun.getMoney();

	return 0;
}
```
실행 결과
```c++
Jaehak의 : gold : 500
Jaehak의 : money : 500
Donghun의 gold : 500
Donghun의 money: 500

Jaehak의 : gold : 400
Jaehak의 : money : 500
Donghun의 gold : 400
Donghun의 money: 1000
```
위의 예시처럼 static 멤버는 동일 클래스의 모든 객체가 공유한다. static 멤버들은 객체 생성 이전부터 존재하고 있으므로, 아무 객체 없이도 사용할 수 있다.
또한, 그 특성상 static 멤버는 동일 클래스의 같은 static인 멤버에만 접근할 수 있고, this 포인터를 사용할 수 없다. 




