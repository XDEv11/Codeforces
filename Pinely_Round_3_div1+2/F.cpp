//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

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

auto MF{[]() {
	int maxval{200000};
	vector<ll> v(maxval + 1);
	v[0] = 1;
	for (int i{1}; i <= maxval; ++i) v[i] = MM(v[i - 1], i);
	return v;
}()};

ll MC(ll n, ll m) {
	return MD(MF[n], MM(MF[m], MF[n - m]));
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	if (v[n - 1] == -1) v[n - 1] = n;
	if (v[n - 1] != n) return cout << "0\n", []{}();

	auto calc{[](int w, int h, int s) {
		return MM(MM(MC(w, s), MC(h, s)), MF[s]);
	}};

	ll ans{1};
	for (int i{0}, j{-1}, vj{0}; i < n; ++i) {
		if (v[i] == -1) continue;
		if (v[i] < vj || v[i] > i + 1) return cout << "0\n", []{}();
		ll s{};
		for (int k{0}; k <= min({i - j, j + 1 - vj, v[i] - vj}); ++k) {
			int r{v[i] - vj - k};
			if (r > i - j || r > i + 1 - vj) continue;
			s = MA(s, MM(calc(i - j, j + 1 - vj, k), calc(i - j, i + 1 - vj - k, r)));
		}
		ans = MM(ans, s);
		j = i, vj = v[i];
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
