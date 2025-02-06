//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<array<int, 3>> v(n);
	for (auto& [h, r, s] : v) cin >> h >> r >> s;

	int mxh{};
	for (auto& [h, r, s] : v) mxh = max(mxh, h);

	for (int i{0}; i < 1825 * mxh; ++i) {
		bool f{true};
		for (auto& [h, r, s] : v) {
			int x{i % h};
			if (s < r) {
				if (clamp(x, s, r) != x) {
					f = false;
					break;
				}
			} else {
				if (x < s) x += h;
				if (clamp(x, s, r + h) != x) {
					f = false;
					break;
				}
			}
		}
		if (f) return cout << i << '\n', true;
	}
	return cout << "impossible\n", true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
