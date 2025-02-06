//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	for (int i{0}; i < n; ++i) cout << i + 2 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
