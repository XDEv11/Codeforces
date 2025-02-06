//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	for (int i{1}; i + 2 < n; ++i) v[i + 2] += v[i] - v[i - 1], v[i] = v[i - 1];
	if (n & 1) cout << "YES\n";
	else cout << (v[n - 2] <= v[n - 1] ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
