//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<int, 4> g;
	for (auto& x : g) cin >> x;

	int cnt{count(g.begin(), g.end(), 1)};
	if (cnt == 0) cout << "0\n";
	else if (cnt <= 3) cout << "1\n";
	else cout << "2\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
