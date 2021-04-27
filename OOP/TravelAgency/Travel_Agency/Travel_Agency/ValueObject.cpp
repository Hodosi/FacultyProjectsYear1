#include "ValueObject.h"

TouristOffer::TouristOffer(const TouristOffer& other) {

	this->name = other.name;
	this->destination = other.destination;
	this->type = other.type;
	this->price = other.price;
	cout << "\nCopy constructor called\n";
}

string TouristOffer::getName() const {
	return this->name;
}

string TouristOffer::getDestination() const {
	return this->destination;
}

string TouristOffer::getType() const {
	return this->type;
}

double TouristOffer::getPrice() const noexcept {
	return this->price;
}

void TouristOffer::setDestination(const string& _destination) {
	this->destination = _destination;
}

void TouristOffer::setType(const string& _type) {
	this->type = _type;
}

void TouristOffer::setPrice(const double& _price) noexcept {
	this->price = _price;
}

string DtoOffer::getDestination() const {
	return this->destination;
}

const int DtoOffer::getCount() const noexcept {
	return this->count;
}

void DtoOffer::setCount(const int new_count)  noexcept {
	this->count = new_count;
}