## 함수 오버로드

함수는 이름이 같아도 사용하는 데이터의 형태가 다르면, 다른 함수로 취급한다. 예를 들어, 두 수의 합을 반환하는 함수 func가 두 개 있다고 할 때, 하나는 매개변수가 정수형이고, 
다른 하나는 매개변수가 실수형이다. 이 때, 메인 함수에서 func 함수를 호출할 때, 인자가 실수일 경우, 실수가 매개변수인 func 함수가 호출되고, 인자가 정수인 경우, 매개변수가 정수인
함수가 호출된다. 다음의 예를 보자.

```c++
#include <iostream>
using namespace std;

int func(int a, int b) {
    return a + b;
}
int func(double a, double b) {
    return a + b;
}
int main()
{
    cout << func(1.5 , 5.3);

    return 0;
}
```
실행 결과
```c++
6
```
이름이 같은 함수가 두 개지만, 메인 함수에서 호출할 때는 매개변수가 실수형인 함수가 호출되었다. 이처럼 함수를 호출할 때, 같은 이름의 함수들 중 
인자 유형에 적절한 함수를 자동으로 찾는 것을 함수 오버로딩이라고 한다. 함수 오버로딩을 사용하면, 데이터의 형태만 다르고 같은 기능을 사용해야 할 때 유용하다.

```c++
#include <iostream>
using namespace std;

int func(int a, int b) {
    return a + b;
}
int func(double a, double b) {
    return a + b;
}
int main()
{
    cout << func(5.3 , 5);

    return 0;
}
```
하지만 다음과 같이 인자의 형태가 double, int일 경우, 컴파일러가 어느 함수로 이동할 지 파악할 수 없기 때문에 컴파일 에러가 발생한다. 


## 기본 매개변수와 함수 오버로드

함수 오버로드는 기본 매개변수의 차이로도 구분될 수 있다. 이를 이용해 빈번히 사용되는 호출 인자를 작성하지 않아도 되어 프로그램의 작성을 효율적으로 할 수 있다.

```c++
#include <iostream>
using namespace std;

int func(int a = 5, int b = 10) {
    return a + b;
}
int func(int a) {
    return a;
}
int main()
{
    cout << func();

    return 0;
}
```
실행 결과
```c++
15
```
만약 위의 예에서 a의 기본 매개변수 값을 없애거나, 호출문에서 하나의 인자를 전달하게 되면 두 함수 모두 적용이 가능해 모호성이 생겨 컴파일 에러를 일으키게 된다.
