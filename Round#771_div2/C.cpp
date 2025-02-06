//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#define fi first
#define se second

using namespace std;

// fast disjoint set union
class DSU {
	vector<int> p, sz;
public:
	explicit DSU(int n) : p(n, -1), sz(n, 1) {}
	int find(int x) { // collapsing find
		return p[x] == -1 ? x : p[x] = find(p[x]);
	}
	void unionn(int x, int y) { // weighted union
		auto rx{find(x)}, ry{find(y)};
		if (rx == ry) return ;
		if (sz[rx] < sz[ry]) swap(rx, ry);
		p[ry] = rx, sz[rx] += sz[ry];
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	DSU dsu{n};

	set<int> s{v[0]};
	for (int i{1}; i < n; ++i) {
		int mx{max(*s.rbegin(), v[i])};
		auto it{s.upper_bound(v[i])};
		while (it != s.end()) {
			dsu.unionn(mx, *it);
			auto it2{next(it)}; s.erase(it), it = it2;
		}
		dsu.unionn(mx, v[i]);
		s.insert(mx);
	}

	int ans{0};
	for (int v{0}; v < n; ++v) ans += (dsu.find(v) == v);
	cout << ans << '\n';
}

void solve2() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	vector<pair<int, int>> s{};
	for (int i{0}; i < n; ++i) {
		s.emplace_back(v[i], v[i]);
		while (s.size() >= 2 && s[s.size() - 2].se > s[s.size() - 1].fi) {
			s[s.size() - 2].fi = min(s[s.size() - 2].fi, s[s.size() - 1].fi);
			s[s.size() - 2].se = max(s[s.size() - 2].se, s[s.size() - 1].se);
			s.pop_back();
		}
	}

	cout << s.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();

	return 0;
}
