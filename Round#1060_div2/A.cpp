//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int ans{0};
		for (int i{0}, j{-m}; i < n; ++i) {
			if (v[i] == '0') continue;
			ans += (i - j + 1 > m);
			j = i;
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
