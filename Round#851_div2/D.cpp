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

void solve() {
	using ll = long long;
	const ll mod{1000000007};

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	ll ans{0};
	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n; ++j) {
			int l{-1}, r{i};
			while (r - l > 1) {
				int m{(l + r) / 2};
				if (v[i] - v[m] > v[j] - v[i]) l = m;
				else r = m;
			}
			int c{r};

			l = j, r = n;
			while (r - l > 1) {
				int m{(l + r) / 2};
				if (v[m] - v[j] >= v[j] - v[i]) r = m;
				else l = m;
			}
			c += n - r;

			ans = (ans + power_mod(2, c, mod)) % mod;
		}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
