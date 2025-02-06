//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
	static const long long mod{998244353};

	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	long long ans{1};
	int c{0};
	for (int i{1}; i < n; ++i) {
		if (v[i] != v[i - 1]) {
			ans = (ans + 1) % mod;
			c = 0;
		} else {
			++c;
			ans = (ans + power_mod(2, c, mod)) % mod; 
		}
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
