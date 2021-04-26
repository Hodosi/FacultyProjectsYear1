#pragma once

#include "valueObject.h"
#include "repository.h"

typedef struct {
    RepositoryImmobile* repository_immobile;
}ServiceImmobile;

/*
 * create a service
 * input:  a pointer to a repository
 *         - the repository must be exists
 * output: a pointer to a service
 */
ServiceImmobile* createService(RepositoryImmobile*);

/*
 * destroy a service and the dependent repository
 * input:  a pointer to a service
 *         - the service must be exists
 */
void destroyService(ServiceImmobile*);

/*
 * generate apartments with empty expenses
 * input:  a pointer to a service
 *         - the service must be exists
 *         the number of apartments
 *         - the number must be an integer greater than 0
 * output: -
 *         the apartments will be add in repository
 *         the apartments number will be between 0 and n - 1
 */
void generateApartments(ServiceImmobile*, int);

/*
 * return all elements from repository
 * input:  a pointer to a service
 *         - the service must be exists
 * output: - a generic pointer to a pointer list
 */
Element getApartments(ServiceImmobile*);

/*
 * add an expense to an apartment
 * input:  a pointer to a service
 *         - the service must be exists
 *         the number of apartment
 *         - the number must be an integer
 *         the cost of expense
 *         - the number must be a double
 *         the type of expense
 *         - the type must be an address to a string
 * output: 0 if the expense was added
 *         2 if the input data was invalid
 */
int addExpense(ServiceImmobile*, int, double, char*);

/*
 * modify an expense to an apartment
 * input:  a pointer to a service
 *         - the service must be exists
 *         the number of apartment
 *         - the number must be an integer
 *         the cost of expense
 *         - the number must be a double
 *         the type of expense
 *         - the type must be an address to a string
 * output: 0 if the expense was modified
 *         2 if the input data was invalid
 */
int modifyExpense(ServiceImmobile*, int, double, char*);

/*
 * delete an expense to an apartment
 * input:  a pointer to a service
 *         - the service must be exists
 *         the number of apartment
 *         - the number must be an integer
 *         the type of expense
 *         - the type must be an address to a string
 * output: 0 if the expense was deleted
 *         2 if the input data was invalid
 */
int deleteExpense(ServiceImmobile*, int, char*);

/*
 * filter the apartments list from repository by a type between a minimal and maximal cost
 * input:  a pointer to a service
 *         - the service must be exists
 *         the minimal cost of expense
 *         - the number must be a double
 *         the maximal cost of expense
 *         - the number must be a double
*          the type of expense
 *         - the type must be an address to a string
 * output: a generic pointer to a new apartments pointer list if the apartments was filtered
 *         - if you use this function you have to destroy the list!!!
 *         NULL if the input data was invalid
 */
Element filtrationBySumAndType(ServiceImmobile*, double, double, char*);

/*
 * sort the apartments list from repository by sum of a type
 * input:  a pointer to a service
 *         - the service must be exists
*          the type of expense
 *         - the type must be an address to a string
 * output: a generic pointer to a new apartments pointer list if the apartments was filtered
 *         - if you use this function you have to destroy the list!!!
 *         NULL if the input data was invalid
 */
Element sortingApartmentsBySum(ServiceImmobile*, char*, int);