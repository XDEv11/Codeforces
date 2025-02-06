//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int mx{99};
	for (int i{n - 1}; i >= 0; --i) {
		if (v[i] > mx) {
			int a{v[i] / 10}, b{v[i] % 10};
			if (!(a <= b && b <= mx)) return cout << "NO\n", []{}();
			mx = a;
		} else mx = v[i];
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
