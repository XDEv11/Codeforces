//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>

using namespace std;

static void solve() {
	array<int, 2> b, a;
	for (auto& x : b) cin >> x;
	for (auto& x : a) cin >> x;

	cout << ((b[0] > b[1]) == (a[0] > a[1]) ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
