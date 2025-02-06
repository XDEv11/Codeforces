//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	int cnt{0};
	vector<vector<bool>> b(n, vector<bool>(m, true));
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			if (g[i][j] == 1) b[i][j] = false;
			if (i - 1 >= 0 && g[i - 1][j] < g[i][j]) b[i][j] = false;
			if (i + 1 < n && g[i + 1][j] < g[i][j]) b[i][j] = false;
			if (j - 1 >= 0 && g[i][j - 1] < g[i][j]) b[i][j] = false;
			if (j + 1 < m && g[i][j + 1] < g[i][j]) b[i][j] = false;
			cnt += b[i][j];
		}
	if (!cnt) return cout << "0\n", []{}();

	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			if (!b[i][j]) continue;
			auto calc{[&](int i, int j) {
				cnt -= b[i][j];
				b[i][j] = true;
				if (g[i][j] == 1) b[i][j] = false;
				if (i - 1 >= 0 && g[i - 1][j] < g[i][j]) b[i][j] = false;
				if (i + 1 < n && g[i + 1][j] < g[i][j]) b[i][j] = false;
				if (j - 1 >= 0 && g[i][j - 1] < g[i][j]) b[i][j] = false;
				if (j + 1 < m && g[i][j + 1] < g[i][j]) b[i][j] = false;
				cnt += b[i][j];
			}};
			auto update{[&](int i, int j) {
				calc(i, j);
				if (i - 1 >= 0) calc(i - 1, j);
				if (i + 1 < n) calc(i + 1, j);
				if (j - 1 >= 0) calc(i, j - 1);
				if (j + 1 < m) calc(i, j + 1);
			}};
			int ans{0};
			vector<int> ci{}, cj{};
			ci.push_back(i), cj.push_back(j);
			if (i - 1 >= 0) ci.push_back(i - 1), cj.push_back(j);
			if (i + 1 < n) ci.push_back(i + 1), cj.push_back(j);
			if (j - 1 >= 0) ci.push_back(i), cj.push_back(j - 1);
			if (j + 1 < m) ci.push_back(i), cj.push_back(j + 1);
			for (int k{0}; k < ci.size(); ++k)
				for (int ii{0}; ii < n; ++ii)
					for (int jj{0}; jj < m; ++jj) {
						bool f{false};
						for (int k2{0}; k2 <= k; ++k2)
							if (ii == ci[k2] && jj == cj[k2]) f = true;
						if (f) continue;

						swap(g[ii][jj], g[ci[k]][cj[k]]);
						update(ii, jj);
						update(ci[k], cj[k]);
						if (!cnt) ++ans;
						swap(g[ii][jj], g[ci[k]][cj[k]]);
						update(ii, jj);
						update(ci[k], cj[k]);
					}
			if (!ans) cout << "2\n";
			else cout << "1 " << ans << '\n';
			return ;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
