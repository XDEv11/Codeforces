//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

template<typename T>
using matrix = vector<vector<T>>;

bool solve() {
	int n, m, h;
	if (!(cin >> h >> n >> m)) return false;
	matrix<char> t1(h, vector<char>(n)), t2(h, vector<char>(m));
	for (auto& v : t1)
		for (auto& x : v) cin >> x;
	for (auto& v : t2)
		for (auto& x : v) cin >> x;

	vector<array<int, 3>> ans{};
	for (int i{0}; i < h; ++i) {
		if (!count(t1[i].begin(), t1[i].end(), '1') != !count(t2[i].begin(), t2[i].end(), '1')) return cout << "-1\n", true;
		for (int j{0}; j < n; ++j)
			for (int k{0}; k < m; ++k) {
				if (!(t1[i][j] == '1' && t2[i][k] == '1')) continue;
				ans.push_back({i, j, k});
			}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto& [x, y, z] : ans) cout << x << ' ' << y << ' ' << z << '\n';

	ans.clear();
	for (int i{0}; i < h; ++i) {
		int j{n - 1}, mj{j}, k{m - 1}, mk{k};
		while (true) {
			while (j >= 0 && t1[i][j] != '1') --j;
			while (k >= 0 && t2[i][k] != '1') --k;
			if (!(j >= 0 && k >= 0)) break;
			ans.push_back({i, j, k}), mj = min(mj, j--), mk = min(mk, k--);
		}
		while (true) {
			while (j >= 0 && t1[i][j] != '1') --j;
			while (k >= 0 && t2[i][k] != '1') --k;
			if (!(j >= 0 || k >= 0)) break;
			if (j >= 0) ans.push_back({i, j, mk}), --j;
			else ans.push_back({i, mj, k}), --k;
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto& [x, y, z] : ans) cout << x << ' ' << y << ' ' << z << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
