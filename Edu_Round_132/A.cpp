//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int x, a, b, c;
	cin >> x >> a >> b >> c;

	if (x == 1) x = a;
	else if (x == 2) x = b;
	else if (x == 3) x = c;
	if (!x) return cout << "NO\n", []{}();
	if (x == 1) x = a;
	else if (x == 2) x = b;
	else if (x == 3) x = c;
	if (!x) return cout << "NO\n", []{}();
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
