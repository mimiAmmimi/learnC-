#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
	double x, y;
	cin >> x >> y;

	double S;
	S = sin(x / y) / cos(x / y);

	double R;
	R = (pow(x, 1.0/3.0) * sin(x)) / (exp(3*x) + exp(3 * y));
	cout << R << " " << S << endl;

	double C = max(R, S);
	cout << C << endl;

	return 0;

}
