#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	while (n >= 10) {
		int t{0};
		while (n) t += n % 10, n /= 10;
		n = t;
	}
	cout << n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
