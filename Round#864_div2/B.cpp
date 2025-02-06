//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> mtx(n, vector<int>(n));
	for (auto& vt : mtx)
		for (auto& x : vt) cin >> x;

	int cnt{0};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) cnt += (mtx[i][j] != mtx[n - 1 - i][n - 1 - j]);
	cnt /= 2;

	cout << (cnt <= k && (!((k - cnt) & 1) || (n & 1)) ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
