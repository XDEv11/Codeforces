//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	int mx{0};
	for (int i{0}; i < n; ++i) mx = max(mx, a[i]);
	for (int i{0}; i < n; ++i) mx = max(mx, b[i]);

	int mx2{0};
	for (int i{0}; i < n; ++i) mx2 = max(mx2, min(a[i], b[i]));

	cout << static_cast<long long>(mx) * mx2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
