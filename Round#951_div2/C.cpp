//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll y{1};
		for (auto& x : v) y = lcm(y, x);

		ll z{};
		for (auto& x : v) z += y / x;

		if (z < y) {
			for (auto& x : v) cout << (y / x) << ' ';
			cout << '\n';
		} else cout << "-1\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
