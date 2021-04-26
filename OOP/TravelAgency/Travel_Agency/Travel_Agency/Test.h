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
<<<<<<< HEAD
<<<<<<< HEAD

public:
=======
public:
	//TestTravelAgency() {};

>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
public:
	//TestTravelAgency() {};

>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	void runAllTests() const;

private:

	void runDomainTests() const;

	void runDynamicArrayTests() const;

	void runRepositoryTests(Repository& repository) const;

	void runFileRepositoryTests() const;

<<<<<<< HEAD
<<<<<<< HEAD
	void runLabActivityRepositoryTests() const;

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	void runValidatorTests() const;

	void runExceptionTests() const;

	void runServiceCrudTests() const;

<<<<<<< HEAD
<<<<<<< HEAD
	void runServiceUndoTests() const;

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	void runServiceFindTests() const;

	void runServiceFiltrationTests() const;

	void runServiceSortTests() const;

	void runWishListTests() const;

	void runWishListServiceTests() const;

	void runDtoOfferTests() const;
};