//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <optional>
#include <functional>
#include <algorithm>

using namespace std;

namespace {
	// segment tree
	// range query & range modify
	class SGT {
		using value_t = int;
		using node_t = pair<value_t, int>;

		int n;
		vector<node_t> t;
		vector<optional<value_t>> lz;
		// [ tv+1 : tv+2*(tm-tl) ) -> left subtree
		int left(int tv) { return tv + 1; }
		int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
		/** differ from case to case **/
		// query is "min" and modify is "add" here
		node_t merge(const node_t& x, const node_t& y) { // associative function
			return min(x, y);
		}
		void update(int tv, int len, const value_t& x) {
			if (!lz[tv]) lz[tv] = x;
			else lz[tv] = lz[tv].value() + x;
			t[tv].fi = t[tv].fi + x;
		}
		/******************************/
		void build(const vector<value_t>& v, int tv, int tl, int tr) {
			if (tr - tl > 1) {
				int tm{(tl + tr) / 2};
				build(v, left(tv), tl, tm);
				build(v, right(tv, tl, tm), tm, tr);
				t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
			} else t[tv] = {v[tl], tl};
		}
		void push(int tv, int tl, int tr) { // lazy propagation
			if (!lz[tv]) return ;
			int tm{(tl + tr) / 2};
			update(left(tv), tm - tl, lz[tv].value());
			update(right(tv, tl, tm), tr - tm, lz[tv].value());
			lz[tv].reset();
		}
		void rmodify(int l, int r, const value_t& x, int tv, int tl, int tr) {
			if (!(l == tl && r == tr)) {
				push(tv, tl, tr);
				int tm{(tl + tr) / 2};
				if (r <= tm) rmodify(l, r, x, left(tv), tl, tm);
				else if (l >= tm) rmodify(l, r, x, right(tv, tl, tm), tm, tr);
				else rmodify(l, tm, x, left(tv), tl, tm),
					rmodify(tm, r, x, right(tv, tl, tm), tm, tr);
				t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
			} else update(tv, tr - tl, x);
		}
		int bsearch(int tv, int tl, int tr) {
			if (tr - tl == 1) return tl;
			push(tv, tl, tr);
			int tm{(tl + tr) / 2};
			if (t[left(tv)].fi < 0) return bsearch(left(tv), tl, tm);
			else return bsearch(right(tv, tl, tm), tm, tr);
		}
	public:
		explicit SGT(const vector<value_t>& v) : n{v.size()}, t(2 * n - 1), lz(2 * n - 1) { build(v, 0, 0, n); }
		void rmodify(int l, int r, const value_t& x) { rmodify(l, r, x, 0, 0, n); } // [l:r)
		int bsearch() {
			if (t[0].fi >= 0) return n;
			return bsearch(0, 0, n);
		}
	};

	void solve() {
		int ta, tb, n;
		cin >> ta >> tb >> n;
		vector<int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		SGT sgt{[&n]{
			vector<int> v(n + 2);
			for (int t{0}; t < n + 2; ++t) v[t] = -(t + 1);
			return v;
		}()};
		auto calc{[&](int i) { return min(n + 1, max(0, a[i] - ta) + max(0, b[i] - tb)); }};
		for (int i{0}; i < n; ++i) sgt.rmodify(calc(i), n + 2, 1);

		int m;
		cin >> m;
		while (m--) {
			int i;
			cin >> i, --i;
			sgt.rmodify(calc(i), n + 2, -1);

			cin >> a[i] >> b[i];
			sgt.rmodify(calc(i), n + 2, 1);

			cout << sgt.bsearch() << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
