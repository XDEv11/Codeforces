//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		ll n, b, c;
		cin >> n >> b >> c;

		if (b == 0) {
			if (c < n - 2) cout << "-1\n";
			else {
				ll t{c < n};
				cout << (n - t) << '\n';
			}
		} else {
			ll t{0};
			if (c < n) t = 1 + (n - 1 - c) / b;
			cout << (n - t) << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
