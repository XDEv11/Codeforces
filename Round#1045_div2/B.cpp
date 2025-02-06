//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll k;
		cin >> n >> k;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		for (auto& x : v) {
			ll t{x % (k + 1)};
			x += t * k;
		}

		for (auto& x : v) cout << x << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
