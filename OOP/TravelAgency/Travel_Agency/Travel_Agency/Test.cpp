#include "Test.h"

void TestTravelAgency::runDomainTests() const {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	string name{ "travel" };
	string destination{ "paris" };
	string type{ "full" };
	double price{ 123.32 };

	// create offer
	TouristOffer offer{ name, destination, type, price };

	// test getters
	assert(offer.getName() == name);
	assert(offer.getDestination() == destination);
	assert(offer.getType() == type);
	assert(offer.getPrice() == price);

	destination = "roma";
	type = "empty";
	price = 43.42;

	// create new offer
	TouristOffer other{ name, destination, type, price };

	// test getters
	assert(offer.getDestination() != destination);
	assert(offer.getType() != type);
	assert(offer.getPrice() != price);

	// test setters
	offer.setDestination(destination);
	offer.setType(type);
	offer.setPrice(price);

	assert(offer.getDestination() == destination);
	assert(offer.getType() == type);
	assert(offer.getPrice() == price);

	// test operator ==
	assert(offer == other);
}

void TestTravelAgency::runDynamicArrayTests() const {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	// constructor
	DynamicVector<int> dynamic_array;

	// size
	assert(dynamic_array.size() == 0);

	// push_back
	dynamic_array.push_back(3);
	dynamic_array.push_back(1);
	dynamic_array.push_back(5);
	dynamic_array.push_back(4);
	dynamic_array.push_back(2);

	assert(dynamic_array.size() == 5);

	// copy assignment operator
	dynamic_array = dynamic_array;
	assert(dynamic_array.size() == 5);

	DynamicVector<int> dynamic_array_copy;
	dynamic_array_copy = dynamic_array;
	assert(dynamic_array_copy.size() == 5);

	// pop_back
	dynamic_array_copy.pop_back();
	dynamic_array_copy.pop_back();
	assert(dynamic_array_copy.size() == 3);

	// erase
	dynamic_array_copy.erase(1);
	assert(dynamic_array_copy.size() == 2);

	try {
		dynamic_array_copy.erase(-1); }
	catch (...) {
		assert(true);
	}

	try {
		dynamic_array_copy.erase(2); }
	catch (...) {
		assert(true);
	}

	assert(dynamic_array_copy.size() == 2);

	// at
	assert(dynamic_array_copy.at(0) == 3);
	assert(dynamic_array_copy.at(1) == 5);

	try {
		dynamic_array_copy.at(-1); }
	catch (...) {
		assert(true);
	}

	try {
		dynamic_array_copy.at(2); }
	catch (...) {
		assert(true);
	}

	// clear
	dynamic_array_copy.erase(1);
	dynamic_array_copy.clear();
	assert(dynamic_array_copy.size() == 0);

	dynamic_array_copy.pop_back();

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// iterator
	/*
	auto iterator = dynamic_array.begin();
	while (iterator != dynamic_array.end()){
		auto element = *iterator;
		iterator++;
	}
	*/

<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	int index = 0;
	for (const auto& element : dynamic_array) {
		assert(element == dynamic_array.at(index));
		index++;
	}

	// destructor
	// by default
}

void TestTravelAgency::runRepositoryTests(Repository& repository) const {
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	/*
	The offer already exists!
	The offer doesn't exist!
	*/
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };

	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };
    
	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	//create repository
	//Repository repository;
	//FileRepository repository{"offers_file_test.txt"};
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	
	// test repository size
	assert(repository.getSize() == 0);

	// test repository add
	repository.addOffer(offer);

	assert(repository.getSize() == 1);

	try {
		repository.addOffer(offer); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer already exists!");
	}

	assert(repository.getSize() == 1);

	// test get offer by name 
	TouristOffer offer_get = repository.getOfferByName(name_1);
	assert(offer_get == offer);

	try {
		repository.getOfferByName("no offer"); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer doesn't exist!");
	}

	// test repository modify
	type_1 = "chep";
	offer.setType(type_1);

	repository.modifyOffer(offer);

	offer_get = repository.getOfferByName(name_1);
	assert(offer_get == offer);

	assert(offer_get.getType() == type_1);

	try {
		repository.modifyOffer(other); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer doesn't exist!");
	}

	// test repository delete
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======

>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	assert(repository.getSize() == 1);

	try {
		repository.deleteOffer(other); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer doesn't exist!");
	}

	repository.addOffer(other);

	assert(repository.getSize() == 2);

	// test get all
<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers = repository.getAll();
=======
	auto all_offers = repository.getAll();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	auto all_offers = repository.getAll();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	assert(all_offers.size() == 2);
	assert(all_offers.at(0) == offer);
	assert(all_offers.at(1) == other);

	// test repository delete
	repository.deleteOffer(offer);

	assert(repository.getSize() == 1);

	repository.deleteOffer(other);

	assert(repository.getSize() == 0);

}

void TestTravelAgency::runFileRepositoryTests() const {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	FileRepository repository{"offers_file_test.txt"};

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };

	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };

	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };

	// test repository size
	assert(repository.getSize() == 0);

	// test repository add
	repository.addOffer(offer);

	assert(repository.getSize() == 1);

	// test repository add
	repository.addOffer(other);

	assert(repository.getSize() == 2);

	FileRepository other_repository{ "offers_file_test.txt" };

	assert(other_repository.getSize() == 2);

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers = other_repository.getAll();
=======
	auto all_offers = other_repository.getAll();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	auto all_offers = other_repository.getAll();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	assert(all_offers.size() == 2);
	assert(all_offers.at(0) == offer);
	assert(all_offers.at(1) == other);
    
	// test repository delete
	repository.deleteOffer(offer);

	assert(repository.getSize() == 1);

	repository.deleteOffer(other);

	assert(repository.getSize() == 0);

<<<<<<< HEAD
<<<<<<< HEAD
	// test repository read from invalid file
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	try {
		FileRepository wrong_repository{ "" }; }
	catch(const RepositoryError& error){
		assert(error.getMessage() == "Open error: ");
	}
<<<<<<< HEAD
<<<<<<< HEAD

	// test repository write to read only file
	string file_name_read_only = "offers_file_test_read_only.txt";
	FileRepository read_only_repository{ file_name_read_only };
	try {
		read_only_repository.addOffer(offer); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "Open error: " + file_name_read_only);
	}
}

void TestTravelAgency::runLabActivityRepositoryTests() const {

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };

	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };

	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };

	LabActivityRepository repository(0.0);

	// test repository size
	assert(repository.getSize() == 0);

	// test repository add
	repository.addOffer(offer);

	assert(repository.getSize() == 1);

	try {
		repository.addOffer(offer); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer already exists!");
	}

	assert(repository.getSize() == 1);

	// test get offer by name 
	TouristOffer offer_get = repository.getOfferByName(name_1);
	assert(offer_get == offer);

	try {
		repository.getOfferByName("no offer"); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer doesn't exist!");
	}

	// test repository modify
	type_1 = "chep";
	offer.setType(type_1);

	repository.modifyOffer(offer);

	offer_get = repository.getOfferByName(name_1);
	assert(offer_get == offer);

	assert(offer_get.getType() == type_1);

	try {
		repository.modifyOffer(other); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer doesn't exist!");
	}

	// test repository delete
	assert(repository.getSize() == 1);

	try {
		repository.deleteOffer(other); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer doesn't exist!");
	}

	repository.addOffer(other);

	assert(repository.getSize() == 2);

	// test get all
	const auto& all_offers = repository.getAll();
	assert(all_offers.size() == 2);
	assert(all_offers.at(0) == offer);
	assert(all_offers.at(1) == other);

	// test repository delete
	repository.deleteOffer(offer);

	assert(repository.getSize() == 1);

	repository.deleteOffer(other);

	assert(repository.getSize() == 0);

	LabActivityRepository probability_repository(1.1);

	// test repository size
	assert(probability_repository.getSize() == 0);

	// test repository add
	try {
		probability_repository.addOffer(offer); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "Oops");
	}
}

void TestTravelAgency::runValidatorTests() const {
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
}

void TestTravelAgency::runValidatorTests() const {
	/*
	* The name can't be empty!
	* The destination can't be empty!
	* The type can't be empty!
	* The price can't be negative!
	*/
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	string name{ "" };
	string destination{ "" };
	string type{ "" };
	constexpr double price{ -1 };

	// create offer
	TouristOffer offer{ name, destination, type, price };
	TravelAgencyValidator validator{ };
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	try {
		validator.touristOfferValidator(offer); }
	catch (const ValidationError& error) {
		assert(error.getMessage() == "The name can't be empty!\nThe destination can't be empty!\nThe type can't be empty!\nThe price can't be negative!");
	}

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };
	constexpr double price_1{ 123.32 };

	TouristOffer other{ name_1, destination_1, type_1, price_1 };
	validator.touristOfferValidator(other);
}

void TestTravelAgency::runExceptionTests() const {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	try {
		throw Exception("error"); }
	catch (const Exception error) {
		assert(error.getMessage() == "error");
	}

	try {
		throw ValueError("error");
	}
	catch (const Exception error) {
		assert(error.getMessage() == "error");
	}

	try {
		throw ValidationError("error"); }
	catch (const Exception error) {
		assert(error.getMessage() == "error");
	}

	try {
		throw RepositoryError("error");
	}
	catch (const Exception error) {
		assert(error.getMessage() == "error");
	}

	try {
		throw WishListError("error");
	}
	catch (const Exception error) {
		assert(error.getMessage() == "error");
	}
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	try {
		throw FileError("error");
	}
	catch (const Exception error) {
		assert(error.getMessage() == "error");
	}
}

void TestTravelAgency::runServiceCrudTests() const {
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	/*
	The offer already exists!
	The offer doesn't exist!
	*/
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };
	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };

	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };

	// create repository
<<<<<<< HEAD
<<<<<<< HEAD
	MemoryRepository repository;
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// create validator
	TravelAgencyValidator validator;

	//create a wish list
	WishList wish_list;

	// create service
	Service service{ repository, validator, wish_list };

	// test repository size
<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_1 = service.getAll();
	assert(all_offers_1.size() == 0);
=======
	auto all_offers = service.getAll();
	assert(all_offers.size() == 0);
	//assert(repository.getSize() == 0);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	auto all_offers = service.getAll();
	assert(all_offers.size() == 0);
	//assert(repository.getSize() == 0);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// test service add
	service.addOffer(name_1, destination_1, type_1, price_1);

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_2 = service.getAll();
	assert(all_offers_2.size() == 1);
=======
	all_offers = service.getAll();
	assert(all_offers.size() == 1);
	//assert(repository.getSize() == 1);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	all_offers = service.getAll();
	assert(all_offers.size() == 1);
	//assert(repository.getSize() == 1);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	try {
		service.addOffer(name_1, destination_1, type_1, price_1); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer already exists!");
	}

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_3 = service.getAll();
	assert(all_offers_3.size() == 1);
=======
	all_offers = service.getAll();
	assert(all_offers.size() == 1);
	//assert(repository.getSize() == 1);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	all_offers = service.getAll();
	assert(all_offers.size() == 1);
	//assert(repository.getSize() == 1);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// test service modify
	type_1 = "chep";

	service.modifyOffer(name_1, destination_1, type_1, price_1);

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_4 = service.getAll();
	assert(all_offers_4.at(0) == offer);
	assert(all_offers_4.at(0).getType() == type_1);
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	all_offers = service.getAll();
	assert(all_offers.at(0) == offer);
	assert(all_offers.at(0).getType() == type_1);
	//TouristOffer offer_get = repository.getOfferByName(name_1);
	//assert(offer_get == offer);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	try {
		service.modifyOffer(name_2, destination_2, type_2, price_2); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer doesn't exist!");
	}

	// test service delete
<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_5 = service.getAll();
	assert(all_offers_5.size() == 1);
=======
	all_offers = service.getAll();
	assert(all_offers.size() == 1);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	all_offers = service.getAll();
	assert(all_offers.size() == 1);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	//assert(repository.getSize() == 1);

	try {
		service.deleteOffer(name_2); }
	catch (const RepositoryError& error) {
		assert(error.getMessage() == "The offer doesn't exist!");
	}

	service.addOffer(name_2, destination_2, type_2, price_2);

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_6 = service.getAll();
	assert(all_offers_6.size() == 2);

	// test get all
	const auto& all_offers_7 = service.getAll();
	assert(all_offers_7.size() == 2);
	assert(all_offers_7.at(0) == offer);
	assert(all_offers_7.at(1) == other);
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	all_offers = service.getAll();
	assert(all_offers.size() == 2);
	//assert(repository.getSize() == 2);

	// test get all
	all_offers = service.getAll();
	assert(all_offers.size() == 2);
	assert(all_offers.at(0) == offer);
	assert(all_offers.at(1) == other);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// test service delete
	service.deleteOffer(name_1);

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_8 = service.getAll();
	assert(all_offers_8.size() == 1);
=======
	all_offers = service.getAll();
	assert(all_offers.size() == 1);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	all_offers = service.getAll();
	assert(all_offers.size() == 1);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	//assert(repository.getSize() == 1);

	service.deleteOffer(name_2);

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_9 = service.getAll();
	assert(all_offers_9.size() == 0);
}

void TestTravelAgency::runServiceUndoTests() const {

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };
	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };

	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };

	// create repository
	FileRepository repository{"offers_file_test.txt"};

	// create validator
	TravelAgencyValidator validator;

	//create a wish list
	WishList wish_list;

	// create service
	Service service{ repository, validator, wish_list };

	// test repository size
	const auto& all_offers_1 = service.getAll();
	assert(all_offers_1.size() == 0);


	// test service add
	service.addOffer(name_1, destination_1, type_1, price_1);

	const auto& all_offers_2 = service.getAll();
	assert(all_offers_2.size() == 1);

	service.addOffer(name_2, destination_2, type_2, price_2);

	const auto& all_offers_3 = service.getAll();
	assert(all_offers_3.size() == 2);

	service.modifyOffer(name_1, destination_2, type_2, price_2);
	service.modifyOffer(name_2, destination_1, type_1, price_1);

	const auto& all_offers_4 = service.getAll();
	assert(all_offers_4.at(0) == offer);
	assert(all_offers_4.at(0).getDestination() == destination_2);
	assert(all_offers_4.at(0).getType() == type_2);
	assert(all_offers_4.at(0).getPrice() == price_2);

	assert(all_offers_4.at(1) == other);
	assert(all_offers_4.at(1).getDestination() == destination_1);
	assert(all_offers_4.at(1).getType() == type_1);
	assert(all_offers_4.at(1).getPrice() == price_1);

	service.undo();
	service.undo();

	const auto& all_offers_5 = service.getAll();
	assert(all_offers_5.at(0) == offer);
	assert(all_offers_5.at(0).getDestination() == destination_1);
	assert(all_offers_5.at(0).getType() == type_1);
	assert(all_offers_5.at(0).getPrice() == price_1);

	assert(all_offers_5.at(1) == other);
	assert(all_offers_5.at(1).getDestination() == destination_2);
	assert(all_offers_5.at(1).getType() == type_2);
	assert(all_offers_5.at(1).getPrice() == price_2);

	service.deleteOffer(name_1);
	service.deleteOffer(name_2);

	const auto& all_offers_6 = service.getAll();
	assert(all_offers_6.size() == 0);

	service.undo();
	service.undo();

	const auto& all_offers_7 = service.getAll();
	assert(all_offers_7.size() == 2);


	service.undo();
	service.undo();

	const auto& all_offers_8 = service.getAll();
	assert(all_offers_8.size() == 0);

	try {
		service.undo(); }
	catch(const ValidationError& error){
		assert(error.getMessage() == "You can't do undo anymore!");
	}
}

void TestTravelAgency::runServiceFindTests() const {
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	all_offers = service.getAll();
	assert(all_offers.size() == 0);
}

void TestTravelAgency::runServiceFindTests() const {
	/*
    The offer already exists!
    The offer doesn't exist!
    */
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };
	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };

	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };

	// create repository
<<<<<<< HEAD
<<<<<<< HEAD
	MemoryRepository repository;
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// create validator
	TravelAgencyValidator validator;

	//create a wish list
	WishList wish_list;

	// create service
	Service service{ repository, validator, wish_list };

	// test repository size
<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_1 = service.getAll();
	assert(all_offers_1.size() == 0);

	// test service add
	service.addOffer(name_1, destination_1, type_1, price_1);
	const auto& all_offers_2 = service.getAll();
	assert(all_offers_2.size() == 1);

	service.addOffer(name_2, destination_2, type_2, price_2);
	const auto& all_offers_3 = service.getAll();
	assert(all_offers_3.size() == 2);
	

	const auto& travel_1 = service.findTravelByName(name_1);
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	auto all_offers = service.getAll();
	assert(all_offers.size() == 0);

	// test service add
	service.addOffer(name_1, destination_1, type_1, price_1);
	all_offers = service.getAll();
	assert(all_offers.size() == 1);

	service.addOffer(name_2, destination_2, type_2, price_2);
	all_offers = service.getAll();
	assert(all_offers.size() == 2);
	

	const auto travel_1 = service.findTravelByName(name_1);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	assert(travel_1.getDestination() == destination_1);
	assert(travel_1.getType() == type_1);
	assert(travel_1.getPrice() == price_1);

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& travel_2 = service.findTravelByName(name_2);
=======
	const auto travel_2 = service.findTravelByName(name_2);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	const auto travel_2 = service.findTravelByName(name_2);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	assert(travel_2.getDestination() == destination_2);
	assert(travel_2.getType() == type_2);
	assert(travel_2.getPrice() == price_2);
}

void TestTravelAgency::runServiceFiltrationTests() const {
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	/*
    The offer already exists!
    The offer doesn't exist!
    */
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };
	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };

	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };

	string name_3{ "trip" };
	string destination_3{ "milano" };
	string type_3{ "full" };
	constexpr double price_3{ 54.27 };

	TouristOffer other_3{ name_3, destination_3, type_3, price_3 };

	// create repository
<<<<<<< HEAD
<<<<<<< HEAD
	MemoryRepository repository;
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// create validator
	TravelAgencyValidator validator;

	//create a wish list
	WishList wish_list;

	// create service
	Service service{ repository, validator, wish_list };

	// test repository size
<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_1 = service.getAll();
	assert(all_offers_1.size() == 0);

	// test service add
	service.addOffer(name_1, destination_1, type_1, price_1);
	const auto& all_offers_2 = service.getAll();
	assert(all_offers_2.size() == 1);

	service.addOffer(name_2, destination_2, type_2, price_2);
	const auto& all_offers_3 = service.getAll();
	assert(all_offers_3.size() == 2);

	service.addOffer(name_3, destination_3, type_3, price_3);
	const auto& all_offers_4 = service.getAll();
	assert(all_offers_4.size() == 3);
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	auto all_offers = service.getAll();
	assert(all_offers.size() == 0);

	// test service add
	service.addOffer(name_1, destination_1, type_1, price_1);
	all_offers = service.getAll();
	assert(all_offers.size() == 1);

	service.addOffer(name_2, destination_2, type_2, price_2);
	all_offers = service.getAll();
	assert(all_offers.size() == 2);

	service.addOffer(name_3, destination_3, type_3, price_3);
	all_offers = service.getAll();
	assert(all_offers.size() == 3);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	
	const auto filtration_destination = service.getOffersByDestination(destination_3);
	assert(filtration_destination.size() == 1);

	assert(filtration_destination.at(0).getName() == name_3);

	const auto filtration_price = service.getOffersByPrice(price_2, price_1);
	assert(filtration_price.size() == 3);

	assert(filtration_price.at(0).getName() == name_1);
	assert(filtration_price.at(1).getName() == name_2);
	assert(filtration_price.at(2).getName() == name_3);
<<<<<<< HEAD
<<<<<<< HEAD
}

void TestTravelAgency::runServiceSortTests() const {
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	
}

void TestTravelAgency::runServiceSortTests() const {
	/*
The offer already exists!
The offer doesn't exist!
*/
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };
	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };

	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };

	string name_3{ "trip" };
	string destination_3{ "milano" };
	string type_3{ "full" };
	constexpr double price_3{ 54.27 };

	TouristOffer other_3{ name_3, destination_3, type_3, price_3 };

	// create repository
<<<<<<< HEAD
<<<<<<< HEAD
	MemoryRepository repository;
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// create validator
	TravelAgencyValidator validator;

	//create a wish list
	WishList wish_list;

	// create service
	Service service{ repository, validator, wish_list };

	// test repository size
<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_1 = service.getAll();
	assert(all_offers_1.size() == 0);

	// test service add
	service.addOffer(name_1, destination_1, type_1, price_1);
	const auto& all_offers_2 = service.getAll();
	assert(all_offers_2.size() == 1);

	service.addOffer(name_2, destination_2, type_2, price_2);
	const auto& all_offers_3 = service.getAll();
	assert(all_offers_3.size() == 2);

	service.addOffer(name_3, destination_3, type_3, price_3);
	const auto& all_offers_4 = service.getAll();
	assert(all_offers_4.size() == 3);
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	auto all_offers = service.getAll();
	assert(all_offers.size() == 0);

	// test service add
	service.addOffer(name_1, destination_1, type_1, price_1);
	all_offers = service.getAll();
	assert(all_offers.size() == 1);

	service.addOffer(name_2, destination_2, type_2, price_2);
	all_offers = service.getAll();
	assert(all_offers.size() == 2);

	service.addOffer(name_3, destination_3, type_3, price_3);
	all_offers = service.getAll();
	assert(all_offers.size() == 3);

<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	const auto sort_name = service.sortByName();
	assert(sort_name.size() == 3);

	assert(sort_name.at(0).getName() == name_2);
	assert(sort_name.at(1).getName() == name_1);
	assert(sort_name.at(2).getName() == name_3);

	const auto sort_destination = service.sortByDestination();
	assert(sort_destination.size() == 3);

	assert(sort_destination.at(0).getName() == name_3);
	assert(sort_destination.at(1).getName() == name_1);
	assert(sort_destination.at(2).getName() == name_2);

	const auto sort_type_price = service.sortByTypeAndPrice();
	assert(sort_type_price.size() == 3);

	assert(sort_type_price.at(0).getName() == name_2);
	assert(sort_type_price.at(1).getName() == name_3);
	assert(sort_type_price.at(2).getName() == name_1);
}

void TestTravelAgency::runWishListTests() const {

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };

	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };

	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };

	//create wish list
	WishList wish_list;

	// test wish list size
	assert(wish_list.getSize() == 0);

	// test wish list add
	wish_list.addWishOffer(offer);

	assert(wish_list.getSize() == 1);

	try {
		wish_list.addWishOffer(offer); }
	catch (const WishListError& error) {
		assert(error.getMessage() == "The offer already exists!");
	}

	assert(wish_list.getSize() == 1);

	wish_list.addWishOffer(other);

	assert(wish_list.getSize() == 2);

<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======

>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	// test wish list delete
	wish_list.deleteWishOffers();

	assert(wish_list.getSize() == 0);

	//test wish list generator
	constexpr int random_number{ 1 };

	vector<TouristOffer> all_offers{ offer, other };
	wish_list.generateWishListOffers(random_number, all_offers);

	assert(wish_list.getSize() == random_number);
}

void TestTravelAgency::runWishListServiceTests() const {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };

	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };

	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };

	string name_3{ "trip" };
	string destination_3{ "milano" };
	string type_3{ "full" };
	constexpr double price_3{ 54.27 };

	TouristOffer other_3{ name_3, destination_3, type_3, price_3 };

	// create repository
<<<<<<< HEAD
<<<<<<< HEAD
	MemoryRepository repository;
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// create validator
	TravelAgencyValidator validator;

<<<<<<< HEAD
<<<<<<< HEAD
	// create a wish list
=======
	//create a wish list
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	//create a wish list
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	WishList wish_list;

	// create service
	Service service{ repository, validator, wish_list };

	// test wish list size
<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_1 = service.getAllWishOffers();
	assert(all_offers_1.size() == 0);
=======
	auto all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 0);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	auto all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 0);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// test service add wish offer
	try {
		service.addWishOffer(name_1); }
	catch(const RepositoryError& error){
		assert(error.getMessage() == "The offer doesn't exist!");
	}

	service.addOffer(name_1, destination_1, type_1, price_1);
	service.addOffer(name_2, destination_2, type_2, price_2);
	service.addOffer(name_3, destination_3, type_3, price_3);

	service.addWishOffer(name_1);
<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_2 = service.getAllWishOffers();
	assert(all_offers_2.size() == 1);
=======
	all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 1);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 1);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	try {
		service.addWishOffer(name_1); }
	catch (const WishListError& error) {
		assert(error.getMessage() == "The offer already exists!");
	}

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_3 = service.getAllWishOffers();
	assert(all_offers_3.size() == 1);

	service.addWishOffer(name_2);
	const auto& all_offers_4 = service.getAllWishOffers();
	assert(all_offers_4.size() == 2);
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 1);

	service.addWishOffer(name_2);
	all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 2);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// test service delete all wish offer
	service.deleteWishOffres();

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_5 = service.getAllWishOffers();
	assert(all_offers_5.size() == 0);
=======
	all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 0);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 0);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	service.addWishOffer(name_1);
	service.addWishOffer(name_2);

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_6 = service.getAllWishOffers();
	assert(all_offers_6.size() == 2);

	// test get all wishes
	const auto& all_offers_7 = service.getAllWishOffers();
	assert(all_offers_7.size() == 2);
	assert(all_offers_7.at(0) == offer);
	assert(all_offers_7.at(1) == other);
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 2);

	// test get all wishes
	all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 2);
	assert(all_offers.at(0) == offer);
	assert(all_offers.at(1) == other);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	service.addWishOffer(name_3);

	int random_number{ -1 };
	try {
		service.generateWishOffers(random_number); }
	catch (const WishListError& error) {
		assert(error.getMessage() == "Too small wish");
	}

	random_number = 4;
	try {
		service.generateWishOffers(random_number); }
	catch (const WishListError& error) {
		assert(error.getMessage() == "Too many wishes");
	}

	random_number = 3;
	service.generateWishOffers(random_number);

<<<<<<< HEAD
<<<<<<< HEAD
	const auto& all_offers_8 = service.getAllWishOffers();
	assert(all_offers_8.size() == 3);
=======
	all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 3);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	all_offers = service.getAllWishOffers();
	assert(all_offers.size() == 3);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
}

void TestTravelAgency::runDtoOfferTests() const {

	string name_1{ "travel" };
	string destination_1{ "paris" };
	string type_1{ "full" };

	constexpr double price_1{ 123.32 };

	TouristOffer offer{ name_1, destination_1, type_1, price_1 };

	string name_2{ "excursion" };
	string destination_2{ "roma" };
	string type_2{ "empty" };
	constexpr double price_2{ 43.42 };

	TouristOffer other{ name_2, destination_2, type_2, price_2 };

	string name_3{ "trip" };
	string destination_3{ "milano" };
	string type_3{ "full" };
	constexpr double price_3{ 54.27 };

	TouristOffer other_3{ name_3, destination_3, type_3, price_3 };

	// create repository
<<<<<<< HEAD
<<<<<<< HEAD
	MemoryRepository repository;
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	Repository repository;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	// create validator
	TravelAgencyValidator validator;

	//create a wish list
	WishList wish_list;

	// create service
	Service service{ repository, validator, wish_list };

	service.addOffer(name_1, destination_2, type_1, price_1);
	service.addOffer(name_2, destination_1, type_2, price_2);
	service.addOffer(name_3, destination_2, type_3, price_3);

	DtoOffer default_dto;
	map<string, DtoOffer> report_destination = service.report();

<<<<<<< HEAD
<<<<<<< HEAD
	const auto iterator = report_destination.find(destination_1);
	const auto val = *iterator;
	assert(val.second.getCount() == 1);
	assert(val.second.getDestination() == destination_1);

    const auto iterator_1 = report_destination.find(destination_2);
    const auto val_1 = *iterator_1;
	assert(val_1.second.getCount() == 2);
	assert(val_1.second.getDestination() == destination_2);
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	assert(report_destination[destination_1].getCount() == 1);
	assert(report_destination[destination_1].getDestination() == destination_1);
	assert(report_destination[destination_2].getCount() == 2);
	assert(report_destination[destination_2].getDestination() == destination_2);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
}

void TestTravelAgency::runAllTests() const {

	runDomainTests();
	runDynamicArrayTests();
<<<<<<< HEAD
<<<<<<< HEAD
	MemoryRepository repository;
	runRepositoryTests(repository);
	FileRepository file_repository{ "offers_file_test.txt" };
	runRepositoryTests(file_repository);
    runLabActivityRepositoryTests();
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	Repository repository;
	runRepositoryTests(repository);
	FileRepository file_repository{ "offers_file_test.txt" };
	runRepositoryTests(file_repository);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	runFileRepositoryTests();
	runValidatorTests();
	runExceptionTests();
	runServiceCrudTests();
<<<<<<< HEAD
<<<<<<< HEAD
	runServiceUndoTests();
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	runServiceFindTests();
	runServiceFiltrationTests();
	runServiceSortTests();
	runWishListTests();
	runWishListServiceTests();
    runDtoOfferTests();

	std::cout << "\nZeu\n";
}