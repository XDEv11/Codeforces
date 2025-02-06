//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [x, y] : v) cin >> x;
	for (auto& [x, y] : v) cin >> y;

	sort(v.begin(), v.end());

	for (auto& [x, y] : v) cout << x << ' ';
	cout << '\n';
	for (auto& [x, y] : v) cout << y << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
