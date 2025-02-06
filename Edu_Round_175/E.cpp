//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		ll ans{}, s{};
		int p{n + 1};
		vector<ll> dp(4 * n + 3);
		for (int i{0}; i < n; ++i) {
			dp[p] += 1, s += 1;
			if (v[i] == '0') {
				s += dp[--p];
			} else if (v[i] == '1') {
				s -= dp[p++];
				s -= dp[p++];
				s -= dp[p++];
			}

			ans += dp[p - 1] + s - dp[p] - dp[p + 1];
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
