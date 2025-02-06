//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const ll mod{1000000007};

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

void solve() {
	ll n;
	cin >> n;

	long long a{n * (n + 1) % mod * (2 * n + 1) % mod * inv_mod(6) % mod}, b{n * (n + 1) % mod * inv_mod(2) % mod};

	cout << (((2 * a - b) * 2022 % mod) + mod) % mod << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
