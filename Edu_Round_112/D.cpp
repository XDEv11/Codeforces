#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i{0}; i < n; ++i) {
		char x;
		cin >> x;
		v[i] = x - 'a';
	}

	vector<array<int, 6>> c(n);
	for (int i{0}; i < n; ++i) {
		c[i][0] = (v[i] == (0 + i % 3) % 3) ? 0 : 1; // abc
		c[i][1] = (v[i] == (1 + i % 3) % 3) ? 0 : 1; // bca
		c[i][2] = (v[i] == (2 + i % 3) % 3) ? 0 : 1; // cab
		c[i][3] = (v[i] == (2 - i % 3 + 3) % 3) ? 0 : 1; // cba
		c[i][4] = (v[i] == (1 - i % 3 + 3) % 3) ? 0 : 1; // bac
		c[i][5] = (v[i] == (0 - i % 3 + 3) % 3) ? 0 : 1; // acb
	}

	vector<array<int, 6>> ps(n + 1);
	for (int j{0}; j < 6; ++j) {
		ps[0][j] = 0;
		for (int i{1}; i <= n; ++i) ps[i][j] = ps[i - 1][j] + c[i - 1][j];
	}

	while (m--) {
		int l, r;
		cin >> l >> r;
		array<int, 6> res;
		for (int j{0}; j < 6; ++j) res[j] = ps[r][j] - ps[l - 1][j];
		cout << *min_element(res.begin(), res.end()) << '\n';
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
