//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;
	vector<vector<char>> mtx(n, vector<char>(m));
	for (auto& vt : mtx)
		for (auto& x : vt) cin >> x;

	array<array<int, 2>, 3> p{};
	for (int i{0}, k{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			if (mtx[i][j] == '.') continue;
			p[k++] = {i, j};
		}

	auto ans{mtx};
	sort(p.begin(), p.end());
	for (int i{p[0][0]}; i <= p[1][0]; ++i) ans[i][p[0][1]] = '#';
	for (int i{p[1][0]}; i <= p[2][0]; ++i) ans[i][p[2][1]] = '#';
	for (int j{p[0][1]}; ; j += (p[0][1] < p[1][1] ? 1 : -1)) {
		ans[p[1][0]][j] = '#';
		if (j == p[1][1]) break;
	}
	for (int j{p[2][1]}; ; j += (p[2][1] < p[1][1] ? 1 : -1)) {
		ans[p[1][0]][j] = '#';
		if (j == p[1][1]) break;
	}

	for (auto& vt : ans) {
		for (auto& x : vt) cout << x;
		cout << '\n';
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
