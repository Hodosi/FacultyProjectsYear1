#define _CRTDBG_MAP_ALLOC

#include "userInterface.h"
#include "test.h"

#include <stdio.h>
#include <crtdbg.h>


int main() {
    runAllTests();
    
    
    RepositoryImmobile* repository_immobile = createRepository();
    ServiceImmobile* service_immobile = createService(repository_immobile);
    UserInterfaceImmobile* ui_immobile = createUserInterface(service_immobile);

    runUserInterface(ui_immobile);

    destroyUserInterface(ui_immobile);

    printf("Ohh yes");
    
    
    _CrtDumpMemoryLeaks();

    return 0;
}