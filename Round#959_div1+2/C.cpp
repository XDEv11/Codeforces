//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int n; ll k;
		cin >> n >> k;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		vector<ll> dp(n + 2);
		ll s{};
		for (int i{n - 1}, j{n}; i >= 0; --i) {
			s += v[i];
			while (s > k) s -= v[--j];
			dp[i] = j - i + dp[j + 1];
		}

		ll ans{};
		for (auto& x : dp) ans += x;

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
