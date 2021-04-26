#pragma once

#include "ValueObject.h"
#include "Exception.h"
<<<<<<< HEAD
<<<<<<< HEAD

#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using std::vector;
using std::map;
using std::ifstream;
using std::ofstream;
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
#include "DynamicArray.h"

#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

class Repository {

private:
<<<<<<< HEAD
<<<<<<< HEAD

public:
	/*
	 * create a repository
	 * input:  -
	 * output: a new empty repository
	*/
	Repository() noexcept = default;

	/*
	* I don't want the repository to be copied
	*/
	Repository(const Repository& other) = delete;

	/*
	 * I don't want the repository to be assigned
	*/
	void operator=(const Repository& other) = delete;

	/*
	 * I want polymorphic behaviour during run time
	*/
	virtual ~Repository() noexcept = default;

	/*
	 * add an offer in repository
	 * input:  an offer for travel agency
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	vector<TouristOffer> dynamic_array;
	//DynamicVector<TouristOffer> dynamic_array;

public:

	/*
     * create a repository and a dynamic array
     * input:  -
     * output: a new empty repository
    */
	Repository() : dynamic_array{ } {}

	/*
	 * add an offer in repository
     * input:  an offer for travel agency
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	 *         - the offer must be valid
	 * output: -
	 *         throw Repository error if the offer already exists
	*/
<<<<<<< HEAD
<<<<<<< HEAD
	virtual void addOffer(const TouristOffer & offer) = 0;

	/*
	 * modify an offer in repository
	 * input:  an offer for travel agency
	 *         - the offer must be valid
	 * output: -
	 *         throw Repository error if the offer doesn't exist
	*/
	virtual const TouristOffer modifyOffer(const TouristOffer & offer) = 0;

	/*
	 * delete an offer in repository
	 * input:  an offer for travel agency
	 *         - the offer must be valid
	 * output: -
	 *         throw Repository error if the offer doesn't exist
	*/
	virtual void deleteOffer(const TouristOffer & offer) = 0;
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	virtual void addOffer(const TouristOffer& offer);

	/*
     * modify an offer in repository
     * input:  an offer for travel agency
     *         - the offer must be valid
     * output: -
     *         throw Repository error if the offer doesn't exist
    */
	virtual void modifyOffer(const TouristOffer& offer);

	/*
     * delete an offer in repository
     * input:  an offer for travel agency
     *         - the offer must be valid
     * output: -
     *         throw Repository error if the offer doesn't exist
    */
	virtual void deleteOffer(const TouristOffer& offer);
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

	/*
	 * find an offer for travel agency
	 * input:  the name of offer
	 *         - string
	 * output: a valid toursit offer
	 *         throw Repository error if the offer doesn't exist
	*/
<<<<<<< HEAD
<<<<<<< HEAD
	virtual const TouristOffer getOfferByName(const string & name) const = 0;

	/*
     * return all offers
    */
	virtual const vector<TouristOffer>& getAll() const noexcept = 0;

	/*
	* return the numbers of offers
	*/
	virtual const int getSize() const noexcept = 0;
};

class MemoryRepository : public Repository {

private:
	vector<TouristOffer> all_offers;

public:
	MemoryRepository() noexcept : Repository(), all_offers{ } {}

	virtual void addOffer(const TouristOffer& offer) override;

	virtual const TouristOffer modifyOffer(const TouristOffer& offer) override;

	virtual void deleteOffer(const TouristOffer& offer) override;

	const TouristOffer getOfferByName(const string& name) const override;

    const vector<TouristOffer>& getAll() const noexcept override;

	const int getSize() const noexcept override;
};

class FileRepository : public MemoryRepository {

private:
	const string file_name;
	void loadFromFile();
	void writeToFile();

public:
	FileRepository(const string& file_name) : MemoryRepository(), file_name{ file_name }{
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	TouristOffer getOfferByName(const string& name) const;

	/*
    * return all offers
    */
	const auto& getAll() const noexcept
	{ return this->dynamic_array; }
	
	/*
    * return the numbers of offers
    */
	const int getSize() const noexcept;
};

class FileRepository : public Repository {
private:
	string file_name;
	void loadFromFile();
	void writeToFile();
public:
	FileRepository(const string& file_name) : Repository(), file_name{ file_name }{
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		this->loadFromFile();
	}

	void addOffer(const TouristOffer& offer) override;

<<<<<<< HEAD
<<<<<<< HEAD
	const TouristOffer modifyOffer(const TouristOffer& offer) override;

	void deleteOffer(const TouristOffer& offer) override;
};

class LabActivityRepository : public Repository {

private:
	map<string, TouristOffer> all_offers;
	vector<TouristOffer> all_offers_vector;
	double probability;
	void throwProbabilityException() const;

public:
	LabActivityRepository(const double probability) noexcept
		: Repository(), all_offers{ }, all_offers_vector{ }, probability{ probability } {}

	void addOffer(const TouristOffer& offer) override;

    const TouristOffer modifyOffer(const TouristOffer& offer) override;

	void deleteOffer(const TouristOffer& offer) override;

	const TouristOffer getOfferByName(const string& name) const override;

	const vector<TouristOffer>& getAll() const noexcept override;

	const int getSize() const noexcept override;
=======
	void modifyOffer(const TouristOffer& offer) override;

	void deleteOffer(const TouristOffer& offer) override;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	void modifyOffer(const TouristOffer& offer) override;

	void deleteOffer(const TouristOffer& offer) override;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
};