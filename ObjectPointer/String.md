# string 클래스를 통한 문자열 사용

기존에 문자열을 출력하는 방법으로는 char 형의 배열을 통해 '\0'가 나올 때 까지 한 단어씩 출력하는 법이 있었다. 이외에도 다른 한 가지 방법이 있는데, 그것은 c++ 표준 라이브러리에서
제공하는 string 클래스를 이용하는 것이다. string 클래스는 문자열을 저장하는 기능 말고도, 문자열을 활용하는 다양한 함수와 연산자를 멤버로 가지고 있어 보다 편리하게 문자열을
사용할 수 있다.

표준 라이브러리의 클래스를 사용하기 위해서는 #include 지시어를 통해 string 클래스를 소스 파일로 불러와야 한다. 다음은 string 클래스를 활용해 문자열을 연결하고 출력하는 과정이다.

```c++
#include <iostream>
#include <string>   // string 클래스 명시
using namespace std;

int main(int argc, const char* argv[]) {

	string a = "Hello";  // string 클래스의 객체 a 생성 및 초기화

	a.append(" World");  // string 클래스의 멤버 함수, 문자열을 뒤에 덧붙이는 역할

	cout << a << endl;   // a 출력

	return 0;
}
```
실행 결과
```c++
Hello World
```

기존에 사용했던 C-스트링(char 배열)으로 문자열을 구현하려면, 반복문이 추가로 필요하고, 처음 선언했던 크기 이상의 문자열을 다룰 수 없어 프로그래밍에 불편함을 초래한다.
따라서 C++에 추가된 문자열 전용 클래스인 string을 사용하여 보다 손쉬운 문자열 구현이 가능하다. 위의 경우에서도, append 함수가 자동으로 저장공간 크기를 늘려
문자열을 덧붙인 것을 확인할 수 있다.

다음은 string 클래스의 멤버 함수를 활용하는 것이다.
```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[]) {

	string a; // 빈 문자열을 가진 a 생성

	string b("Hello haha"); // 문자열 객체 b 생성, 초기화

	string c(b); // b의 문자열을 복사해서 저장하는 객체 c 생성

	char text[] = { 'w','h','a','t',' ','t','h','e','\0' };
	string d(text); // C-스트링 배열을 저장하는 객체 d 생성

  cin >> a;     // 객체 a에 문자열을 입력
	cout << a << endl << b << endl << c << endl << d << endl;

	
	return 0;
}
```
실행 결과
```c++

hi // 입력한 임의의 문자열
Hello haha
Hello haha
what the
```

string 객체 역시 new와 delete를 이용해 동적 생성 및 반환이 가능하다. 다음은 그 예시이다.

```c++

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[]) {

	string* p = new string("fucking");   // string 객체 동적 생성
	cout << *p << endl;

	p->append(" C++");        // p는 "fucking C++"을 가리키게 됨
	cout << *p << endl;

	delete p;

	
	return 0;
}

```
실행 결과
```c++
fucking
fucking C++
```


+ ## string 클래스의 주요 생성자

string 또한, 클래스이기에 객체 생성시 실행되는 생성자가 존재한다.

> + string() : 빈 문자열을 가진 스트링 객체 생성
> 
> + string(const string& str) : str을 복사한 새로운 스트링 객체 생성
> 
> + string(const char* s) : C-스트링의 배열 s의 문자열을 복사하여 스트링 객체 생성
> 
> + string(const char* s, int n) : 문자 배열 s에서 n개의 문자를 복사하여 스트링 객체 생성, 문자열의 왼쪽부터 복사한다.


+ ## 공백을 포함한 문자열 입력

cin >> 연산자를 통해 문자열을 입력하는 경우, 공백을 입력 시 그 앞까지의 내용만 입력되어 이후의 문자는 읽어들일 수 없다.
이러한 문제를 해결하기 위해서는 <string> 헤더 파일에 선언된 **getline() 함수**를 사용해야 한다. 다음은 공백을 포함한 문자열을
  입력할 때, getline()함수의 사용 유무 차이이다.
  
  + getline()을 사용하지 않은 공백 문자열 입력
  ```c++
  #include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[]) {

	string a;

	cin >> a;

	cout << a << endl;

	return 0;
}
```
실행 결과
```c++
hello world // cin을 통해 hello world 입력
hello // 공백 이전까지의 문자열만 출력됨
```
  
  + getline() 함수를 사용했을 때
  ```c++
  #include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[]) {

	string a;

	getline(cin, a, '\n'); // 줄 띄움 명령어 '\n'을 만나기 전까지 키보드로부터 문자열을 입력받아(cin) a에 저장

	cout << a << endl;

	return 0;
}
  ```
  실행 결과
  ```
  hello world // hello world 입력
  hello world // 그대로 출력됨
```
  
+ ## string 배열
  
  string 객체 또한 배열로 선언이 가능하다. 다음은 스트링 배열에 문자열을 입력하고 출력하는 과정이다.
 ```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[]) {

	string name[5];

	for (int i = 0; i < 5; i++) {
		cout << "이름을 입력하세요 : " << endl;
		getline(cin, name[i], '\n');
	}
	
	string a = name[0]; //알파벳 순 가장 뒤의 문자열을 저장하기 위해 선언

	for (int i = 0; i < 5; i++) { // 문자열을 비교하여 더 뒤의 문자열을 갱신
		if (a < name[i]) a = name[i];
	}

	cout << "알파벳 순에서 가장 뒤에 있는 문자열 : " << a << endl;

	return 0;
}
```
실행 결과
```c++
                                                
이름을 입력하세요 :
Kim do hyeon
이름을 입력하세요 :
Kim jin ho
이름을 입력하세요 :
Lee Dong Hun
이름을 입력하세요 :
Kim Dae Hong
이름을 입력하세요 :
Hong Yoo Sung
알파벳 순에서 가장 뒤에 있는 문자열 : Lee Dong Hun
```
                                                
스트링 객체 a는 자신과 그 다음 배열의 문자열을 비교하여 알파벳 순으로 더 뒤의 문자열을 저장한다.
문자는 프로그램 내부에서 2진수 값으로 저장되어 있고, 알파벳 순으로 수가 증가하는 방식이기 때문에
부등호를 통해 문자의 알파벳 순을 비교할 수 있다. 또한, 문자열의 크기를 비교할 때는 맨 앞의 문자만 확인한다는 것을 알 수 있다.
                                                
                                                

 
  
  










