//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve1() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<int> dp0(n + 1), dp1(n + 1), lst(n + 1, -1);
	for (int i{1}; i <= n; ++i) {
		dp0[i] = dp0[i - 1];
		int j{lst[v[i]]};
		if (j != -1) dp0[i] = max(dp0[i], dp1[i] = max(dp0[j - 1] + i + 1 - j, dp1[j] + i - j));
		lst[v[i]] = i;
	}

	cout << dp0[n] << '\n';
}

void solve2() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<int> dp(n + 1), mn(n + 1, n);
	for (int i{1}; i <= n; ++i) {
		dp[i] = min(dp[i - 1] + 1, mn[v[i]]);
		mn[v[i]] = min(mn[v[i]], dp[i - 1]);
	}

	cout << n - dp[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();
}
