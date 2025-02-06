//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// segment tree
template<typename value_t>
class SGT {
	int n;
	vector<value_t> t; // root starts at 1
public:
	explicit SGT(int _n) : n{_n}, t(2 * n) {}
	void add(int p, const value_t& x) {
		for (t[p += n] += x; p > 1; p >>= 1) {
			t[p >> 1] = 0;
			t[p >> 1] += p > n ? !!t[p] : t[p];
			t[p >> 1] += (p ^ 1) >= n ? !!t[p ^ 1]: t[p ^ 1];
		}
	}
	value_t query(int l, int r) { // [l:r)
		value_t init{0};
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) init += l >= n ? !!t[l] : t[l], ++l;
			if (r & 1) --r, init += r >= n ? !!t[r] : t[r];
		}
		return init;
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	SGT<int> sgt1{n}, sgt2{n};
	for (int i{0}; i < n; ++i) sgt1.add(i, 0), sgt2.add(i, 0);
	while (q--) {
		int t, x1, y1, x2, y2;
		cin >> t;
		if (t == 1) {
			cin >> x1 >> y1, --x1, --y1;
			sgt1.add(x1, 1);
			sgt2.add(y1, 1);
		} else if (t == 2) {
			cin >> x1 >> y1, --x1, --y1;
			sgt1.add(x1, -1);
			sgt2.add(y1, -1);
		} else if (t == 3) {
			cin >> x1 >> y1 >> x2 >> y2, --x1, --y1, --x2, --y2;
			cout << (sgt1.query(x1, x2 + 1) == x2 - x1 + 1 || sgt2.query(y1, y2 + 1) == y2 - y1 + 1 ? "Yes\n" : "No\n");
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
