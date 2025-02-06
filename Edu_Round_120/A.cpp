//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	array<int, 3> l;
	for (auto& x : l) cin >> x;
	sort(l.begin(), l.end());

	if ((l[0] == l[1] && l[2] % 2 == 0) || (l[1] == l[2] && l[0] % 2 == 0)) return cout << "YES\n"s, []{}();

	cout << (l[0] + l[1] == l[2] ? "YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
