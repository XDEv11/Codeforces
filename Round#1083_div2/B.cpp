//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	void solve() {
		int x;
		cin >> x;

		int ans{1};
		for (int d{2}; d * d <= x; ++d) {
			if (x % d) continue;
			while (x % d == 0) x /= d;
			ans *= d;
		}
		if (x > 1) ans *= x;

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
