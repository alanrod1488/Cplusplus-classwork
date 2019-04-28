#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int random_int(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int main(int argc, char* argv[])
{
	int count, min, max;

	count = atoi(argv[1]);
	min = atoi(argv[2]);
	max = atoi(argv[3]);
	srand(time(0));
	for (int i = 0; i < count; ++i)
		cout << random_int(min, max) << endl;
	return 0;
}