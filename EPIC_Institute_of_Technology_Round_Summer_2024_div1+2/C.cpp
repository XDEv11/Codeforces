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
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll ans{v[n - 1]};
		for (int i{n - 2}; i >= 0; --i) ans = max(ans + 1, v[i]);

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
