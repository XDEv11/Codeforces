//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
	using ll = long long;

	ll a, b, r;
	cin >> a >> b >> r;

	ll c{};
	for (int i{59}; i >= 0; --i) {
		ll m{1ll << i};
		if (a & m && !(b & m)) {
			if (r - m < 0 || c <= 0) c += m;
			else c -= m, r -= m;
		} else if (!(a & m) && b & m) {
			if (r - m < 0 || c >= 0) c -= m;
			else c += m, r -= m;
		}
	}

	cout << abs(c) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
