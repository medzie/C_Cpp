#include <iostream>
using namespace std;

struct Radar
{
    int id;
    float moc_db;
    char status;
};

void konfigurujRadar(struct Radar* p) {
    static int licznik = 1;
    p->moc_db = 3.6;
    p->status = 'A';
    p->id = licznik;

    licznik++;
}


int main() {

    struct Radar radar1;
    struct Radar radar2;

    konfigurujRadar(&radar1);
    printf("radar id: %d moc: %0.2f status: %c\n", radar1.id, radar1.moc_db, radar1.status);

    konfigurujRadar(&radar1);
    printf("radar id: %d moc: %0.2f status: %c", radar1.id, radar1.moc_db, radar1.status);


}