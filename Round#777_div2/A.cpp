//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n % 3 == 2) {
		cout << '2', n -= 2;
		while (n) cout << "12", n -= 3;
	} else {
		if (n % 3 == 1) cout << '1', n -= 1;
		while (n) cout << "21", n -= 3;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
