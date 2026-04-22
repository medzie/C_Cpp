#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;

struct Radar {
	volatile uint8_t status = 0b10110110;
};

void turnOnPower(volatile Radar *p) {
	p->status |= (1 << 0);
	cout << bitset<8>(p->status) << " turn on power" << endl;
}

void turnOffAntenna(volatile Radar* p) {
	p->status &= ~(1 << 1);
	cout << bitset<8>(p->status) << " turn off antenna" << endl;
}

void checkStrength (volatile Radar* p) {
	uint8_t strength = (p->status >> 4);
	cout << "signal strength: " << (int)strength << endl;
}

void powerStatus(volatile Radar* p) {
	if (p->status & (1 << 0)) {
		cout<<"Power in ON" << endl;
	}
}

void overheatInfo(volatile Radar* p) {
	if (p->status & (1 << 2)) {
		cout << "Overheat detected." << endl;
	}
}

int main()
{
	Radar radar;

	turnOnPower(&radar);
	powerStatus(&radar);
	overheatInfo(&radar);
	turnOffAntenna(&radar);
	checkStrength(&radar);



	return 0;
}