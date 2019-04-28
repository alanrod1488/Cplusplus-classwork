#include <iostream>
#include <string>
using namespace std;

int main()
{
	char c;
	string s;
	size_t i;

	while (cin.get(c)) s += c;
	if ((i = s.size() + 1) != 1) {
		while (i != 0) cout.put(s[--i]);
	}
	return 0;
}