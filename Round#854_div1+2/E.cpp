//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mtx(n, vector<char>(m));
	for (auto& vt : mtx)
		for (auto& x : vt) cin >> x;

	auto fill = [&] {
		bool f{true};
		while (f) {
			f = false;
			for (int i{0}; i < n; ++i) {
				int u{m}, d{-1};
				for (int j{0}; j < m; ++j) {
					if (mtx[i][j] == '.') continue;
					u = min(u, j), d = max(d, j);
				}
				for (int j{u}; j <= d; ++j) {
					if (mtx[i][j] != '.') continue;
					mtx[i][j] = '#', f = true;
				}
			}
			for (int j{0}; j < m; ++j) {
				int l{n}, r{-1};
				for (int i{0}; i < n; ++i) {
					if (mtx[i][j] == '.') continue;
					l = min(l, i), r = max(r, i);
				}
				for (int i{l}; i <= r; ++i) {
					if (mtx[i][j] != '.') continue;
					mtx[i][j] = '#', f = true;
				}
			}
		}
	};

	fill();

	int i{0}, j{0};
	while (mtx[i][j] != '#') i == n - 1 ? (i = 0, ++j) : (++i);
	const array<array<int, 2>, 4> dir{0, 1, 1, 0, 0, -1, -1, 0};
	queue<pair<int, int>> qu{}; qu.emplace(i, j), mtx[i][j] = '@';
	while (!qu.empty()) {
		tie(i, j) = qu.front(), qu.pop();
		for (auto& [di, dj] : dir) {
			auto ni{i + di}, nj{j + dj};
			if (!(ni == clamp(ni, 0, n - 1) && nj == clamp(nj, 0, m - 1) && mtx[ni][nj] == '#')) continue;
			qu.emplace(ni, nj), mtx[ni][nj] = '@';
		}
	}
	int l1{n - 1}, r1{0}, u1{m - 1}, d1{0};
	int l2{n - 1}, r2{0}, u2{m - 1}, d2{0};
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j) {
			if (mtx[i][j] == '@') l1 = min(l1, i), r1 = max(r1, i), u1 = min(u1, j), d1 = max(d1, j);
			if (mtx[i][j] == '#') l2 = min(l2, i), r2 = max(r2, i), u2 = min(u2, j), d2 = max(d2, j);
		}
	if (l2 <= r2 && u2 <= d2) {
		int i1, j1, i2, j2;
		r1 < l2 ? (i1 = r1, i2 = l2) : (i1 = l1, i2 = r2);
		d1 < u2 ? (j1 = d1, j2 = u2) : (j1 = u1, j2 = d2);
		mtx[i1][j1] = 'S', mtx[i2][j2] = 'T';
		for (i = min(i1, i2); i <= max(i1, i2); ++i) mtx[i][j1] = 'x';
		for (j = min(j1, j2); j <= max(j1, j2); ++j) mtx[i2][j] = 'x';

		fill();
	}

	for (auto& vt : mtx) {
		for (auto& x : vt) cout << (x == '.' ? '.' : '#');
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
