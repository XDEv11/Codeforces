//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#define fi first
#define se second
#include <tuple>
#include <algorithm>

using namespace std;

namespace {
	// segment tree
	template<typename value_t, class merge_t>
	class SGT {
		int n;
		vector<value_t> t; // root starts at 1
		value_t defa;
		merge_t merge; // associative function for SGT
	public:
		explicit SGT(int _n, value_t _defa, const merge_t& _merge = merge_t{})
			: n{_n}, t(2 * n), defa{_defa}, merge{_merge} {}
		void modify(int p, const value_t& x) {
			for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
		}
		value_t query(int l, int r) { return query(l, r, defa); }
		value_t query(int l, int r, value_t init) { // [l:r)
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l & 1) init = merge(init, t[l++]);
				if (r & 1) init = merge(init, t[--r]);
			}
			return init;
		}
	};
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<vector<int>> c(n + 1);
		for (int i{0}; i < n; ++i) c[v[i]].push_back(i);

		struct MX { int operator()(int a, int b) { return max(a, b); } };
		struct MN { int operator()(int a, int b) { return min(a, b); } };
		SGT<int, MX> tmx{n, 0};
		SGT<int, MN> tmn{n, n + 1};
		for (int i{0}; i < n; ++i) tmx.modify(i, v[i]), tmn.modify(i, v[i]);

		vector<int> ans{};
		for (int i{0}, j{0}; i < n; ++i) {
			if (c[v[i]].empty()) continue;
			if (i == c[v[i]].back()) {
				while (!c[v[i]].empty()) {
					int m{ans.size() & 1 ? tmn.query(j, i + 1) : tmx.query(j, i + 1)};
					ans.push_back(m);
					int k{-1};
					for (auto& x : c[m]) {
						tmx.modify(x, 0), tmn.modify(x, n + 1);
						if (k < j) k = x;
					}
					j = k;
					c[m].clear();
				}
			}
		}

		cout << ans.size() << '\n';
		for (auto& x : ans) cout << x << ' ';
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
