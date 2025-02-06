//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	int ask(int l, int r) {
		cout << "? " << (l + 1) << " " << (r + 1) << endl;
		return cin >> l, l;
	}
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> v(m);
		for (auto& [x, y] : v) cin >> x >> y, --x, --y;

		vector<pair<int, int>> t{};
		sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
			if (a.fi != b.fi) return a.fi < b.fi;
			else return a.se > b.se;
		});
		for (int i{0}, j{-1}; i < m; ++i) {
			if (j != -1 && v[i].se <= v[j].se) continue;
			t.push_back(v[i]);
			j = i;
		}

		bool f{ask(0, n / 2 - 1)};

		int ans{};
		for (auto& [x, y] : t) {
			if ((f && n / 2 <= x) || (!f && y < n / 2)) continue;
			ans = max(ans, ask(x, y));
		}
		cout << "! " << ans << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
