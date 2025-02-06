//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second
#include <map>
#include <iterator>

using namespace std;

// segment tree
template<typename value_t, class merge_t>
class SGT1 {
	int n;
	vector<value_t> t; // root starts at 1
	merge_t merge; // associative function for SGT
public:
	explicit SGT1(int _n, const merge_t& _merge = merge_t{})
		: n{_n}, t(2 * n), merge{_merge} {}
	void modify(int p, const value_t& x) {
		for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
	}
	value_t query(int l, int r, value_t init) { // [l:r)
		if (l == r) return init;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) init = merge(init, t[l++]);
			if (r & 1) init = merge(init, t[--r]);
		}
		return init;
	}
};

class SGT2 {
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
	explicit SGT2(int _n) : n{_n}, t(2 * n - 1) {}
	void modify(int p, long long x) { modify(p, x, 0, 0, n); };
	long long query(int l, int r) { return query(l, r, 0, 0, n); }
	int ps_lower_bound(long long ps) {
		/* prefix sum lower bound 
			* binary search on tree
		 */
		if (ps >= t[0]) return n;

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
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	map<int, int> mp{};
	for (auto& x : v) ++mp[x];

	cout << "mp:";
	for (auto& [x, c] : mp) cout << "(" << x << ", " << c << ") ";
	cout << endl;

	vector<pair<int, int>> cnt{};
	int i{0};
	for (auto& [x, c] : mp) cnt.emplace_back(c, i), c = i++;
	sort(cnt.begin(), cnt.end());

	cout << "mp:";
	for (auto& [x, c] : mp) cout << "(" << x << ", " << c << ") ";
	cout << endl;
	cout << "cnt:";
	for (auto& [c, i] : cnt) cout << "(" << c << ", " << i << ") ";
	cout << endl;

	vector<int> idx(mp.size());
	for (int i{0}; i < mp.size(); ++i) idx[cnt[i].se] = i;

	cout << "idx:";
	for (auto& x : idx) cout << x << ' ';
	cout << endl;

	SGT1<int, plus<int>> sgt1{mp.size()};
	for (int i{0}; i < mp.size(); ++i) sgt1.modify(i, 0);
	SGT2 sgt2{mp.size()};
	for (int i{0}; i < mp.size(); ++i) sgt2.modify(i, cnt[i].fi);

	int last{-1};
	auto it{mp.begin()};
	if (it->fi == 0)
		for ( ; it != mp.end() && it->fi == last + 1; it = next(it)) {
			sgt1.modify(idx[it->se], 1);
			sgt2.modify(idx[it->se], 0);
			last = it->fi;
		}
	auto lb{sgt2.ps_lower_bound(k)};
	int ans{mp.size() - lb - sgt1.query(lb, mp.size(), 0)};
	while (it != mp.end()) {
		auto d{it->fi - last - 1};
		if (k < d) break;
		k -= d;
		for ( ; it != mp.end() && it->fi == last + 1; it = next(it)) {
			sgt1.modify(idx[it->se], 1);
			sgt2.modify(idx[it->se], 0);
			last = it->fi;
		}
		lb = sgt2.ps_lower_bound(k);
		ans = min(ans, int(mp.size()) - lb - sgt1.query(lb, mp.size(), 0));
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
