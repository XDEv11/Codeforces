#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> left(n+1, vector<int> (m+1)); // [n][m]
	vector<vector<int>> right(n+1, vector<int> (m+1));
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		while (k--) {
			int l, r;
			cin >> l >> r;
			for (int j = l; j <= r; ++j) {
				left[i][j] = l;
				right[i][j] = r;
			}
		}
	}
	
	vector<vector<int>> dp(m+2, vector<int> (m+2, 0));
	for (int l = m; l >= 1; --l)
		for (int r = l; r <= m; ++r) {
			for (int k = l; k <= r; ++k) {
				int fully = 0;
				for (int i = 1; i <= n; ++i)
					if (left[i][k] >= l && right[i][k] <= r) ++fully;
				dp[l][r] = max(dp[l][r], dp[l][k-1] + fully * fully + dp[k+1][r]);
			}
		}
	cout << dp[1][m] << endl;
	return 0;
}
