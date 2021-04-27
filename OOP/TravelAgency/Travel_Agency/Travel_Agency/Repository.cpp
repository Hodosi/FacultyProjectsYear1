#include "Repository.h"

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
		throw RepositoryError("The offer doesn't exist!");
	}

	return *iterator;
}

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
	this->writeToFile();
}

void FileRepository::loadFromFile() {

	ifstream fin(this->file_name);

	if (!fin.is_open()) {
		throw FileError("Open error: " + this->file_name);
	}

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

	fin.close();
}

void FileRepository::writeToFile() {

	ofstream fout(file_name);

	if (!fout.is_open()) {
		throw FileError("Open error: " + this->file_name);
	}

	for (const auto& offer : this->getAll()) {
		fout << offer.getName() << " ";
		fout << offer.getDestination() << " ";
		fout << offer.getType() << " ";
		fout << offer.getPrice() << "\n";
	}

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