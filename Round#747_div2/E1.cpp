#include <iostream>

using namespace std;

/* Iterative Function to calculate (a^b) % mod in O(log b) */
long long power_mod(long long a, long long b, long long mod) { 
    long long res{1};
    while (b > 0) {
        if (b & 1) res = (res * a) % mod; 
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

void solve() {
	static constexpr long long mod{1000000007};

	int k;
	cin >> k;

	cout << 6 * power_mod(4, (1LL << k) - 2, mod) % mod << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
