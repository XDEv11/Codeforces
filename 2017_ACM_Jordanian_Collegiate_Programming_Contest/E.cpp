//#pragma GCC optimize ("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve(ifstream& fin) {
	const array<array<int, 2>, 4> dir{-1, 0, 0, 1, 1, 0, 0, -1};

	int n, m, q;
	fin >> n >> m >> q;
	int x, y, d;
	fin >> x >> y, --x, --y;
	{
		char t;
		fin >> t;
		switch (t) {
			break; case 'U': d = 0;
			break; case 'R': d = 1;
			break; case 'D': d = 2;
			break; case 'L': d = 3;
		}
	}
	vector<vector<char>> g(n, vector<char>(m));
	for (auto& v : g)
		for (auto& e : v) fin >> e;
	vector<pair<char, int>> ins(q);
	for (auto& [t, e] : ins) {
		fin >> t;
		if (t == 'F') fin >> e;
	}

	int ans{};
	bool f{true};
	int c{0};
	for (int i{0}; i < q; ) {
		auto& [t, e]{ins[i]};
		if (t == 'R') {
			int j{i + 1};
			while (j < q && ins[j].fi == 'R') ++j;
			int d1{d};
			while (true) {
				int nx{x + dir[d1][0]}, ny{y + dir[d1][1]};
				if (g[nx][ny] == '.') break;
				d1 = (d1 + 1) % 4;
			}
			int d2{(d + j - i) % 4};
			while (true) {
				int nx{x + dir[d2][0]}, ny{y + dir[d2][1]};
				if (g[nx][ny] == '.') break;
				d2 = (d2 + 1) % 4;
			}
			if (d1 != d2) {
				while (true) {
					int nd{(d2 - 1 + 4) % 4}, nx{x + dir[nd][0]}, ny{y + dir[nd][1]};
					if (g[nx][ny] == '.') break;
					d2 = nd;
				}
				f = true, c = (d2 - d + 4) % 4, d = d2;
			}
			i = j;
		} else if (t == 'F') {
			while (e--) {
				int nx, ny;
				while (true) {
					nx = x + dir[d][0], ny = y + dir[d][1];
					if (g[nx][ny] == '.') break;
					d = (d + 1) % 4;
				}
				x = nx, y = ny;
			}
			if (f) ans += c + 1, f = false, c = 0;
			++i;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin{"reduce.in"};
	
	int t{1};
	fin >> t;
	while (t--) solve(fin);
}
