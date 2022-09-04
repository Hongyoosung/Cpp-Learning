## 추상 클래스

기본 클래스의 가상 함수는 파생 클래스에서 재활용될 수 있지만, 완전히 새로이 제작된다면 기본 클래스의 가상 함수는 실행되지 않으며 이런 경우 해당 함수에 코드를 작성할
필요가 없다(어차피 파생 클래스에서 작성할 테니깐). 이런 상황에 사용되는 **순수 가상 함수**는 코드가 없고 선언만 있는 가상 함수를 말한다. 순수 가상 함수는
함수의 원형 뒤에 =0; 으로 선언한다.
```c++
class A  { 
public:
  void show() {
    name(); // 순수 가상 함수 호출 가능
  }
	virtual void name() = 0;

};
```
순수 가상 함수는 코드를 가지지 않으므로 몸체 또한 존재하지 않는다.

이러한 순수 가상 함수를 하나라도 가진 클래스를 **추상 클래스**라고 한다. 위 예시의 클래스 A는 순수 가상 함수 name()을 가지므로 추상 클래스라고 볼 수 있다.
하지만 순수 가상 함수의 존재로 인해 **추상 클래스는 객체를 생성할 수 없다.**  다음 두 경우는 컴파일 에러가 발생하는 예시이다.
```c++
// 컴파일 에러 : 추상 클래스를 인스턴스화할 수 없습니다.
A a;
A* ap = new A();
```
다만, 다음과 같이 추상 클래스에 대한 포인터 선언은 가능하다.
```c++
A* ap;
```

추상 클래스는 객체를 생성하지 않고 오로지 상속만을 위한 기본 클래스로 활용하는 데 그 목적이 있다. 순수 가상 함수를 통해
파생 클래스에서 오버라이딩할 함수의 원형을 보여주는 틀의 역할을 하며 파생 클래스에서 활용할 멤버 함수만
순수 가상 함수로 선언하고 나머지 멤버 변수와 멤버 함수는 나름의 기능을 갖추기도 한다.

추상 클래스를 상속받는 파생 클래스 또한, 순수 가상 함수를 상속받기에 추상 클래스가 된다. 따라서 파생 클래스 또한 객체를 생성할 수 없다.
이러한 불완전 문제를 해결할려면, 기본 클래스에서 상속받은 모든 순수 가상 함수를 파생 클래스에서 오버라이딩하여 구현해야 한다. 한마디로 기능을 작성하여
순수 가상 함수를 없애야 한다는 뜻이다. 다음은 추상 클래스 A를 상속받은 파생 클래스 B의 객체를 생성하는 과정이다.

```c++
class A  { 
public:
	void show() {
		name();
	}
	virtual void name() = 0; // 순수 가상 함수 name()

};

class B : public A { 
public:
	void name() {                      
		cout << "B" << endl; // name()을 구현
	}
 };

int main(int argc, const char* argv[]) {

	B b;       // 정상적 실행
	b.show(); 

	return 0;
}
```

+ ## 추상 클래스의 활용

추상 클래스의 장점은 프로그램 제작 시 설계와 직접적인 구현을 구분할 수 있다는 점이다. 추상 클래스로 전체적인 설계의 틀을 제공하고 파생 클래스로
해당 부분을 하나씩 구현해가면 작업이 보다 수월해진다. 또한 추상 클래스는 계층적 상속 관계를 가진 클래스들의 구조를 만들 때 적합하다.
다음은 추상 클래스로 설계와 구현이 분리된 코드의 예시이다.

```c++
class Job  {  // 추상 클래스, 틀을 제공하여 파생 클래스에서 설계에 따른 구현을 가능하게 함
protected:
	string a;
	virtual string name(string a) = 0; // 순수 가상 함수
public:
	void show() {
		cout << "My job is " << name(a) << endl;
	}
};

class Student : public Job { 
protected:
	string name(string a) { 
		a = "Student";
		return a; 
	}
 };
class Programmer : public Job {
protected:
	string name(string a) {
		a = "Programmer";
		return a;
	}
};

int main(int argc, const char* argv[]) {

	Student a;
	Programmer b;

	a.show();
	b.show();

	return 0;
}
```
실행 결과

```c++
My job is Student
My job is Programmer
```
















