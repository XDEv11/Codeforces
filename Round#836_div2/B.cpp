//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n & 1) {
		for (int i{0}; i < n; ++i) cout << 1 << " \n"[i == n - 1];
	} else {
		if (n == 2) cout << "1 3\n";
		else {
			cout << (n / 2) << ' ' << (n / 2) << " 3 ";
			for (int i{3}; i < n; ++i) cout << "1 ";
			cout << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
