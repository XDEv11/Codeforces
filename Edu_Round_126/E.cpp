//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <iterator>

using namespace std;

const array<array<int, 2>, 4> dir{1, 0, 0, 1, -1, 0, 0, -1};

void solve() {
	int n;
	cin >> n;
	vector<array<int, 3>> g(n);
	for (int j{0}; j < 3; ++j)
		for (int i{0}; i < n; ++i) {
			char c;
			cin >> c;
			g[i][j] = c == '1';
		}

	int lb{2};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < 3; ++j) {
			if (g[i][j] != 1) continue;
			queue<pair<int, int>> qu{};
			g[i][j] = lb, qu.emplace(i, j);
			while (!qu.empty()) {
				auto [x, y]{qu.front()}; qu.pop();
				for (auto& [dx, dy] : dir) {
					auto nx{x + dx}, ny{y + dy};
					if (!(0 <= nx && nx < n && 0 <= ny && ny < 3)) continue;
					if (g[nx][ny] != 1) continue;
					g[nx][ny] = lb, qu.emplace(nx, ny);
				}
			}
			++lb;
		}

	vector<int> L(lb - 2), R(lb - 2);
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < 3; ++j)
			if (g[i][j]) R[g[i][j] - 2] = i;
	for (int i{n - 1}; i >= 0; --i)
		for (int j{0}; j < 3; ++j)
			if (g[i][j]) L[g[i][j] - 2] = i;

	sort(L.begin(), L.end());
	sort(R.begin(), R.end());

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;
	
		auto c1{distance(R.begin(), lower_bound(R.begin(), R.end(), l))};
		auto c2{distance(upper_bound(L.begin(), L.end(), r), L.end())};
		cout << lb - 2 - c1 - c2 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
