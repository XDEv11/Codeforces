//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;

	if ((a % 2 == 0 && a / 2 != b) || (b % 2 == 0 && b / 2 != a)) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
