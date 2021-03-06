#pragma once

#include <string>
#include <iostream>

using std::string;
using std::cout;

class TouristOffer {

private:
	string name{ "" };
	string destination{ "" };
	string type{ "" };
	double price{ 0 };

public:
	/*
	 * create an toursit offer
	 * input:  -
	 * output: an empty tourist offer
	 */
	TouristOffer() : name{ "" }, destination{ "" }, type{ "" }, price{ 0 } {} 

	/*
	 * create an toursit offer
	 * input:  the name of offer
	 *         - string
	 *         the destination of offer
	 *         - string
	 *         the type of offer
	 *         - string
	 *         the price of offer
	 *         - double
	 * output: a tourist offer
	 */
	TouristOffer(const string& name, const string& destination, const string& type, const double& price)
		: name{ name }, destination{ destination }, type{ type }, price{ price } {}

	/*
	* copy constructor
	*/
	TouristOffer(const TouristOffer& other);

	/*
	* destructor
	*/
	~TouristOffer() {}

	/*
	* return the name of the offer
	*/
	string getName() const;

	/*
    * return the destintion of the offer
    */
	string getDestination() const;

	/*
	* return the type of the offer
	*/
	string getType() const;

	/*
	* return the price of the offer
	*/
	double getPrice() const noexcept;

	/*
	* modify the destintion of the offer
	* input:  the new destination
	*         - string
	*/
	void setDestination(const string& _destination);

	/*
	* modify the type of the offer
	* input:  the new type
	*         - string
	*/
	void setType(const string& _type);

	/*
	* modify the price of the offer
	* input:  the new price
	*         - double
	*/
	void setPrice(const double& _price) noexcept;

	/*
     * equal operator
	 * compare the name of offers
    */
	bool operator == (const TouristOffer& other) const {
		return this->getName() == other.getName();
	}

	/*
	 * not equal operator
	 * compare the name of offers
	*/
	bool operator != (const TouristOffer& other) const {
		return this->getName() != other.getName();
	}
};

class DtoOffer {

private:
	string destination{ "" };
	int count{ 0 };

public:
	DtoOffer() {}

	DtoOffer(const string& destination, const int count)
		: destination{ destination }, count{ count } {}

	string getDestination() const;

	const int getCount() const noexcept;

	void setCount(const int new_count) noexcept;
};