//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;

	int n; ll x, y;
	if (!(cin >> n >> x >> y)) return false;

	vector<ll> dp(n + 1);
	for (int i{1}; i <= n; ++i) dp[i] = i * x;
	for (int i{1}; i <= n; ++i) {
		if (2 * i <= n) dp[2 * i] = min(dp[2 * i], dp[i] + y);
		if (2 * i + 1 <= n) dp[2 * i + 1] = min(dp[2 * i + 1], dp[i] + y + x);
		if (2 * i - 1 <= n) dp[2 * i - 1] = min(dp[2 * i - 1], dp[i] + y + x);
	}

	return cout << dp[n] << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
