#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	int c{};
	while (n % 2 == 0) n /= 2, ++c;

	if (n == 1) cout << (!c || (c & 1) ? "Bob\n" : "Alice\n");
	else cout << (c ? "Alice\n" : "Bob\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
