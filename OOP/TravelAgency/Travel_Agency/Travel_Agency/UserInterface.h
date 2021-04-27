#pragma once

#include "Service.h"
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

	void runUI();

private:
	Service& service;

	void showMenu() const;

	void addSomeTravels();

	void addTouristOfferUI();

	void modifyTouristOfferUI();

	void deleteTouristOfferUI();

	void undoUI();

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

	void reportUI() const;

	void exportCSV() const;
};