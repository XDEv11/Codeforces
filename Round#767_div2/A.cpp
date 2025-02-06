//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<array<int, 2>> v(n);
	for (auto& [a, b] : v) cin >> a;
	for (auto& [a, b] : v) cin >> b;

	sort(v.begin(), v.end());

	for (int i{0}; i < n && v[i][0] <= k; ++i) k += v[i][1];

	cout << k << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
