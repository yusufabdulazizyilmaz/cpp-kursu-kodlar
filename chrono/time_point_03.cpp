#include <chrono>
#include <ctime>
#include <iostream>
#include <iomanip>


using namespace std;
using namespace chrono;


void print_time(const time_t& timer)
{
	static const char* const pmons[] = {
	"Ocak",
	"Subat",
	"Mart",
	"Nisan",
	"Mayis",
	"Haziran",
	"Temmuz",
	"Agustos",
	"Eylul",
	"Ekim",
	"Kasim",
	"Aralik"
	};

	static const char* const pdays[] = {
	"Pazar",
	"Pazartesi",
	"Sali",
	"Carsamba",
	"Persembe",
	"Cuma",
	"Cumartesi",
	};

	auto p = localtime(&timer);
	cout.fill('0');
	cout << setw(2) << p->tm_mday << " " << pmons[p->tm_mon] << " " << p->tm_year + 1900 << " " <<
		pdays[p->tm_wday] << " " << setw(2) << p->tm_hour << ":" << setw(2)
		<< p->tm_min << ":" << setw(2) << p->tm_sec << "\n";
}



int main()
{
	auto tp_now = system_clock::now();


	print_time(system_clock::to_time_t(tp_now));
	int min;
	cout << "kac dakika : ";
	cin >> min;
	time_t timer = system_clock::to_time_t(tp_now - minutes{ min });
	cout << min << " dakika oncesi : ";
	print_time(timer);
	timer = system_clock::to_time_t(tp_now + minutes{ min });
	cout << min << " dakika sonrasi : ";
	print_time(timer);
}
