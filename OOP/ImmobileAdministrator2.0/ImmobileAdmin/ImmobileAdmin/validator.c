#include "validator.h"

#include <string.h>

int validateApartmentNumber(int repo_size, int number_of_apartment) {
    if (number_of_apartment < 0) {
        return 2;
    }
    if (number_of_apartment >= repo_size) {
        return 2;
    }
    return 0;
}

int validateType(char* type) {
    if (strlen(type) == 0) {
        return 2;
    }
    if (strcmp(type, "water") == 0) {
        return 0;
    }
    if (strcmp(type, "sewer") == 0) {
        return 0;
    }
    if (strcmp(type, "heating") == 0) {
        return 0;
    }
    if (strcmp(type, "gas") == 0) {
        return 0;
    }
    return 2;
}

int validateCosts(double min_cost, double max_cost) {
    if (min_cost > max_cost) {
        return 2;
    }
    return 0;
}