//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SGT {
	int n;
	vector<long long> t;
	int left(int tv) { return tv + 1; }
	int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
	void modify(int p, long long x, int tv, int tl, int tr) {
		if (tr - tl > 1) {
			int tm{(tl + tr) / 2};
			if (p < tm) modify(p, x, left(tv), tl, tm);
			else modify(p, x, right(tv, tl, tm), tm, tr);
			t[tv] = t[left(tv)] + t[right(tv, tl, tm)];
		} else t[tv] = x;
	}
	long long query(int l, int r, int tv, int tl, int tr) {
		if (l == tl && r == tr) return t[tv];
		int tm{(tl + tr) / 2};
		if (r <= tm) return query(l, r, left(tv), tl, tm);
		else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
		else return query(l, tm, left(tv), tl, tm) + query(tm, r, right(tv, tl, tm), tm, tr);
	}
public:
	explicit SGT(int _n) : n{_n}, t(2 * n - 1) {}
	void modify(int p, long long x) { modify(p, x, 0, 0, n); }
	long long query(int l, int r) { return query(l, r, 0, 0, n); }
	int ps_lower_bound(long long ps) {
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

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	SGT sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, 1);

	for (int i{0}, j{0}, k; i < n - 1; ++i) {
		int c{(sgt.query(0, j + 1) - 1 + v[j] - 1) % (n - i)};
		k = sgt.ps_lower_bound(c + 1);
		sgt.modify(k, 0);
		if (c == n - i - 1) c = 0;
		j = sgt.ps_lower_bound(c + 1);
	}

	cout << (sgt.ps_lower_bound(1) + 1) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
