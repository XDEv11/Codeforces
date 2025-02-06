//#pragma GCC optimize ("O3")

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void solve(ifstream& fin) {
	using ll = long long;
	ll n, k;
	fin >> n >> k;

	ll ans{};
	ans += n * (n / (k + 1));
	ans += (n / (k + 1)) * (n % (k + 1));
	ans += (n % (k + 1));

	cout << (n * n - ans) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin{"chess.in"};
	
	int t{1};
	fin >> t;
	while (t--) solve(fin);
}
