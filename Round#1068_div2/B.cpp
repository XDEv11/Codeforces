//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		ll mx{}, mn{};
		for (int i{0}; i < n; ++i) {
			ll nx{max(mx - a[i], b[i] - mn)};
			ll nn{min(mn - a[i], b[i] - mx)};
			mx = nx, mn = nn;
		}

		cout << mx << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
