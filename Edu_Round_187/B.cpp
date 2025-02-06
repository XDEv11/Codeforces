//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		ll x;
		cin >> x;

		int ans{};
		array<int, 10> c{};
		while (x) {
			++ans;
			int t{x % 10}; x /= 10;
			++c[t - !x];
		}

		int s{8};
		ans -= c[0];
		for (int k{1}; k < 10; ++k) {
			int t{min(c[k], s / k)};
			ans -= t;
			s -= t * k;
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
