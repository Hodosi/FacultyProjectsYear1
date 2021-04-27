#pragma once

#include "service.h"

typedef struct {
    ServiceImmobile* service_immobile;
}UserInterfaceImmobile;

/*
 * create an user interface
 * input:  a pointer to a service
 *         - the service must be exists
 * output: a pointer to an user interface
 */
UserInterfaceImmobile* createUserInterface(ServiceImmobile*);

/*
 * destroy an user interface and the dependent service
 * input:  a pointer to an user interface
 *         - the user interface must be exists
 */
void destroyUserInterface(UserInterfaceImmobile*);

/*
 * starts the user interface
 * input:  a pointer to an user interface
 *         - the user interface must be exists
 */
void runUserInterface(UserInterfaceImmobile*);