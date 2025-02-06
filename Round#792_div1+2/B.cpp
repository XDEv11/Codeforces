//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	long long a, b, c;
	cin >> a >> b >> c;

	long long z{c}, y{z + b}, x{y + a};
	cout << x << ' ' << y << ' ' << z << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
