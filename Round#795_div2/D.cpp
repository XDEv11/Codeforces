//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <stack>
#include <limits>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

// sparse table
template<typename value_t, class merge_t>
class ST {
    int n;
    vector<int> log2;
    vector<vector<value_t>> t;
    merge_t merge; // associative & idempotent function for ST
public:
    explicit ST(const vector<value_t>& v, const merge_t& _merge = merge_t{})
        : n{v.size()}, log2(n + 1), merge{_merge} {
        log2[1] = 0;
        for (int i{2}; i <= n; ++i) log2[i] = log2[i / 2] + 1;

        t.assign(n, vector<value_t>(log2[n] + 1));
        for (int i{n - 1}; i >= 0; --i) {
            t[i][0] = v[i];
            for (int j{1}; i + (1 << j) <= n; ++j)
                t[i][j] = merge(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
        }
    }
    value_t query(int l, int r) const { // [l:r)
        int j{log2[r - l]};
        return merge(t[l][j], t[r - (1 << j)][j]);
    }
};

struct st_merge_t { pll operator()(const pll& a, const pll& b) const { return max(a, b); } };
using st_t = ST<pll, st_merge_t>;

bool dac(const st_t& st, int l, int r, ll& sum, ll& lms, ll& rms) {
	if (r - l == 0) return sum = lms = rms = 0, true;
	else if (r - l == 1) {
		ll x{st.query(l, r).fi};
		sum = x;
		lms = rms = max(0ll, x);
		return true;
	}
	auto [x, m]{st.query(l, r)};
	ll lsum, llms, lrms, rsum, rlms, rrms;
	if (!dac(st, l, m, lsum, llms, lrms)) return false;
	if (!dac(st, m + 1, r, rsum, rlms, rrms)) return false;
	if (lrms + rlms > 0) return false;
	sum = lsum + x + rsum;
	lms = max(llms, lsum + x + rlms);
	rms = max(rrms, rsum + x + lrms);
	return true;
}

void solve1() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<pll> tmp(n);
	for (int i{0}; i < n; ++i) tmp[i] = {v[i], i};
	st_t st{tmp};

	ll _;
	cout << (dac(st, 0, n, _, _, _) ? "YES\n" : "NO\n");
}

void solve2() {
	int n;
	cin >> n;
	vector<ll> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<int> lg(n + 1), rg(n + 1);
	{
		stack<pair<ll, int>> stk{};
		stk.emplace(numeric_limits<ll>::max(), 0);
		for (int i{1}; i <= n; ++i) {
			while (stk.top().fi <= v[i]) stk.pop();
			lg[i] = stk.top().se;
			stk.emplace(v[i], i);
		}
	}
	{
		stack<pair<ll, int>> stk{};
		stk.emplace(numeric_limits<ll>::max(), n + 1);
		for (int i{n}; i >= 1; --i) {
			while (stk.top().fi <= v[i]) stk.pop();
			rg[i] = stk.top().se;
			stk.emplace(v[i], i);
		}
	}

	vector<int> psll(n + 1), psrg(n + 1);
	for (int i{1}; i <= n; ++i) v[i] += v[i - 1];
	{
		stack<pair<ll, int>> stk{};
		stk.emplace(numeric_limits<ll>::min(), -1);
		for (int i{0}; i <= n; ++i) {
			while (stk.top().fi >= v[i]) stk.pop();
			psll[i] = stk.top().se;
			stk.emplace(v[i], i);
		}
	}
	{
		stack<pair<ll, int>> stk{};
		stk.emplace(numeric_limits<ll>::max(), n + 1);
		for (int i{n}; i >= 0; --i) {
			while (stk.top().fi <= v[i]) stk.pop();
			psrg[i] = stk.top().se;
			stk.emplace(v[i], i);
		}
	}

	for (int i{1}; i <= n; ++i) {
		if (psll[i - 1] >= lg[i] || psrg[i] < rg[i]) return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();
}
