# vector 컨테이너

> **vector** 클래스는 가변 길이 배열을 구현한 제네릭 클래스이다. vector에는 내부에 배열을 가지고 원소를 저장, 삭제, 검색하는 멤버들을 제공한다. vector는 내부 배열의 크기를
> 스스로 조절하기 때문에 개발자가 크기에 대해 고민하지 않아도 되며 오직 vector에서 제공하는 멤버 함수를 통해 vector를 사용하면 된다. vector의 배열은 일반 배열과 같이
> 인덱스 0부터 시작한다.


+ ### vector 객체 생성

다음은 int 타입을 저장하는 vector 객체를 생성하는 예시이다. < >안에 다루고자 하는 타입을 작성한다.
```c++
vector<int> v; // int 타입의 데이터만 다루는 벡터 객체 생성, 다른 타입의 데이터를 삽입하면 오류가 발생한다.
```

+ ### vector에 원소 삽입

벡터에 값을 삽입하기 위해 **push_back()** 멤버 함수를 사용한다. 해당 멤버 함수는 벡터의 맨 마지막에 값을 삽입하며 다음의 예시는 1, 2, 3을 순서대로 벡터에 저장한다.
```c++
v.push_back(1);
v.push_back(2);
v.push_back(3);
// 벡터에 저장된 원소의 개수는 3이 됨
```


+ ### vector의 원소 값 읽기 및 변경하기

벡터 내 원소의 값에 접근하기 위해 **at()** 멤버 함수를 사용한다. ()안은 배열의 인덱스가 들어간다.

```c++
v.at(2) = 5;    // v의 세 번째 원소 값을 5로 변경, 3은 5가 됨.
int n = v.at(1);// v의 두 번째 원소 값을 읽어 n에 저장
```

[] 연산자를 사용하여 벡터를 배열처럼 사용할 수 있다.

```c++
v[2] = 5;     // 벡터 v의 세 번째 원소 값을 5로 변경, v.at(2) = 5와 같다
int n = v[1]; // 벡터 v의 두 번째 원소 값을 읽어 n에 저장

for(int i=0; i<3; i++) cout << v[i] << endl; // 벡터의 요소를 출력
```

+ ### vector의 원소 개수 알아내기

**size()** 함수를 사용하여 벡터에 존재하는 모든 원소의 개수를 알 수 있다. size() 함수는 벡터의 모든 요소의 개수를 리턴하므로 다음과 같이 사용할 수 있다.
```c++
for(int i=0; i < v.size(); i++) cout << v[i] << endl; // 벡터의 모든 요소를 출력
```

+ ### vector의 원소 삭제

벡터에 저장된 원소를 삭제하는 함수로 **erase()** 가 있지만 해당 함수는 iterator와 함께 사용해야 한다. iterator는 후술

```c++
vector<int>::iterator it; // it은 정수 벡터의 원소를 가리키는 포인터
it = v.begin();           // it은 벡터 v의 첫 번째 원소를 가리킴, begin() : 벡터의 첫 번째 원소를 리턴
it = v.erase(it);         // 벡터 v의 첫 번째 원소를 삭제
```
erase(it)은 it이 가리키는 원소를 삭제하고 벡터의 원소들은 앞으로 한 자리씩 이동시킨다. 그리고 삭제된 원소의 다음 원소를 가리키는 포인터를 리턴하며 따라서
erase(it) 사용 후에는 반드시 it이 리턴 값으로 치환되어야 한다.
```c++
it = v.erase(it); // 삭제 후 erase()의 리턴 값으로 it 재설정
```

+ ### STL vector의 멤버 함수와 연산자 함수

  + **push_back(e)** : 벡터의 마지막에 e를 추가
  + **at(index)** : 벡터의 index 위치에 있는 원소에 대한 참조 리턴
  + **begin()** : 벡터의 첫 번째 원소에 대한 참조 리턴
  + **end()** : 벡터의 끝(마지막 원소 다음)을 가리키는 참조 리턴
  + **empty()** : 벡터가 비어 있으면 true를 리턴
  + **erase(iterator it)** : 벡터에서 it이 가리키는 원소를 삭제, 삭제 후 자동으로 원소 위치 조절
  + **insert(iterator it, e)** : 벡터 내 it 위치에 원소 e를 삽입
  + **size()** : 벡터에 존재하는 요소의 개수를 리턴
  + **operator[]()** : 지정된 원소에 대한 참조 리턴
  + **operator=()** : 해당 벡터를 다른 벡터에 치환(복사)


+ ## vector 컨테이너 활용

다음은 vector 클래스를 이용하여 정수 벡터를 사용하는 예시이다.

```c++
#include <iostream>
#include <vector>    // vector 클래스 사용
using namespace std;


int main(int argc, const char* argv[]) {

	vector<int> v;  // vector 클래스의 정수형 객체 선언

	for (int i = 0; i < 5; i++) {
		v.push_back(i);       // 벡터에 순서대로 i를 삽입
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	v[1] = 20;     // 벡터의 두 번째 원소에 20을 삽입
	v.at(2) = 30;  // 벡터의 세 번째 원소에 30을 삽입

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;
	cout << "v의 3번 째 원소의 값 : " << v.operator[](2) << endl; // 벡터의 세 번째 요소를 출력

	return 0;
}
```
실행 결과
```c++
0 1 2 3 4
0 20 30 3 4

v의 3번 째 원소의 값 : 30
```

+ ## 문자열을 저장하는 벡터

벡터를 이용하여 입력한 문자열 중 사전 상 가장 뒤에 나오는 문자열을 출력하는 프로그램
```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(int argc, const char* argv[]) {

	vector<string> sv;
	string name;

	cout << "세 개의 이름을 입력" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "번 째 이름 입력" << endl;
		getline(cin, name);  // name에 이름을 입력
		sv.push_back(name);  // name을 벡터에 저장
	}
	name = sv.at(0);   // name에 맨 처음 이름을 저장

	for (int i = 1; i < sv.size(); i++) { // 인덱스 0은 이미 저장하였으므로 1부터 시작
		if (name < sv[i]) // sv[i]에 저장된 이름이 name보다 사전에서 먼저 오는 경우
			name = sv[i]; // name에 sv[i]에 저장된 이름을 저장
	}
	cout << "사전에서 가장 뒤에 나오는 이름은 : " << name << endl;

	return 0;
}
```
실행 결과
```c++
세 개의 이름을 입력
1번 째 이름 입력
abc
2번 째 이름 입력
bcd
3번 째 이름 입력
def
사전에서 가장 뒤에 나오는 이름은 : def
```
문자는 순서대로 ASCII 코드 값이 증가하는 형태이므로 뒤의 순서의 문자가 ASCII 코드 값이 더 큼. 따라서 문자열 간 크기 비교는 ASCII 코드 값을 기준으로 한다는 점을 이용






