//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<array<int, 2>, 3> t;
	for (auto& [y, x] : t) cin >> x >> y;

	sort(t.rbegin(), t.rend());

	cout << (t[0][0] == t[1][0] ? t[0][1] - t[1][1] : 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
