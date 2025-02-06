//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	long long n;
	cin >> n;

	if (n < 4 || n & 1) return cout << "-1\n", []{}();

	cout << (n + 5) / 6 << ' ' << n / 4 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
