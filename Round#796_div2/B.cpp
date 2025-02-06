//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	
	int c{count_if(v.begin(), v.end(), [](const int& x) { return !(x & 1); })};
	if (c == n) {
		int mn{numeric_limits<int>::max()};
		for (auto& x : v) mn = min(mn, __builtin_ctz(x));
		cout << mn + n - 1 << '\n';
	} else cout << c << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
