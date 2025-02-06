#include <iostream>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;

	int x;
	switch ((a - 1) % 4) {
		case 0 :
			x = a - 1;
			break;
		case 1 :
			x = 1;
			break;
		case 2 :
			x = a;
			break;
		case 3:
			x = 0;
	}

	if (x == b) cout << a;
	else if ((x ^ b) != a) cout << a + 1;
	else cout << a + 2;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
