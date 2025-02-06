//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	const int mod{998244353};
	int n;
	cin >> n;

	if (n & 1) cout << "0\n";
	else {
		long long f{1};
		for (int i{1}; i <= n / 2; ++i) f = f * i % mod;
		cout << f * f % mod << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
