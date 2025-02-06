//#pragma GCC optimize ("O3")

#include <iostream>
#include <fstream>

using namespace std;

void solve(ifstream& fin) {
	int n, k;
	fin >> n >> k;


	cout << (k != 1) + (k != n) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin{"tabs.in"};
	
	int t{1};
	fin >> t;
	while (t--) solve(fin);
}
