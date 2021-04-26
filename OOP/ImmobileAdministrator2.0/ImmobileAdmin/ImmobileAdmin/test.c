#include "test.h"
#include "service.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>

void runDomainTests() {
    printf("Start of domain tests...\n");

    // expense tests
    //////////////////////////////////////////////////////////////////////////

    int number_of_apartment = 1;
    double cost = 4.5;
    char type[256] = "water";
    char test_type[256];

    // create test
    Expense* expense = createExpense(number_of_apartment, cost, type);

    assert(getApartmentNumberOfExpense(expense) == number_of_apartment);
    assert(getCost(expense) == cost);
    getType(expense, test_type);
    assert(strcmp(test_type, type) == 0);

    // destroy test
    destroyExpense(expense);

    // apartment tests
    //////////////////////////////////////////////////////////////////////////

    // create test
    Apartment *apartment = createApartment(number_of_apartment);

    // test number of apartment
    assert(getApartmentNumber(apartment) == number_of_apartment);

    // test number of expenses and cost
    double new_cost = 8.9;
    for (int i = 0; i < apartment -> number_of_expenses; i++) {
        assert(getApartmentNumberOfExpense(apartment -> expenses[i]) == number_of_apartment);
        assert(getCost(apartment -> expenses[i]) == 0);
        setCost(apartment -> expenses[i], new_cost);
        assert(getCost(apartment -> expenses[i]) == new_cost);
    }

    // test get cost by valid type
    cost = getCostByType(apartment, type);
    assert(fabs(cost - new_cost) < 0.01);

    // test get cost by invalid type
    cost = getCostByType(apartment, "sistem");
    assert(cost == 0);

    // test set cost by type
    cost = 6.7;
    setCostByType(apartment, type, cost);
    new_cost = getCostByType(apartment, type);
    assert(fabs(cost - new_cost) < 0.01);

    // test type
    getType(apartment->expenses[0], type);
    assert(strcmp(type, "water") == 0);

    getType(apartment->expenses[1], type);
    assert(strcmp(type, "sewer") == 0);

    getType(apartment->expenses[2], type);
    assert(strcmp(type, "heating") == 0);

    getType(apartment->expenses[3], type);
    assert(strcmp(type, "gas") == 0);

    // destroy test
    destroyApartment(apartment);

    printf("End of domain tests...\n");
}

void runRepositoryTests() {
    printf("Start of repository tests...\n");

    int number_of_apartment = 0;
    Apartment *apartment = createApartment(number_of_apartment);

    // create test
    RepositoryImmobile *repository = createRepository();

    assert(getRepositorySize(repository) == 0);

    addApartment(repository, apartment);

    assert(getRepositorySize(repository) == 1);

    // get all apartments test
    DynamicVector* vector = getAllApartments(repository);

    assert(getApartmentNumber(vector -> items[0]) == number_of_apartment);

    // get valid apartment test
    Apartment* new_apartment = getApartmentByNumber(repository, number_of_apartment);
    assert(getApartmentNumber(new_apartment) == number_of_apartment);

    // get invalid apartment test
    new_apartment = getApartmentByNumber(repository, -2);
    assert(new_apartment == NULL);

    // destroy test
    destroyRepository(repository);

    printf("End of repository tests...\n");
}

void crudTests(ServiceImmobile *service, int (*crud_operation)(ServiceImmobile*, int, double, char*)) {
    int number_of_apartment;
    double cost;
    char type[256];

    // invalid number
    number_of_apartment = -1;
    cost = 4.5;
    strcpy_s(type, strlen("water") + 1, "water");
    assert(crud_operation(service, number_of_apartment, cost, type) != 0);

    number_of_apartment = 2;
    cost = 4.5;
    strcpy_s(type, strlen("water") + 1, "water");
    assert(crud_operation(service, number_of_apartment, cost, type) != 0);

    // invalid type
    number_of_apartment = 1;
    cost = 4.5;
    strcpy_s(type, strlen("") + 1, "");
    assert(crud_operation(service, number_of_apartment, cost, type) != 0);

    number_of_apartment = 1;
    cost = 4.5;
    strcpy_s(type, strlen("yes sir") + 1, "yes sir");
    assert(crud_operation(service, number_of_apartment, cost, type) != 0);

    // valid type and number
    number_of_apartment = 1;
    cost = 4.5;
    strcpy_s(type, strlen("water") + 1, "water");
    assert(crud_operation(service, number_of_apartment, cost, type) == 0);

    number_of_apartment = 1;
    cost = 4.5;
    strcpy_s(type, strlen("sewer") + 1, "sewer");
    assert(crud_operation(service, number_of_apartment, cost, type) == 0);

    number_of_apartment = 1;
    cost = 4.5;
    strcpy_s(type, strlen("heating") + 1, "heating");
    assert(crud_operation(service, number_of_apartment, cost, type) == 0);

    number_of_apartment = 1;
    cost = 4.5;
    strcpy_s(type, strlen("gas") + 1, "gas");
    assert(crud_operation(service, number_of_apartment, cost, type) == 0);
}

void runServiceCrudTests() {
    printf("Start of service tests...\n");

    RepositoryImmobile* repository = createRepository();

    // create test
    //////////////////////////////////////////////////////////////////////////
    ServiceImmobile* service = createService(repository);

    int number_of_apartments = 2;

    // generate apartments test
    generateApartments(service, number_of_apartments);

    // get all apartments test
    DynamicVector* vector = getApartments(service);

    assert(getApartmentNumber(vector->items[0]) == 0);
    assert(getApartmentNumber(vector->items[1]) == 1);

    // add expense test with valid input
    int number_of_apartment = 1;
    double cost = 4.5;
    double cost_before, cost_after, new_cost;
    char type[256] = "gas";

    // add expense test
    Apartment* apartment = getApartmentByNumber(repository, number_of_apartment);
    cost_before = getCostByType(apartment, type);
    addExpense(service, number_of_apartment, cost, type);
    cost_after = getCostByType(apartment, type);

    new_cost = cost_before + cost;
    assert(fabs(new_cost - cost_after) < 0.001);

    crudTests(service, addExpense);

    // modify expense
    //////////////////////////////////////////////////////////////////////////
    cost = 7.53;
    modifyExpense(service, number_of_apartment, cost, type);
    cost_after = getCostByType(apartment, type);

    assert(fabs(cost - cost_after) < 0.001);

    crudTests(service, modifyExpense);

    // delete expense
    //////////////////////////////////////////////////////////////////////////
    deleteExpense(service, number_of_apartment, type);
    cost_after = getCostByType(apartment, type);

    assert(fabs(0.0 - cost_after) < 0.001);

    // add expense test with invalid input
    // invalid number
    number_of_apartment = -1;
    strcpy_s(type, strlen("water") + 1, "water");
    assert(deleteExpense(service, number_of_apartment, type) != 0);

    number_of_apartment = 2;
    strcpy_s(type, strlen("water") + 1, "water");
    assert(deleteExpense(service, number_of_apartment, type) != 0);

    // invalid type
    number_of_apartment = 1;
    strcpy_s(type, strlen("") + 1, "");
    assert(deleteExpense(service, number_of_apartment, type) != 0);

    number_of_apartment = 1;
    strcpy_s(type, strlen("yes sir") + 1, "yes sir");
    assert(deleteExpense(service, number_of_apartment, type) != 0);

    // valid type and number
    number_of_apartment = 1;
    strcpy_s(type, strlen("water") + 1, "water");
    assert(deleteExpense(service, number_of_apartment, type) == 0);

    number_of_apartment = 1;
    strcpy_s(type, strlen("sewer") + 1, "sewer");
    assert(deleteExpense(service, number_of_apartment, type) == 0);

    number_of_apartment = 1;
    strcpy_s(type, strlen("heating") + 1, "heating");
    assert(deleteExpense(service, number_of_apartment, type) == 0);

    number_of_apartment = 1;
    strcpy_s(type, strlen("gas") + 1, "gas");
    assert(deleteExpense(service, number_of_apartment, type) == 0);

    destroyService(service);

    printf("End of service tests...\n");
}

void runServiceFiltrationAndSortingTests() {
    printf("Start of service tests...\n");
    RepositoryImmobile *repository_filtration = createRepository();
    ServiceImmobile *service_filtration = createService(repository_filtration);

    int number_of_apartments, number_of_apartment;
    double cost;
    char type[256];
    number_of_apartments = 4;
    generateApartments(service_filtration, number_of_apartments);

    number_of_apartment = 0;
    cost = 4.5;
    strcpy_s(type, strlen("gas") + 1, "gas");
    addExpense(service_filtration, number_of_apartment, cost, type);

    number_of_apartment = 1;
    cost = 3.7;
    strcpy_s(type, strlen("gas") + 1, "gas");
    addExpense(service_filtration, number_of_apartment, cost, type);

    number_of_apartment = 2;
    cost = 6.8;
    strcpy_s(type, strlen("gas") + 1, "gas");
    addExpense(service_filtration, number_of_apartment, cost, type);

    number_of_apartment = 3;
    cost = 5.1;
    strcpy_s(type, strlen("gas") + 1, "gas");
    addExpense(service_filtration, number_of_apartment, cost, type);

    double sum_min = 4.9;
    double sum_max = 7.8;

    // test filtration
    //////////////////////////////////////////////////////////////////////////
    Element items;
    items = filtrationBySumAndType(service_filtration, sum_min, sum_max, "war");
    assert(items == NULL);
    items = filtrationBySumAndType(service_filtration, 5, 2, "water");
    assert(items == NULL);

    items = filtrationBySumAndType(service_filtration, sum_min, sum_max, type);

    DynamicVector* vector_filtration = items;

    Apartment* apartment_filtration;

    apartment_filtration = vector_filtration -> items[0];

    double test_cost = getCostByType(apartment_filtration, "gas");
    cost = 6.8;
    assert(fabs(test_cost - cost) < 0.0001);

    apartment_filtration = vector_filtration -> items[1];

    test_cost = getCostByType(apartment_filtration, "gas");
    cost = 5.1;
    assert(fabs(test_cost - cost) < 0.0001);

    for (int i = 0; i < vector_filtration->length; i++) {
        destroyApartment(vector_filtration->items[i]);
    }
    destroyDynamicVector(vector_filtration);

    // test sorting
    //////////////////////////////////////////////////////////////////////////

    // invalid type
    items = sortingApartmentsBySum(service_filtration, "love", 1);
    assert(items == NULL);

    DynamicVector *vector_sorting;
    Apartment *apartment_sorting;

    // descending
    items = sortingApartmentsBySum(service_filtration, "gas", 2);
    vector_sorting = items;

    apartment_sorting = vector_sorting->items[0];

    cost = 6.8;
    test_cost = getCostByType(apartment_sorting, "gas");
    assert(fabs(test_cost - cost) < 0.0001);

    apartment_sorting = vector_sorting->items[3];

    cost = 3.7;
    test_cost = getCostByType(apartment_sorting, "gas");
    assert(fabs(test_cost - cost) < 0.0001);

    for (int i = 0; i < vector_sorting->length; i++) {
        destroyApartment(vector_sorting->items[i]);
    }
    destroyDynamicVector(vector_sorting);

    // ascending
    items = sortingApartmentsBySum(service_filtration, "gas", 1);
    vector_sorting = items;

    apartment_sorting = vector_sorting->items[0];

    cost = 3.7;
    test_cost = getCostByType(apartment_sorting, "gas");
    assert(fabs(test_cost - cost) < 0.0001);

    apartment_sorting = vector_sorting->items[3];

    cost = 6.8;
    test_cost = getCostByType(apartment_sorting, "gas");
    assert(fabs(test_cost - cost) < 0.0001);

    for (int i = 0; i < vector_sorting->length; i++) {
        destroyApartment(vector_sorting->items[i]);
    }
    destroyDynamicVector(vector_sorting);

    destroyService(service_filtration);
    printf("End of service tests...\n");
}

void runAllTests() {
    runDomainTests();
    runRepositoryTests();
    runServiceCrudTests();
    runServiceFiltrationAndSortingTests();
}