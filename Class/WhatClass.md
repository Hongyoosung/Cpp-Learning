# 클래스란

객체지향언어인 C++는 데이터를 객체화할 수 있다. 객체화란 특정 데이터를 하나의 객체로 간주해
고유의 행동과 속성을 부여하여 데이터 중심적인 프로그래밍을 가능토록 하는 것이다. 객체화된 데이터는 캡슐화되어 외부로부터의 접근을 차단하여 의도치 않은 변조 등을 막을 수
있다.

객체는 클래스를 통해 정의되며 클래스 내부에 멤버 변수와 멤버 함수로 존재하게 된다. 멤버란 클래스 내부의 데이터들을 의미하며 멤버 변수는 해당 클래스에 사용되는 변수, 멤버 함수는 
해당 클래스에 사용되는 함수를 뜻한다. 

클래스를 통해 프로그램의 각 기능들을 사용 용도에 따라 구분하여 유지보수가 용이하고 다른 기능들에게 영향을 끼치지 않아 원활한 프로그래밍이 가능하다. 예를 들어 TV의 기능을 클래스로
구현해보자. 이 때, 멤버 변수는 bool형의 전원 스위치, 채널 번호, 볼륨 크기가 될 수 있으며, 멤버 함수로 전원 켜기, 채널 변경, 볼륨 조절 등이 될 수 있다. 만일 TV에 문제가 생겼을 경우, 
TV의 문제를 해결할 때, 냉장고나 컴퓨터는 전혀 영향을 받지 않아 TV에만 집중할 수 있다.

## 클래스의 구현

```c++
class TV {                  //명령어 class를 통해 TV 클래스 생성
	bool power;               //멤버 변수 power, channel, volume 선언, 일반 변수 선언과 같이 초기화 또한 가능하다.
	int channel;
	int volume;
public :
	void powerOn() {};        //멤버 함수
	void powerOff() {};
	void channelChange() {};
	void volumeChange() {};
};
```

위 TV의 예를 코드로 구현한 것. class 명령어를 통해 클래스를 생성할 수 있다. 클래스 생성 시 접근 지정자를 설정하여 해당 멤버가 외부로부터 접근이 가능한지, 불가능한지를 설정할 수 있다.
클래스는 기본적으로 모든 멤버를 private로 설정하여 외부 접근을 차단한다. 접근을 허용하고 싶을 경우, public : 을 작성해 해당 문장 밑의 멤버들을 외부 접근이 가능하도록 한다. 접근이
허용된 멤버들은 다른 클래스에서도 활용이 가능하다. 다음은 클래스를 실제로 응용하는 예이다.

```c++
#include <iostream>
using namespace std;;

class Student {
	string name;
	int age;
public:
	void setName(string name);   // 매개 변수를 문자열 멤버 변수 name에 저장
	string getName();            // name을 리턴
	void setAge(int age);        // 매개 변수를 정수형 멤버 변수 age에 저장
	int getAge();                // age를 리턴
};
void Student::setName(string name) {
	this->name = name;
}
string Student::getName() { 
	return name;
}
void Student::setAge(int age) {
	this->age = age;
}
int Student::getAge() {
	return age;
}

int main(int argc, const char* argv[]) {

	Student Jinho;                     //객체 생성
	Jinho.setAge(26);                  // 멤버 함수 호출, 26 전달 -> 객체 Jinho의 age에 26을 저장
	Jinho.setName("Kim-Jin-Ho");       // 객체 Jinho의 name에 문자열 저장
	cout << Jinho.getName() << "의 나이 : " << Jinho.getAge() << endl; // 각 변수를 리턴하는 함수를 출력

	Student Dohyeon;                   //객체 생성 2, 하나의 클래스에 다수의 객체를 생성할 수 있다.
	Dohyeon.setAge(23);
	Dohyeon.setName("Kim-Do-Hyeon");
	cout << Dohyeon.getName() << "의 나이 : " << Dohyeon.getAge() << endl;


	return 0;
}
  ```
  
실행 결과
```c++
Kim-Jin-Ho의 나이 : 26
Kim-Do-Hyeon의 나이 : 23
```
위는 클래스를 생성하고 멤버 함수를 구현 후 메인 함수에서 해당 클래스의 객체를 생성하고 활용하는 예이다. 클래스 멤버 함수의 구현은 클래스 외부에서 이루어지므로 함수 이름 앞에 클래스의 이름과 범위 지정 연산자 :: 을 사용하여 해당 함수가 어느 클래스에 속하는지 작성한다. 단, 함수의 기능 코드가 그렇게 길지 않은 경우 선언과 함께 몸체의 작성이 가능하다. 멤버 변수와 멤버 함수는 일반 변수, 함수와 같이 초기화, 매개변수 지정 등이 가능하다.

  클래스의 멤버 함수를 모두 구현한 후 메인 함수에서 클래스를 사용하기 위해 객체를 생성한다. 객체의 생성은 변수의 선언과 같이 자료형 부분에 클래스의 이름을 작성하고, 객체의 이름을 작성하여 객체를 생성한다. 생성된 객체는 클래스의 각 멤버에 대한 저장 공간을 가지고 있으며 해당 객체의 멤버에 접근하기 위해서는 객체 이름 뒤에 . 을 붙이고 원하는 멤버를 작성한다. 일반적인 경우, 객체지향의 캡슐화를 위해 클래스의 멤버 변수는 대부분 private 접근 지정자를 선호한다. 따라서 메인 함수에서 직접적으로 사용할 수 없으므로 해당 멤버 변수의 값을 반환하는 멤버 함수를 작성해 멤버 변수에 간접적으로 접근한다.

  이로 미루어보아, 클래스는 사용자가 임의로 만든 하나의 새로운 자료형이라고 볼 수 있고 해당 자료형을 통해 생성한 변수를 객체라고 한다.







