//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<int, 4> a;
	for (auto& x : a) cin >> x;

	sort(a.begin(), a.end());

	cout << (a[0] * a[2]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
