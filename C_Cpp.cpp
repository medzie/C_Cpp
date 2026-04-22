#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;

struct Radar {
	uint8_t status = 0b10110110;
};

void turnOnPower(Radar *p) {
	p->status |= (1 << 0);
	cout << bitset<8>(p->status) << " turn on power" << endl;
}

void turnOffAntenna(Radar* p) {
	p->status &= ~(1 << 1);
	cout << bitset<8>(p->status) << " turn off antenna" << endl;
}

void checkStrength (Radar* p) {
	uint8_t strength = (p->status >> 4);
	cout << "signal strength: " << (int)strength << endl;
}

int main()
{
	Radar radar;
	cout << "radar status: " << bitset<8>(radar.status) << endl;

	if (radar.status & (1 << 0)) {
		cout << "Power is ON." << endl;
	}

	if (radar.status & ( 1 << 2)) {
		cout << "Overheat detected." << endl;
	}
	turnOnPower(&radar);
	turnOffAntenna(&radar);
	checkStrength(&radar);
	return 0;

}