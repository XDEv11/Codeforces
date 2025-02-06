#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

static constexpr long long mod{998244353};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<long long> dp1(n + 1, 0), dp2(n + 1, 0);
	for (int i{0}; i < n; ++i) {
		const auto& x{v[i]};
		dp1[x] = (dp1[x] + dp1[x]) % mod;
		if (x - 1 >= 0) dp1[x] = (dp1[x] + dp1[x - 1]) % mod;

		dp2[x] = (dp2[x] + dp2[x]) % mod;
		if (x - 2 >= 0) dp2[x] = (dp2[x] + dp1[x - 2]) % mod;
		if (x + 2 <= n) dp2[x + 2] = (dp2[x + 2] + dp2[x + 2]) % mod;

		if (v[i] == 0) dp1[0] += 1;
		else if (v[i] == 1) dp2[1] += 1;
	}

	long long ans{0};
	for (auto& x : dp1) ans = (ans + x) % mod;
	for (auto& x : dp2) ans = (ans + x) % mod;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
