//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, m, k;
		cin >> n >> m >> k;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int ans{};
		for (int i{0}, c{0}; i < n; ++i) {
			c = (v[i] == '0' ? c + 1 : 0);
			if (c == m) ++ans, c = 0, i += k - 1;
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
