//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	long long n, m;
	cin >> n >> m;

	long long ans{0};
	ans += m * (1 + m) / 2;
	ans -= m;
	ans += n * (m + m * n) / 2;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
