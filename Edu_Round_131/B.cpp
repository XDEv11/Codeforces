//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;

	cout << "2\n";
	for (int i{1}; i <= n; ++i) {
		if (i % 2 == 0) continue;
		for (int j{i}; j <= n; j *= 2) cout << j << ' ';
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
