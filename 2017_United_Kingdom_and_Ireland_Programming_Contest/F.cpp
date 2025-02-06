//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool solve() {
	int n, k;
	if (!(cin >> n >> k)) return false;

	vector<double> p(n + 1);
	p[0] = 1;
	while (k--) {
		vector<double> np(n + 1);
		np[0] = p[0] / 2;
		for (int i{1}; i <= n; ++i) np[i] = p[i - 1] / 2 + p[i] / 2;
		np[n - 1] += p[n] / 2;
		p = np;
	}

	double ans{};
	for (int i{1}; i <= n; ++i) ans += p[i] * i;

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << fixed << setprecision(7);

	while (solve()) ;
}
