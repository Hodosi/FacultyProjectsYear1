#pragma once

#include "Repository.h"
#include "WishList.h"
#include "Validator.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "Undo.h"
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

#include <algorithm>
#include <vector>
#include <string>
<<<<<<< HEAD
<<<<<<< HEAD
#include <map>
#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::map;

class Service {

private:
	Repository& repository;
	WishList& wish_list;
	const TravelAgencyValidator& validator;
	vector<unique_ptr<UndoAction>> undo_action;

	const vector<TouristOffer> costumSort(const string& type_of_sort) const;
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
#include <functional>
#include <map>

using namespace std;


class Service {
private:
	Repository& repository;
	WishList& wish_list;
	TravelAgencyValidator& validator;

	vector<TouristOffer> costumSort(const string& type_of_sort) const;
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

public:
	/*
	 * create a service
	 * input:  a repository to a travel agency and a validator to a tourist offer from travel agency, a wish list to a travel agency
	 *         - the repository must be exists
	 *         - the validator must be exists
	 *         - the wish list must be exists
	 * output: a new service to a travel agency
	 */
<<<<<<< HEAD
<<<<<<< HEAD
	Service(Repository& repository, const TravelAgencyValidator& validator, WishList& wish_list) noexcept
		: repository{ repository }, validator{ validator }, wish_list{ wish_list }, undo_action{ } {};

	/*
	* I don't want the service to be copied
	*/
	Service(const Service& other) = delete;

	/*
	* I don't want the service to be assigned
	*/
	void operator=(const Service& other) = delete;
=======
	Service(Repository& repository, TravelAgencyValidator& validator, WishList& wish_list) 
		: repository{ repository }, validator{ validator }, wish_list{ wish_list } {};
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	Service(Repository& repository, TravelAgencyValidator& validator, WishList& wish_list) 
		: repository{ repository }, validator{ validator }, wish_list{ wish_list } {};
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
    
	/*
	 * add an offer for travel agency
	 * input:  the name of offer
	 *         - string
	 *         the destination of offer
	 *         - string
	 *         the type of offer
	 *         - string
	 *         the price of offer
	 *         - double
	 * output: -
	 *         throw Validation Error if input is invalid
	 */
	void addOffer(const string& name, const string& destination, const string& type, const double& price);

	/*
	 * modify an offer for travel agency
	 * input:  the name of offer
	 *         - string
	 *         the new destination of offer
	 *         - string
	 *         the new type of offer
	 *         - string
	 *         the new price of offer
	 *         - double
	 * output: -
	 *         throw Validation Error if input is invalid
	*/
	void modifyOffer(const string& name, const string& destination, const string& type, const double& price);

    /*
	 * delete an offer for travel agency
	 * input:  the name of offer
	 *         - string
	 * output: -
	 *         throw Validation Error if input is invalid
	*/
	void deleteOffer(const string& name);

	/*
<<<<<<< HEAD
<<<<<<< HEAD
	* undo for adding, deleting and modifying
	*/
	void undo();

	/*
	* return all offers
	*/
	const auto& getAll() const noexcept {
		return this -> repository.getAll();
	}
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	* return all offers
	*/
	const auto& getAll() const noexcept
	{ return this -> repository.getAll(); }
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	/*
	 * find an offer for travel agency
	 * input:  the name of offer
	 *         - string
	 * output: a valid toursit offer
	*/	
	const auto findTravelByName(const string& name) const {
<<<<<<< HEAD
<<<<<<< HEAD

		const auto& offer = this->repository.getOfferByName(name);
=======
		const auto offer = this->repository.getOfferByName(name);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
		const auto offer = this->repository.getOfferByName(name);
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		return offer;
	}

	/*
	 * filter all offers with a given destination
	 * input:  the destination of offer
	 *         - string
	 * output: all offers with a given destination
	*/
	const auto getOffersByDestination(const string& destination) const {

		const auto& all_offers = this->repository.getAll();

		vector<TouristOffer> dynamic_array;

		copy_if(all_offers.begin(), all_offers.end(), back_inserter(dynamic_array),
<<<<<<< HEAD
<<<<<<< HEAD
			[&](const auto& offer) { return offer.getDestination() == destination; });
=======
			[&](auto& offer) { return offer.getDestination() == destination; });
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
			[&](auto& offer) { return offer.getDestination() == destination; });
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

		return dynamic_array;
	}

	/*
	 * filter all offers between a given price
	 * input:  the minimum price of offer
	 *         - string
	 *         the maximum price of offer
	 *         - string
	 * output: all offers between a given price
	*/
	const auto getOffersByPrice(double price_min, double price_max) const {

		const auto& all_offers = this->repository.getAll();

		vector<TouristOffer> dynamic_array;

		copy_if(all_offers.begin(), all_offers.end(), back_inserter(dynamic_array),
<<<<<<< HEAD
<<<<<<< HEAD
			[&](const auto& offer) noexcept { 
=======
			[&](auto& offer) { 
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
			[&](auto& offer) { 
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
				return price_min <= offer.getPrice() && offer.getPrice() <= price_max;
			});

		return dynamic_array;
	}

	/*
     * sort all offers by name
     * input:  -
     * output: all offers sorted by name
    */
	const auto sortByName() const{
		return costumSort("name");
	}

	/*
     * sort all offers by destination
     * input:  -
     * output: all offers sorted by destination
    */
	const auto sortByDestination() const {
		return costumSort("destination");
	}

	/*
     * sort all offers by type
	 * if the type is equal it will be sorted by price
     * input:  -
     * output: all offers sorted
    */
	const auto sortByTypeAndPrice() const {
		return costumSort("type_price");
	}

	/*
	 * add a wish offer for travel agency
	 * input:  the name of offer
	 *         - string
	 * output: -
	 *         throw Validation Error if input is invalid
	*/
	void addWishOffer(const string& name);

	/*
	 * delete all wish offers for travel agency
	 * input:  the name of offer
	 *         - string
	*/
<<<<<<< HEAD
<<<<<<< HEAD
	void deleteWishOffres() noexcept;
=======
	void deleteWishOffres();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	void deleteWishOffres();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	/*
	*  generate random offers in wish list
	*/
	void generateWishOffers(const int random_number);

	/*
	 * return all wish offers
	*/
	const auto& getAllWishOffers() const noexcept {
		return this->wish_list.getAll();
	}

<<<<<<< HEAD
<<<<<<< HEAD
	/*
	 * return a dictionary with key : destination, and the value: a data transfer object 
	 * with destination and number of occurrences in offers
	*/
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	const auto report() const {

		const auto& all_offers = this->repository.getAll();
		map<string, DtoOffer> destination_number;
<<<<<<< HEAD
<<<<<<< HEAD

		for (const auto& offer : all_offers) {

			auto iterator = destination_number.find(offer.getDestination());

			if (iterator == destination_number.end()) {
=======
		for (const auto& offer : all_offers) {
			if (destination_number.find(offer.getDestination()) == destination_number.end()) {
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
		for (const auto& offer : all_offers) {
			if (destination_number.find(offer.getDestination()) == destination_number.end()) {
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
				DtoOffer new_value{ offer.getDestination(), 1 };
				destination_number[offer.getDestination()] = new_value;
			}
			else {
<<<<<<< HEAD
<<<<<<< HEAD
				auto old_value = *iterator;
				const int old_count = old_value.second.getCount();
				old_value.second.setCount(old_count + 1);
				destination_number[offer.getDestination()] = old_value.second;
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
				DtoOffer old_value = destination_number[offer.getDestination()];
				int old_count = old_value.getCount();
				old_value.setCount(old_count + 1);
				destination_number[offer.getDestination()] = old_value;
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
			}
		}

		return destination_number;
	}
};