#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n; cin >> m;
	if (n == 0) {
		cout << 0; return 0;
	}
	int whole = n / m;
	n -= m * (n / m);
	int c = gcd(n, m);
	n /= c; m /= c;
	if(whole != 0) cout << whole << " ";

	if (n != 0) cout << n << "/" << m;
}