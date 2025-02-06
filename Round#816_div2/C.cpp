//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <optional>
#include <functional>

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
	void push(int tv, int tl, int tr) { // mlzy propagation
		if (!lz[tv]) return ;
		
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
	void modify(int l, int r, const value_t& x) { modify(l, r + 1, x, 0, 0, n); } // [l:r]
	void modify(int p, const value_t& x) { modify(p, p + 1, x, 0, 0, n); }
	//value_t query(int l, int r) { return query(l, r + 1, 0, 0, n); } // [l:r]
	value_t query(int p) { return query(p, p + 1, 0, 0, n); }
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	auto calc{[&n](int l, int r) {
		long long ln{l}, mn{r - l + 1}, rn(n - 1 - r);
		return ln * rn + ln * mn + mn * rn + mn * (mn - 1) / 2 + mn;
	}};

	vector<int> mr(n), ml(n);
	for (int i{0}; i < n; ++i) {
		if (i - 1 >= 0 && v[i - 1] == v[i]) ml[i] = ml[i - 1];
		else ml[i] = i;
	}
	for (int i{n - 1}; i >= 0; --i) {
		if (i + 1 < n && v[i + 1] == v[i]) mr[i] = mr[i + 1];
		else mr[i] = i;
	}

	long long ans{0};
	for (int i{0}; i < n; i = mr[i] + 1) ans += calc(i, mr[i]);

	SGT<long long> sgt_ml{n}, sgt_mr{n};
	for (int i{0}; i < n; ++i) sgt_ml.modify(i, ml[i]);
	for (int i{0}; i < n; ++i) sgt_mr.modify(i, mr[i]);

	while (m--) {
		int p, x;
		cin >> p >> x, --p;

		int ml_p_sub_1{};
		if (p - 1 >= 0) ml_p_sub_1 = sgt_ml.query(p - 1);
		int mr_p_add_1{};
		if (p + 1 < n) mr_p_add_1 = sgt_mr.query(p + 1);

		ans -= calc(sgt_ml.query(p), sgt_mr.query(p)); // ml[p], mr[p]
		if (p - 1 >= 0 && v[p - 1] != v[p]) ans -= calc(ml_p_sub_1, p - 1); // ml[p - 1], p - 1
		if (p + 1 < n && v[p + 1] != v[p]) ans -= calc(p + 1, mr_p_add_1); // p + 1, mr[p + 1]

		v[p] = x;
		if (p - 1 >= 0 && v[p - 1] == x) sgt_ml.modify(p, ml_p_sub_1); // ml[p] = ml[p - 1]
		else sgt_ml.modify(p, p);
		if (p + 1 < n && v[p + 1] == x) sgt_mr.modify(p, mr_p_add_1); // mr[p] = mr[p + 1]
		else sgt_mr.modify(p, p);
		if (p - 1 >= 0) {
		   if (v[p - 1] == x) sgt_mr.modify(ml_p_sub_1, p - 1, sgt_mr.query(p)); // mr[ml[p - 1]...p - 1] = mr[p]
			else sgt_mr.modify(ml_p_sub_1, p - 1, p - 1);
		}
		if (p + 1 < n) {
			if (v[p + 1] == x) sgt_ml.modify(p + 1, mr_p_add_1, sgt_ml.query(p)); // ml[p + 1...mr[p + 1]] = ml[p]
			else sgt_ml.modify(p + 1, mr_p_add_1, p + 1);
		}

		ans += calc(sgt_ml.query(p), sgt_mr.query(p));
		if (p - 1 >= 0 && v[p - 1] != v[p]) ans += calc(ml_p_sub_1, p - 1);
		if (p + 1 < n && v[p + 1] != v[p]) ans += calc(p + 1, mr_p_add_1);

		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
