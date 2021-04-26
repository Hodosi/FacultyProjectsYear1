#pragma once

#include <string>

<<<<<<< HEAD
<<<<<<< HEAD
using std::string;

class Exception {

private:
	const string error_message;
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
using namespace std;

class Exception {
private:
	string error_message;
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

public:
	Exception(string error_mesage) : error_message{ error_mesage } {}

	const string& getMessage() const noexcept { return error_message; }
};

class ValueError : public Exception {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
private:

public:
	ValueError(string error_message) : Exception(error_message) {}
};

class ValidationError : public Exception {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
private:

public:
	ValidationError(string error_message) : Exception(error_message) {}
};

class RepositoryError : public Exception {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
private:

public:
	RepositoryError(string error_message) : Exception(error_message) {}
};

class FileError : public RepositoryError {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
private:

public:
	FileError(string error_message) : RepositoryError(error_message) {}
};

class WishListError : public Exception {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
private:

public:
	WishListError(string error_message) : Exception(error_message) {}
};