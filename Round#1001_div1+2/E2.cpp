//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <limits>
#include <algorithm>

using namespace std;

namespace {
	template<typename value_t, class merge_t>
	class BIT {
		int n;
		vector<value_t> t;
		merge_t merge;
	public:
		BIT(const vector<value_t>& v, const merge_t& m = merge_t{}) : n{v.size() - 1}, t(n + 1), merge{m} {
			for (int i{1}; i <= n; ++i) {
				t[i] = v[i];
				for (int j{i - 1}; j > i - (i & -i); j -= j & -j) t[i] += t[j];
			}
		}
		void add(int i, int x) {
			for (; i <= n; i += i & -i) t[i] = merge(t[i], x);
		}
		value_t prefix(int i) {
			value_t r{};
			for (; i; i -= i & -i) r = merge(r, t[i]);
			return r;
		}
	};
	int n;
	vector<vector<int>> a{};
	vector<vector<int>> adj{};
	vector<int> dfn{}, out{};
	int t;
	void dfs(int u, int w = -1) {
		dfn[u] = ++t;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
		}
		out[u] = t;
	}
	void solve() {
		cin >> n;
		a.assign(n + 1, {});
		for (int v{0}; v < n; ++v) {
			int x; cin >> x;
			a[x].push_back(v);
		}
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfn.resize(n), out.resize(n), t = 0, dfs(0);

		vector<int> ans{};
		set<int> st{};
		int l{n + 1}, r{0};
		struct M { int operator()(int x, int y) { return max(x, y); }; };
		BIT<int, M> bit{vector<int>(n + 1, 0)};
		for (int x{n}; x >= 1; --x) {
			if (!st.empty()) {
				for (auto& v : a[x]) {
					if ((*st.begin() < dfn[v] || *st.rbegin() > out[v]) && 
						dfn[v] < l && r <= out[v] && bit.prefix(dfn[v]) <= out[v]) ans.push_back(v);
				}
				for (auto& v : a[x]) {
					int mn{*st.begin()}, mx{*st.rbegin()};
					if (dfn[v] < mn && mx <= out[v]) continue;
					if (dfn[v] < mx && mx <= out[v]) mx = *prev(st.lower_bound(dfn[v]));
					else if (dfn[v] < mn && mn <= out[v]) mn = *st.upper_bound(out[v]);
					if (mx < dfn[v]) {
						l = min(l, dfn[v]);
						r = max(r, mx);
						bit.add(mn, dfn[v]);
					} else if (mn > out[v]) {
						l = min(l, mn);
						r = max(r, dfn[v]);
						bit.add(dfn[v], mx);
					} else {
						l = min(l, dfn[v]);
						r = max(r, dfn[v]);
						bit.add(mn, dfn[v]);
						bit.add(dfn[v], mx);
					}
				}
			}
			for (auto& v : a[x]) st.insert(dfn[v]);
		}
		sort(ans.begin(), ans.end());

		cout << ans.size() << ' ';
		for (auto& v : ans) cout << (v + 1) << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
