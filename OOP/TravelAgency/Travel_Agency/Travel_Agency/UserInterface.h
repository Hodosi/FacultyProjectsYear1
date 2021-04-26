#pragma once

#include "Service.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "Exception.h"

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::getline;
using std::cout;
using std::string;
using std::size_t;
using std::ofstream;

class UI {

public:
	UI(Service& service) noexcept : service{ service } {};

	UI(const UI& other) = delete;

	void operator=(const UI& other) = delete;
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

#include <iostream>
#include <string>

using namespace std;

class UI {
public:
	UI(const Service& service) : service{ service } {};
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	void runUI();

private:
<<<<<<< HEAD
<<<<<<< HEAD
	Service& service;
=======
	Service service;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	Service service;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	void showMenu() const;

	void addSomeTravels();

	void addTouristOfferUI();

	void modifyTouristOfferUI();

	void deleteTouristOfferUI();

<<<<<<< HEAD
<<<<<<< HEAD
	void undoUI();

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	void showAllOffersUI() const;

	void findTravelByNameUI() const;

	void getOffersByDestinationUI() const;

	void getOffersByPriceUI() const;

	void sortByNameUI() const;

	void sortByDestinationUI() const;

	void sortByTypeAndPriceUI() const;

	void showAllWishOffersUI() const;

	void deleteTouristWishOffersUI();

	void addTouristWishOfferUI();

	void generateTouristWishOfferUI();

<<<<<<< HEAD
<<<<<<< HEAD
	void reportUI() const;

	void exportCSV() const;
=======
	void reportUI();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	void reportUI();
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
};