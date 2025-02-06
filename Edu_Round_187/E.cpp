//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>
#include <limits>

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

namespace {
	using ll = long long;
	const ll PM{998244353};
	ll MC(ll a) { return (a % PM + PM) % PM; }
	ll MA(ll a, ll b) { return (a + b) % PM; }
	ll MS(ll a, ll b) { return (a - b + PM) % PM; }
	ll MM(ll a, ll b) { return (a * b) % PM; }
	ll MP(ll a, ll b) {
		ll res{1};
		do {
			if (b & 1) res = MM(res, a);
		} while (a = MM(a, a), b >>= 1);
		return res;
	}
	const vector<ll> _MI{[] {
		int MXNUM{200000};
		vector<ll> val(MXNUM + 1);
		val[1] = 1;
		// (PM / i) * i + (PM % i) is 0 modulo PM
		for (int i{2}; i <= MXNUM; ++i) val[i] = MM(PM - PM / i, val[PM % i]);
		return val;
	}()};
	ll MI(ll a) { return _MI[a]; }
	ll MD(ll a, ll b) { return MM(a, MI(b)); }

	bool solve() {
		int n;
		if (!(cin >> n)) return false;
		vector<ll> val(n);
		for (auto& x : val) cin >> x;

		vector<int> idx(n);
		{
			vector<pair<ll, int>> t(n);
			for (int i{0}; i < n; ++i) t[i] = {val[i], i};
			sort(t.begin(), t.end());
			for (int j{0}; j < n; ++j) idx[t[j].se] = j;
		}

		vector<ll> ans(n - 2);
		SGT<int, plus<>> ct{n, 0};
		SGT<ll, plus<>> vt{n, 0};
		set<pair<ll, int>> st{};
		ll sum{};
		auto f{[&](int p1, int p2) {
			ll mx{};
			if (p1 >= 0) mx = vt.query(p1, p1 + 1) * ct.query(0, p1) - vt.query(0, p1);
			if (p2 < n) mx = max(mx, vt.query(p2 + 1, n) - vt.query(p2, p2 + 1) * ct.query(p2 + 1, n));
			return mx;
		}};
		for (int i{0}; i < n; ++i) {
			ct.modify(idx[i], 1);
			vt.modify(idx[i], val[i]);
			st.emplace(val[i], idx[i]);
			sum += val[i];

			if (i < 2) continue;

			ll mn{numeric_limits<ll>::max()};
			ll avg{(sum + i) / (i + 1)};
			auto it{st.upper_bound({avg, -1})};
			int p1{it != st.begin() ? prev(it)->se : -1}, p2{next(it) != st.end() ? next(it)->se : n};
			mn = f(p1, p2);
			if (p1 != -1) {
				p1 = (prev(it) != st.begin() ? prev(it, 2)->se : -1), p2 = it->se;
				mn = min(mn, f(p1, p2));
			}

			ans[i - 2] = MD(MC(mn), i - 1);
		}

		for (auto& x : ans) cout << x << '\n';
		cout << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
