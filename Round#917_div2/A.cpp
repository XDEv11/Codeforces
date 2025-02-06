//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int c0{}, cn{};
	for (auto& x : v) {
		if (x == 0) ++c0;
		else if (x < 0) ++cn;
	}

	if (c0 || cn % 2) return cout << "0\n", []{}();
	else return cout << "1\n1 0\n", []{}();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
