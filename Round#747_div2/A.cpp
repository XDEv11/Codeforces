#include <iostream>

using namespace std;

void solve() {
	long long n;
	cin >> n;

	cout << -(n - 1) << ' ' << n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
