//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;

	a = abs(a), b = abs(b);
	if (a < b) swap(a, b);
	cout << 2 * b + (a > b ? 2 * (a - b) - 1 : 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
