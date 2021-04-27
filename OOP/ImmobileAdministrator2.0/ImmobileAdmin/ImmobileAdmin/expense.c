#include "valueObject.h"

#include <string.h>
#include <stdlib.h>

//water, sewer, heating, gas
Expense* createExpense(int number_of_apartment, double cost, char *type) {
    Expense *expense = (Expense*)malloc(sizeof(Expense));

    expense -> number_of_apartment = number_of_apartment;
    expense -> cost = cost;
    expense -> type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
    strcpy_s(expense -> type, strlen(type) + 1, type);

    return expense;
}

void destroyExpense(Expense *expense) {
    free(expense -> type);
    free(expense);
}

Expense* copyExpense(Expense *expense) {
    int number_of_apartment = expense->number_of_apartment;
    double cost = expense -> cost;
    char *type = expense -> type;
    return createExpense(number_of_apartment, cost, type);
}

int getApartmentNumberOfExpense(Expense *expense) {
    return expense -> number_of_apartment;
}

double getCost(Expense *expense) {
    return expense -> cost;
}

void setCost(Expense *expense, double new_cost) {
    expense -> cost = new_cost;
}

void getType(Expense *expense, char *type) {
    strcpy_s(type, strlen(expense -> type) + 1, expense->type);
}