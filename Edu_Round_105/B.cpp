#include <iostream>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	array<int, 4> arr;
	for (auto& x : arr) cin >> x;

	auto check = [&n](array<int, 4> a, int bitmask) {
		for (int i{0}; i < 4; ++i)
			if (bitmask & (1 << i)) --a[i], --a[(i + 1) % 4];
		
		for (auto& x : a)
			if (x > (n - 2) || x < 0) return false;
		return true;
	};

	for (int i{0}; i < 16; ++i) // try all combination
		if (check(arr, i)) {
			cout << "YES\n";
			return ;
		}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
