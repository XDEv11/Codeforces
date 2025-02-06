//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool read(int& d, vector<pair<int, bool>>& v) {
	string s;
	cin >> s;
	if (s == "AC"s || s == "F"s) return false;
	cin >> d;
	v.resize(d);
	for (auto& [di, bi] : v) cin >> di >> bi;
	return true;
}

void write(int i) {
	cout << i + 1 << endl;
}

void solve() {
	int n, m, s, c;
	cin >> n >> m >> s >> c;

	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v), adj[v].push_back(u);
	}

	int d, lastd{-1};
	vector<pair<int, bool>> v{};
	while (read(d, v)) {
		bool f{false};

		if (!f) {
			int cnt{0};
			for (int i{0}; i < v.size(); ++i)
				if (!(v[i].fi == 1 && v[i].se)) ++cnt;
			if (cnt == 1) {
				for (int i{0}; i < v.size(); ++i)
					if (!(v[i].fi == 1 && v[i].se)) write(i), f = true;
			}
		}

		if (!f) {
			for (int i{0}; i < v.size(); ++i)
				if (!v[i].se) {
					write(i), f = true;
					break;
				}
		}

		if (!f) {
			int cnt{0};
			for (int i{0}; i < v.size(); ++i) cnt += (v[i].fi == lastd);
			if (cnt <= 3) {
				for (int i{0}; i < v.size(); ++i)
					if (v[i].fi == lastd) v[i].fi = 2;
			}

			int mx{0}, mxi{0}, mx2{0}, mx2i{0};
			for (int i{0}; i < v.size(); ++i) {
				if (v[i].fi > mx) mx2 = mx, mx2i = mxi, mx = v[i].fi, mxi = i;
				else if (v[i].fi > mx2) mx2 = v[i].fi, mx2i = i;
			}
			write(mxi), f = true;
		}

		lastd = d;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
