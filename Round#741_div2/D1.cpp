#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SGT {
	int n;
	vector<long long> t; // tree
	int left(int tv) { return tv + 1; } // left child of tv
	int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
	
	void modify(int p, long long x, int tv, int tl, int tr) {
		if (tr - tl == 1) t[tv] = x;
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
		else return query(l, tm, left(tv), tl, tm) + query(tm, r, right(tv, tl, tm), tm, tr);
	}
	
public:
	SGT(int _n) : n{_n}, t(2 * n) {}
	void modify(int p, long long x) { modify(p, x, 1, 0, n); }
	long long query(int l, int r) {
		return query(l, r, 1, 0, n);
	}
};

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i{0}; i < n; ++i) {
		char c; cin >> c;
		v[i] = ((i & 1) ^ (c == '+') ? 1 : -1);
	}

	SGT sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, v[i]);

	while (q--) {
		int l, r;
		cin >> l >> r, --l;
		
		int s{sgt.query(l, r)};

		if (s & 1) cout << "1\n"s;
		else cout << (s == 0 ? 0 : 2) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
