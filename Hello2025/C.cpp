//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		ll l, r;
		cin >> l >> r;

		int k{29};
		while ((l >> k) == (r >> k)) --k;

		ll a{r & ~((1 << k) - 1)}, b{a - 1}, c{(l != b ? l : l + 2)};

		cout << a << ' ' << b << ' ' << c << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
