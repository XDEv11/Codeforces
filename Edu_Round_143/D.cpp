//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Iterative Function to calculate (a^b) % mod in O(log b) */
long long power_mod(long long a, long long b, long long mod) {
    long long res{1};
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

/* exists when a and mod are coprime */
long long inv_mod(long long a, long long mod) {
    return power_mod(a, mod - 2, mod);
}

void solve() {
	using ll = long long;
	const ll mod{998244353};

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	ll ans{1};
	for (int i{0}; i < n; i += 3) {
		sort(v.begin() + i, v.begin() + i + 3);
		if (v[i] == v[i + 2]) ans = (ans * 3) % mod;
		else if (v[i] == v[i + 1]) ans = (ans * 2) % mod;
	}

	for (ll i{n / 3 / 2 + 1}; i <= n / 3; ++i) ans = (ans * i) % mod;
	ll t{1};
	for (ll i{1}; i <= n / 3 / 2; ++i) t = (t * i) % mod;
	ans = ans * inv_mod(t, mod) % mod;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
