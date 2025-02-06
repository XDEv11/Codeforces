//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<int, 6> a;
	for (auto& x : a) cin >> x;

	cout << min(a[4] >= a[2] ? a[4] - a[2] : a[0] - a[2] + a[0] - a[4],
			a[5] >= a[3] ? a[5] - a[3] : a[1] - a[3] + a[1] - a[5]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
