//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>
#define fi first
#define se second
#include <numeric>

using namespace std;

// segment tree
// range query & range modify
template <typename value_t>
class SGT {
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
	void update(int tv, const value_t& x) {
		if (!lz[tv]) lz[tv] = x;
		else lz[tv] = lz[tv].value() + x;
		t[tv].fi += x;
	}
	/******************************/
	void build(const vector<value_t>& v, int tv, int tl, int tr) {
		if (tr - tl == 1) t[tv] = {v[tl], tl};
		else {
			int tm{(tl + tr) / 2};
			build(v, left(tv), tl, tm);
			build(v, right(tv, tl, tm), tm, tr);
			t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
		}
	}
	void push(int tv, int tl, int tr) { // lazy propagation
		if (!lz[tv]) return ;

		int tm{(tl + tr) / 2};
		update(left(tv), lz[tv].value());
		update(right(tv, tl, tm), lz[tv].value());
		lz[tv].reset();
	}
	void modify(int l, int r, const value_t& x, int tv, int tl, int tr) {
		if (l == tl && r == tr) update(tv, x);
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
	node_t query(int l, int r, int tv, int tl, int tr) {
		if (l == tl && r == tr) return t[tv];
		push(tv, tl, tr);
		int tm{(tl + tr) / 2};
		if (r <= tm) return query(l, r, left(tv), tl, tm);
		else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
		else return merge(query(l, tm, left(tv), tl, tm),
				query(tm, r, right(tv, tl, tm), tm, tr));
	}
public:
	explicit SGT(const vector<value_t>& v) : n{v.size()}, t(2 * n - 1), lz(2 * n - 1) { build(v, 0, 0, n); }
	void modify(int l, int r, const value_t& x) { modify(l, r, x, 0, 0, n); } // [l:r)
	node_t query(int l, int r) { return query(l, r, 0, 0, n); } // [l:r)
};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<long long> ans(n);
	long long c{}, s{};
	SGT<int> sgt{[n] {
		vector<int> t(n + 1);
		iota(t.begin(), t.end(), 0);
		return t;
	}()};
	for (int i{0}; i < n; ++i) {
		s += v[i], ++c;
		sgt.modify(v[i], n + 1, -1);
		auto [mn, val]{sgt.query(0, n + 1)};
		if (mn == -1) {
			sgt.modify(val, n + 1, 1);
			s -= val, --c;
		}
		ans[i] = s - (1 + c) * c / 2;
	}

	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
