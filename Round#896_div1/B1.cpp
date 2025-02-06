//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll a{};
	for (auto& x : v) a += x;
	if (a % n) return cout << "No\n", []{}();
	a /= n;

	map<ll, int> mp{};
	for (auto& x : v) {
		x -= a;
		if (!x) continue;
		ll t{abs(x)}, y{1}, z;
		while (t % 2 == 0) t /= 2, y *= 2;
		t += 1, z = t * y;
		while (t % 2 == 0) t /= 2;
		if (t > 1) return cout << "No\n", []{}();
		if (x > 0) --mp[y], ++mp[z];
		else ++mp[y], --mp[z];
	}

	for (auto& [k, v] : mp) {
		if (v) return cout << "No\n", []{}();
	}

	cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
