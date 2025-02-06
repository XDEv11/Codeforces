//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const ll mod{1000000007};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());

	ll ans{1};
	int j{0};
	for (int i{0}; i < n; ++i) {
		while (j < n && a[j] > b[i]) ++j;
		if (j <= i) return cout << "0\n", []{}();
		ans = ans * (j - i) % mod;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
