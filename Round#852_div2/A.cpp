//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	long long a, b, n, m;
	cin >> a >> b >> n >> m;

	long long x{min(a * m, b * (m + 1))}, y{min(a, b)};

	cout << n / (m + 1) * x + n % (m + 1) * y << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
