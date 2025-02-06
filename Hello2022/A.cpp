//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	if (k > (n + 1) / 2) return cout << "-1\n"s, []{}();

	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < n; ++j) cout << (i == j && i % 2 == 0 && i / 2 < k ? 'R' : '.');
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
