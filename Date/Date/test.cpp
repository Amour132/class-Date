#include "Date.h"

using namespace std;

int main()
{
	Date d1;
	d1.print();
	Date d2(2018, 4, 5);
	d2.print();
	d2 = d1++;
	d2.print();
	return 0;
}