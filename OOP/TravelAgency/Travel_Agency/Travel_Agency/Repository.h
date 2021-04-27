#pragma once

#include "ValueObject.h"
#include "Exception.h"

#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using std::vector;
using std::map;
using std::ifstream;
using std::ofstream;

class Repository {

private:

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
	 *         - the offer must be valid
	 * output: -
	 *         throw Repository error if the offer already exists
	*/
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

	/*
	 * find an offer for travel agency
	 * input:  the name of offer
	 *         - string
	 * output: a valid toursit offer
	 *         throw Repository error if the offer doesn't exist
	*/
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
		this->loadFromFile();
	}

	void addOffer(const TouristOffer& offer) override;

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
};