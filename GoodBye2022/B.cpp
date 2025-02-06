//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	for (int i{1}; i <= n + 1 - i; ++i) {
		if (i < n + 1 - i) cout << n + 1 - i << ' ';
		cout << i << ' ';
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
