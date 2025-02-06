//#pragma GCC optimize ("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

void solve(ifstream& fin) {
	int n, k;
	fin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) fin >> x;

	struct sgt_merge_t { int operator()(int a, int b) const { return a | b; } };
	SGT<int, sgt_merge_t> sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, v[i]);

	int ans{};
	for (int i{0}, j{0}; i < n; ++i) {
		while (j < n && sgt.query(i, j + 1, 0) <= k) ++j;
		ans = max(ans, j - i);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin{"wifi.in"};
	
	int t{1};
	fin >> t;
	while (t--) solve(fin);
}
