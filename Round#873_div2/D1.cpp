//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
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

void solve() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<pair<int, int>> tmp(n);
	for (int i{1}; i <= n; ++i) tmp[i - 1] = {v[i], i};
	sort(tmp.rbegin(), tmp.rend());

	long long ans{0};
	vector<int> fg(n + 1);
	struct SGT_MERGE { int operator()(int a, int b) const { return min(a, b); } };
	SGT<int, SGT_MERGE> sgt{n + 1};
	vector<int> cnt(n + 1);
	for (int l{1}; l <= n; ++l) {
		int mn{n};
		for (auto& [_, idx] : tmp) {
			if (idx < l) continue;
			mn = min(mn, idx), fg[idx] = mn;
		}

		cnt[l - 1] = 0;
		for (int r{l}; r <= n; ++r) {
			sgt.modify(r, fg[r] = min(fg[r], sgt.query(fg[r], r, n)));
			ans += (cnt[r] = cnt[fg[r] - 1] + r - fg[r]);
		}
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
