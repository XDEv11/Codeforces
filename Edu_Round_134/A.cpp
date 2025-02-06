//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<char, 4> a{};
	for (auto& x : a) cin >> x;

	sort(a.begin(), a.end());
	if (a[1] == a[2]) {
		if (a[0] == a[1] && a[2] == a[3]) cout << "0\n";
		else if (a[0] == a[1] || a[2] == a[3]) cout << "1\n";
		else cout << "2\n";
	} else if (a[0] == a[1] && a[2] == a[3]) cout << "1\n";
	else if (a[0] == a[1] || a[2] == a[3]) cout << "2\n";
	else cout << "3\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
