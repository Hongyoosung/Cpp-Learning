# 조건문

조건문은 프로그램 실행 중 참과 거짓의 여부를 통하여 상황에 따라 원하는 기능을 실행토록 한다. 관계연산자를 통하여 해당 기능의 실행 조건을 구현할 수 있으며, 이를 통해 조건이 참일 경우와
거짓인 경우, 특정 상황일 경우에 실행될 기능을 구현할 수 있다. 조건문에는 if문, else if문이 있다.

## if 문

만약 ~이 ~인 경우에 if 문 몸체에 구현된 기능을 실행한다. ~에는 사용자가 원하는 변수 등이 사용되며 관계연산자를 통해 조건을 완성한다. 조건이 참일 경우 if문 몸체에 있는 기능이 실행되며
거짓일 경우에는 실행되지 않고 if문 다음에 구현된 문장이 실행된다.

예시 1)
```c++
#include <iostream>
using namespace std;;

int main(){
  int a;
  
  cout << "수를 입력하세요" << endl;
  cin >> a;
  
  if(a > 10){
    cout << "Hello World" << endl;
   }
   
   return 0;
}
```

해당 예시는 프로그램 실행 후 사용자가 10 초과의 정수를 입력하면 "Hello World"를 출력한다. 선언된 변수 a에 사용자가 데이터를 입력하면 if 조건문의 ()안 식에서 a에 대한 조건의 참과
거짓을 판별한 후 해당 조건이 참이면 { }안 if문 몸체의 기능이 실행되는 것이다.

## else 문

else문은 해당 조건이 거짓일 때 실행되는 문장을 구현하는 함수이다. 조건의 참이 있어야 거짓이 있으므로 반드시 if문과 함께 사용해야 하며, 단독으로 사용될 수 없다.

예시2)
```c++
#include <iostream>
using namespace std;;

int main(){
  int a;
  
  cout << "수를 입력하세요" << endl;
  cin >> a;
  
  if(a > 10){
    cout << "Hello World" << endl;
   }
   
   else {
    cout << "Hello C++" << endl;
   }
   
   return 0;
}
```

위의 예시에서 만약 10 이하의 정수를 입력했을 경우, else문 몸체의 기능이 실행되어 "Hello C++"을 출력하게 된다.

## else if문

만약 참과 거짓의 두 가지 경우 외에 다채로운 경우를 만들고 싶다면 else if문을 사용하면 된다. 해당 기능은 '~이 아니면 ~인가?'라는 의미를 갖고 있으며, if문에서 사용한 조건 외에도 다른 조건을 구현할 수 있다. 해당 함수 또한 if문과 같이 사용해야하며, if문과 else문 사이에 위치해야 한다. 이때, else 문은 if문과 else if문의 조건이 모두 거짓일 경우에 실행된다.

예시3)
```c++
#include <iostream>
using namespace std;;

int main(){
  int a;
  
  cout << "수를 입력하세요" << endl;
  cin >> a;
  
  if(a > 10){
    cout << "Hello World" << endl;
   }
   
  else if(a > 5){
    cout << "Hello" << endl;
  }
  
   else {
    cout << "Hello C++" << endl;
   }
   
   return 0;
}
```

해당 예시에서 else if문은 위의 if문에서 a가 10 이하일 시 실행되고 10 이하인 a가 5 초과일 경우에 실행된다. 만약 a가 5 이하일 경우 else문이 실행된다.
다음은 조건문의 전체적인 실행 흐름이다.

if문 : a가 10 초과인가? -> 참이면 if문 실행, 거짓일 시 다음 else if문 실행
else if문 : 그렇다면 a는 5 초과인가? -> 참이면 else if문 실행, 거짓일 시 else 문 실행
else 문 : a가 5 이하일 시 실행

















