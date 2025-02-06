//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m, --n, --m;

	if ((n + m) % 2 == 0) cout << "Tonya\n";
	else cout << "Burenka\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
