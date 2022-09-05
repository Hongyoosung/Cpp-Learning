+ ## 가상 소멸자

클래스 만들 때, 소멸자를 가상 함수로 만드는 습관을 들이는 것이 좋다. 앞선 예시처럼 보통 가상 함수를 사용하기 위해 기본 클래스의 포인터 객체 p로
파생 클래스의 가상 함수를 호출하여 저장 공간을 생성 후 다시 해지한다고 가정해본다. 이 때, 이를 해지하기 위해 p에 delete 지시어를 사용했다. 하지만 p는
기본 클래스의 객체이기 때문에 해지된건 파생 클래스의 저장 공간이지만 기본 클래스의 소멸자만이 실행된다. 우리는 상속 관계에 있는 객체의 생성자와 소멸자의
실행 순서를 배웠으므로 정상적인 경우라면 파생 클래스의 소멸자가 실행되고 기본 클래스의 소멸자가 실행되어야 한다. 따라서 기본 클래스와 파생 클래스의 소멸자를
가상 함수로 선언하여 동적 바인딩(쉽게 말해 오버로딩)을 일으켜 두 소멸자를 모두 실행시키는 정상적인 과정을 밟을 수 있다. 다음은 소멸자를 가상 함수로 선언한 것과 그렇지
않은 경우이다.

  + ### 소멸자를 가상 함수로 선언하지 않은 경우
```c++
class A  { 
public:
	virtual void name()  { 
		cout << "A" << endl;
	}
	~A() { cout << "delete A" << endl; }
};

class B : public A { 
public:
	void name() {                      
		cout << "B" << endl;
	}
	~B() { cout << "delete B" << endl; }
 };

int main(int argc, const char* argv[]) {

	A* ap = new B(); // 동적 생성
	delete ap;

	return 0;
}
```
실행 결과
```c++
delete A
```

  + ### 소멸자를 가상 함수로 선언한 경우
```c++

class A  { 
public:
	virtual void name()  { 
		cout << "A" << endl;
	}
	virtual ~A() { cout << "delete A" << endl; }
};

class B : public A { 
public:
	void name() {                      
		cout << "B" << endl;
	}
	virtual ~B() { cout << "delete B" << endl; }
 };

int main(int argc, const char* argv[]) {

	A* ap = new B(); // 동적 생성
	delete ap;

	return 0;
}
```
실행 결과
```c++
delete B
delete A
```


해당 과정은 기본 클래스의 객체가 아닌 파생 클래스의 객체가 소멸해도 동적 바인딩이 일어난다. 또한 생성자는 가상 함수가 될 수 없다. 


+ ## 오버로딩의 정의와 함수 재정의, 오버라이딩의 차이

**오버로딩**이란 매개 변수의 타입이나 개수가 다른 같은 이름의 함수를 중복으로 작성하는 것이다. 클래스 이전에 배운
함수 오버로드가 이에 해당한다. 이러한 함수 중복이 클래스의 상속 관계에서 일어나 파생 클래스가
기본 클래스의 함수를 원형 그대로 재작성하는 것을 **함수 재정의**, 함수 재정의에서 가상 함수의 개념이 추가되어 동적 바인딩을 일으키는 것을 **오버라이딩**이라고 한다.

오버로딩의 목적은 편의성 향상, 함수 재정의의 목적은 파생 클래스에서 별도로 필요로 하는 함수의 작성, 오버라이딩의 목적은 기본 클래스의 멤버를 무시하고
파생 클래스에서 새로운 기능으로 재작성하기 위함이다. 셋은 목적이 모두 다르지만 오버로딩과 함수 재정의는 정적 바인딩이라는 점과 컴파일 시간의 다형성을 실현한다는
공통점을 가지고 있다. 오버라이딩은 이와 달리 동적 바인딩과 프로그램 실행 시간의 다형성을 실현한다는 차이점이 있다.













