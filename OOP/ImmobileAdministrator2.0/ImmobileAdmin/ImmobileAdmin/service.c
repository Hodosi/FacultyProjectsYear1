#include "service.h"
#include "validator.h"
#include "valueObject.h"

#include <stdlib.h>
#include <stdbool.h>


ServiceImmobile* createService(RepositoryImmobile *repository_immobile) {
    ServiceImmobile* service = (ServiceImmobile*)malloc(sizeof(ServiceImmobile));

    service -> repository_immobile = repository_immobile;

    return service;
}

void destroyService(ServiceImmobile *service_immobile) {
    destroyRepository(service_immobile -> repository_immobile);
    free(service_immobile);
}

void generateApartments(ServiceImmobile *service, int number_of_apartments) {
    Apartment* apartment;
    int number_of_apartment;
    for (number_of_apartment = 0; number_of_apartment < number_of_apartments; number_of_apartment++) {
        apartment = createApartment(number_of_apartment);
        addApartment(service -> repository_immobile, apartment);
    }
}

Element getApartments(ServiceImmobile *service) {
    return getAllApartments(service -> repository_immobile);
}

int addExpense(ServiceImmobile *service, int number_of_apartment, double cost, char *type) {
    int repo_size = getRepositorySize(service -> repository_immobile);

    if (validateApartmentNumber(repo_size, number_of_apartment) != 0) {
        return 2;
    }

    if (validateType(type) != 0) {
        return 2;
    }

    addApartmentExpense(service->repository_immobile, number_of_apartment, cost, type);

    return 0;
}

int modifyExpense(ServiceImmobile *service, int number_of_apartment, double cost, char *type) {
    int repo_size = getRepositorySize(service -> repository_immobile);

    if (validateApartmentNumber(repo_size, number_of_apartment) != 0) {
        return 2;
    }

    if (validateType(type) != 0) {
        return 2;
    }

    modifyApartmentExpense(service -> repository_immobile, number_of_apartment, cost, type);

    return 0;
}

int deleteExpense(ServiceImmobile *service, int number_of_apartment, char *type) {
    int repo_size = getRepositorySize(service -> repository_immobile);

    if (validateApartmentNumber(repo_size, number_of_apartment) != 0) {
        return 2;
    }

    if (validateType(type) != 0) {
        return 2;
    }

    deleteApartmentExpense(service -> repository_immobile, number_of_apartment, type);

    return 0;
}

Element filtrationBySumAndType(ServiceImmobile *service, double min_cost, double max_cost, char *type) {
    if (validateCosts(min_cost, max_cost) != 0) {
        return NULL;
    }

    if (validateType(type) != 0) {
        return NULL;
    }

    Element items = getAllApartments(service -> repository_immobile);
    DynamicVector* vector_filtration = items;

    Element res_of_filtration = createDynamicVector();

    Apartment *apartment, *copy_apartment;

    int size = vector_filtration->length;
    double cost;
    for (int i = 0; i < size; i++) {
        apartment = vector_filtration->items[i];
        cost = getCostByType(apartment, type);
        if (min_cost <= cost && cost <= max_cost) {
            copy_apartment = copyApartment(apartment);
            add(res_of_filtration, copy_apartment);
        }
    }

    return res_of_filtration;
}

Element mySpecialSorting(DynamicVector *res_of_sorting, char *type, int mode, bool (*cmp)(Apartment*, Apartment*, int, char*)) {
    Apartment *apartment_i, *apartment_j;
    int size = res_of_sorting -> length;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            apartment_i = res_of_sorting->items[i];
            apartment_j = res_of_sorting->items[j];
            if (cmp(apartment_i, apartment_j, mode, type)) {
                res_of_sorting->items[i] = apartment_j;
                res_of_sorting->items[j] = apartment_i;
            }
        }
    }

    return res_of_sorting;
}

bool compareFunction(Apartment* ap1, Apartment* ap2, int mode, char* type) {
    double cost_1, cost_2;
    cost_1 = getCostByType(ap1, type);
    cost_2 = getCostByType(ap2, type);
    if (mode == 1) {
        if (cost_1 > cost_2) {
            return true;
        }
        return false;
    }
    if (cost_1 < cost_2) {
        return true;
    }
    return false;
}

Element sortingApartmentsBySum(ServiceImmobile *service, char *type, int mode) {
    if (validateType(type) != 0) {
        return NULL;
    }

    Element items = getAllApartments(service->repository_immobile);
    DynamicVector *vector_sorting = items;

    DynamicVector *res_of_sorting = createDynamicVector();

    Apartment *apartment, *copy_apartment;

    int size = vector_sorting->length;

    for (int i = 0; i < size; i++) {
        apartment = vector_sorting->items[i];
        copy_apartment = copyApartment(apartment);
        add(res_of_sorting, copy_apartment);
    }

    return mySpecialSorting(res_of_sorting, type, mode, compareFunction);
}