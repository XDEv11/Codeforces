//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	vector<ll> pn{[] {
		ll n{10000000};
		vector<bool> c(n + 1);
		vector<ll> t{};
		for (ll i{2}; i <= n; ++i) {
			if (c[i]) continue;
			t.push_back(i);
			for (ll j{i * i}; j <= n; j += i) c[j] = true;
		}
		return t;
	}()};
	set<ll> pf(ll x) {
		ll y{x};
		set<ll> st{};
		for (int i{0}; pn[i] * pn[i] <= x && y > 1; ++i) {
			if (y % pn[i]) continue;
			st.insert(pn[i]);
			while (y % pn[i] == 0) y /= pn[i];
		}
		if (y > 1) st.insert(y);
		return st;
	}
	void solve() {
		ll n, m;
		cin >> n >> m;

		int l{0}, r{pn.size()};
		while (r - l > 1) {
			int md{(l + r) / 2};
			(pn[md] <= n ? l : r) = md;
		}
		l = pn[l];

		ll ans{};
		set<ll> st{};
		for (ll x{n - 1}; x >= l; --x) {
			for (auto& p : pf(x + 1)) st.insert(p);

			ll a{n};
			for (auto& p : st) {
				ll t1{}, t2{};
				for (ll k{p}; k <= n; k *= p) t1 += x / k, t2 += n / k;
				int i{1};
				for (ll k{p}; k <= m; k *= p, ++i) {
					if (t1 / i != t2 / i) a = min(a, t1 / i);
				}
			}
			ans += a;
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
