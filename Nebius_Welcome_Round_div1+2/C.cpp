//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, x, p;
	cin >> n >> x >> p;

	// (x + (p + 1) * p / 2) % n == 0
	vector<bool> ck(n);
	int t{x};
	for (int i{1}; i <= min(2 * n, p); ++i) ck[t = (t + i) % n] = true;

	cout << (ck[0] ? "Yes\n" : "No\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
