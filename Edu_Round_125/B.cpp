//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	long long n, b, x, y;
	cin >> n >> b >> x >> y;

	long long a{0}, ans{0};
	for (int i{1}; i <= n; ++i) {
		if (a + x <= b) a += x;
		else a -= y;
		ans += a;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
