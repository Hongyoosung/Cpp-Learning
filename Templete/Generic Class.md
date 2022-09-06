# 제네릭 클래스

클래스에도 템플릿을 이용한 제네릭을 적용할 수 있으며 이를 통해 만들어진 것을 **제네릭 클래스**라고 한다. 제네릭 클래스는 다양한 타입의 데이터를 동일한 알고리즘으로
처리할 때 사용될 수 있다. 제네릭 클래스의 선언부와 구현부에는 모두 template 키워드를 작성하며 제네릭 클래스의 멤버 함수는 모두 제네릭 함수이다.

클래스 구현부에서 멤버 함수를 구현할 때 제네릭 타입이 'T'인 경우 함수 앞에 template <class T>를 작성하고 클래스 이름 뒤에 <T>를 붙여준다.
  
```c++
// 제네릭 클래스 class1의 멤버 함수 구현
template <class T>
void class1<T>::func(T a) {
  
}
```
제네릭 클래스의 객체를 생성할 때는 구체화할 타입을 명시하여 작성한다. 
```c++
class1<int> a; // class1의 int형 객체 a 생성, T에 int 타입을 구체화
class1<double> b; // class1의 double형 객체 b 생성, T에 double 타입을 구체화
```
 
생성된 객체는 보통의 객체처럼 사용이 가능하며 컴파일러는 템플릿의 T에 int 타입과 double 타입을 적용하여 두 개의 구체화된 클래스 소스를 생성한다.

+ ## 제네릭 클래스 구현
	
+ **제네릭 스택 클래스**
  
다음은 제네릭 클래스를 통해 **스택**을 구현하는 코드이다.

> 스택 : 먼저 입력된 데이터가 나중에 나오는 선입후출의 데이터 구조, 데이터를 저장할 때 밑에서부터 쌓다가 데이터를 추출할 때는 맨 위에서부터 꺼내야 하는 단방향 구조이다.


```c++
template <class T>
class MyStack {    // 제네릭 클래스 MyStack 선언
	int tos;       // 배열의 인덱스, 스택의 현재 저장 정도를 표현
	T data[100];   // 스택으로 사용할 배열, 크기는 100
public:
	MyStack();
	void push(T element); // push의 기능을 할 함수, element를 배열 data에 삽입
	T pop();              // pop의 기능을 할 함수, 맨 위의 데이터를 배열에서 리턴
};

// 생성자 구현
template <class T>
MyStack<T>::MyStack() { tos = -1; } // 인덱스가 1 증가하고 시작할 것이므로 -1로 설정

// push 함수 구현
template <class T>
void MyStack<T>::push(T element) {  
	if (tos == 99) { // 스택이 가득 찼을 경우
		cout << "stack is full" << endl;
		return; // 프로그램 종료
	}
	tos++;
	data[tos] = element;
}

// pop 함수 구현
template <class T>
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {  // 스택이 비어있을 경우
		cout << "stack is empty" << endl;
		return 0; // 에러
	}
	retData = data[tos--]; // retData에 최상위 스택 데이터를 저장
	return retData;        // 최상위 스택 데이터 반환
}
int main(int argc, const char* argv[]) {

	MyStack<int> iStack; // int 타입만을 사용하는 스택
	for (int i = 0; i < 50; i++) {
		iStack.push(i);
	}
	cout << iStack.pop() << endl;  // 가장 나중에 저장된 49를 반환

	MyStack<double> dStack; // double 타입만을 사용하는 스택
	dStack.push(3.5);
	cout << dStack.pop() << endl;

	MyStack<char>* p = new MyStack<char>(); // char 타입만을 사용하는 스택 동적 할당
	p->push('a');
	cout << p->pop() << endl;
	delete p;

	return 0;
}
```
실행 결과
```c++
49
3.5
a
```

	
+ **두 개 이상의 제네릭 타입을 가진 제네릭 클래스 만들기**

```c++
template <class T1, class T2>
class Gclass {
	T1 data1;
	T2 data2;
public:
	Gclass();
	void set(T1 a, T2 b);
	void get(T1& a, T2& b);
};

template <class T1, class T2>
Gclass<T1, T2>::Gclass() {
	data1 = 0; data2 = 0;
}

template <class T1, class T2>
void Gclass<T1, T2>::set(T1 a, T2 b) {
	data1 = a; data2 = b;                // data1과 data2에 전달받은 a와 b를 저장
}

template <class T1, class T2>
void Gclass<T1, T2>::get(T1& a, T2& b) { // a와 b에 set으로 저장된 data1과 data2를 저장
	a = data1; b = data2;
}



int main(int argc, const char* argv[]) {

	int a;
	double b;
	Gclass<int, double> x; // int와 double로 구체화한 객체 x 생성
	x.set(2, 0.5);
	x.get(a, b);

	cout << "a = " << a << endl << "b = " << b << endl;

	char c;
	double d;
	Gclass<char, double> y; // char와 double로 구체화한 객체 y 생성
	y.set('s', 1.5);
	y.get(c, d);

	cout << "c = " << c << endl << "d = " << d << endl;

	return 0;
}
```
실행 결과
```c++
a = 2
b = 0.5
c = s
d = 1.5 
```
위의 결과를 보아 두 개 이상의 제네릭 타입을 가진 제네릭 클래스의 객체를 생성할 때 구체화 타입을 작성하는 과정에서, 작성한 순서대로 제네릭 타입에 대입되는 것을 알 수 있다.
  
  
  
  
  
  
  
  
  
  
  
  
