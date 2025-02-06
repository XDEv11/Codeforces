//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <map>
#include <algorithm>

using namespace std;

bool solve() {
	int n, q;
	if (!(cin >> n >> q)) return false;
	vector<char> v(n);
	for (auto& e : v) cin >> e;

	vector<pair<int, int>> p0(n + 1), p1(n + 1);
	p0[0] = {0, 0};
	for (int i{0}, x{0}, y{0}; i < n; ++i) {
		switch (v[i]) {
			break; case 'U': ++y;
			break; case 'D': --y;
			break; case 'L': --x;
			break; case 'R': ++x;
		}
		p0[i + 1] = {x, y};
	}
	p1[0] = {0, 0};
	for (int i{0}, x{0}, y{0}; i < n; ++i) {
		switch (v[n - 1 - i]) {
			break; case 'U': ++y;
			break; case 'D': --y;
			break; case 'L': --x;
			break; case 'R': ++x;
		}
		p1[i + 1] = {x, y};
	}
	map<pair<int, int>, vector<int>> mp0{}, mp1{};
	for (int i{0}; i <= n; ++i) mp0[p0[i]].push_back(i), mp1[p1[i]].push_back(i);

	while (q--) {
		int x, y, l, r;
		cin >> x >> y >> l >> r;
		auto& v0{mp0[{x, y}]};
		if (!v0.empty() && (v0.front() < l || v0.back() >= r)) {
			cout << "YES\n";
			continue;
		}
		x -= p0[l - 1].fi, y -= p0[l - 1].se;
		x += p1[n - r].fi, y += p1[n - r].se;
		auto& v1{mp1[{x, y}]};
		bool f{false};
		int bsl{0}, bsr{v1.size() - 1};
		while (!f && bsl <= bsr) {
			int bsm{(bsl + bsr) / 2};
			if (v1[bsm] <= n - r) bsl = bsm + 1;
			else if (v1[bsm] > n - l + 1) bsr = bsm - 1;
			else f = true;
		}
		cout << (f ? "YES\n" : "NO\n");
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
