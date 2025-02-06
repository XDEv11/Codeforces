//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<int> p0(n + 1), p2(n + 1);
	for (int i{1}, j{0}, k{0}; i <= n; ++i) {
		p0[i] = j, p2[i] = k;
		if (v[i] == 0) j = i;
		else if (v[i] == 2) k = i;
	}

	vector<int> dp(n + 1, n);
	dp[0] = 0;
	for (int i{1}; i <= n; ++i) dp[i] = dp[v[i] || p0[i] < p2[i] ? max(0, p0[i] - 1) : p0[i]] + 1;

	return cout << dp[n] << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
