#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
	tm date = tm(), min_date = tm();

	if (!(cin >> get_time(&min_date, "%m/%d/%Y"))) return 0;
	while (cin >> get_time(&date, "%m/%d/%Y")) {
		if (difftime(mktime(&date), mktime(&min_date)) < 0)
			min_date = date;
	}
	cout << put_time(&min_date, "%m/%d/%Y") << endl;
	return 0;
}