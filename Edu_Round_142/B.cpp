//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<int, 4> a;
	for (auto& x : a) cin >> x;
	if (!a[0]) return cout << "1\n", []{}();

	int ans{0}, c{0};

	ans += a[0], c += a[0];

	if (a[1] < a[2]) swap(a[1], a[2]);
	ans += 2 * a[2];

	int t{min(a[1] - a[2], c + 1)};
	ans += t, c -= t;

	t = min(a[3], c + 1);
	ans += t, c -= t;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
