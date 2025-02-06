#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int cnt{count(v.begin(), v.end(), '2')};
	if (cnt == 1 || cnt == 2) return cout << "NO\n"s, []{}();

	vector<vector<char>> ans(n, vector<char>(n, 'X'));
	for (int i{0}; i < n; ++i) {
		if (v[i] == '1') {
			for (int j{0}; j < n; ++j) {
				if (j == i) continue;
				ans[i][j] = ans[j][i] = '=';
			}
		} else {
			int j{(i + 1) % n};
			while (v[j] != '2') j = (j + 1) % n;
			ans[i][j] = '+', ans[j][i] = '-';
		}
	}

	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			if (i == j) continue;
			if (ans[i][j] == 'X') ans[i][j] = '+', ans[j][i] = '-';
		}

	cout << "YES\n"s;
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < n; ++j) cout << ans[i][j];
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
