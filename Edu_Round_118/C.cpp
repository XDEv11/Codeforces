#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	long long h;
	cin >> n >> h;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long l{0}, r{h};
	while (r - l > 1) {
		long long m{(l + r) / 2};

		long long d{m};
		for (int i{0}; i + 1 < n; ++i) d += min(v[i + 1] - v[i], m);
		if (d < h) l = m;
		else r = m;
	}

	cout << r << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
