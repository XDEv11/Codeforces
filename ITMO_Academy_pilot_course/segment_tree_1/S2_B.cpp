#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class SGT {
	int n;
	vector<long long> t;
 
	inline int left(int tv) { return tv + 1; }
	inline int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
	void modify(int p, long long x, int tv, int tl, int tr) {
		if (tl == tr - 1) t[tv] = x;
		else {
			int tm{(tl + tr) / 2};
			if (p < tm) modify(p, x, left(tv), tl, tm);
			else modify(p, x, right(tv, tl, tm), tm, tr);
			t[tv] = t[left(tv)] + t[right(tv, tl, tm)];
		}
	}
	long long query(int l, int r, int tv, int tl, int tr) {
		if (l == tl && r == tr) return t[tv];
		int tm{(tl + tr) / 2};
		if (r <= tm) return query(l, r, left(tv), tl, tm);
		else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
		else return query(l, tm, left(tv), tl, tm) +
					query(tm, r, right(tv, tl, tm), tm, tr);
	}
public:
	explicit SGT(int _n) : n{_n}, t(2 * n - 1) {}
	void modify(int p, long long x) { modify(p, x, 0, 0, n); };
	long long query(int l, int r) { return query(l, r, 0, 0, n); }
	int ps_lower_bound(long long ps) {
		/* prefix sum lower bound 
		 * binary search on tree
		 */
		if (ps > t[0]) return n;

		int tv{0}, tl{0}, tr{n};
		while (tr - tl > 1) {
			int tm{(tl + tr) / 2};
			if (t[left(tv)] >= ps) tv = left(tv), tr = tm;
			else ps -= t[left(tv)], tv = right(tv, tl, tm), tl = tm;
		}
		return tl;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	SGT sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, v[i]);

	while (m--) {
		int op, var;
		cin >> op >> var;
		if (op == 1) sgt.modify(var, sgt.query(var, var + 1) ? 0 : 1);
		else if (op == 2) cout << sgt.ps_lower_bound(var + 1) << '\n'; // k-th one (actually (k+1) one's)
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	// cin >> t;
	while (t--) solve();
	
	return 0;
}
