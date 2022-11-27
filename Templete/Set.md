# set 컨테이너

  set은 연관 컨테이너(Associative container)중 하나로, 연관 컨테이너는 데이터와 그 데이터의 정보가 함께 묶여있으며, 정렬과 관련이 있다. 
  따라서 연관 컨테이너에는 관계 연산자가 기본적으로 내포되어 있다. 그 중 set은 데이터와 그 순서만 내부적으로 관리하며, 기본적으로 삽입된 값들을 오름차순으로 정렬하는 기능을 갖고 있다. set에서의 원소는 모두 key라고 불리며,
일반 set에서는 key의 중복이 불가능하지만, multiset은 가능하다.
  
  
  #
  
  
  ### 주요 멤버 함수
  
  ![image](https://user-images.githubusercontent.com/101240036/204145197-f4c7c67b-e5c5-43b1-8d6c-3c2bcdd9417a.png)


다음은 set 컨테이너를 활용한 예이다.

```c++
#include <iostream>
#include <set>

using namespace std;

int main(int argc, const char* argv[]) {

	set<string> s;
	set<string>::iterator it;
	set<string>::iterator it2;
	string word;

	cout << "사전에 저장할 영단어를 입력하시오" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> word;
		s.insert(word);
	}

	cout << "저장 완료" << endl;
	int num;

	while (1) {
		int count = 1;
		cout << "(1) 검색" << endl << "(2) 종료" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "검색할 단어를 입력하시오" << endl;
			cin >> word;
			it = s.find(word);
			it2 = s.begin();
			if (it != s.end()) {
				while (1) {
					if (it == it2) {
						cout << word << "는 " << count << "번 째에 있습니다" << endl;
						break;
					}
					else {
						count++;
						it2++;
					}
				}
				continue;
			}
			else {
				cout << word << "는 존재하지 않습니다" << endl;
				continue;
			}
		case 2:
			break;

		default:
			break;
		}
		break;
	}

	return 0;
}

```

#

### REFERENCE
https://blog.naver.com/PostView.nhn?blogId=pkjhj485&logNo=221339918113
