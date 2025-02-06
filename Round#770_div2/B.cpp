//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n; long long x, y;
	cin >> n >> x >> y;
	x &= 1;
	while (n--) {
		long long a;
		cin >> a;
		x ^= (a & 1);
	}

	cout << (x == (y & 1) ? "Alice\n" : "Bob\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
