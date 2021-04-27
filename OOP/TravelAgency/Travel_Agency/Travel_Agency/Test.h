#pragma once

#include "ValueObject.h"
#include "DynamicArray.h"
#include "Repository.h"
#include "Validator.h"
#include "Exception.h"
#include "Service.h"
#include "WishList.h"

#include <iostream>
#include <assert.h>

class TestTravelAgency {

public:
	void runAllTests() const;

private:

	void runDomainTests() const;

	void runDynamicArrayTests() const;

	void runRepositoryTests(Repository& repository) const;

	void runFileRepositoryTests() const;

	void runLabActivityRepositoryTests() const;

	void runValidatorTests() const;

	void runExceptionTests() const;

	void runServiceCrudTests() const;

	void runServiceUndoTests() const;

	void runServiceFindTests() const;

	void runServiceFiltrationTests() const;

	void runServiceSortTests() const;

	void runWishListTests() const;

	void runWishListServiceTests() const;

	void runDtoOfferTests() const;
};