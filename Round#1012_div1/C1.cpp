//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{1000000007};
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
	ll MI(ll a) { return MP(a, PM - 2); }
	ll MD(ll a, ll b) { return MM(a, MI(b)); }
	vector<ll> Inv{[] {
		vector<ll> v(5001);
		for (ll i{1}; i <= 5000; ++i) v[i] = MI(i);
		return v;
	}()};
	void solve() {
		int n, m, _;
		cin >> n >> m >> _;

		vector<ll> ans(n), v(n);
		v[0] = 1;
		for (; m; --m) {
			vector<ll> w(n);
			for (int i{0}; i < n; ++i) {
				for (int j{0}; j < n; ++j) {
					ll t{MM(v[i], MM(m / n + ((j - i + n) % n < m % n), Inv[m]))};
					ans[j] = MA(ans[j], t);
					w[(j + 1) % n] = MA(w[(j + 1) % n], t);
				}
			}
			v = w;
		}

		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
