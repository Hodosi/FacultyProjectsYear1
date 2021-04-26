#include "presentation/userInterface.h"

#include "test/test.h"
#define _CRTDBG_MAP_ALLOC

int main() {
    runAllTests();

    RepositoryImmobile *repository_immobile = createRepository();
    ServiceImmobile *service_immobile = createService(repository_immobile);
    UserInterfaceImmobile *ui_immobile = createUserInterface(service_immobile);

    runUserInterface(ui_immobile);

    destroyUserInterface(ui_immobile);

    _CrtDumpMemoryLeaks();
    return 0;
}
