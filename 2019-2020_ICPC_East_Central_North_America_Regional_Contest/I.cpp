//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace I {
	int n, m;
	vector<vector<char>> mtx{};
	vector<vector<char>> ans{};
	bool dfs(int i, int j, int t) {
		while (i < n && ans[i][j]) j == m - 1 ? ++i, j = 0 : ++j;
		if (i == n) return true;
		int k{0};
		for (int c{0}; i + k < n && j + k < m; ++k) {
			bool f{false};
			for (int ii{i}; ii <= i + k; ++ii) {
				if (ans[ii][j + k]) f = true;
				else if (mtx[ii][j + k] == '$') ++c;
			}
			for (int jj{j}; jj < j + k; ++jj) {
				if (ans[i + k][jj]) f = true;
				else if (mtx[i + k][jj] == '$') ++c;
			}
			if (f || c > 1) break;
			for (int ii{i}; ii <= i + k; ++ii) ans[ii][j + k] = (t >= 26 ? 'a' + t - 26 : 'A' + t);
			for (int jj{j}; jj < j + k; ++jj) ans[i + k][jj] = (t >= 26 ? 'a' + t - 26 : 'A' + t);
			if (!c) continue;
			if (dfs(i, j + k, t + 1)) return true;
		}
		for (int ii{i}; ii < i + k; ++ii)
			for (int jj{j}; jj < j + k; ++jj) ans[ii][jj] = '\0';
		return false;
	}
	bool solve() {
		if (!(cin >> n >> m)) return false;
		mtx.assign(n, vector<char>(m));
		for (auto& vt : mtx)
			for (auto& x : vt) cin >> x;
		
		ans.assign(n, vector<char>(m));
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < m; ++j) {
				if (mtx[i][j] == '#') ans[i][j] = '#';
			}
		if (!dfs(0, 0, 0)) return cout << "elgnatcer\n", true;
		for (auto& v : ans) {
			for (auto& x : v) cout << x;
			cout << '\n';
		}
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (I::solve()) ;
}
