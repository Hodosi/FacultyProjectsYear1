#include "Service.h"

void Service::addOffer(const string& name, const string& destination, const string& type, const double& price) {
<<<<<<< HEAD
<<<<<<< HEAD
	
	const TouristOffer offer{ name, destination, type, price };
	validator.touristOfferValidator(offer);
	this->repository.addOffer(offer);

	this->undo_action.push_back(make_unique<UndoAdd>(this->repository, offer));
}

void Service::modifyOffer(const string& name, const string& destination, const string& type, const double& price) {
	
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	TouristOffer offer{ name, destination, type, price };
	validator.touristOfferValidator(offer);
	this->repository.addOffer(offer);
}

void Service::modifyOffer(const string& name, const string& destination, const string& type, const double& price) {
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	TouristOffer offer = this->repository.getOfferByName(name);
	offer.setDestination(destination);
	offer.setType(type);
	offer.setPrice(price);
	validator.touristOfferValidator(offer);
<<<<<<< HEAD
<<<<<<< HEAD
	const auto old_offer = this->repository.modifyOffer(offer);

	this->undo_action.push_back(make_unique<UndoModify>(this->repository, old_offer));
}

void Service::deleteOffer(const string& name) {
	
	const TouristOffer offer = this->repository.getOfferByName(name);
	this->repository.deleteOffer(offer);

	this->undo_action.push_back(make_unique<UndoDelete>(this->repository, offer));
}

void Service::undo() {
	
	if (this->undo_action.empty()) {
		//throw Exception("You can't do undo anymore!");
		throw ValidationError("You can't do undo anymore!");
	}
	this->undo_action.back()->doUndo();
	this->undo_action.pop_back();
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	this->repository.modifyOffer(offer);
}

void Service::deleteOffer(const string& name) {
	TouristOffer offer = this->repository.getOfferByName(name);
	this->repository.deleteOffer(offer);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
}

bool compareByName(const TouristOffer& obj1, const TouristOffer& obj2) {
	return (obj1.getName() < obj2.getName());
}

<<<<<<< HEAD
<<<<<<< HEAD
bool compareByDestination(const TouristOffer& obj1, const TouristOffer& obj2) {
	return obj1.getDestination() < obj2.getDestination();
}

bool compareByTypeAndPrice(const TouristOffer& obj1, const TouristOffer& obj2) {
	
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
bool compareByDestination(TouristOffer obj1, TouristOffer obj2) {
	return obj1.getDestination() < obj2.getDestination();
}

bool compareByTypeAndPrice(TouristOffer obj1, TouristOffer obj2) {
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	if (obj1.getType() == obj2.getType()) {
		return obj1.getPrice() < obj2.getPrice();
	}
	return obj1.getType() < obj2.getType();
}

<<<<<<< HEAD
<<<<<<< HEAD
const vector<TouristOffer> Service::costumSort(const string& type_of_sort) const {
	
=======
vector<TouristOffer> Service::costumSort(const string& type_of_sort) const {
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
vector<TouristOffer> Service::costumSort(const string& type_of_sort) const {
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	vector<TouristOffer> all_offers = this->repository.getAll();

	// sort by name
	if (type_of_sort == "name") {
		sort(all_offers.begin(), all_offers.end(), compareByName);
	}

	// sort by destination
	if (type_of_sort == "destination") {
		sort(all_offers.begin(), all_offers.end(), compareByDestination);
	}

	// sort type + price
	if (type_of_sort == "type_price") {
		sort(all_offers.begin(), all_offers.end(), compareByTypeAndPrice);
	}

	return all_offers;
}


void Service::addWishOffer(const string& name) {
	const auto offer = this->repository.getOfferByName(name);
	this->wish_list.addWishOffer(offer);
}

<<<<<<< HEAD
<<<<<<< HEAD
void Service::deleteWishOffres() noexcept {
=======
void Service::deleteWishOffres() {
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
void Service::deleteWishOffres() {
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	this->wish_list.deleteWishOffers();
}

void Service::generateWishOffers(const int random_number) {
<<<<<<< HEAD
<<<<<<< HEAD
	
	const int repo_size = this->repository.getSize();
=======
	int repo_size = this->repository.getSize();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	int repo_size = this->repository.getSize();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	if (random_number < 0) {
		throw WishListError("Too small wish");
	}
	if (random_number > repo_size) {
		throw WishListError("Too many wishes");
	}
	wish_list.deleteWishOffers();
	const auto all_offers = this->repository.getAll();
	wish_list.generateWishListOffers(random_number, all_offers);
<<<<<<< HEAD
<<<<<<< HEAD
}
=======
}


>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
}


>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
