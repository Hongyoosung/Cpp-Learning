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
  

  
  
  
  
  
  
  
  
  
  
  
  
  
