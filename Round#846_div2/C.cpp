//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n), t(m);
	for (auto& x : v) cin >> x;
	for (auto& x : t) cin >> x;

	vector<int> cnt(n + 1);
	for (auto& x : v) ++cnt[x];

	vector<int> g{};
	for (auto& x : cnt) {
		if (x) g.push_back(x);
	}

	int ans{0};
	vector<vector<int>> dp(t.size(), vector<int>(g.size()));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
