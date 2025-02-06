//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define fi first
#define se second
#include <functional>
#include <algorithm>

using namespace std;

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

	vector<int> nxt(n + 1);
	stack<pair<int, int>> stk{};
	stk.emplace(n + 1, n + 1);
	for (int i{n}; i >= 0; --i) {
		while (v[i] > stk.top().fi) stk.pop();
		nxt[i] = stk.top().se;
		stk.emplace(v[i], i);
	}

	vector<vector<int>> tmp(n + 1);
	for (int i{0}; i <= n; ++i) {
		if (nxt[i] == n + 1) continue;
		tmp[nxt[i]].push_back(i);
	}

	struct MG { int operator()(int a, int b) { return max(a, b); } };
	vector<int> dp(n + 1);
	SGT<int, MG> sgt{n + 1};
	for (int i{0}; i <= n; ++i) {
		dp[i] = sgt.query(0, v[i] + 1, 0) + 1;
		sgt.modify(v[i], dp[i]);
		for (auto& j : tmp[i]) sgt.modify(v[j], max(sgt.query(v[j], v[j] + 1, 0), dp[j] + 1));
	}

	cout << sgt.query(0, n + 1, 0) - 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
