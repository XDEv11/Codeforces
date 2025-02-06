//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	const array<array<int, 2>, 4> dir{1, 0, 0, 1, -1, 0, 0, -1};
	void solve() {
		int n, m;
		cin >> n >> m;
		matrix<int> g(n, vector<int>(m));
		for (auto& v : g)
			for (auto& x : v) cin >> x;

		vector<int> cnt(n * m + 1);
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < m; ++j) {
				auto& c{g[i][j]};
				cnt[c] = max(cnt[c], 1);
				for (auto& [di, dj] : dir) {
					int ni{i + di}, nj{j + dj};
					if (clamp(ni, 0, n - 1) != ni || clamp(nj, 0, m - 1) != nj) continue;
					if (g[ni][nj] == c) cnt[c] = 2;
				}
			}

		int ans{}, mx{};
		for (auto& x : cnt) ans += x, mx = max(mx, x);
		ans -= mx;

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
