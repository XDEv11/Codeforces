//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <utility>
#define fi first
#define se second
#include <set>
#include <cmath>

using namespace std;

void solve() {
	int n, x, y;
	array<pair<int, int>, 3> a;
	cin >> n;
	for (auto& [r, c] : a) cin >> r >> c, --r, --c;
	cin >> x >> y, --x, --y;

	set<int> sr{}, sc{};
	for (auto& [r, c] : a) {
		if (sr.count(r)) sr.erase(r);
		else sr.insert(r);
		if (sc.count(c)) sc.erase(c);
		else sc.insert(c);
	}
	int er{*sr.begin()}, ec{*sc.begin()};

	for (auto& [r, c] : a) {
		if (r == er || c == ec) continue;
		if ((r == 0 || r == n - 1) && (c == 0 || c == n - 1)) {
			if (r == x || c == y) return cout << "YES\n", []{}();
			return cout << "NO\n", []{}();
		}
	}

	if (abs(x - er) % 2 == 0 && abs(y - ec) % 2 == 0) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
