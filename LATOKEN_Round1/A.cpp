#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> t(n, vector<char>(m));
	for (auto& v : t)
		for (auto& x : v) cin >> x;

	bool ans{true};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j)
			if ((i & 1) ^ (j & 1)) {
				if (t[i][j] == 'R') ans = false;
			} else {
				if (t[i][j] == 'W') ans = false;
			}
	if (ans) {
		cout << "YES\n"s;
		for (int i{0}; i < n; ++i) {
			for (int j{0}; j < m; ++j)
				if ((i & 1) ^ (j & 1)) cout << 'W';
				else cout << 'R';
			cout << '\n';
		}
		return ;
	}

	ans = true;
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j)
			if ((i & 1) ^ (j & 1)) {
				if (t[i][j] == 'W') ans = false;
			} else {
				if (t[i][j] == 'R') ans = false;
			}
	if (ans) {
		cout << "YES\n"s;
		for (int i{0}; i < n; ++i) {
			for (int j{0}; j < m; ++j)
				if ((i & 1) ^ (j & 1)) cout << 'R';
				else cout << 'W';
			cout << '\n';
		}
		return ;
	}

	cout << "NO\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
