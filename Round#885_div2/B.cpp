//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> v(k);
	for (int i{0}; i < n; ++i) {
		int c;
		cin >> c, --c;
		v[c].push_back(i);
	}

	int ans{n};
	for (int i{0}; i < k; ++i) {
		if (v[i].empty()) continue;
		vector<int> tmp{};
		tmp.push_back(v[i].front());
		tmp.push_back(n - 1 - v[i].back());
		for (int j{0}; j + 1 < v[i].size(); ++j) tmp.push_back(v[i][j + 1] - (v[i][j] + 1));
		sort(tmp.rbegin(), tmp.rend());
		ans = min(ans, max(tmp[0] / 2, tmp[1]));
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
