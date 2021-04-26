#include "Repository.h"

<<<<<<< HEAD
<<<<<<< HEAD
void MemoryRepository::addOffer(const TouristOffer& offer) {

	const auto iterator = find_if(this->all_offers.begin(), this->all_offers.end(),
		[&](const TouristOffer& item) { return offer == item; });

	if (iterator != this->all_offers.end()) {
		throw RepositoryError("The offer already exists!");
	}

	this->all_offers.push_back(offer);
}

const TouristOffer MemoryRepository::modifyOffer(const TouristOffer& offer) {

	const auto iterator = find_if(this->all_offers.begin(), this->all_offers.end(),
		[&](const TouristOffer& item) { return offer == item; });

	if (iterator == this->all_offers.end()) {
		throw RepositoryError("The offer doesn't exist!");
	}
    
	const auto old_offer = *iterator;

	replace_if(this->all_offers.begin(), this->all_offers.end(),
		[&](const TouristOffer& item) { return item == offer; }, offer);

	return old_offer;
}


void MemoryRepository::deleteOffer(const TouristOffer& offer) {

	const auto iterator = remove_if(this->all_offers.begin(), this->all_offers.end(),
		[&](const TouristOffer& item) { return item == offer; });

	if (iterator == this->all_offers.end()) {
		throw RepositoryError("The offer doesn't exist!");
	}

	this->all_offers.pop_back();
}

const TouristOffer MemoryRepository::getOfferByName(const string& name) const {

	const auto iterator = find_if(this->all_offers.begin(), this->all_offers.end(),
		[&](const TouristOffer& offer) { return offer.getName() == name; });

	if (iterator == this->all_offers.end()) {
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
void Repository::addOffer(const TouristOffer& offer) {

	auto iterator = find_if(this->dynamic_array.begin(), this->dynamic_array.end(),
		[&](TouristOffer item) { return offer == item; });

	if (iterator != this->dynamic_array.end()) {
		throw RepositoryError("The offer already exists!");
	}

	dynamic_array.push_back(offer);
}

void Repository::modifyOffer(const TouristOffer& offer) {

	auto iterator = find_if(this->dynamic_array.begin(), this->dynamic_array.end(),
		[&](TouristOffer item) { return offer == item; });

	if (iterator == this->dynamic_array.end()) {
		throw RepositoryError("The offer doesn't exist!");
	}
    
	replace_if(this->dynamic_array.begin(), this->dynamic_array.end(),
		[&](TouristOffer& item) { return item == offer; }, offer);
}


void Repository::deleteOffer(const TouristOffer& offer) {

	auto iterator = remove_if(this->dynamic_array.begin(), this->dynamic_array.end(),
		[&](TouristOffer& item) { return item == offer; });

	if (iterator == this->dynamic_array.end()) {
		throw RepositoryError("The offer doesn't exist!");
	}

	this->dynamic_array.pop_back();
}

TouristOffer Repository::getOfferByName(const string& name) const {

	auto iterator = find_if(this->dynamic_array.begin(), this->dynamic_array.end(),
		[&](TouristOffer offer) { return offer.getName() == name; });

	if (iterator == this->dynamic_array.end()) {
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		throw RepositoryError("The offer doesn't exist!");
	}

	return *iterator;
}

<<<<<<< HEAD
<<<<<<< HEAD
const vector<TouristOffer>& MemoryRepository::getAll() const noexcept {
	return this->all_offers;
}

const int MemoryRepository::getSize() const noexcept{
	return this->all_offers.size();
}


// file repository
void FileRepository::addOffer(const TouristOffer& offer) {

	MemoryRepository::addOffer(offer);
	this->writeToFile();
}

const TouristOffer FileRepository::modifyOffer(const TouristOffer& offer) {

	const auto old_offer = MemoryRepository::modifyOffer(offer);
	this->writeToFile();
	return old_offer;
}

void FileRepository::deleteOffer(const TouristOffer& offer) {

	MemoryRepository::deleteOffer(offer);
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
const int Repository::getSize() const noexcept{
	return this->dynamic_array.size();
}


//file repository
void FileRepository::addOffer(const TouristOffer& offer) {
	Repository::addOffer(offer);
	this->writeToFile();
}

void FileRepository::modifyOffer(const TouristOffer& offer) {
	Repository::modifyOffer(offer);
	this->writeToFile();
}

void FileRepository::deleteOffer(const TouristOffer& offer) {
	Repository::deleteOffer(offer);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	this->writeToFile();
}

void FileRepository::loadFromFile() {
<<<<<<< HEAD
<<<<<<< HEAD

	ifstream fin(this->file_name);

	if (!fin.is_open()) {
		throw FileError("Open error: " + this->file_name);
	}

=======
	ifstream fin(this->file_name);
	if (!fin.is_open()) {
		throw FileError("Open error: " + this->file_name);
	}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	ifstream fin(this->file_name);
	if (!fin.is_open()) {
		throw FileError("Open error: " + this->file_name);
	}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	while (!fin.eof()) {
		string name{""};
		fin >> name;
		//check empty lines
		if (fin.eof()) {
			break;
		}
		string destination{ "" };
		fin >> destination;
		string type{ "" };
		fin >> type;
		double price{ 0 };
		fin >> price;

		TouristOffer offer{ name, destination, type, price };
		FileRepository::addOffer(offer);
	}
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	fin.close();
}

void FileRepository::writeToFile() {
<<<<<<< HEAD
<<<<<<< HEAD

	ofstream fout(file_name);

	if (!fout.is_open()) {
		throw FileError("Open error: " + this->file_name);
	}

	for (const auto& offer : this->getAll()) {
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	ofstream fout(file_name);
	if (!fout.is_open()) {
		throw FileError("Open error: " + this->file_name);
	}
	for (auto& offer : this->getAll()) {
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		fout << offer.getName() << " ";
		fout << offer.getDestination() << " ";
		fout << offer.getType() << " ";
		fout << offer.getPrice() << "\n";
	}
<<<<<<< HEAD
<<<<<<< HEAD

	fout.close();
}

// lab activity repository

void LabActivityRepository::throwProbabilityException() const {

	if (rand() % 10 * 0.1 < this->probability) {
		throw RepositoryError("Oops");
	}
}

void LabActivityRepository::addOffer(const TouristOffer& offer) {

	this->throwProbabilityException();

	const auto iterator = this->all_offers.find(offer.getName());

	if (iterator != this->all_offers.end()) {
		throw RepositoryError("The offer already exists!");
	}

	this->all_offers.insert(make_pair(offer.getName(), offer));

	this->all_offers_vector.push_back(offer);
}

const TouristOffer LabActivityRepository::modifyOffer(const TouristOffer& offer) {

	this->throwProbabilityException();

	const auto iterator = this->all_offers.find(offer.getName());

	if (iterator == this->all_offers.end()) {
		throw RepositoryError("The offer doesn't exist!");
	}

	const auto old_offer = *iterator;

	this->all_offers.erase(iterator);

	this->all_offers.insert(make_pair(offer.getName(), offer));

	replace_if(this->all_offers_vector.begin(), this->all_offers_vector.end(),
		[&](const TouristOffer& item) { return item == offer; }, offer);

	return old_offer.second;
}

void LabActivityRepository::deleteOffer(const TouristOffer& offer) {

	this->throwProbabilityException();

	const int erased = this->all_offers.erase(offer.getName());

	if (erased == 0) {
		throw RepositoryError("The offer doesn't exist!");
	}

	const auto iterator = remove_if(this->all_offers_vector.begin(), this->all_offers_vector.end(),
		[&](const TouristOffer& item) { return item == offer; });

	this->all_offers_vector.pop_back();
}

const TouristOffer LabActivityRepository::getOfferByName(const string& name) const {

	this->throwProbabilityException();

	const auto iterator = this->all_offers.find(name);

	if (iterator == this->all_offers.end()) {
		throw RepositoryError("The offer doesn't exist!");
	}

	return (*iterator).second;
}

const vector<TouristOffer>& LabActivityRepository::getAll() const noexcept {
	return this->all_offers_vector;
}

const int LabActivityRepository::getSize() const noexcept {
	return this->all_offers.size();
}
=======
	fout.close();
}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	fout.close();
}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
