#pragma once

/*
 * validate an apartment number
 * it must be between 0 and the apartment size - 1
 * input:  the size of repository witch contains the apartments
 *         - an integer
 *         the number of apartment
 *         - an integer
 * output: 0 if the apartment number exists
 *         2 if the apartment number not exists
 */
int validateApartmentNumber(int, int);

/*
 * validate an expense type
 * it must be water, sewer, heating or gas
 * input: a pointer to a char
 * output: 0 if the type is valid
 *         2 if the type is not valid
 */
int validateType(char*);

/*
 * validate min an max cost
 * the min cost must be smaller than max cost
 * input: min cost
 *        - double
 *        max cost
 *        - double
 * output: 0 if the costs are valid
 *         2 id the costs are not valid
 */
int validateCosts(double, double);