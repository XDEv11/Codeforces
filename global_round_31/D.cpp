//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;
		if (n == 1) return void(cout << "0\n");

		int ans{};
		ll mn{v[0]}, mx{v[1]};
		for (int i{1}; i < n; ++i) {
			ll nx{v[i] + (v[i] - mn)}, nn{v[i] + (v[i] - mx)};
			if (i + 1 < n) nx = min(v[i + 1], nx);
			
			if (nx <= nn) mn = v[i];
			else ++ans, mn = nn;
			mx = nx;
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
