//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define fi first
#define se second
#include <limits>
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
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	struct M { int operator()(int x, int y) { return max(x, y); } };
	SGT<int, M> asgt{n};
	for (int i{0}; i < n; ++i) asgt.modify(i, a[i]);

	vector<int> bll(n), brl(n);
	{
		stack<pair<int, int>> s{};
		s.emplace(numeric_limits<int>::min(), -1);
		for (int i{0}; i < n; ++i) {
			while (s.top().fi >= b[i]) s.pop();
			bll[i] = s.top().se;
			s.emplace(b[i], i);
		}
	}
	{
		stack<pair<int, int>> s{};
		s.emplace(numeric_limits<int>::min(), n);
		for (int i{n - 1}; i >= 0; --i) {
			while (s.top().fi >= b[i]) s.pop();
			brl[i] = s.top().se;
			s.emplace(b[i], i);
		}
	}

	vector<vector<int>> t(n + 1);
	for (int i{0}; i < n; ++i) t[a[i]].push_back(i);
	for (int i{0}; i < n; ++i) {
		int x{b[i]};
		if (a[i] > x) return cout << "NO\n", []{}();
		if (a[i] == x) continue;
		bool f{false};
		auto it{lower_bound(t[x].begin(), t[x].end(), i)};
		if (it != t[x].begin() && asgt.query(*--it, i, 0) <= x && *it > bll[i]) f = true;
		it = upper_bound(t[x].begin(), t[x].end(), i);
		if (it != t[x].end() && asgt.query(i + 1, *it + 1, 0) <= x && *it < brl[i]) f = true;
		if (!f) return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t1{1};
	cin >> t1;
	while (t1--) solve();
}
