//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

int query(int a, int b) {
	cout << "? " << a << ' ' << b << endl;
	int r;
	return cin >> r, r;
}

void answer(int x) {
	cout << "! " << x << endl;		
}

void solve() {
	int ans{0};
	for (int b{1}; b <= 29; ++b) {
		auto r{query((1 << b) - ans, (1 << (b + 1)) - ans)};
		if (r != (1 << b)) ans += (1 << (b - 1));
	}
	auto r{query((1 << 29) - ans, (1 << 29) * 3 - ans)};
	if (r == (1 << 30)) ans += (1 << 29);

	answer(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
