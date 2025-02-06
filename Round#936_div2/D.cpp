//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	auto sg{[](int x, int y) {
		for (int b{29}; b >= 0; --b) {
			if ((x & (1 << b)) < (y & (1 << b))) return false;
		}
		return true;
	}};

	int ans{-1};
	for (int b{29}; b >= 1; --b) {
		if (!(m & (1 << b))) continue;
		int c{}, x{};
		for (int i{0}; i < n; ++i) {
			x ^= v[i];
			if (!(x & (1 << b)) && sg(m >> b, x >> b)) x = 0, ++c;
		}
		if (!x) ans = max(ans, c);
	}
	{
		int c{}, x{};
		for (int i{0}; i < n; ++i) {
			x ^= v[i];
			if (sg(m, x)) x = 0, ++c;
		}
		if (!x) ans = max(ans, c);
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
