//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x >> x, x += 180;

	vector<bool> ck(720);
	for (int i{0}; i < n; ++i) {
		int j{(i + 1) % n};
		int p1{v[i]}, p2{v[j]};
		if (p1 > p2) swap(p1, p2);
		if (p2 - p1 == 180) return cout << "yes\n", true;
		else if (p2 - p1 < 180) {
			for (int k{2 * p1}; k != 2 * p2 + 1; ++k) ck[k] = true;
		} else {
			for (int k{2 * p2}; k != 2 * p1 + 1; k = (k + 1) % 720) ck[k] = true;
		}
	}

	auto it{find(ck.begin(), ck.end(), false)};
	if (it != ck.end()) {
		cout << "no ";
		int p{distance(ck.begin(), it)};
		if (p < 360) cout << '-';
		cout << (abs(p - 360) / 2) << (p & 1 ? ".5\n" : ".0\n");
	} else cout << "yes\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
