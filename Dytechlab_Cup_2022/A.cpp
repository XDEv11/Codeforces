//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	array<int, 26> cnt{};
	for (int i{0}; i < n; ++i) {
		char x;
		cin >> x;
		++cnt[x - 'a'];
	}

	for (int i{0}; i < k; ++i)
		for (int j{0}; j < 26 && j < (n / k) + 1; ++j) {
			if (j == n / k || !cnt[j]) {
				cout << char('a' + j);
				break;
			}
			--cnt[j];
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
