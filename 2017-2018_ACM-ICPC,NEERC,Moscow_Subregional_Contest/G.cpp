//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<long long>> r(n, vector<long long>(m)), c{r};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) cin >> r[i][j] >> c[i][j];

	for (int i{0}; i + 1 < n; ++i)
		for (int j{0}; j < m; ++j) c[i][j] += r[i][j], r[i + 1][j] += r[i][j], c[i][(j + 1) % m] -= r[i][j], r[i][j] = 0;
	for (int j{0}; j + 1 < m; ++j) {
		for (int i{1}; i < n; ++i) c[i][j] -= c[0][j];
		for (int i{0}; i < n; ++i) c[i][j + 1] += c[0][j];
		c[0][j] = 0;
	}

	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			if (c[i][j] || r[i][j]) return cout << "No\n", []{}();
		}
	cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
