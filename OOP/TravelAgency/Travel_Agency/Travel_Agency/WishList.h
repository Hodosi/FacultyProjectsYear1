#pragma once

#include "ValueObject.h"
#include "Exception.h"
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include "DynamicArray.h"
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
#include "DynamicArray.h"
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

#include <vector>
#include <algorithm>
#include <random>
#include <string>
<<<<<<< HEAD
<<<<<<< HEAD

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
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
using namespace std;

class WishList {
private:
	vector<TouristOffer> dynamic_array;
public:
	/*
     * create a repository and a dynamic array
     * input:  -
      * output: a new empty repository
    */
	WishList() : dynamic_array{ } {};
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

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
<<<<<<< HEAD
<<<<<<< HEAD
	void deleteWishOffers() noexcept;
=======
	void deleteWishOffers();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	void deleteWishOffers();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

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