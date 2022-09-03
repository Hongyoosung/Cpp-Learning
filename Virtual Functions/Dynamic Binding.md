# 동적 바인딩과 오버라이딩의 특징

+ ## 동적 바인딩의 특징


동적 바인딩은 가상 함수와 관련이 깊다. 컴파일 중 가상 함수가 호출되면, 컴파일러는 함수 호출 관계(바인딩)를 프로그램 실행 중에 결정하도록 미뤄둔다.
그리고 프로그램 실행 중 오버라이딩된 가상 함수를 찾아 호출한다. 이러한 동적 바인딩은 **실행 시간 바인딩** 또는 **늦은 바인딩**이라고도 부른다.
다만, 기본 클래스의 가상 함수 호출만으로는 동적 바인딩이 일어나지 않는다. **동적 바인딩은 파생 클래스의 객체에 대해 기본 클래스의 포인터로 가상 함수가 호출될 때 일어난다.**
이러한 경우들은 다음과 같다.

  + (1) 기본 클래스 내의 멤버 함수가 가상 함수를 호출
  + (2) 파생 클래스 내의 멤버 함수가 가상 함수를 호출
  + (3) main()과 같은 외부 함수에서 기본 클래스의 포인터로 가상 함수 호출
  + (4) 다른 클래스에서 가상 함수 호출

해당 경우는 모두 동적 바인딩을 통해 파생 클래스에 오버라이딩된 가상 함수를 실행한다. 다음은 동적 바인딩이 호출되는 가상 함수 호출의 예시이다.

```c++
class Person {
public:
	void show() {        // 가상 함수 name을 호출하는 함수 show
		name();
	}
	virtual void name() { // 가상 함수 선언
		cout << "Jinho" << endl;
	}
};

class Man : public Person {
public:
	virtual void name() { // 가상 함수 재정의
		cout << "Dohyeon" << endl;
	}
 };


int main(int argc, const char* argv[]) {

	Person* pPerson = new Man(); // 기본 클래스의 포인터로 파생 클래스 객체 동적 할당, 업 캐스팅
	pPerson->show();

	delete pPerson;

	return 0;
}
```
실행 결과
```c++
Dohyeon
```
위의 예는 동적 바인딩이 적용되는 1번과 3번의 경우라고 볼 수 있다. 기본 클래스의 포인터로 어떤 파생 클래스의 객체를 가르키냐에 따라 어떤 오버라이딩을
따르게 될지 결정된다. 위의 예는 기본 클래스의 포인터로 파생 클래스 Man을 가리키고 있고, 해당 포인터로 가상 함수 호출 시 Man의 오버라이딩을 따르고 있다.

+ ## override 지시어

컴파일러에게 해당 가상 함수가 오버라이딩 되었는지 확인시키는 지시어, 만약 코드 작성 중 오버라이딩을 하려 했지만 오타가 발생하여 다음과 같이 작성되었다고 가정해본다.

```c++
class Person {
public:
	void show() {        // 가상 함수 name을 호출하는 함수 show
		name();
	}
	virtual void name() { // 가상 함수 선언
		cout << "Jinho" << endl;
	}
};

class Man : public Person {
public:
	virtual void no() { // 오타 발생
		cout << "Dohyeon" << endl;
	}
 };
 ```
 
 이처럼 오타가 발생하여 오버라이딩할 함수와 이름이 달라지게 되면 컴파일러는 새로운 함수를 선언하는 것으로 알고 아무 문제없이 프로그램이 실행되어
 오버라이딩이 발생하지 않게 된다. 해당 경우, 개발자는 실행 결과가 의도와 다르지만 실행에는 문제가 없어 혼란을 겪에 된다.
 따라서 override 지시어를 사용해 해당 함수가 오버라이딩 처리가 되었는지 확인할 수 있다.
 ```c++
 class Man : public Person {
public:
	virtual void no() override { // 지시어 사용, 가상 함수의 원형 뒤에 붙여준다
		cout << "Dohyeon" << endl;
	}
 };
```
override 지시어를 붙여주면 no에 빨간 줄이 그이고 실행 시 컴파일 에러가 발생하여 개발자에게 해당 함수가 오버라이딩이 적용되지 않음을 알릴 수 있다.


+ ## final 지시어


파생 클래스에서 해당 가상 함수를 오버라이딩하지 못하게 하는 지시어. override 지시어와 같이 함수 원형 뒤에 작성하여 사용한다. final 지시어가 적용된
가상 함수는 파생 클래스에서 오버라이딩할 수 없게 되며, 오버라이딩 시 컴파일 에러를 일으킨다.



```c++
class Person {
public:
	void show() {        // 가상 함수 name을 호출하는 함수 show
		name();
	}
	virtual void name() final { // final 지시어 적용
		cout << "Jinho" << endl;
	}
};

class Man : public Person {
public:
	virtual void name() { // 오버라이딩 시도, 컴파일 에러 발생
		cout << "Dohyeon" << endl;
	}
 };

```

또는 클래스 이름 뒤에 작성하여 해당 클래스의 상속을 막을 수 있다.
```c++
class Person final { // final 지시어 적용, 상속 금지 선언
public:
	void show() {       
		name();
	}
	virtual void name()  { 
		cout << "Jinho" << endl;
	}
};

class Man : public Person { // Person 클래스를 상속받을 수 없음, 컴파일 에러 발생
public:
	virtual void name() { 
		cout << "Dohyeon" << endl;
	}
 };
 ```


+ ## c++ 오버라이딩의 특징


  + #### 가상 함수의 이름과 매개 변수 타입과 개수, 리턴 타입이 모두 일치해야 오버라이딩이 성공한다.
 ```c++
  class Person  { 
public:
	virtual void name()  { 
		cout << "Jinho" << endl;
	}
};

class Man : public Person { 
public:
	virtual int name() {  // 리턴 타입이 달라 컴파일 에러 발생
		cout << "Dohyeon" << endl;
	}
 };
   ```
  + #### virtual 키워드는 상속되는 속성이 있어, 파생 클래스에서 virtual 키워드를 생략할 수 있다.
 ```c++
 class Person  { 
public:
	virtual void name()  { 
		cout << "Jinho" << endl;
	}
};

class Man : public Person { 
public:
	void name() {  // virtual을 생략해도 name은 가상 함수를 의미
		cout << "Dohyeon" << endl;
	}
 };
 ```
 


  + #### 가상 함수 또한 접근 지정자 private, public, protected를 자유롭게 작성할 수 있다.
  + #### 상속이 중첩되어 있어도 모든 파생 클래스는 최상위 기본 클래스의 가상 함수 오버라이딩이 가능하다.

```c++
class A  { 
public:
	virtual void name()  { 
		cout << "A" << endl;
	}
};

class B : public A { 
public:
	void name() {  // virtual을 생략해도 name은 가상 함수를 의미
		cout << "B" << endl;
	}
 };

class C : public B {
public:
	void name() {
		cout << "C" << endl;
	}
};


int main(int argc, const char* argv[]) {

	C c;
	A* ap;
	B* bp;
	C* cp;

	ap = bp = cp = &c; // 모든 클래스의 포인터가 C 클래스의 객체를 가리킴

	// 모두 C의 오버라이딩 함수를 실행
	ap->name();
	bp->name();
	cp->name();

	return 0;
}
```
실행 결과
```c++
C
C
C
```


  + #### 범위 지정 연산자를 통해 정적 바인딩을 할 수 있다.

오버라이딩으로 무력화된 기본 클래스의 가상 함수를 범위 지정 연산자를 통해 사용할 수 있다. 이는 정적 바인딩으로 이루어지며 파생 클래스의 오버라이딩에서도
호출할 수 있다. 보통 기본 클래스의 가상 함수를 그대로 활용하면서 새로운 기능을 추가하고자 할 때 주로 사용된다. 다음은 그 예시이다.
```c++
class A  { 
public:
	virtual void name()  { 
		cout << "A" << endl;
	}
};

class B : public A { 
public:
	void name() {            // 오버라이딩
		A::name();           // 기본 클래스의 가상 함수를 호출
		cout << "B" << endl;
	}
 };

int main(int argc, const char* argv[]) {

	B b;
	A* ap;

	ap = &b; // 업 캐스팅

	ap->name();    // 동적 바인딩, 오버라이딩 가상 함수 실행
	ap->A::name(); // 정적 바인딩, 기본 클래스의 가상 함수 실행

	return 0;
}
```
실행 결과
```c++
A
B
A
```



















