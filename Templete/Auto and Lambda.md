## autu와 람다식

> **auto** 키워드는 변수 선언문에서 자료형을 대신하여 쓰이며 컴파일러가 데이터의 타입을 추론하여 변수를 적절한 자료형으로 결정하도록 지시한다. 해당 키워드를 이용해
> 변수 선언을 간소화할 수 있으며 타입 선언의 오타 등을 줄여준다.

+ ### autu의 사용

```c++
int main(int argc, const char* argv[]) {

	auto a = 3.14; // double로 변환
	auto b = 'A';  // char로 변환
	auto c = 10;   // int로 변환
	auto* d = &c;  // int* 로 변환

	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	cout << sizeof(c) << endl;
	cout << sizeof(d) << endl;

	return 0;
}
```
실행 결과
```c++
8
1
4
8
```
auto 키워드를 통해 변수 세 개를 선언하고 각기 다른 타입의 값을 저장했다. 그리고 sizeof()함수를 통해 해당 저장공간의 크기를 바이트 단위로 출력해본 결과 각 8(double), 1(char),
4(int)가 출력되었다. 이를 통해 컴파일러는 컴파일 시 auto 키워드가 작성된 변수의 데이터 타입을 파악하고 적절한 자료형을 붙여주어 저장 공간을 생성한다는 것을 알 수 있다.

#

+ ### auto의 사용 2

```c++
int f(int a) {
	return a;
}
int main(int argc, const char* argv[]) {

	int a = 10;       // 정수형 변수 a
	int& ref = a;     // a를 참조하는 ref
	auto ref2 = ref;  // ref를 참조하는 ref2
  
  // 셋의 주소가 같다 = 같은 저장 공간을 사용한다 = ref2의 auto는 자동으로 '&'를 삽입
	cout << &a << endl;
	cout << &ref << endl;
	cout << &ref2 << endl;

	auto b = f(a);  // b는 f의 리턴 값을 저장, 리턴형이 int형임

	cout << sizeof(b) << endl; // b의 크기 출력, 4 = int


	return 0;
}
```
실행 결과
```c++
000000F8B04FF7C4
000000F8B04FF7C4
000000F8B04FF804
4
```
auto는 변수가 참조 변수를 참조한다면 자동으로 자료형에 '&'를 붙여 같은 데이터를 참조하도록 만든다. 또, auto가 사용된 변수에 함수의 리턴 값을 저장하면
해당 함수의 리턴형에 맞게 변환된다.

#

+ ### STL 템플릿에 활용

auto를 vector, map 등의 템플릿에 활용하여 코드를 더욱 간소화할 수 있다. 다음은 vector에 데이터를 저장하고 출력하는 예이다.

  + auto를 사용하지 않은 경우
  ```c++
  int main(int argc, const char* argv[]) {

	vector<int> v = { 1,2,3,4,5 };

	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}
```

  + auto를 사용할 경우
  ```c++
  int main(int argc, const char* argv[]) {

	vector<int> v = { 1,2,3,4,5 };

	for (auto it = v.begin(); it != v.end(); it++) { // it을 vector<int>::iterator 타입으로 추론
		cout << *it << endl; 
	}

	return 0;
}
```

auto를 사용하여 it 변수 선언을 생략할 수 있는 것을 알 수 있다.






















