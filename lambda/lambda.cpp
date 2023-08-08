#include <iostream>
using namespace std;
int main(){
	int N, M = 100;

	auto f = [&M](int x) -> int{
		cout << "hello world!" << endl;
		M = 999;
		return M;
	};

	cout << f(99) << endl;
	return 0;
}
