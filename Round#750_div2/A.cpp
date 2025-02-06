#include <iostream>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a >= 10) a = 10 + (a & 1);
	if (b >= 10) b = 10 + (b & 1);
	if (c >= 10) c = 10 + (c & 1);

	int c1{0}, c2{0};
	while (a || b || c) {
		if (c1 > c2) swap(c1, c2);

		if (c) c1 += 3, --c;
		else if (b) c1 += 2, --b;
		else c1 += 1, --a;
	}

	cout << abs(c1 - c2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
