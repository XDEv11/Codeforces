#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mtx(n, vector<char>(m));
	for (auto& vt : mtx)
		for (auto& x : vt) cin >> x;

	vector<int> ps(m, 0);
	for (int i{1}; i < n; ++i)
		for (int j{1}; j < m; ++j) ps[j] += (mtx[i - 1][j] != '.') && (mtx[i][j - 1] != '.');
	for (int j{1}; j < m; ++j) ps[j] += ps[j - 1];

	int q;
	cin >> q;
	while (q--) {
		int x1, x2;
		cin >> x1 >> x2, --x1, --x2;

		cout << (ps[x2] - ps[x1] ? "NO\n" : "YES\n");
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
