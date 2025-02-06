//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n & 1) {
		cout << "1 ";
		for (int i{n - 2}; i >= 2; --i) cout << i << ' ';
		cout << n - 1 << ' ' << n << '\n';
	} else {
		for (int i{n - 2}; i >= 1; --i) cout << i << ' ';
		cout << n - 1 << ' ' << n << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
