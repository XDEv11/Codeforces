#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	int i{0};
	while (i < n && !(v[i] > 0)) ++i;

	bool flag{true};
	if (i == n) flag = false;
	else {
		for (int j{0}; j + 1 < i; ++j)
			if (abs(v[j] - v[j + 1]) < v[i]) flag = false;
	}

	cout << i + flag << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
