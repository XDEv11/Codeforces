//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
ll PM;
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

bool solve() {
	ll n, r;
	if (!(cin >> n >> PM >> r)) return false;

	if (n >= 2 * PM) {
		if (!r) return cout << PM << ' ' << 1 << '\n', true;
	} else if (n >= PM) {
		if (!r) {
			if (n > 2) return cout << (PM == 2 ? 3 : PM - 1) << ' ' << 1 << '\n', true;
			//else 2 2 0
		} else {
			ll x{1};
			for (ll i{1}; i <= n; ++i) {
				if (i == PM) continue;
				x = MM(x, i % PM);
			}
			ll y{MD(r, x)};
			if (y < PM) return cout << PM << ' ' << y << '\n', true;
		}
	} else if (r) {
		ll x{1};
		for (ll i{1}; i <= n; ++i) x = MM(x, i);
		x = MD(r, x);
		for (ll i{2}; i <= n; ++i) {
			ll y{MM(x, i)};
			if (y < i) return cout << i << ' ' << y << '\n', true;
		}
	}
	return cout << "-1 -1\n", true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
