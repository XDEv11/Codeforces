//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <utility>
#define fi first
#define se second
#include <map>
#include <algorithm>

#include <numeric>

using namespace std;

using ll = long long;
ll MA(ll a, ll b, ll m) { return (a + b) % m; }
ll MS(ll a, ll b, ll m) { return (a - b + m) % m; }
ll MM(ll a, ll b, ll m) { return (a * b) % m; }
/* solve x, y for ax + by = gcd(a, b) = g */
template<typename T>
void extEcu(T a, T b, T &g, T &x, T &y) {
    if (b) extEcu(b, a % b, g, y, x), y -= x * (a / b);
    else g = a, x = 1, y = 0;
}
ll MI(ll a, ll m) {
    ll d, x, y;
    extEcu(a, m, d, x, y);
    return d == 1 ? (x + m) % m : -1;
}
ll MD(ll a, ll b, ll m) { return MM(a, MI(b, m), m); }

pair<ll, ll> CRT(const vector<pair<ll, ll>>& congruences) {
    ll M{1}, sol{};
    for (auto& [m, a] : congruences) M *= m;
    for (auto& [m, a] : congruences) {
		ll x{M / m}, y{MI(x, m)};
        sol = MA(sol, MM(MM(a, x, M), y, M), M);
    }
    return {M, sol};
}

bool solve() {
	ll a, b, f, g;
	array<ll, 3> r{};
	if (!(cin >> a >> b >> r[0] >> r[1] >> r[2] >> f >> g)) return false;

	vector<ll> t{};
	for (ll h{1}; a - 2 * h > 0 && b - 2 * h > 0; ++h) t.push_back((a - 2 * h) * (b - 2 * h) * h);
	sort(t.rbegin(), t.rend());

	map<ll, pair<ll, ll>> mp{};
	for (int i{0}; i < 3; ++i) {
		ll x{t[i]};
		for (ll pm{2}; x > 1; ++pm) {
			ll pw{1};
			while (x % pm == 0) x /= pm, pw *= pm;
			if (pw == 1) continue;
			if (mp.count(pm)) {
				auto& [pw2, a2]{mp[pm]};
				if (pw > pw2) mp[pm] = {pw, r[i] % pw};
			} else mp[pm] = {pw, r[i] % pw};
		}
	}

	vector<pair<ll, ll>> c{};
	for (auto& [k, v] : mp) c.emplace_back(v.fi, v.se);

	auto [mod, ans]{CRT(c)};

	if (ans >= f) {
		ll k{(ans - f) / mod};
		ans -= k * mod;
	} else {
		ll k{(f - ans + mod - 1) / mod};
		ans += k * mod;
	}

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
