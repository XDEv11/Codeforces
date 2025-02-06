//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	using pii = pair<int, int>;
	int ask(int l, int r) {
		cout << "? " << (l + 1) << " " << (r + 1) << endl;
		return cin >> l, l;
	}
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<pii> v(m);
		for (auto& [x, y] : v) cin >> x >> y, --x, --y;

		vector<pii> t{};
		sort(v.begin(), v.end(), [](pii a, pii b) {
			if (a.fi != b.fi) return a.fi < b.fi;
			else return a.se > b.se;
		});
		for (int i{0}, j{-1}; i < m; ++i) {
			if (j != -1 && v[j].se >= v[i].se) continue;
			t.push_back(v[j = i]);
		}

		int l{0}, r{t.size()};
		while (r - l > 1) {
			int md{(l + r) / 2};
			(ask(0, t[md - 1].se) >= ask(t[md].fi, n - 1) ? r : l) = md;
		}

		int ans{ask(t[l].fi, t[l].se)};
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
