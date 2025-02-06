//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> dp(n, 1), pmx(n, 1);
	for (int i{1}; i < n; ++i) {
		for (int j{i - 1}; j >= 0 && (i >> 8) == (j >> 8); --j) {
			if ((v[j] ^ i) < (v[i] ^ j)) dp[i] = max(dp[i], dp[j] + 1);
		}
		pmx[i] = max(pmx[i - 1], dp[i]);
	}
	cout << pmx[n - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
