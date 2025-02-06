#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mtx(n, vector<char>(m, '0'));

	for (int i{0}; i < n; i += 2) mtx[i][0] = mtx[i][m - 1] = '1';
	for (int j{2}; j < m - 2; j += 2) mtx[0][j] = mtx[n - 1][j] = '1';

	for (auto& vt : mtx) {
		for (auto& x : vt) cout << x;
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
