//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	if (k == 1) return cout << (n - 2 + 1) / 2 << '\n', []{}();

	int ans{0};
	for (int i{1}; i + 1 < n; ++i) {
		if (v[i] > v[i - 1] + v[i + 1]) ++ans;
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
