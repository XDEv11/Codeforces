//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <numeric>
#include <map>
#include <algorithm>

using namespace std;

// fast disjoint set union
class DSU {
    vector<int> pa, sz, mx;
public:
    explicit DSU(int n) : pa(n, -1), sz(n, 1), mx(n) { iota(mx.begin(), mx.end(), 0); }
    int find(int x) { // collapsing find
        return pa[x] == -1 ? x : pa[x] = find(pa[x]);
    }
    void unionn(int x, int y) { // weighted union
        auto rx{find(x)}, ry{find(y)};
        if (rx == ry) return ;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        pa[ry] = rx, sz[rx] += sz[ry], mx[rx] = max(mx[rx], mx[ry]);
    }
    int maxx(int x) {
        return mx[find(x)];
    }
};

void solve() {
	int n, m, _k;
	cin >> n >> m >> _k;
	vector<pair<int, int>> a(m);
	for (auto& [l, r] : a) cin >> l >> r, --l, --r;

	vector<vector<int>> cnt(n);
	DSU dsu{n + 1};
	for (int j{0}; j < m; ++j) {
		auto& [l, r]{a[j]};
		for (int i{dsu.maxx(l)}; i <= r; i = dsu.maxx(i + 1)) {
			cnt[i].push_back(j);
			if (cnt[i].size() > 2) dsu.unionn(i, i + 1);
		}
	}

	int ans0{};
	map<int, int> mp1{};
	map<pair<int, int>, int> mp2{};
	for (int i{dsu.maxx(0)}; i < n; i = dsu.maxx(i + 1)) {
		if (cnt[i].size() == 0) ++ans0;
		else if (cnt[i].size() == 1) {
			++mp1[cnt[i][0]];
		} else if (cnt[i].size() == 2) {
			if (cnt[i][0] > cnt[i][1]) swap(cnt[i][0], cnt[i][1]);
			++mp2[{cnt[i][0], cnt[i][1]}];
		}
	}

	int mx1{}, mx2{};
	for (auto& [k, v] : mp1) {
		if (v > mx1) mx2 = mx1, mx1 = v;
		else if (v > mx2) mx2 = v;
	}
	int ans1{mx1 + mx2};
	for (auto& [k, v] : mp2) {
		ans1 = max(ans1, v + mp1[k.fi] + mp1[k.se]);
	}

	cout << (ans0 + ans1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
