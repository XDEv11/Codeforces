//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;

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
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (n == 2 && v[0] > v[1]) return cout << "NO\n"s, []{}();
	else if (n <= 2) return cout << "YES\n"s, []{}();

	SGT<long long, plus<long long>> sgt{n + 1};
	long long inv{0};
	for (int i{0}; i < n; ++i) {
		inv += sgt.query(v[i] + 1, n + 1, 0);
		if (sgt.query(v[i], v[i] + 1, 0)) return cout << "YES\n"s, []{}();
		sgt.modify(v[i], 1);
	}

	(inv & 1) ? (cout << "NO\n"s) : (cout << "YES\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
