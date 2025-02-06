//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, C;
	vector<long long> a(n);
	for (int i{0}; i < m; ++i) {
		int c;
		long long d, h;
		cin >> c >> d >> h;
		a[i] = d * h;
	}
	int m;
	cin >> m;
	vector<long long> b(m);
	for (int i{0}; i < m; ++i) {
		long long d, h;
		cin >> d >> h;
		b[i] = d * h;
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
