#include <iostream>

using namespace std;

void solve() {
	static constexpr long long mod{1000000007};

	long long n, k;
	cin >> n >> k;

	long long ans{0}, p{1};
	while (k) {
		if (k & 1) ans = (ans + p) % mod;
		p = p * n % mod;
		k >>= 1;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
