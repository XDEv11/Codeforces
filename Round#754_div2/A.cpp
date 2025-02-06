#include <iostream>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << ((a + c - 2 * b) % 3 ? 1 : 0) << '\n'; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
