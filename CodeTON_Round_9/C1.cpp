//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int x; ll m;
		cin >> x >> m;

		int ans{};
		for (int y{1}; y <= min(ll(x) << 1, m); ++y) {
			if (x == y) continue;
			int t{x ^ y};
			ans += (x % t == 0 || y % t == 0);
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
