#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;

int main()
{
	uint8_t status = 0b10110101;// Example status byte

	if (status & (1 << 0)) {
		cout << "Power is ON." << endl;
	}

	if (status & ( 1 << 2)) {
		cout << "Overheat detected." << endl;
	}

	status &= ~(1 << 1);

	cout << bitset<8>(status) << endl;

	uint8_t strength = (status >> 4);
	cout << "signal strength: " << (int)strength << endl;


}