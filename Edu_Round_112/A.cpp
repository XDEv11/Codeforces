#include <iostream>
#include <string>

using namespace std;

void solve() {
	long long n;
	cin >> n;

	if (n < 6) cout << "15\n"s;
	else cout << (n + (n & 1)) * 5 / 2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
