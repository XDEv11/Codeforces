//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	// segment tree
	template<typename value_t, class merge_t>
	class SGT {
		int n;
		vector<value_t> t; // root starts at 1
		value_t defa;
		merge_t merge; // associative function for SGT
	public:
		explicit SGT(int _n, value_t _defa, const merge_t& _merge = merge_t{})
			: n{_n}, t(2 * n), defa{_defa}, merge{_merge} {}
		void modify(int p, const value_t& x) {
			for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
		}
		value_t query(int l, int r) { return query(l, r, defa); }
		value_t query(int l, int r, value_t init) { // [l:r)
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l & 1) init = merge(init, t[l++]);
				if (r & 1) init = merge(init, t[--r]);
			}
			return init;
		}
	};

	using pii = pair<int, int>;
	struct _M { pii operator()(pii x, pii y) { return max(x, y); } };
	using sgt_t = SGT<pii, _M>;
	sgt_t sgt{0, {}};
	int dac(int l, int r) {
		if (r - l <= 2) return 0;
		auto [_, i]{sgt.query(l, r)};
		int ans{dac(l, i) + r - (i + 1)};
		ans = min(ans, i - l + dac(i + 1, r));
		return ans;
	}
	void solve() {
		int n;
		cin >> n;
		sgt = sgt_t{n, {}};
		for (int i{0}; i < n; ++i) {
			int x;
			cin >> x;
			sgt.modify(i, {x, i});
		}

		cout << dac(0, n) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
