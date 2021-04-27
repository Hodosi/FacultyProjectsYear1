#pragma once

#include <string>

using std::string;

class Exception {

private:
	const string error_message;

public:
	Exception(string error_mesage) : error_message{ error_mesage } {}

	const string& getMessage() const noexcept { return error_message; }
};

class ValueError : public Exception {

private:

public:
	ValueError(string error_message) : Exception(error_message) {}
};

class ValidationError : public Exception {

private:

public:
	ValidationError(string error_message) : Exception(error_message) {}
};

class RepositoryError : public Exception {

private:

public:
	RepositoryError(string error_message) : Exception(error_message) {}
};

class FileError : public RepositoryError {

private:

public:
	FileError(string error_message) : RepositoryError(error_message) {}
};

class WishListError : public Exception {

private:

public:
	WishListError(string error_message) : Exception(error_message) {}
};