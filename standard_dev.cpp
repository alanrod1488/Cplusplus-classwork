#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double mean(const vector<double>& v)
{
	double sum = 0;

	for (size_t i = 0; i != v.size(); ++i)
		sum += v[i];
	return (sum / v.size());
}

double stddev(const vector<double>& v)
{
	double m = mean(v), s = 0;

	for (size_t i = 0; i != v.size(); ++i)
		s += pow(v[i] - m, 2);
	return sqrt(s / v.size());
}

int main()
{
	vector<double> v;
	double n;

	while (cin >> n) v.push_back(n);
	if (!v.empty()) cout << stddev(v) << endl;
	return 0;
}