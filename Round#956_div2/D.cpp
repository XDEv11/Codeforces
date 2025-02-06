//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <map>
#define fi first
#define se second
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
	void solve() {
		int n;
		cin >> n;
		array<vector<int>, 2> v{}; v.fill(vector<int>(n));
		for (int k{0}; k < 2; ++k)
			for (auto& x : v[k]) cin >> x;

		map<int, int> mp{};
		for (int k{0}; k < 2; ++k)
			for (int i{0}; i < n; ++i) mp[v[k][i]];
		if (mp.size() > n) return cout << "NO\n", []{}();

		{
			auto it{mp.begin()};
			for (int i{0}; i < n; ++i, ++it) it->se = i;
		}

		for (int k{0}; k < 2; ++k)
			for (int i{0}; i < n; ++i) v[k][i] = mp[v[k][i]];

		array<long long, 2> cnt{};
		for (int k{0}; k < 2; ++k) {
			SGT<int, plus<int>> sgt{n, 0};
			for (int i{0}; i < n; ++i) {
				cnt[k] += sgt.query(v[k][i], n);
				sgt.modify(v[k][i], 1);
			}
		}

		cout << ((cnt[0] & 1) == (cnt[1] & 1) ? "YES\n" : "NO\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
