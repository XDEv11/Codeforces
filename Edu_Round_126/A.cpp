//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	long long ans{0};
	for (int i{0}; i + 1 < n; ++i) {
		ans += min(abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]), abs(a[i] - b[i + 1]) + abs(b[i] - a[i + 1]));
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
