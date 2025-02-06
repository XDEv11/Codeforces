#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

void solve() {
	long long x1, p1, x2, p2;
	cin >> x1 >> p1 >> x2 >> p2;

	if (p1 > p2) {
		if (p1 - p2 > 6) return cout << ">\n"s, []{}();
		while (p1-- > p2) x1 *= 10;
	} else {
		if (p2 - p1 > 6) return cout << "<\n"s, []{}();
		while (p2-- > p1) x2 *= 10;
	}

	if (x1 > x2) cout << ">\n"s;
	else if (x1 == x2) cout << "=\n"s;
	else cout << "<\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
