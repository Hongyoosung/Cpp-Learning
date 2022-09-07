# iterator

> iterator는 컨테이너 내 원소들을 하나씩 순차적으로 접근하기 위한 **원소에 대한 포인터**이다. iterator를 생성하기 위해서는 컨테이너 템플릿에 구체적인 타입을 작성하여
> 원소의 타입이 드러나도록 해야 한다.

+ vector<int> 컨테이너의 원소에 대한 iterator 변수 it을 생성하는 코드
```c++
  vector<int>::iterator it;
```

+ 이렇게 생성된 iterator 변수 it은 int 형 원소를 가진 벡터에 대한 포인터이다. it은 아직 어떠한 곳도 가리키고 있지 않으므로 첫 번째 원소의 주소를
  리턴하는 v.begin()을 사용해 it이 벡터의 첫 번째 원소를 가리키도록 해본다.
  
```c++
vector<int> v;
it = v.begin();
```
  
+ iterator는 하나의 변수이기 때문에 연산자를 사용할 수 있다. 다음은 it에 증감연산자를 사용하여 다음 원소를 가리키게 하거나 이전의 원소를 가리키도록 하는 것이다.
```c++
it++; // 벡터의 다음 원소를 가리킴
it--; // 벡터의 이전 원소를 가리킴
```
 
+ iterator는 포인터 변수이므로 역참조연산자를 통해 일반 변수에 it이 가리키는 곳에 저장된 값을 복사대입할 수 있다.
```c++
int n = *it;
*it = 5; // it이 가리키는 곳에 5를 저장
```
  
  
  
+ v.end()는 마지막 원소가 아닌, 마지막 원소 다음 위치에 대한 주소를 리턴한다는 점을 주의한다. 다음은 begin()과 end() 함수를 이용하여 벡터 v에 있는
  모든 원소를 검색하여 출력하는 코드이다.
```c++
  for (it = v.begin(); it != v.end(); it++) { // 벡터의 시작부터 끝이 아닐 때 까지 반복
		int n = *it;       // 정수 n에 it이 가리키는 값을 저장
		cout << n << endl; // it이 1씩 증가하며 n에 저장되고 출력
	}
```
  
  
  + iterator를 이용하여 벡터 내 모든 원소의 값을 두 배 곱하기
```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(int argc, const char* argv[]) {

	vector<int> v;
	vector<int>::iterator it;

	for (int i = 0; i < 5; i++) { // 벡터에 값을 저장
		v.push_back(i * 10);
	}

	for (it = v.begin(); it != v.end(); it++) { 
		int n = *it; // 정수 n에 it이 가리키는 값을 저장
		n *= 2;      // n을 2배로 증가
		*it = n;     // it이 증가한 n을 가리키도록 함
	}

	for (it = v.begin(); it != v.end(); it++) { // 벡터 내 모든 원소를 출력
		cout << *it << " ";
	}

	return 0;
}
```
                   
벡터를 사용할 때와 일반 배열을 사용할 때의 차이점으로, 배열은 반복문으로 활용하기 위해 반복 변수를 선언하고 이를 통해 반복 횟수를 결정하지만,
벡터를 반복문으로 활용할 때는 벡터의 멤버 함수를 이용해 반복 변수를 새로 선언하고 값을 조정할 필요가 없다는 것이다.

  
  
  
  
  
  
  
