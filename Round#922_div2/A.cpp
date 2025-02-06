//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	cout << (n * (m / 2)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
