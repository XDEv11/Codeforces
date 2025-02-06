//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [x, y] : v) cin >> x >> y;

	bool fn{}, fe{}, fs{}, fw{};
	for (auto& [x, y] : v) {
		if (x > 0) fe = true;
		else if (x < 0) fw = true;
		if (y > 0) fn = true;
		else if (y < 0) fs = true;
	}

	cout << (!fn || !fe || !fs || !fw ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
