#include "Validator.h"

void TravelAgencyValidator::touristOfferValidator(const TouristOffer& offer) const {
<<<<<<< HEAD
<<<<<<< HEAD
	
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	string error{ "" };
	if (offer.getName() == "") {
		error += "The name can't be empty!\n";
	}
	if (offer.getDestination() == "") {
		error += "The destination can't be empty!\n";
	}
	if (offer.getType() == "") {
		error += "The type can't be empty!\n";
	}
	if (offer.getPrice() < 0) {
		error += "The price can't be negative!";
	}
	if (error.size() > 0) {
		throw ValidationError(error);
	}
}