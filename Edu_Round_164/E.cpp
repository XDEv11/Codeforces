//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

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

template<typename T>
struct Min {
	T operator()(const T& a, const T& b) { return min(a, b); }
};

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	using pii = pair<int, int>;
	SGT<pii, Min<pii>> sgt1{n, {100001, 0}};
	for (int i{0}; i < n; ++i) sgt1.modify(i, {v[i], i});

	vector<int> s(n, -1);
	queue<pair<int, int>> qu{};
	qu.emplace(0, n);
	while (!qu.empty()) {
		auto [l, r]{qu.front()}; qu.pop();
		if (r - l == 1) continue;
		auto [_mn, mn]{sgt1.query(l, r)};
		if (mn != l) {
			auto [_mnl, mnl]{sgt1.query(l, mn)};
			s[mnl] = mn;
			qu.emplace(l, mn);
		}
		if (mn != r - 1) {
			auto [_mnr, mnr]{sgt1.query(mn + 1, r)};
			s[mnr] = mn;
			qu.emplace(mn + 1, r);
		}
	}

	vector<int> c1(n, 1);
	for (auto& x : s) {
		if (x != -1) --c1[x];
	}
	int mx{*max_element(v.begin(), v.end())};
	vector<int> c2(mx + 1);
	for (int i{0}; i < n; ++i) c2[v[i]] += c1[i];

	SGT<int, plus<int>> sgt2{mx + 1, 0};
	for (int i{1}; i <= mx; ++i) sgt2.modify(i, c2[i]);
	for (int i{1}; i <= mx; ++i) {
		using ll = long long;
		ll ans{};
		for (int j{1}; ; ++j) {
			int a{i * (j - 1) + 1}, b{min(mx, i * j)};
			if (!(a <= mx)) break;
			ans += ll(j) * sgt2.query(a, b + 1);
		}
		cout << ans << " \n"[i == mx];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
