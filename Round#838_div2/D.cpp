//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdlib>

using namespace std;

int ask(int i, int j) {
	cout << i + 1 << ' ' << j + 1 << endl;
	return cin >> i, i;
}

void ans(int x, int y) {
	cout << x + 1 << ' ' << y + 1 << endl;
	if (cin >> x, x == -1) exit(EXIT_SUCCESS);
}

void solve() {
	int n;
	cin >> n;

	int mx{0}, j;
	for (int i{1}; i < n; ++i) { // n - 1
		int t{ask(0, i)};
		if (t >= mx) mx = t, j = i;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
