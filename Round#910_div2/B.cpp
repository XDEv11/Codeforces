//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll ans{}, x{v[n - 1]};
	for (int i{n - 2}; i >= 0; --i) {
		ll k{(v[i] + x - 1) / x};
		ans += k - 1, x = v[i] / k;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
