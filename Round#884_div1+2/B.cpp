//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n <= 2) {
		for (int i{1}; i <= n; ++i) cout << i << " \n"[i == n];
		return ;
	}

	cout << "2 ";
	int i{0};
	for (; i < (n - 3) / 2; ++i) cout << i + 4 << ' ';
	cout << "1 ";
	for (; i < n - 3; ++i) cout << i + 4 << ' ';
	cout << "3\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
