//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	static auto p2 = [](int x) {
		x |= (x >> 1);
		x |= (x >> 2);
		x |= (x >> 4);
		x |= (x >> 8);
		x |= (x >> 16);
		return (x + 1) >> 1;
	};

	int n;
	cin >> n;

	int x{p2(n - 1)};
	for (int i{n - 1}; i >= x; --i) cout << i << ' ';
	cout << "0 "s;
	for (int i{x - 1}; i > 0; --i) cout << i << " \n"s[i == 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
