#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	static const long long mod{998244353};

	int n;
	cin >> n;
	vector<int> v(n);
	int mx{0};
	for (auto& x : v) cin >> x, mx = max(mx, x);

	int c1{0}, c2{0};
	for (auto& x : v) {
		if (x == mx) ++c1;
		if (x == mx - 1) ++c2;
	}

	if (c1 > 1) {
		long long ans{1};
		for (int i{1}; i <= n; ++i) ans = ans * i % mod;
		cout << ans << '\n';
	} else if (c2) {
		long long ans{1};
		for (int i{1}; i <= n; ++i) {
			if (i == c2 + 1) continue;
			ans = ans * i % mod;
		}
		ans = ans * c2 % mod;
		cout << ans << '\n';
	} else cout << "0\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
