//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(n, vector<char>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	if (g[0][0] == '1') return cout << "-1\n", []{}();

	cout << n * m << '\n';
	for (int i{n - 1}; i >= 0; --i)
		for (int j{m - 1}; j >= 0; --j) {
			if (g[i][j] == '1') {
				if (i >= 1) cout << i << ' ' << j + 1 << '\n';
				else cout << i + 1 << ' ' << j << '\n';
			} else cout << i + 1 << ' ' << j + 1 << '\n';
			cout << i + 1 << ' ' << j + 1 << '\n';
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
