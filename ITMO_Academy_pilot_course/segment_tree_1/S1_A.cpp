#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<typename value_t, class merge_t>
class SGT {
	int n;
	vector<value_t> t;
	merge_t merge; // associative function for SGT
 
	inline int left(int tv) { return tv + 1; }
	inline int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
	void modify(int p, const value_t& x, int tv, int tl, int tr) {
		if (tl == tr - 1) t[tv] = x;
		else {
			int tm{(tl + tr) / 2};
			if (p < tm) modify(p, x, left(tv), tl, tm);
			else modify(p, x, right(tv, tl, tm), tm, tr);
			t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
		}
	}
	value_t query(int l, int r, int tv, int tl, int tr) {
		if (l == tl && r == tr) return t[tv];
		int tm{(tl + tr) / 2};
		if (r <= tm) return query(l, r, left(tv), tl, tm);
		else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
		else return merge(query(l, tm, left(tv), tl, tm)
				, query(tm, r, right(tv, tl, tm), tm, tr));
	}
public:
	explicit SGT(int _n = 0, const merge_t& _merge = merge_t{})
		: n{_n}, t(2 * n - 1), merge{_merge} {}
	void modify(int p, const value_t& x) { modify(p, x, 0, 0, n); };
	value_t query(int l, int r) { return query(l, r, 0, 0, n); } // [l:r)
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	SGT<long long, plus<long long>> sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, v[i]);

	while (m--) {
		int op, var1, var2;
		cin >> op >> var1 >> var2;
		if (op == 1) sgt.modify(var1, var2);
		else if (op == 2) cout << sgt.query(var1, var2) << '\n';
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
