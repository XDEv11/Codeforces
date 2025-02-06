#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> vec(n);
		for (auto& a : vec)
			cin >> a;
		int begin = 0, end = n - 1;
		for (; begin < n && vec[begin] == begin + 1; ++begin) ;
		if (begin > end) {
			cout << 0 << endl;
			continue;
		}
		for (; vec[end] == end + 1; --end) ;

		bool flag = false;
		for (int i = begin; i <= end; ++i)
			if (vec[i] == i + 1)
				flag = true;
		cout << (flag ? 2 : 1) << endl;
	}
	return 0;
}
