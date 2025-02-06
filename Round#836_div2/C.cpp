//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

const int maxn{2 * 100000};
vector<int> mn_fac{[](){
	vector<int> v(maxn + 1);
	v[1] = 1;
	for (long long i{2}; i <= maxn; ++i) {
		if (!v[i]) v[i] = i;
		for (long long j{i * i}; j <= maxn; j += i) {
			if (!v[j]) v[j] = i;
		}
	}
	return v;
}()};

void solve() {
	int n, x;
	cin >> n >> x;

	if (n % x) return cout << "-1\n", []{}();

	cout << x << ' ';
	for (int i{2}; i <= n - 1; ++i) {
		if (i == x) {
			x = x * mn_fac[n / x];
			cout << x << ' ';
		} else cout << i << ' ';
	}
	cout << "1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
