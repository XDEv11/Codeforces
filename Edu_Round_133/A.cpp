//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n == 1) cout << "2\n";
	else cout << (n + 2) / 3 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
