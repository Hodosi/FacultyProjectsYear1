#include "UserInterface.h"

/*
 Adding, deleting, modifying and displaying tourist offers
 Offer search
 Filtering tourist offers by: destination, price
 Sort offers by: name, destination, type + price 
*/
void UI::showMenu() const{

	std::cout << "\n\n";
	std::cout << "1. Add tourist offer" << "\n";
	std::cout << "2. Delete tourist offer" << "\n";
	std::cout << "3. Modify tourist offer" << "\n";
	std::cout << "4. Undo" << "\n";
	std::cout << "5. Display tourist offers" << "\n";
	std::cout << "6. Find tourist offer by name" << "\n";
	std::cout << "7. Filter tourist offers by destination" << "\n";
	std::cout << "8. Filter tourist offers by price" << "\n";
	std::cout << "8. Sort tourist offers by name" << "\n";
	std::cout << "10. Sort tourist offers by destination" << "\n";
	std::cout << "11. Sort tourist offers by type and price" << "\n";
	std::cout << "12. Show cart(wish list)" << "\n";
	std::cout << "13. Empty cart: delete all offer from the cart" << "\n";
	std::cout << "14. Add to cart: add to cart a tourist offer by name" << "\n";
	std::cout << "15. Generate cart: the user enters the total number of offers, the cart itself populates randomly with tourist offers" << "\n";
	std::cout << "16. The number of tourist offers for each destination" << "\n";
	std::cout << "17. Export cart(wishlist) in CSV file" << "\n";
	std::cout << "exit";
	std::cout << "\n\n";
}

void UI::addSomeTravels() {

	string name{ "" };
	string destination{ "" };
	string type{ "" };
	double price{ 0 };

	name = "travel";
	destination = "paris";
	type = "full";
	price = 213.5;
	this->service.addOffer(name, destination, type, price);

	name = "excursion";
	destination = "milano";
	type = "empty";
	price = 43.46;
	this->service.addOffer(name, destination, type, price);

	name = "trip";
	destination = "roma";
	type = "full";
	price = 73.51;
	this->service.addOffer(name, destination, type, price);
}

void UI::addTouristOfferUI() {

	string name{ "" };
	string destination{ "" };
	string type{ "" };
	string price_string{ "" };
	double price{ 0 };
	size_t offset = NULL;

	cout << "Give the name of the offer: " << "\n";
	getline(cin, name);

	cout << "Give the destination of the offer: " << "\n";
	getline(cin, destination);

	cout << "Give the type of the offer: " << "\n";
	getline(cin, type);

	cout << "Give the price of the offer: " << "\n";
	getline(cin, price_string);

	try {
		price = stod(price_string, &offset);
	}
	catch (...) {
		throw ValueError("Incorrect numeric value!");
	}

	this->service.addOffer(name, destination, type, price);
}

void UI::modifyTouristOfferUI() {

	string name{ "" };
	string destination{ "" };
	string type{ "" };
	string price_string{ "" };
	double price{ 0 };
	size_t offset = NULL;

	cout << "Give the name of the offer: " << "\n";
	getline(cin, name);

	cout << "Give the new destination of the offer: " << "\n";
	getline(cin, destination);

	cout << "Give the new type of the offer: " << "\n";
	getline(cin, type);

	cout << "Give the new price of the offer: " << "\n";
	getline(cin, price_string);

	try {
		price = stod(price_string, &offset);
	}
	catch (...) {
		throw ValueError("Incorrect numeric value!");
	}

	this->service.modifyOffer(name, destination, type, price);
}

void UI::deleteTouristOfferUI() {

	string name{ "" };

	cout << "Give the name of the offer: " << "\n";
	getline(cin, name);

	this->service.deleteOffer(name);
}

void UI::showAllOffersUI() const {

	const auto& all_offers = this->service.getAll();

	cout << "\n";
	cout << "Name    " << "Destination" << "  Type  " << "  Price" << "\n";
	for (const auto& offer : all_offers) {
		cout << offer.getName() << "  ";
		cout << offer.getDestination() << "  ";
		cout << offer.getType() << "  ";
		cout << offer.getPrice() << "  ";
		cout << "\n";
	}
}

void UI::undoUI() {

	this->service.undo();
}

void UI::findTravelByNameUI() const {

	string name{ "" };

	cout << "Give the name of the offer: " << "\n";
	getline(cin, name);

	const auto& offer = this->service.findTravelByName(name);

	cout << "\n";
	cout << "Name    " << "Destination" << "  Type  " << "  Price" << "\n";
	cout << offer.getName() << "  ";
	cout << offer.getDestination() << "  ";
	cout << offer.getType() << "  ";
	cout << offer.getPrice() << "  ";
	cout << "\n";
}

void UI::getOffersByDestinationUI() const {

	string destination{ "" };

	cout << "Give the destination of the offers: " << "\n";
	getline(cin, destination);

	const auto& all_offers = this->service.getOffersByDestination(destination);

	cout << "\n";
	cout << "Name    " << "Destination" << "  Type  " << "  Price" << "\n";
	for (const auto& offer : all_offers) {
		cout << offer.getName() << "  ";
		cout << offer.getDestination() << "  ";
		cout << offer.getType() << "  ";
		cout << offer.getPrice() << "  ";
		cout << "\n";
	}
}

void UI::getOffersByPriceUI() const {

	string min_price_string{ "" };
	string max_price_string{ "" };
	double min_price{ 0 };
	double max_price{ 0 };
	size_t offset = NULL;

	cout << "Give the minimum price of the offers: " << "\n";
	getline(cin, min_price_string);

	try {
		min_price = stod(min_price_string, &offset);
	}
	catch (...) {
		throw ValueError("Incorrect numeric value!");
	}

	cout << "Give the maximum price of the offers: " << "\n";
	getline(cin, max_price_string);

	try {
		max_price = stod(max_price_string, &offset);
	}
	catch (...) {
		throw ValueError("Incorrect numeric value!");
	}

	const auto& all_offers = this->service.getOffersByPrice(min_price, max_price);

	cout << "\n";
	cout << "Name    " << "Destination" << "  Type  " << "  Price" << "\n";
	for (const auto& offer : all_offers) {
		cout << offer.getName() << "  ";
		cout << offer.getDestination() << "  ";
		cout << offer.getType() << "  ";
		cout << offer.getPrice() << "  ";
		cout << "\n";
	}
}

void UI::sortByNameUI() const {

	const auto& all_offers = this->service.sortByName();

	cout << "\n";
	cout << "Name    " << "Destination" << "  Type  " << "  Price" << "\n";
	for (const auto& offer : all_offers) {
		cout << offer.getName() << "  ";
		cout << offer.getDestination() << "  ";
		cout << offer.getType() << "  ";
		cout << offer.getPrice() << "  ";
		cout << "\n";
	}
}

void UI::sortByDestinationUI() const {

	const auto& all_offers = this->service.sortByDestination();

	cout << "\n";
	cout << "Name    " << "Destination" << "  Type  " << "  Price" << "\n";
	for (const auto& offer : all_offers) {
		cout << offer.getName() << "  ";
		cout << offer.getDestination() << "  ";
		cout << offer.getType() << "  ";
		cout << offer.getPrice() << "  ";
		cout << "\n";
	}
}

void UI::sortByTypeAndPriceUI() const {

	const auto& all_offers = this->service.sortByTypeAndPrice();

	cout << "\n";
	cout << "Name    " << "Destination" << "  Type  " << "  Price" << "\n";
	for (const auto& offer : all_offers) {
		cout << offer.getName() << "  ";
		cout << offer.getDestination() << "  ";
		cout << offer.getType() << "  ";
		cout << offer.getPrice() << "  ";
		cout << "\n";
	}
}

void UI::showAllWishOffersUI() const {

	const auto& all_offers = this->service.getAllWishOffers();

	cout << "\n";
	cout << "Name    " << "Destination" << "  Type  " << "  Price" << "\n";
	for (const auto& offer : all_offers) {
		cout << offer.getName() << "  ";
		cout << offer.getDestination() << "  ";
		cout << offer.getType() << "  ";
		cout << offer.getPrice() << "  ";
		cout << "\n";
	}
}

void UI::deleteTouristWishOffersUI() {

	this->service.deleteWishOffres();
	const auto& all_offers = this->service.getAllWishOffers();
	cout << "Number of wished offers: " << all_offers.size() << "\n";
}

void UI::addTouristWishOfferUI() {

	string name{ "" };
	
	cout << "Give the name of the offer: " << "\n";
	getline(cin, name);

	this->service.addWishOffer(name);

	const auto& all_offers = this->service.getAllWishOffers();
	cout << "Number of wished offers: " << all_offers.size() << "\n";
}

void UI::generateTouristWishOfferUI() {

	string random_number_string{ "" };
	int random_number{ 0 };
	size_t offset = NULL;

	cout << "Give the numbers of the wishd offers: " << "\n";
	getline(cin, random_number_string);

	try {
		random_number = stoi(random_number_string, &offset);
	}
	catch (...) {
		throw ValueError("Incorrect numeric value!");
	}
    
	this->service.generateWishOffers(random_number);

	const auto& all_offers = this->service.getAllWishOffers();
	cout << "Number of wished offers: " << all_offers.size() << "\n";
}

void UI::reportUI() const {

	const map<string, DtoOffer>& report_destination = service.report();

	for (const auto& v : report_destination) {
		cout << v.first << " " << v.second.getCount() << "\n";
	}
	cout << "\n";
}

void UI::exportCSV() const {
	
	string file_name{ "" };
	cout << "Add the file name:\n";
	getline(cin, file_name);
	file_name = file_name + ".csv";
	ofstream fout;
	fout.open(file_name);

	const auto& all_offers = this->service.getAllWishOffers();
	fout << "Name, Destination, Type,  Price, \n";
	for (const auto& offer : all_offers) {
		fout << offer.getName() << ",";
		fout << offer.getDestination() << ",";
		fout << offer.getType() << ",";
		fout << offer.getPrice() << ",";
		fout << "\n";
	}

	fout.close();

	cout << "Number of wished offers: " << all_offers.size() << "\n";
}

void UI::runUI() {

	//this->addSomeTravels();

	string command{ "exit" };

	while (true){
		this->showMenu();
		getline(cin, command);
		if (command == "exit") {
			return;
		}
		try {

			if (command == "1") {
				this -> addTouristOfferUI();
			}
			else if (command == "2") {
				this->deleteTouristOfferUI();
			}
			else if (command == "3") {
				this->modifyTouristOfferUI();
			}
			else if (command == "4") {
				this->undoUI();
			}
			else if (command == "5") {
				this->showAllOffersUI();
			}
			else if (command == "6") {
				this->findTravelByNameUI();
			}
			else if (command == "7") {
				this->getOffersByDestinationUI();
			}
			else if (command == "8") {
				this->getOffersByPriceUI();
			}
			else if (command == "9") {
				this->sortByNameUI();
			}
			else if (command == "10") {
				this->sortByDestinationUI();
			}
			else if (command == "11") {
				this->sortByTypeAndPriceUI();
			}
			else if (command == "12") {
				this->showAllWishOffersUI();
			}
			else if (command == "13") {
				this->deleteTouristWishOffersUI();
			}
			else if (command == "14") {
				this->addTouristWishOfferUI();
			}
			else if (command == "15") {
				this->generateTouristWishOfferUI();
			}
			else if (command == "16") {
				this->reportUI();
			}
			else if (command == "17") {
				this->exportCSV();
			}
			else {
				std::cout << "\n" << "Invalid Command" << "\n";
			}

		}
		catch (const ValueError &error) {
			std::cout << error.getMessage() << "\n";
		}
		catch (const ValidationError &error){
			std::cout << error.getMessage() <<"\n";
		}
		catch (const RepositoryError &error) {
			std::cout << error.getMessage() << "\n";
		}
		catch (const WishListError &error) {
			std::cout << error.getMessage() << "\n";
		}
	}
}