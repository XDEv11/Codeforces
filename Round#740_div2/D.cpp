#include <iostream>
#include <vector>

using namespace std;

void solve() {
	long long n, m;
	cin >> n >> m;

	vector<long long> dp(n + 1), s(n + 2); // suffix sum
	s[n + 1] = 0, s[n] = dp[n] = 1;
	for (long long i{n - 1}; i >= 1; --i) {
		dp[i] = s[i + 1];
		for (long long z{2}; i * z <= n; ++z)
			dp[i] = (dp[i] + s[i * z] - s[min(n + 1, (i + 1) * z)]) % m;

		s[i] = (s[i + 1] + dp[i]) % m;
	}

	cout << dp[1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
