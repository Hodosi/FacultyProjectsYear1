#include "WishList.h"

void WishList::addWishOffer(const TouristOffer& offer) {

	const auto iterator = find_if(this->dynamic_array.begin(), this->dynamic_array.end(),
		[&](const TouristOffer& item) { return offer == item; });

	if (iterator != this->dynamic_array.end()) {
		throw WishListError("The offer already exists!");
	}

	dynamic_array.push_back(offer);
}

void WishList::deleteWishOffers() noexcept {
	this->dynamic_array.clear();
}

/*
string randomString() {
	string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	random_device device;
	mt19937 generator(device());

	shuffle(str.begin(), str.end(), generator);

	return str.substr(0, 5);
}
*/

void WishList::generateWishListOffers(const int random_number, vector<TouristOffer> all_offers) {
	/*
	for (int i = 0; i < random_number; i++) {
		string name = randomString();
		string destination = randomString();
		string type = randomString();
		double price = rand() % 1000;
		TouristOffer offer{ name, destination, type, price };
		this->addWishOffer(offer);
	}
	*/

	shuffle(begin(all_offers), end(all_offers), default_random_engine{});

	for (int i = 0; i < random_number; i++) {
		this->addWishOffer(all_offers.at(i));
	}
}   

const int WishList::getSize() const noexcept {
	return this->dynamic_array.size();
}