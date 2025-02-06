//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long mod{998244353};
const int mxa{200000};

// segment tree
template<typename value_t, class merge_t>
class SGT {
	int n;
	vector<value_t> t; // root starts at 1
	merge_t merge; // associative function for SGT
public:
	explicit SGT(int _n, const merge_t& _merge = merge_t{})
		: n{_n}, t(2 * n), merge{_merge} {}
	void modify(int p, const value_t& x) {
		for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
	}
	value_t query(int l, int r, value_t init) { // [l:r)
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) init = merge(init, t[l++]);
			if (r & 1) init = merge(init, t[--r]);
		}
		return init;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> s(n), t(n);
	for (auto& x : s) cin >> x;
	for (auto& x : t) cin >> x;

	vector<int> c(mxa + 1, 0);
	for (auto& a : s) ++c[a];
	SGT<int, plus> sgt(mxa + 1);
	for (int a{0}; a <= mxa; ++a) sgt.modify(a, c[a]);

	long long p{1};
	for (int i{0}; i < m && p; ++i) {
		int c0{sgt.query(t[i], t[i] + 1)}, c1{sgt.query(t[i] + 1, mxa + 1)};
		ans += p * ??;
		p *= c0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
