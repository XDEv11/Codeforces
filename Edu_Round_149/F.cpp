//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second

using namespace std;

class SGT {
	int n;
	vector<int> t;

	int left(int tv) { return tv + 1; }
	int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
	void modify(int p, int x, int tv, int tl, int tr) {
		if (tl == tr - 1) t[tv] = x;
		else {
			int tm{(tl + tr) / 2};
			if (p < tm) modify(p, x, left(tv), tl, tm);
			else modify(p, x, right(tv, tl, tm), tm, tr);
			t[tv] = t[left(tv)] + t[right(tv, tl, tm)];
		}
	}
	void modify(int p, int x) { modify(p, x, 0, 0, n); };
public:
	explicit SGT(int _n) : n{_n}, t(2 * n - 1) {}
	void set(int p) { modify(p, 1); }
	void unset(int p) { modify(p, 0); }
	int kth1(int k) {
		if (k <= 0) return -1;
		if (k > t[0]) return n;
		int tv{0}, tl{0}, tr{n};
		while (tr - tl > 1) {
			int tm{(tl + tr) / 2};
			if (t[left(tv)] >= k) tv = left(tv), tr = tm;
			else k -= t[left(tv)], tv = right(tv, tl, tm), tl = tm;
		}
		return tl;
	}
	int kth0(int k) {
		if (k <= 0) return -1;
		if (k > (n - t[0])) return n;
		int tv{0}, tl{0}, tr{n};
		while (tr - tl > 1) {
			int tm{(tl + tr) / 2};
			if ((tm - tl - t[left(tv)]) >= k) tv = left(tv), tr = tm;
			else k -= (tm - tl - t[left(tv)]), tv = right(tv, tl, tm), tl = tm;
		}
		return tl;
	}
};

void solve() {
	using ll = long long;

	int n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<pair<ll, int>> t(n);
	for (int i{0}; i < n; ++i) t[i] = {v[i], i};
	sort(t.begin(), t.end());
	vector<int> rk(n);
	for (int i{0}; i < n; ++i) rk[t[i].se] = i;

	int c1{0}, c2{k}; ll ans1{0}, ans2{0};
	for (int i{0}; i < c2; ++i) ans2 += t[i].fi;

	ll ans{ans2};

	SGT sgt{n};
	for (int i{0}; i < n; ++i) {
		int mx1{sgt.kth1(c1)};
		if (c1 && v[i] < t[mx1].fi) { // adjust part 1
			ans1 -= t[mx1].fi, ans1 += v[i];
		}

		sgt.set(rk[i]); // remove x

		int mx2{sgt.kth0(c2)};
		if (rk[i] < mx2) { // adjust part 2
			ans2 -= v[i];
			if (mx2 == n) {
				--c2, ++c1;
				ans1 += t[sgt.kth1(c1)].fi;
			} else ans2 += t[mx2].fi;
		}

		while (true) { // maintain answer
			mx1 = sgt.kth1(c1 + 1), mx2 = sgt.kth0(c2);
			if (mx1 == n || mx2 == -1) break;
			ll na1{ans1 + t[mx1].fi}, na2{ans2 - t[mx2].fi};
			if (max(ans1, ans2) <= max(na1, na2)) break;
			--c2, ++c1;
			ans1 = na1, ans2 = na2;
		}

		ans = min(ans, max(ans1, ans2));
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
