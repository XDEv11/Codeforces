//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#define fi first
#define se second
#include <functional>
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
		vector<pair<int, int>> v(n);
		for (auto& [x, y] : v) cin >> x >> y;

		map<int, int> idx{}, idy{};
		for (auto& [x, y] : v) idx[x] = idy[y] = 0;
		int c{};
		for (auto& [x, i] : idx) i = c++;
		vector<int> xv(c);
		for (auto& [x, i] : idx) xv[i] = x;
		c = 0;
		for (auto& [y, i] : idy) i = c++;
		vector<int> yv(c);
		for (auto& [y, i] : idy) yv[i] = y;

		for (auto& [x, y] : v) x = idx[x], y = idy[y];
		sort(v.begin(), v.end());

		int ans{-1}, anx, any;
		SGT<int, plus<int>> sgt0{c, 0}, sgt1{c, 0};
		for (auto& [x, y] : v) sgt0.modify(y, sgt0.query(y, y + 1) + 1);
		for (int x{0}, i{0}; x < xv.size(); ++x) {
			int l{-1}, r{n / 4 + 1}, lx, ly;
			while (r - l > 1) {
				int m{(l + r) / 2};

				int lf{-1}, ri{c};
				while (ri - lf > 1) {
					int md{(lf + ri) / 2};
					(min(sgt0.query(0, md), sgt1.query(0, md)) >= m ? ri : lf) = md;
				}

				if (min(sgt0.query(ri, c), sgt1.query(ri, c)) >= m) l = m, lx = x, ly = ri;
				else r = m;
			}
			if (l > ans) ans = l, anx = lx, any = ly;

			while (i < n && v[i].fi == x) {
				int y{v[i].se};
				sgt0.modify(y, sgt0.query(y, y + 1) - 1);
				sgt1.modify(y, sgt1.query(y, y + 1) + 1);
				++i;
			}
		}

		cout << ans << '\n' << xv[anx] << ' ' << yv[any] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
