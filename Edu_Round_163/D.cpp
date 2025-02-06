//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

void solve() {
	auto equal{[](char a, char b) {
		return (a == '?') || (b == '?') || (a == b);
	}};

	string v{};
	cin >> v;
	int n{v.size()};

	for (int k{n / 2}; k >= 1; --k)
		for (int i{0}, j{-2}, c{0}; i + k < n; ++i) {
			if (equal(v[i], v[i + k])) {
				if ((c = (i == j + 1 ? c + 1 : 1)) >= k) return cout << (2 * k) << '\n', []{}();
				j = i;
			}
		}
	cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
