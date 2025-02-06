//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> m(n, vector<int>(n));

	vector<pair<int, int>> ans{};
	for (int k{n - 1}; k >= 0; --k) {
		ans.emplace_back(2, k + 1);
		for (int i{0}; i < n; ++i) m[i][k] = i + 1;
		ans.emplace_back(1, k + 1);
		for (int j{0}; j < n; ++j) m[k][j] = j + 1;
	}

	long long s{};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) s += m[i][j];

	cout << s << ' ' << (2 * n) << '\n';
	for (auto& [x, y] : ans) {
		cout << x << ' ' << y << ' ';
		for (int i{1}; i <= n; ++i) cout << i << " \n"[i == n];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
