#include "EuropeanOption.h"
#include <iostream>

using namespace std;
using namespace Instruments::Options;

int main(int argc, char const *argv[])
{
	EuropeanOption callOption;
	
	cout << "Call option on a stock: " << callOption.Price() << endl;

	EuropeanOption indexOption(100.0,95.0,0.50,0.20,0.10,0.05,0.05,OT_PUT);

	cout << "Put option on an Index: " << indexOption.Price() << endl;

	EuropeanOption futureOption(19.0,19.0,0.75,0.28,0.10,0.10,0.0,OT_PUT);

	cout << "Put option on a future: " << futureOption.Price() << endl;

	futureOption.toggle();

	cout << "Call option on a future: " << futureOption.Price() << endl;

	return 0;
}