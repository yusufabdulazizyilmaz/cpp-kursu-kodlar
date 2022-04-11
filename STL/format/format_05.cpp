#include <iostream>
#include <format>

int main()
{
	using namespace std;

	double dval = 3. / 7;
	int width = 12;
	int precision = 5;

	cout << format("|{2:<{0}.{1}f}|", width, precision, dval);    //  |0.42857     |
}
