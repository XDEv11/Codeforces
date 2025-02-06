#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int m;
	cin >> m;
	vector<vector<int>> mtx(2, vector<int>(m + 1));
	for (int i{0}; i < 2; ++i)
		for (int j{1}; j <= m; ++j) cin >> mtx[i][j];

	vector<vector<int>> ps(2, vector<int>(m + 1));
	for (int i{0}; i < 2; ++i) {
		ps[i][0] = 0;
		for (int j{1}; j <= m; ++j) ps[i][j] = ps[i][j - 1] + mtx[i][j];
	}

	int ans{numeric_limits<int>::max()};
	for (int j{1}; j <= m; ++j) {
		int sum{max(ps[0][m] - ps[0][j], ps[1][j - 1])};
		ans = min(ans, sum);
	}

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
