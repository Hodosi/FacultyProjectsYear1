//
// Created by Hodosi on 3/5/2021.
//

#include "service.h"
#include <stdlib.h>
#include <stdbool.h>

#include "../validation/validator.h"

ServiceImmobile* createService(RepositoryImmobile *repository_immobile){
    ServiceImmobile *service = (ServiceImmobile*)malloc(sizeof(ServiceImmobile));

    service -> repository_immobile = repository_immobile;

    return service;
}

void destroyService(ServiceImmobile *service_immobile){
    destroyRepository(service_immobile -> repository_immobile);
    free(service_immobile);
}

void generateApartments(ServiceImmobile *service, int number_of_apartments){
    Apartment *apartment;
    for(int number_of_apartment = 0; number_of_apartment < number_of_apartments; number_of_apartment++){
        apartment = createApartment(number_of_apartment);
        addApartment(service -> repository_immobile, apartment);
    }
}

Element getApartments(ServiceImmobile *service){
    return getAllApartments(service -> repository_immobile);
}

int addExpense(ServiceImmobile *service, int number_of_apartment, double cost, char *type){
    int repo_size = getRepositorySize(service -> repository_immobile);

    if(validateApartmentNumber(repo_size, number_of_apartment) != 0){
        return 2;
    }
    if(validateType(type) != 0){
        return 2;
    }

    addApartmentExpense(service -> repository_immobile, number_of_apartment, cost, type);

    return 0;
}

int modifyExpense(ServiceImmobile *service, int number_of_apartment, double cost, char *type){
    int repo_size = getRepositorySize(service -> repository_immobile);

    if(validateApartmentNumber(repo_size, number_of_apartment) != 0){
        return 2;
    }
    if(validateType(type) != 0){
        return 2;
    }

    modifyApartmentExpense(service -> repository_immobile, number_of_apartment, cost, type);

    return 0;
}

int deleteExpense(ServiceImmobile *service, int number_of_apartment,  char *type){
    int repo_size = getRepositorySize(service -> repository_immobile);

    if(validateApartmentNumber(repo_size, number_of_apartment) != 0){
        return 2;
    }
    if(validateType(type) != 0){
        return 2;
    }

    deleteApartmentExpense(service -> repository_immobile, number_of_apartment, type);

    return 0;
}

Element filtrationBySumAndType(ServiceImmobile *service, double min_cost, double max_cost, char *type){
    if(validateCosts(min_cost, max_cost) != 0){
        return NULL;
    }
    if(validateType(type) != 0){
        return NULL;
    }

    Element items = getAllApartments(service -> repository_immobile);

    DynamicVector *vector_filtration = items;
    //DynamicStaticVector *vector_filtration = items;

    Element res_of_filtration = createDynamicVector();
    //Element res_of_filtration = createDynamicStaticVector();

    Apartment *apartment, *copy_apartment;

    int size = vector_filtration -> length;
    double cost;
    for(int i = 0; i < size; i++){
        apartment = vector_filtration -> items[i];
        cost = getCostByType(apartment, type);
        if(min_cost <= cost && cost <= max_cost){
            copy_apartment = copyApartment(apartment);
            add(res_of_filtration, copy_apartment);
            //addStatic(res_of_filtration, copy_apartment);
        }
    }

    return res_of_filtration;
}



Element mySpecialSorting(DynamicVector *res_of_sorting, char *type, int mode, bool (*cmp)(double, double, int)){

    Apartment *apartment_i, *apartment_j;
    double cost_i, cost_j;
    int size = res_of_sorting -> length;
    for(int i = 0; i < size - 1; i++){
        for(int j = i+1; j < size; j++){
            apartment_i = res_of_sorting -> items[i];
            apartment_j = res_of_sorting -> items[j];
            cost_i = getCostByType(apartment_i, type);
            cost_j = getCostByType(apartment_j, type);
            if(cmp(cost_i, cost_j, mode)) {
                res_of_sorting->items[i] = apartment_j;
                res_of_sorting->items[j] = apartment_i;
            }
        }
    }

    return res_of_sorting;
}

bool compareFunction(double cost_1, double cost_2, int mode){
    if(mode == 1){
        if(cost_1 > cost_2){
            return true;
        }
        return false;
    }
    else if (cost_1 < cost_2){
        return true;
    }
    return false;
}

Element sortingApartmentsBySum(ServiceImmobile *service, char *type, int mode){
    if(validateType(type) != 0){
        return NULL;
    }

    Element items = getAllApartments(service -> repository_immobile);

    DynamicVector *vector_sorting = items;
    //DynamicStaticVector *vector_sorting = items;

    DynamicVector *res_of_sorting = createDynamicVector();
    //DynamicStaticVector *res_of_sorting = createDynamicStaticVector();

    Apartment *apartment, *apartment_i, *apartment_j, *copy_apartment;

    int size = vector_sorting -> length;
    double cost_i, cost_j;

    for(int i = 0; i < size; i++){
        apartment = vector_sorting -> items[i];
        copy_apartment = copyApartment(apartment);
        add(res_of_sorting, copy_apartment);
        //addStatic(res_of_sorting, copy_apartment);
    }



    /*
    for(int i = 0; i < size - 1; i++){
        for(int j = i+1; j < size; j++){
            apartment_i = res_of_sorting -> items[i];
            apartment_j = res_of_sorting -> items[j];
            cost_i = getCostByType(apartment_i, type);
            cost_j = getCostByType(apartment_j, type);
            if(cost_i > cost_j) {
                res_of_sorting->items[i] = apartment_j;
                res_of_sorting->items[j] = apartment_i;
            }
        }
    }
    */

    return mySpecialSorting(res_of_sorting, type, mode, compareFunction);
}