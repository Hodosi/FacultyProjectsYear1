//
// Created by Hodosi on 3/5/2021.
//

#ifndef IMMOBILEADMINISTRATOR_VALUEOBJECT_H
#define IMMOBILEADMINISTRATOR_VALUEOBJECT_H

/*
 * define expense data type
 * number_of_apartment: - int
 *                      - the number of dependent apartment
 * cost: - double
 *       - the cost of expense
 * (*type): - pointer la char
 *          - the type of expense
 *          - can be (water, sewer, heating, gas)
 */
typedef struct {
    int number_of_apartment;
    double cost;
    char *type;
} Expense;

/*
 * define apartment data type
 * number_of_apartment: - int
 *                      - the number of apartment
 * number_of_expenses: - int
 *                     - the number of expenses
 * (**expenses): - a pointer to a expenses pointer list
 */
typedef struct{
    int number_of_apartment;
    int number_of_expenses;
    Expense **expenses;
} Apartment;

/*
 * create an expense to an apartment
 * input:  the number of apartment
 *         - the number must be an integer
 *         - the number must ba a valid apartment number
 *         the cost of expense
 *         - the number must be a double
 *         - the number must be valid
 *         the type of expense
 *         - the type must be a address to a string
 *         - the type must a valid apartment expense
 * output: a pointer to a valid expense
 */
Expense* createExpense(int, double, char*);

/*
 * destroy an expense
 * input:  a pointer to an expense
 *         - the expense must be exists
 */
void destroyExpense(Expense*);

/*
 * copy an expense
 * input:  a pointer to an expense
 *         - the expense must be exists
 * output: a pointer to a new expense
 */
Expense* copyExpense(Expense*);

/*
 * return the dependent apartment number of expense
 * input:  a pointer to an expense
 *         - the expense must be exists
 * output: a valid apartment number
 *         an integer
 */
int getApartmentNumberOfExpense(Expense*);

/*
 * return the cost of an expense
 * input:  a pointer to an expense
 *         - the expense must be exists
 * output: the cost of expense
 *         - a double
 */
double getCost(Expense*);

/*
* set the cost of an expense
* input:  a pointer to an expense
*         - the expense must be exists
*/
void setCost(Expense*, double);

/*
* set the type of an expense
* input:  a pointer to an expense
*         - the expense must be exists
*/
void getType(Expense*, char*);

/*
 * create an apartment with empty expenses
 * input:  the number of apartments
 *         - the number must be an integer greater than 0
 * output: a pointer to a new apartment
 */
Apartment* createApartment(int);

/*
 * destroy an apartment and the dependent expenses
 * input:  a pointer to an apartment
 *         - the apartment must be exists
 */
void destroyApartment(Apartment*);

/*
 * copy an apartment
 * input:  a pointer to an apartment
 *         - the apartment must be exists
 * output: a pointer to a new apartment
 */
Apartment* copyApartment(Apartment*);

/*
 * return the number of an apartment
 * input:  a pointer to an apartments
 *         - the apartment must be exists
 * output: a valid apartment number
 *         - an integer
 */
int getApartmentNumber(Apartment*);

/*
 * return the cost of an apartment expense specified by type
 * input:  a pointer to an apartments
 *         - the apartment must be exists
 *         the type of expense
 *         - the type must be a address to a string
 *         - the type must a valid apartment expense
 * output: the cost of expense dependent of apartment specified by type
 *         - a double
 */
double getCostByType(Apartment* apartment, char* type);

/*
 * set the cost of an apartment expense specified by type
 * input:  a pointer to an apartments
 *         - the apartment must be exists
 *         the type of expense
 *         - the type must be a address to a string
 *         - the type must a valid apartment expense
 *         the new cost of expense
 *         - the number must be a double
 *         - the number must be valid
 */
void setCostByType(Apartment*, char*, double);

#endif //IMMOBILEADMINISTRATOR_VALUEOBJECT_H
