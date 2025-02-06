//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	ll ans{};
	vector<int> dp(n);
	for (int i{0}; i < n; ++i) {
		if (v[i] == '0') continue;
		dp[i] = (i + 1);
		if (i - 1 >= 0) dp[i] -= dp[i - 1];
		if (i - 2 >= 0) dp[i] -= dp[i - 2];
		ans += ll(dp[i]) * (n - i);
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
