#include<iostream>
using namespace std;;

int main(int argc, char const* argv[]) {
	int a;
	a = 10;
	cout << a << endl;
	a += 10;
	cout << a << endl;
	a += a += a;
	cout << a << endl;

	return 0;
}
