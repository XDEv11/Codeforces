//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ask(int i) {
	cout << "? " << i + 1 << endl;
	int r;
	cin >> r;
	return r;
}

void ans(int x) {
	cout << "! " << x << endl;
}

void solve() {
	int n, k;
	cin >> n >> k;

	int x{};
	for (int i{0}; i < n % k; ++i) x ^= ask(i);
	for (int i{n % k}; i <= n - k; i += k) x ^= ask(i);
	ans(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
