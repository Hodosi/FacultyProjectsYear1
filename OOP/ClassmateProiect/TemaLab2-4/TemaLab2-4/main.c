#include <crtdbg.h>
#include "teste.h"
#include "ui.h"


int main() {
	run_all_tests();
	run();
	
	_CrtDumpMemoryLeaks();

	return 0;
}