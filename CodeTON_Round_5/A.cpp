//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	auto sa{accumulate(a.begin(), a.end(), 0ll)},
		sb{accumulate(b.begin(), b.end(), 0ll)};
	if (sa > sb) cout << "Tsondu\n";
	else if (sa < sb) cout << "Tenzing\n";
	else cout << "Draw\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
