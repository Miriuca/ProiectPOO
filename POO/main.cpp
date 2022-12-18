#include "bilete.cpp"
#include <iostream>

int main()
{
	eveniment e;
	bilete b;

	// Input name and event details
	cout << "Enter your name: ";
	string name;
	getline(cin, name);
	b.setNume(name);

	cout << "Enter event details: " << endl;
	cin >> e;

	// Print ticket details
	cout << "Ticket details: " << endl;
	cout << b << endl;
	cout << e << endl;

	return 0;
}
