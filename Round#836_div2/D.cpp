//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n & 1) {
		vector<int> v(n);
		for (int i{0}; i < n; ++i) v[i] = 4 * n - 2 * (n / 2) + 2 * i;
		--v[0], ++v[n - 1];
		for (auto& x : v) cout << x << ' ';
		cout << '\n';

	} else {
		for (int i{n - n / 2}; i <= n + n / 2; ++i) {
			if (i == n) continue;
			cout << i << ' ';
		}
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
