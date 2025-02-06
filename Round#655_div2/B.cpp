#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int max_factor(int n) {
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) return n / i;
	}
	return 1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int k = max_factor(n);
		cout << k << " " << n - k << endl;
	}
	return 0;
}
