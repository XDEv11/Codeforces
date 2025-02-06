//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <limits>
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
			for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p - (p & 1)], t[p + (~p & 1)]);
		}
		value_t query(int l, int r) { return query(l, r, defa); }
		value_t query(int l, int r, value_t init) { // [l:r)
			value_t inl{init}, inr{init};
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l & 1) inl = merge(inl, t[l++]);
				if (r & 1) inr = merge(t[--r], inr);
			}
			return merge(inl, inr);
		}
	};

	using T = array<int, 5>;
	ostream& operator<<(ostream& os, T x) {
		os << "(";
		for (auto& e : x) os << e << " ";
		return os << ")";
	}
	T make_T() {
		const int mx{1000000000}, mi{200000};
		return {mx, -mi, mx + mi, 0, 0};
	}
	T make_T(int i, int x) {
		return {x - i, x - i, x + i, x + i, 0};
	}
	struct M {
		T operator()(T a, T b) {
			T c;
			c[0] = min(a[0], b[0]);
			c[1] = max(a[1], b[1]);
			c[2] = min(a[2], b[2]);
			c[3] = max(a[3], b[3]);
			c[4] = max({a[4], b[4], b[1] - a[0], a[3] - b[2]});
			return c;
		}
	};
	void solve() {
		int n, q;
		cin >> n >> q;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		SGT<T, M> sgt{n, make_T()};
		for (int i{0}; i < n; ++i) {
			sgt.modify(i, make_T(i, v[i]));
		}

		cout << sgt.query(0, n)[4] << '\n';
		while (q--) {
			int i, x;
			cin >> i >> x, --i;
			sgt.modify(i, make_T(i, x));

			cout << sgt.query(0, n)[4] << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
