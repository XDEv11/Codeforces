//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	if (accumulate(v.begin(), v.end(), 0LL) > 0) return cout << n << '\n', []{}();

	vector<int> dp(n + 1, numeric_limits<int>::min());
	dp[0] = 0;
	for (int i{1}; i <= n; ++i) {
		long long s{0};
		int j{i};
		while (j >= 1) {
			s += v[j--];
			if (s > 0) dp[i] = max(dp[i], dp[j] + i - j);
			else if (s < 0) dp[i] = max(dp[i], dp[j] + j - i);
			else dp[i] = max(dp[i], dp[j]);	
		}
	}
	for (auto& x : dp) cout << x << ' ';
	cout << '\n';
	cout << dp[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
