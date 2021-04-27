#pragma once

#include "ValueObject.h"
#include "Exception.h"

#include <vector>
#include <algorithm>
#include <random>
#include <string>

using std::vector;
using std::default_random_engine;

class WishList {

private:
	vector<TouristOffer> dynamic_array;

public:
	/*
     * create a wish list and a dynamic array
     * input:  -
     * output: a new empty wish list
    */
	WishList() noexcept : dynamic_array{ } {};

	WishList(const WishList& other) = delete;

	void operator=(const WishList& other) = delete;

	/*
	 * add a wished offer in a wish list
	 * input:  an offer for travel agency
	 *         - the offer must be valid
	 * output: -
	 *         throw WishList error if the offer already exists
	*/
	void addWishOffer(const TouristOffer& offer);

	/*
	* deleteWishOffers
	*/
	void deleteWishOffers() noexcept;

	/*
	* generate and add random offers in wish list
	*/
	void generateWishListOffers(const int random_number, vector<TouristOffer> all_offers);

	/*
     * return all wished offers
    */
	const auto& getAll() const noexcept {
		return this->dynamic_array;
	}

	/*
     * return the numbers of offers
    */
	const int getSize() const noexcept;
};