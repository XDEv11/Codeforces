//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int c{count(v.begin(), v.end(), '1')}, ans{c * 11};

	int fi, la;
	for (int i{0}; i < n; ++i)
		if (v[i] == '1') la = i;
	for (int i{n - 1}; i >= 0; --i)
		if (v[i] == '1') fi = i;

	if (v.front() == '1' && v.back() == '1') ans -= 11;
	else if (v.front() == '1') {
		ans -= 1;
		if (n - 1 - la <= k) {
			if (la == 0) ans = 1;
			else ans -= 10;
		}
	} else if (v.back() == '1') {
		ans -= 10;
		if (fi <= k && fi != n - 1) ans -= 1;
	} else if (c) {
		bool taken{false};
		if (n - 1 - la <= k) taken = true, k -= n - 1 - la, ans -= 10;
		if ((fi != la || !taken) && fi <= k) k -= fi, ans -= 1;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
