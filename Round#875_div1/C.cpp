//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <stack>
#include <tuple>

using namespace std;

using ll = long long;
const ll PM{998244353};
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
ll MI(ll a) { return MP(a, PM - 2); }
ll MD(ll a, ll b) { return MM(a, MI(b)); }

const ll maxv{300000};
const vector<ll> fac{[] {
	vector<ll> v(maxv + 1);
	v[0] = 1;
	for (ll i{1}; i <= maxv; ++i) v[i] = MM(v[i - 1], i);
	return v;
}()};

ll calc(int n) {
	if (!n) return 0;
	return MD(MD(MD(fac[2 * n], fac[n]), fac[n]), n + 1);
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(k);
	for (auto& [l, r] : v) cin >> l >> r, --l;

	if (n & 1) return cout << "0\n", []{}();

	v.emplace_back(0, n);
	sort(v.begin(), v.end());

	ll ans{1};
	vector<tuple<int, int, int>> stk{};
	for (auto [l, r] : v) {
		int c{r - l};
		while (!stk.empty()) {
			auto [sl, sr, sc]{stk.back()};
			cerr << "[DEBUG] " << sl << ", " << sr << ", " << c << endl; //
			if (r <= sr) break;
			stk.pop_back();
			if (sr <= l) {
				if (sc & 1) return cout << "0\n", []{}();
				cerr << "[DEBUG] sc=" << sc << endl; //
				ans = MM(ans, calc(sc / 2));
			} else if (sl <= l) {
				int c1{l - sl}, c2{sr - l};
				if (c1 & 1) return cout << "0\n", []{}();
				cerr << "[DEBUG] c1=" << c1 << endl; //
				ans = MM(ans, calc(c1 / 2));
				if (c2 & 1) return cout << "0\n", []{}();
				cerr << "[DEBUG] c2=" << c2 << endl; //
				ans = MM(ans, calc(c2 / 2));
				l = sl, c = r - sr;
			} else {
				if (sc & 1) return cout << "0\n", []{}();
				cerr << "[DEBUG] sc=" << sc << endl; //
				ans = MM(ans, calc(sc / 2));
				c -= sc;
			}
		}
		if (!stk.empty()) {
			auto& [sl, sr, sc]{stk.back()};
			sc -= c;
		}
		stk.emplace_back(l, r, c);

		cerr << "[DEBUG] stk: ";
		for (auto& [l, r, c] : stk) cerr << "(" << l << ", " << r << ", " << c << ") ";
		cerr << endl; //
	}
	while (!stk.empty()) {
		auto [sl, sr, sc]{stk.back()}; stk.pop_back();
		if (sc & 1) return cout << "0\n", []{}();
		cerr << "[DEBUG] sc=" << sc << endl; //
		ans = MM(ans, calc(sc / 2));
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
