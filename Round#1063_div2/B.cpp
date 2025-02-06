//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n + 1);
		for (int i{1}; i <= n; ++i) cin >> v[i];
		vector<char> r(n + 1);
		for (int i{1}; i <= n; ++i) cin >> r[i];

		vector<int> p(n + 1);
		for (int i{1}; i <= n; ++i) p[v[i]] = i;
		if (r[1] == '1' || r[n] == '1' || r[p[1]] == '1' || r[p[n]] == '1') return cout << "-1\n", []{}();

		vector<pair<int, int>> ans{};
		ans.emplace_back(min(p[1], p[n]), max(p[1], p[n]));
		ans.emplace_back(1, p[1]);
		ans.emplace_back(1, p[n]);
		ans.emplace_back(p[1], n);
		ans.emplace_back(p[n], n);

		cout << ans.size() << '\n';
		for (auto& [x, y] : ans) cout << x << ' ' << y << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
