//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class SGT {
	int n;
	vector<long long> t;
 
	int left(int tv) { return tv + 1; }
	int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
	void modify(int p, long long x, int tv, int tl, int tr) {
		if (tl == tr - 1) t[tv] = x;
		else {
			int tm{(tl + tr) / 2};
			if (p < tm) modify(p, x, left(tv), tl, tm);
			else modify(p, x, right(tv, tl, tm), tm, tr);
			t[tv] = min(t[left(tv)], t[right(tv, tl, tm)]);
		}
	}
	long long query(int l, int r, int tv, int tl, int tr) {
		if (l == tl && r == tr) return t[tv];
		int tm{(tl + tr) / 2};
		if (r <= tm) return query(l, r, left(tv), tl, tm);
		else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
		else return min(query(l, tm, left(tv), tl, tm),
					query(tm, r, right(tv, tl, tm), tm, tr));
	}
public:
	explicit SGT(int _n) : n{_n}, t(2 * n - 1) {}
	void modify(int p, long long x) { modify(p, x, 0, 0, n); };
	long long query(int l, int r) { return query(l, r, 0, 0, n); }
	int first_lower_than(long long x) {
		/* binary search on tree */
		if (t[0] >= x) return n;

		int tv{0}, tl{0}, tr{n};
		while (tr - tl > 1) {
			int tm{(tl + tr) / 2};
			if (t[left(tv)] < x) tv = left(tv), tr = tm;
			else tv = right(tv, tl, tm), tl = tm;
		}
		return tl;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	for (int i{0}; i < n; ++i) v[i] -= (i + 1);
	SGT sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, v[i]);

	long long ans{0};
	for (int l{0}; l < n; ++l) {
		int r{sgt.first_lower_than(-l)};
		ans += r - l;
		sgt.modify(l, numeric_limits<int>::max());
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
