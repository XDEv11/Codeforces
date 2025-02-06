//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	for (int i{1}; i <= n; ++i) {
		cout << i << ' ';
		for (int j{n}; j >= 1; --j) {
			if (j == i) continue;
			cout << j << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
