#include "Service.h"

void Service::addOffer(const string& name, const string& destination, const string& type, const double& price) {
	
	const TouristOffer offer{ name, destination, type, price };
	validator.touristOfferValidator(offer);
	this->repository.addOffer(offer);

	this->undo_action.push_back(make_unique<UndoAdd>(this->repository, offer));
}

void Service::modifyOffer(const string& name, const string& destination, const string& type, const double& price) {
	
	TouristOffer offer = this->repository.getOfferByName(name);
	offer.setDestination(destination);
	offer.setType(type);
	offer.setPrice(price);
	validator.touristOfferValidator(offer);
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
}

bool compareByName(const TouristOffer& obj1, const TouristOffer& obj2) {
	return (obj1.getName() < obj2.getName());
}

bool compareByDestination(const TouristOffer& obj1, const TouristOffer& obj2) {
	return obj1.getDestination() < obj2.getDestination();
}

bool compareByTypeAndPrice(const TouristOffer& obj1, const TouristOffer& obj2) {
	
	if (obj1.getType() == obj2.getType()) {
		return obj1.getPrice() < obj2.getPrice();
	}
	return obj1.getType() < obj2.getType();
}

const vector<TouristOffer> Service::costumSort(const string& type_of_sort) const {
	
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

void Service::deleteWishOffres() noexcept {
	this->wish_list.deleteWishOffers();
}

void Service::generateWishOffers(const int random_number) {
	
	const int repo_size = this->repository.getSize();
	if (random_number < 0) {
		throw WishListError("Too small wish");
	}
	if (random_number > repo_size) {
		throw WishListError("Too many wishes");
	}
	wish_list.deleteWishOffers();
	const auto all_offers = this->repository.getAll();
	wish_list.generateWishListOffers(random_number, all_offers);
}