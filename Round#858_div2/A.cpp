//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (b > d) return cout << "-1\n", []{}();
	if (c - a > d - b) return cout << "-1\n", []{}();

	cout << (d - b) + ((d - b) - (c - a)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
