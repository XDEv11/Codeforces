//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i{1}; i < n; i += 2) {
		for (int j{0}; j < m; ++j) cout << i * m + j + 1 << ' ';
		cout << '\n';
	}
	for (int i{0}; i < n; i += 2) {
		for (int j{0}; j < m; ++j) cout << i * m + j + 1 << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
