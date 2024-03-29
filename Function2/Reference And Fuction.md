# 참조 변수

함수를 이용해 두 변수의 값을 바꾸는 코드를 작성해보자.
```c++
#include <iostream>
using namespace std;

void swap(int a, int b) {
    int c;
    c = a;
    a = b;
    b = c;

    cout << "func a : " << a << endl;
    cout << "func b : " << b << endl;
}

int main()
{
    int a = 10;
    int b = 20;
    
    swap(a, b);

    cout << endl;
    cout << "Main a : " << a << endl;
    cout << "Main b : " << b << endl;

    return 0;
}
```
실행 결과
```c++
func a : 20
func b : 10

Main a : 10
Main b : 20
```

함수에서는 정상적으로 두 변수의 값이 바뀌었지만, 메인 함수에서는 적용되지 않았다. 이는 함수에서의 a, b와 메인 함수에서의 a, b는 서로 다른 저장공간을 사용하기 때문이다.
변수는 이름이 같더라도 선언된 범위가 다르면 컴파일에 문제가 없으며 다른 저장공간으로 취급된다. 물론 다른 범위의 변수는 서로 호환 또한 불가능하다. 변수는 선언된 그 범위 내에서만
통용되며, { }를 벗어난 외부 범위에서는 사용하지 못한다. 프로그램 실행 중 범위인 { }를 벗어나게 되면, 그 안에서 선언된 변수는 소멸하게 된다. 위의 경우에서도 함수 func의 호출이 끝나면
func 함수의 a와 b는 소멸된다. 따라서 함수를 사용할 때는 보통 변수가 소멸하기 전 값을 반환하여 메인 함수의 새로운 저장공간에 보관하여 함수가 종료되어 변수가 소멸하더라도 메인 함수에서
값을 사용할 수 있게 된다.

하지만 값은 하나만 반환할 수 있기에, 위의 두 변수의 값을 바꾸는 문제는 일반적인 방법으로는 해결할 수 없다. 그러나 메인 함수의 변수와 일반 함수에 있는 변수가 서로 같은 저장 공간을
사용한다면 문제가 해결된다. 이를 할 수 있게 해주는 것이 참조 변수이며, 저장공간의 공유는 변수 선언 범위를 초월한다. 다음은 참조 변수를 활용해 위의 문제를 해결한 것이다.

```c++
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int c;
    c = a;
    a = b;
    b = c;

    cout << "func a : " << a << endl;
    cout << "func b : " << b << endl;
}

int main()
{
    int a = 10;
    int b = 20;
    
    swap(a, b);

    cout << endl;
    cout << "Main a : " << a << endl;
    cout << "Main b : " << b << endl;

    return 0;
}
```
실행 결과
```c++
func a : 20
func b : 10

Main a : 20
Main b : 10
```

참조 변수는 선언 시 자료형 뒤에 '&'를 붙여주어 선언한다. 위의 경우에서 swap 함수의 매개변수인 두 참조변수는 메인 함수에서 호출문을 통해 인자를 전달받으면 해당 변수의 저장공간을
사용하게 된다. 따라서 참조 변수는 새로운 저장공간을 할당하지 않고 기존에 존재하는 변수의 저장공간을 같이 사용한다고 볼 수 있다. 이로 인해 swap 함수에서는 메인 함수의 a와 b의
저장공간을 사용할 수 있었고 메인 함수에서 a와 b의 값이 바뀔 수 있는 것이다.

```c++

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int& b = a; //참조 변수 b는 a의 저장공간을 사용

    a += 10;
    cout << b << endl;
    b += 10;
    cout << a << endl;

    return 0;
}
```
실행 결과
```c++
20
30
```
참조 변수의 다른 사용 예, 참조 변수는 함수의 매개변수로도 사용할 수 있지만, 위처럼 함수 몸체에도 사용될 수 있다. 참조 변수 b는 a의 저장 공간을 사용하므로 둘은 공유된 상태이다.
따라서 a와 b는 값의 변동을 서로 공유하게 된다. 참조 변수는 참조할 저장공간을 필요로 하기 때문에 대입 연산자로 상수가 아닌 변수만 사용이 가능하다.


+ ## 참조 변수의 특징

    + 상수를 대입할 수 없다.
    + 참조 변수의 배열은 만들 수 없다.
    + 참조 변수에 또 다른 참조 변수를 저장할 수 있다.
    + 포인터 변수에 참조 변수의 주소를 저장할 수 있다.
    + 참조 변수는 선언과 동시에 초기화해야 한다.

+ ## 객체에 대한 참조

클래스 형태의 참조 변수를 선언할 수 있다. 참조 변수 ref는 객체 이름만 다를 뿐, Jinho와 같은 저장 공간을 사용한다.
```c++
class Man {
	int age;
public:
	Man() { age = 26; }
	Man(int age) { this->age = age; }
	void setAge(int age) { this->age = age; }
	int getAge() { return age; }
};


int main(int argc, const char* argv[]) {

	Man Jinho;
	Man& ref = Jinho;

	ref.setAge(30);
	cout << Jinho.getAge() << endl;

	return 0;
}
```
실행 결과
```c++
30      // ref의 변동 사항이 Jinho에도 적용된 모습
```

+ ## 참조에 의한 호출로 객체 전달

```c++
void aging(Man& a){
    int b = a.getAge();
    a.setAge(b+10);
 }
```

값에 의한 호출을 통한 객체 전달에서 함수에 객체를 전달받으면 매개 변수 객체가 생성되고, 소멸자만을 실행한다.
참조에 의한 호출로 객체를 전달할 시, 매개 변수 객체를 생성해 저장 공간을 할당받는 것이 아니라 이름만을 생성하고 저장 공간을 
공유하기 때문에 생성자나 소멸자를 실행하지 않는다.


+ ## 참조 반환(리턴)

참조를 반환하는 함수를 작성할 수 있다. 이 경우, 반환 값은 참조 변수의 형태이다. 다음은 참조 리턴을 이용해 문자열을 변경하는 예이다.

```c++
char& find(char a[], int i) {
	return a[i];    // 참조 리턴
}

int main(int argc, const char* argv[]) {

	char name[] = { "Jinho" };
	cout << name << endl;

	find(name, 0) = 'M';   // name의 첫 번째 index를 'M'으로 변경
	cout << name << endl;

	char& ref = find(name, 3);  // ref는 name의 4번 째 index를 참조
	ref = 'o';                  // name의 4번 째 index를 'o'로 변경
	cout << name << endl;

	return 0;
}
```
실행 결과
```c++
Jinho
Minho
Minoo
```

만약 find 함수를 참조 형태로 하지 않을 경우, 메인 함수의 find 함수 부분에 컴파일 에러가 발생한다.



 








