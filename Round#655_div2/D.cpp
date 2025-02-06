#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> vec(n);
	int half = (n + 1) / 2;
	for (int i = 0; i < n; ++i)
		if (i % 2 == 0) cin >> vec[i/2];
		else cin >> vec[half + i/2];
	
	long long tmp = 0;
	for (int i = 0; i < half; ++i) // sum of [0:half-1]
		tmp += vec[i];
	auto ans = tmp;
	for (int i = 0; i < n; ++i) {
		tmp -= vec[i];
		tmp += vec[(i + half) % n];
		if (tmp > ans) ans = tmp;
	}
	cout << ans << endl;
	return 0;
}
