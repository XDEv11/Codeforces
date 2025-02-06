//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <algorithm>

using namespace std;

// fast disjoint set union
class DSU {
    vector<int> pa, sz;
public:
    explicit DSU(int n) : pa(n, -1), sz(n, 1) {}
    int find(int x) { // collapsing find
        return pa[x] == -1 ? x : pa[x] = find(pa[x]);
    }
    int unionn(int x, int y) { // weighted union
        auto rx{find(x)}, ry{find(y)};
        if (rx == ry) return rx;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        pa[ry] = rx, sz[rx] += sz[ry];
		return rx;
    }
};

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	template<typename T>
	using tensor = vector<matrix<T>>;
	using ll = long long;
	using plc = pair<ll, char>;
	void solve() {
		int n, m;
		cin >> n >> m;
		matrix<plc> col(n, vector<plc>(m + 1)), row(n + 1, vector<plc>(m));
		for (int i{1}; i < n; ++i)
			for (int j{1}; j <= m; ++j) cin >> col[i][j].fi;
		for (int i{1}; i <= n; ++i)
			for (int j{1}; j < m; ++j) cin >> row[i][j].fi;
		for (int i{1}; i < n; ++i)
			for (int j{1}; j <= m; ++j) cin >> col[i][j].se;
		for (int i{1}; i <= n; ++i)
			for (int j{1}; j < m; ++j) cin >> row[i][j].se;

		matrix<ll> w(n + 1, vector<ll>(m + 1));
		for (int i{1}; i < n; ++i)
			for (int j{1}; j < m; ++j) w[i][j] += col[i][j].fi - col[i][j + 1].fi + row[i][j].fi - row[i + 1][j].fi;

		DSU dsu{(n + 1) * (m + 1)};
		auto pos{[&m](int i, int j) { return i * (m + 1) + j; }};
		auto gti{[&m](int p) { return p / (m + 1); }};
		auto gtj{[&m](int p) { return p % (m + 1); }};
		for (int i{0}; i <= n; ++i) dsu.unionn(0, pos(i, 0)), dsu.unionn(0, pos(i, m));
		for (int j{0}; j <= m; ++j) dsu.unionn(0, pos(0, j)), dsu.unionn(0, pos(n, j));
		for (int i{1}; i < n; ++i)
			for (int j{1}; j <= m; ++j) {
				if (col[i][j].se != '0') continue;
				dsu.unionn(pos(i, j - 1), pos(i, j));
			}
		for (int i{1}; i <= n; ++i)
			for (int j{1}; j < m; ++j) {
				if (row[i][j].se != '0') continue;
				dsu.unionn(pos(i - 1, j), pos(i, j));
			}
		for (int i{1}; i < n; ++i)
			for (int j{1}; j < m; ++j) {
				int p{pos(i, j)}, r{dsu.find(p)};
				if (p == r) continue;
				w[gti(r)][gtj(r)] += w[i][j];
			}

		ll ans{};
		for (int i{0}; i <= n; ++i) {
			for (int j{0}; j <= m; ++j) {
				int p{pos(i, j)}, r{dsu.find(p)};
				if (p != r || r == dsu.find(0)) continue;
				ans += max(0ll, w[i][j]);
			}
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
