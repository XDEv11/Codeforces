//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;

	int ans{b - a};
	for (int i{0}; a + i < b; ++i) {
		int c{a + i};
		int j{19};
		while (j >= 0 && !((c & (1 << j)) && !(b & (1 << j)))) --j;
		if (j < 0) ans = min(ans, i + 1);
		else ans = min(ans, i + c % (1 << (j + 1)) - b % (1 << j) + 1);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
