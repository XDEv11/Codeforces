//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll mx{*max_element(v.begin(), v.end())}, g{};
	for (auto& x : v) g = gcd(g, x = mx - x);
	if (!g) return cout << "1\n", []{}();

	multiset<ll> ms{};
	if (g) {
		for (auto& x : v) ms.insert(x / g);
	}
	ll x{1};
	while (ms.find(x) != ms.end()) ++x;
	ms.insert(x);

	cout << accumulate(ms.begin(), ms.end(), 0ll) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
