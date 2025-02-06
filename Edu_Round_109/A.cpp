#include <iostream>
#include <numeric>

using namespace std;

void solve() {
	int k;
	cin >> k;

	cout << 100 / gcd(k, 100) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
