//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <optional>

using namespace std;

// segment tree
// range query & range modify
template <typename value_t>
class SGT {
	int n;
	vector<value_t> t;
	vector<optional<value_t>> lz;
	// [ tv+1 : tv+2*(tm-tl) ) -> left subtree
	int left(int tv) { return tv + 1; }
	int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
	/** differ from case to case **/
	// query is "sum" and modify is "set" here
	value_t merge(const value_t& x, const value_t& y) { // associative function
		return x + y;
	}
	void update(int tv, int len, const value_t& x) {
		lz[tv] = x;
		t[tv] = len * x;
	}
	/******************************/
	void push(int tv, int tl, int tr) { // lazy propagation
		if (!lz[tv]) return;
		
		int tm{(tl + tr) / 2};
		update(left(tv), tm - tl, lz[tv].value());
		update(right(tv, tl, tm), tr - tm, lz[tv].value());
		lz[tv].reset();
	}
	void modify(int l, int r, const value_t& x, int tv, int tl, int tr) {
		if (l == tl && r == tr) update(tv, tr - tl, x);
		else {
			push(tv, tl, tr);
			int tm{(tl + tr) / 2};
			if (r <= tm) modify(l, r, x, left(tv), tl, tm);
			else if (l >= tm) modify(l, r, x, right(tv, tl, tm), tm, tr);
			else modify(l, tm, x, left(tv), tl, tm),
				modify(tm, r, x, right(tv, tl, tm), tm, tr);
			t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
		}
	}
	value_t query(int l, int r, int tv, int tl, int tr) {
		if (l == tl && r == tr) return t[tv];
		push(tv, tl, tr);
		int tm{(tl + tr) / 2};
		if (r <= tm) return query(l, r, left(tv), tl, tm);
		else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
		else return merge(query(l, tm, left(tv), tl, tm), 
				query(tm, r, right(tv, tl, tm), tm, tr));
	}
public:
	explicit SGT(int _n) : n{_n}, t(2 * n - 1), lz(2 * n - 1) {}
	void modify(int l, int r, const value_t& x) { modify(l, r, x, 0, 0, n); } // [l:r)
	value_t query(int l, int r) { return query(l, r, 0, 0, n); } // [l:r)
};

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	SGT<long long> sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, i + 1, v[i]);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i, x;
			cin >> i >> x, --i;
			sgt.modify(i, i + 1, x);
		} else if (t == 2) {
			int x;
			cin >> x;
			sgt.modify(0, n, x);
		}
		cout << sgt.query(0, n) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
