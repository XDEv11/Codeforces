//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int d{k - (n - 1 + m - 1)};
	if (d < 0 || d & 1) return cout << "NO\n", []{}();

	vector<vector<char>> hans(n, vector<char>(m - 1, 'R')), vans(n - 1, vector<char>(m, 'R'));
	for (int j{1}; j < m - 1; j += 2) hans[0][j] = 'B';
	for (int i{m & 1}; i < n - 1; i += 2) vans[i][m - 1] = 'B';
	hans[1][0] = hans[1][1] = 'B';

	cout << "YES\n";
	for (auto& vt : hans) {
		for (auto& x : vt) cout << x << ' ';
		cout << '\n';
	}
	for (auto& vt : vans) {
		for (auto& x : vt) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
