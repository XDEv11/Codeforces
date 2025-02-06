//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

using ll = long long;
const ll mod{998244353};

/* Iterative Function to calculate (a^b) % mod in O(log b) */
long long power_mod(long long a, long long b) { 
    long long res{1};
    while (b > 0) {
        if (b & 1) res = res * a % mod; 
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

/* exists when a and mod are coprime */
long long inv_mod(long long a) {
    return power_mod(a, mod - 2);
}

const int maxn{2022};
const vector<ll> fac{[]() {
	vector<ll> v(2 * maxn + 1);
	v[0] = 1;
	for (int i{1}; i <= maxn; ++i) v[i] = (v[i - 1] * i) % mod;
	return v;
}()};
const vector<ll> inf{[]() {
	vector<ll> v(2 * maxn + 1);
	for (int i{0}; i <= maxn; ++i) v[i] = inv_mod(fac[i]);
	return v;
}()};

void solve() {
	int n;
	cin >> n;
	vector<int> v(2 * n);
	for (auto& x : v) cin >> x;

	map<int, int> mp{}, mnp{};
	for (auto& x : v) {
		bool f{false};
		for (int i{2}; i * i <= x; ++i) {
			if (x % i == 0) {
				f = true;
				break;
			}
		}
		if (x == 1 || f) ++mnp[x];
		else ++mp[x];
	}

	vector<ll> dp(n + 1, 0);
	dp[0] = 1;
	auto it{mp.begin()};
	for (int i{1}; i <= mp.size(); ++i, it = next(it))
		for (int j{n}; j >= 0; --j) {
			dp[j] = dp[j] * inf[it->second] % mod;
			if (j) dp[j] = (dp[j] + dp[j - 1] * inf[it->second - 1] % mod * j) % mod;
		}

	ll ans{dp[n]};
	for (auto& [np, c] : mnp) ans = ans * inf[c] % mod;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
