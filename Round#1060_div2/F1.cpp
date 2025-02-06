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
	int n{3000};
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
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		ll ans{};
		for (int s{1}; s <= n; ++s) {
			ll a{1};
			int l{1}, r{s + 1}, c{};
			for (int i{0}; i <= n; ++i) {
				if (i == n) {
					if (c < s + 1 - l) { a = 0; break; }
					a = MM(a, MC(c, s + 1 - l));
					break;
				} else if (s < v[i]) {
					if (v[i] < r) { a = 0; break; }
					int d{v[i] - r};
					if (c < d) { a = 0; break; }
					a = MM(a, MC(c, d)), c -= d;
					l += c, r = v[i] + 1, c = 0;
					if (s + 1 < l) { a = 0; break; }
				} else if (1 <= v[i]) {
					if (v[i] < l) { a = 0; break; }
					int d{v[i] - l};
					if (c < d) { a = 0; break; }
					a = MM(a, MC(c, d)), c -= d;
					r += c, l = v[i] + 1, c = 0;
					if (n + 1 < r) { a = 0; break; }
				} else if (v[i] == -1) ++c;
			}

			if (s == n && a) ans = MS(ans, n - 2);
			else ans = MA(ans, a);
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
