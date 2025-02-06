//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
ll MI(ll a) { return MP(a, PM - 2); }
ll MD(ll a, ll b) { return MM(a, MI(b)); }

vector<ll> MF{[] {
	const int n{1000000};
	vector<ll> t(n + 1);
	t[0] = 1;
	for (int i{1}; i <= n; ++i) t[i] = MM(t[i - 1], i);
	return t;
}()};
ll MC(ll n, ll m) { return MD(MF[n], MM(MF[m], MF[n - m])); }

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n + 2); v[n + 1] = n + 1;
		for (int i{1}; i <= n; ++i) cin >> v[i];

		vector<int> s(n + 2);
		int f{0};
		for (int i{0}; i <= n + 1; ++i) {
			if (v[i] == -1) continue;

			if (v[i] == i) {
				if (f) s[i] = 1, f = 2;
			} else {
				if (f == 2) return cout << "0\n", []{}();
				if (v[i] > i) s[i] = 1;
				f = 1;
			}
		}
		if (f == 0) {
			ll ans{1};
			for (int i{1}, ls{0}; i <= n + 1; ++i) {
				if (v[i] == -1) continue;

				int c{i - ls - 1};
				ans = MA(ans, MS(MP(2, c), c + 1));
				ls = i;
			}
			cout << ans << '\n';
			return ;
		}

		ll a{1};
		int mn{2}, mx{n};
		for (int i{1}, ls{0}; i <= n + 1; ++i) {
			if (v[i] == -1) continue;

			int c{i - ls - 1};
			if (s[i] == 0) {
				mn = max(mn, v[i] + 1);
				if (s[ls] == 1) {
					mn = max(mn, v[ls] - (i - v[i] - 1));
					mx = min(mx, v[ls] - max(0, (i - v[i] - 1 - c)));
				} else {
					int d{v[i] - v[ls] - 1};
					if (clamp(d, 0, c) != d) return cout << "0\n", []{}();
					a = MM(a, MC(c, d));
				}
			} else {
				mx = min(mx, v[i]);
				if (s[ls] == 0) {
					mn = max(mn, v[i] - (ls - v[ls] + c));
					mx = min(mx, v[i] - (ls - v[ls]));
				} else {
					int d{v[i] - v[ls] - 1};
					if (clamp(d, 0, c) != d) return cout << "0\n", []{}();
					a = MM(a, MC(c, d));
				}
			}
			ls = i;
		}
		if (mn > mx) return cout << "0\n", []{}();

		vector<ll> t(mx + 1, 1);
		for (int i{1}, ls{0}; i <= n + 1; ++i) {
			if (v[i] == -1) continue;

			int c{i - ls - 1};
			if (s[i] == 0 && s[ls] == 1) {
				for (int k{mn}; k <= mx; ++k) {
					int d{(k - 1 + i - v[i]) - v[ls]};
					t[k] = MM(t[k], MC(c, d));
				}
			} else if (s[i] == 1 && s[ls] == 0) {
				for (int k{mn}; k <= mx; ++k) {
					int d{v[i] - (k + ls - v[ls])};
					t[k] = MM(t[k], MC(c, d));
				}
			}
			ls = i;
		}
		ll ans{};
		for (int k{mn}; k <= mx; ++k) ans = MA(ans, t[k]);
		ans = MM(ans, a);

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
