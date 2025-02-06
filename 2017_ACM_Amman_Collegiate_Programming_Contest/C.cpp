//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << (a < b && a < c ? "First\n" : (b < c ? "Second\n" : "Third\n"));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
