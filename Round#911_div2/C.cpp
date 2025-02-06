//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace C {
	int n;
	vector<char> s{};
	vector<pair<int, int>> t{};
	int dfs(int v) {
		int d{n + 1};
		if (t[v].fi != -1) d = min(d, dfs(t[v].fi) + (s[v] != 'L'));
		if (t[v].se != -1) d = min(d, dfs(t[v].se) + (s[v] != 'R'));
		return d == n + 1 ? 0 : d;
	}
	void solve() {
		cin >> n;
		s.resize(n), t.resize(n);
		for (auto& x : s) cin >> x;
		for (auto& [x, y] : t) cin >> x >> y, --x, --y;

		cout << dfs(0) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) C::solve();
}
