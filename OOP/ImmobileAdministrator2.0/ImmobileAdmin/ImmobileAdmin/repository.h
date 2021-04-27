#pragma once

#include "valueObject.h"
#include "dynamicVector.h"

typedef struct {
    DynamicVector* dynamic_vector;
    //DynamicStaticVector* dynamic_vector;
}RepositoryImmobile;

/*
 * create a repository and a general list
 * input: -
 * output: a pointer to a repository
 */
RepositoryImmobile* createRepository();

/*
 * destroy the repository and the dependent general list
 * input:  a pointer to a service
 *         - the service must be exists
 */
void destroyRepository(RepositoryImmobile*);

/*
 * add an apartment in the general list
 * input:  a pointer to a repository
 *         - the repository must be exists
 *         a pointer to an apartment
 *         - the apartment must be exists
 *         - the apartment must be different from the existent apartments
 */
void addApartment(RepositoryImmobile*, Apartment*);

/*
* return all elements from the general list
* input:  a pointer to repository
*         - the repository must be exists
* output: - a generic pointer to a pointer list
*/
Element getAllApartments(RepositoryImmobile*);

/*
* return the number elements from the general list
* input:  a pointer to repository
*         - the repository must be exists
* output: - a generic pointer to a pointer list
*/
int getRepositorySize(RepositoryImmobile*);

/*
 * add an expense to an apartment
 * input:  a pointer to a repository
 *         - the repository must be exists
 *         the number of apartment
 *         - the number must be an integer
 *         - the number must ba a valid apartment number
 *         the cost of expense
 *         - the number must be a double
 *         - the number must be valid
 *         the type of expense
 *         - the type must be a address to a string
 *         - the type must a valid apartment expense
 */
void addApartmentExpense(RepositoryImmobile*, int, double, char*);

/*
 * modify an expense to an apartment
 * input:  a pointer to a repository
 *         - the repository must be exists
 *         the number of apartment
 *         - the number must be an integer
 *         - the number must ba a valid apartment number
 *         the cost of expense
 *         - the number must be a double
 *         - the number must be valid
 *         the type of expense
 *         - the type must be an address to a string
 *         - the type must a valid apartment expense
 */
void modifyApartmentExpense(RepositoryImmobile*, int, double, char*);

/*
 * delete an expense to an apartment
 * input:  a pointer to a repository
 *         - the repository must be exists
 *         the number of apartment
 *         - the number must be an integer
 *         - the number must ba a valid apartment number
 *         the type of expense
 *         - the type must be an address to a string
 *         - the type must a valid apartment expense
 */
void deleteApartmentExpense(RepositoryImmobile*, int, char*);

/*
 * return a pointer to an apartment
 * input:  a pointer to a repository
 *         - the repository must be exists
 *         the number of apartment
 *         - the number must be an integer
 *         - the number must ba a valid apartment number
 * output: - a pointer to an apartment
 *         - NULL if the apartment number is invalid
 */
Apartment* getApartmentByNumber(RepositoryImmobile*, int);