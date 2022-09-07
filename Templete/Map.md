# map 컨테이너

> map은 **키**와 **값**이 쌍으로 존재하는 원소를 저장하고 이 '키'에 해당하는 값을 검색하는 제네릭 컨테이너이다. 키나 값의 타입은 기본 타입과 클래스 타입 모두 가능하지만
> 동일한 키를 가지는 원소가 중복될 경우 에러가 발생한다. map 컨테이너를 사용하기 위해서는 <map> 헤더파일과 using 지시어가 필요하다.
   
  
#
  
### map 컨테이너의 멤버 함수와 연산자 함수

  
> + **insert(pair<> &element)** : 맵에 '키'와 '값'으로 구성된 pair 객체에 element를 삽입
> + **at(key_type& key)** : 맵에서 '키'에 해당하는 '값'을 리턴
> + **begin()** : 맵의 첫 번째 원소에 대한 참조 리턴
> + **end()** : 맵의 끝(마지막 원소 다음)을 가리키는 참조 리턴
> + **empty()** : 맵이 비어있으면 true를 리턴
> + **find(key_type& key)** : 맵에서 '키'에 해당하는 원소를 가리키는 iterator를 리턴
> + **erase(iterator it)** : 맵에서 it이 가리키는 원소를 삭제
> + **size()** : 맵에 들어 있는 원소의 개수를 리턴
> + **operator[ key_type& key ]()** : 맵에서 '키'에 해당하는 '값'을 리턴
> + **operator=()** : 맵 치환(복사)
  

  
+ map 컨테이너 생성 및 원소 삽입
  
```c++
  map<string, string> dic; // string 타입의 키와 값의 원소 쌍을 저장할 map 컨테이너 dic 생성
  
  dic.insert(make_pair("love", "사랑")); // ("love", "사랑") 저장, "love"라는 키를 검색 시 "사랑" 리턴
  dic["love"] = "사랑";                  // ("love", "사랑") 저장  "love"라는 키를 검색 시 "사랑" 리턴
```
  
+ '키'로 검색하여 '값' 알아내기
```c++
  string kor = dic["love"]; // kor은 "사랑" 을 저장
  
  string kor = dic.at("love");
  
  if(dic.find(eng) == dic.end()) // eng의 '키'를 찾을 수 없다면 조건문은 true를 리턴
```
  
  [] 연산자는 키에 해당하는 값을 찾을 수 없는 경우 빈 문자열 " "을 리턴한다. at 함수를 이용하여 검색할 수도 있지만 at는 값을 찾을 수 없는 경우 예외를 발생시킨다.
  
  
+ ### map을 이용하여 영한 사전 만들기
  

```c++
  #include <iostream>
#include <map>
#include <string>
using namespace std;


int main(int argc, const char* argv[]) {

	map<string, string> dic; // map 컨테이너 dic 생성

	// map 컨테이너에 키와 키에 해당하는 값을 저장
	dic.insert(make_pair("love", "사랑"));
	dic.insert(make_pair("happy", "행복"));
	dic["Dark knight"] = "암흑 기사";

	cout << "저장된 단어의 개수 : " << dic.size() << endl;

	string eng;    // 문자열을 입력받을 변수 eng 생성(키)
	while (true) {
		cout << "찾고 싶은 단어 : ";
		getline(cin, eng);
		if (eng == "exit") break; // exit를 입력받을 때 까지 단어 검색 반복
		
		if (dic.find(eng) == dic.end()) // 검색한 단어를 찾을 수 없음
			cout << "없음" << endl;

		else cout << dic[eng] << endl;  // eng(키)에 해당하는 값을 출력
	}

	cout << "종료" << endl;

	return 0;
}
```
실행 결과
```c++
저장된 단어의 개수 : 3
찾고 싶은 단어 : love
사랑
찾고 싶은 단어 : happy
행복
찾고 싶은 단어 : Dark knight
암흑 기사
찾고 싶은 단어 : as
없음
찾고 싶은 단어 : d
없음
찾고 싶은 단어 : exit
종료
```

  
  
  
  
