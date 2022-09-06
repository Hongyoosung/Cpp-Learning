# 다양한 제네릭 함수

+ ## 제네릭 타입이 하나인 경우

+ **두 개의 매개 변수 중 더 큰 값 구하기**

```c++
template <class T> 
T func(T& a, T& b) {      // 리턴 타입 또한 제네릭 타입으로 구현 가능
	if (a > b) return a;
	else return b;
}

int main(int argc, const char* argv[]) {

	int a = 10, b = 20;
	char c = 'e', d = 'f';

	cout << "func(a,b)의 결과 : " << func(a, b) << endl;
	cout << "func(c,d)의 결과 : " << func(c, d) << endl;

	return 0;
}
```
실행 결과
```c++
func(a,b)의 결과 : 20
func(c,d)의 결과 : f
```


+ **배열의 합 구하기**
```c++
template <class T> 
T func(T array[], int n) { // T타입 배열 array, n개의 원소를 더함
	T sum = 0; // 합을 저장할 T 타입의 변수
	for (int i = 0; i < n; i++) {
		sum += array[i];
	}
	return sum; // 합을 반환
}

int main(int argc, const char* argv[]) {

	int data[] = { 1,2,3,4,5 };
	double data2[] = { 1.4,2.2,5.5,1.3,3.2 };

	cout << "배열 data의 원소 5개의 합 : " << func(data, 5) << endl;
	cout << "배열 data2의 원소 2개의 합 : " << func(data2, 2) << endl;

	return 0;
}
```
실행 결과
```c++
배열 data의 원소 5개의 합 : 15
배열 data2의 원소 2개의 합 : 3.6
```

+ ## 두 개 이상의 제네릭 타입을 가진 경우

+ **서로 다른 타입의 배열을 복사하기**

```c++
template <class T1, class T2>             // 제네릭 타입 2개, 서로 다른 타입의 데이터를 처리 가능
void func(T1 array[], T2 copy[], int n = 5 ) { // array의 n개 원소를 copy에 복사, 기본 매개변수 사용 가능
	for (int i = 0; i < n; i++) {
		copy[i] = (T2)array[i];           // 복사를 위해 T1 타입의 array를 T2로 형변환
	}
}

int main(int argc, const char* argv[]) {

	int a[] = { 1,2,3,4,5 };
	double b[5];
	char c[] = { 'a','b','c','d','e' }, d[5];

	func(a, b); // 배열 a의 원소 5개를 b에 복사
	func(c, d, 3); // 배열 c의 원소 5개를 d에 복사

	for (int i = 0; i < 5; i++) cout << b[i] << " ";
	cout << endl;
	for (int i = 0; i < 3; i++) cout << d[i] << " ";

	return 0;
}
```
실행 결과
```c++
1 2 3 4 5
a b c
```

+ ## 제네릭 함수와 이름이 같은 중복 함수

만약 정수 1이 저장된 char 타입의 변수가 제네릭 함수를 통해 구체화되면, << 연산자는 char 타입의 데이터를 문자로 해석하고 운영체제의 문자 코드표에 1에 해당하는 그래픽 
문자를 출력한다. 만약 char 형으로 문자가 아닌 정수 1을 출력하고 싶다면 다음의 경우처럼 제네릭 함수와 이름이 같은 중복 함수를 하나 더 작성해주면 된다. 이는 컴파일러가
제네릭 함수보다 중복 함수의 바인딩을 더 우선시하기 때문이다.

  + 중복 함수를 작성하지 않은 경우
```c++
template <class T>             
void func(T array[], int n) {
	for (int i = 0; i < n; i++) 
		cout << array[i] << " "; // char 타입 정수를 출력할 경우 그래픽 문자를 출력
	cout << endl;
}

int main(int argc, const char* argv[]) {

	int a[] = { 1,2,3,4,5 };
	char b[] = { 1,2,3,4,5 };

	func(a, 3);
	func(b, 5);
	
	return 0;
}
```
실행 결과
```c++
1 2 3
    
```

  + 중복 함수를 작성한 경우

```c++
template <class T>             
void func(T array[], int n) {
	for (int i = 0; i < n; i++) 
		cout << array[i] << " "; 
	cout << endl;
}

void func(char array[], int n) { // 중복 함수 작성, 호출문의 인자가 char 타입이면 해당 함수로 우선 바인딩
	for (int i = 0; i < n; i++)
		cout << (int)array[i] << " ";
	cout << endl;
}

int main(int argc, const char* argv[]) {

	int a[] = { 1,2,3,4,5 };
	char b[] = { 1,2,3,4,5 };

	func(a, 3);
	func(b, 5);
	
	return 0;
}
```
실행 결과
```c++
1 2 3
1 2 3 4 5
```



































