#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;
	const ll maxv{1000000000};

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll l{1};
	for (int i{0}; i < n; ++i) {
		l = lcm(l, i + 2);
		if (l > maxv) break;
		if (v[i] % l == 0) return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
