//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (auto& [x, y] : v) cin >> x >> y, --x, --y;

	vector<bool> ro(n, false), co(n, false);
	for (auto& [x, y] : v) ro[x] = true, co[y] = true;
	cout << (count(ro.begin(), ro.end(), false) || count(co.begin(), co.end(), false) ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
