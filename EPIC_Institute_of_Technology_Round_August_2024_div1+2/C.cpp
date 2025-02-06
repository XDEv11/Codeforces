//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	ll squ(ll n) { return n * n; }
	ll dis2(array<ll, 2> a, array<ll, 2> b) {
		return squ(a[0] - b[0]) + squ(a[1] - b[1]);
	}
	void solve() {
		int n;
		cin >> n;
		vector<array<ll, 2>> v(n);
		for (auto& [x, y] : v) cin >> x >> y;
		array<ll, 2> s, t;
		cin >> s[0] >> s[1] >> t[0] >> t[1];

		ll d{dis2(s, t)};
		for (auto& e : v) {
			if (dis2(e, t) <= d) return cout << "NO\n", []{}();
		}
		cout << "YES\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
