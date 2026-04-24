#include <iostream>
using namespace std;

struct config {
	unsigned int active : 1;
	unsigned int mode : 2;
}; typedef struct config config_t;

struct module {
	int id;
	config_t params;
}; typedef struct module module_t;

void setModule(module_t* p) {
	p->id = 100;
	p->params.active = 1;
	p->params.mode = 3;
}


int main() {
	module_t module;
	setModule(&module);
	printf("id %d active %d mode %d", module.id, module.params.active, module.params.mode);
}