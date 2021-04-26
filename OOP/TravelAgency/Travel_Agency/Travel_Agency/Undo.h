#pragma once

<<<<<<< HEAD
<<<<<<< HEAD
#include "ValueObject.h"
#include "Repository.h"

// pure virtual class
class UndoAction {

private:

public:
	/*
	* I want all subclasses defines this function
	*/
	virtual void doUndo() = 0;

	virtual ~UndoAction() noexcept = default;
};

class UndoAdd : public UndoAction {

private:
	TouristOffer added_offer;
	Repository& repository;

public:
	UndoAdd(Repository& repository, const TouristOffer& offer)
		: repository{ repository }, added_offer{ offer } {}
	/*
	* undo add : delete added offer
	*/
	void doUndo() override {
		repository.deleteOffer(added_offer);
	}
};

class UndoModify : public UndoAction {

private:
	TouristOffer modified_offer;
	Repository& repository;

public:
	UndoModify(Repository& repository, const TouristOffer& offer)
		: repository{ repository }, modified_offer{ offer } {}

	/*
	* undo modify : modify back modified offer
	*/
	void doUndo() override {
		repository.modifyOffer(modified_offer);
	}
};

class UndoDelete : public UndoAction {

private:
	TouristOffer deleted_offer;
	Repository& repository;

public:
	UndoDelete(Repository& repository, const TouristOffer& offer)
		: repository{ repository }, deleted_offer{ offer } {}

	/*
	* undo delete : add back deleted offer 
	*/
	void doUndo() override {
		repository.addOffer(deleted_offer);
	}
};
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
class UndoAction {
private:
public:
	virtual void doUndo() = 0;

	virtual ~UndoAction() = default;

};

class UndoAdd {
private:
public:
};

class UndoModify {
private:
public:
};

class UndoDelete {
private:
public:
};
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
