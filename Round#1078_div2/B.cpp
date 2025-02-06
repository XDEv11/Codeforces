//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int n; ll a, b;
		cin >> n >> a >> b;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll ans{}, s{};
		for (auto& x : v) s += x / a * b;
		for (auto& x : v) ans = max(ans, x + s - x / a * b);

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
