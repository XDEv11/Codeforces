//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
	int q;
	if (!(cin >> q)) return false;

	array<int, 31> c{};
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			++c[b];
		} else {
			bool f{true};
			auto d{c};
			for (int i{0}; i <= 29; ++i) {
				if (b & (1 << i)) {
					if (!d[i]) {
						f = false;
						break;
					} else --d[i], b -= (1 << i);
				}
				d[i + 1] += d[i] / 2;
			}
			cout << (f ? "YES\n" : "NO\n");
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
