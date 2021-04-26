#pragma once

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
#include <iostream>

using namespace std;

<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
template< typename ElementType>
class IteratorVector;

template< typename ElementType>
class DynamicVector {
<<<<<<< HEAD
<<<<<<< HEAD

	friend class IteratorVector<ElementType>;

=======
	friend class IteratorVector<ElementType>;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
	friend class IteratorVector<ElementType>;
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
private:
	ElementType* items;
	int capacity = 1;
	int dimension = 0;

	void redim() {
		ElementType* new_items = new ElementType[2 * this->capacity];

		for (int i = 0; i < this->dimension; i++) {
			new_items[i] = items[i];
		}

		this->capacity = 2 * this->capacity;

		delete[] this->items;

		this->items = new_items;
	}
<<<<<<< HEAD
<<<<<<< HEAD

public:
	// constructor
	DynamicVector<ElementType>() noexcept {

		this->capacity = 1;
		this->items = new ElementType[this->capacity];
		this->dimension = 0;
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
public:
	// constructor
	DynamicVector<ElementType>() noexcept {
		this->capacity = 1;
		this->items = new ElementType[this->capacity];
		this->dimension = 0;

		//std::cout << "Creatorul 2000\n";
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	}

	// destructor
	~DynamicVector<ElementType>() {
		delete[] this->items;
<<<<<<< HEAD
<<<<<<< HEAD
=======

		//std::cout << "Distrugatorul 2000\n";
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======

		//std::cout << "Distrugatorul 2000\n";
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	}

	// copy constructor
	DynamicVector<ElementType>(const DynamicVector<ElementType>& other) {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		this->capacity = other.capacity;
		this->dimension = other.dimension;
		this->items = new ElementType[other.capacity];

		for (int i = 0; i < other.dimension; i++) {
			this->items[i] = other.items[i];
		}
<<<<<<< HEAD
<<<<<<< HEAD
=======

		//std::cout << "sunt aici sa copiez\n";
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======

		//std::cout << "sunt aici sa copiez\n";
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
	}

	// copy assignment operator
	const DynamicVector<ElementType>& operator=(const DynamicVector<ElementType>& other) {
<<<<<<< HEAD
<<<<<<< HEAD
		
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		if (this == &other)
			return *this;

		delete[] this->items;
		this->items = new ElementType[other.capacity];
		this->capacity = other.capacity;
		this->dimension = other.dimension;

		for (int i = 0; i < other.dimension; i++) {
			this->items[i] = other.items[i];
		}
<<<<<<< HEAD
<<<<<<< HEAD
=======
		
		//std::cout << "Asignez pe aici!\n";
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
		
		//std::cout << "Asignez pe aici!\n";
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9

		return *this;
	}

	void push_back(const ElementType& item) {
<<<<<<< HEAD
<<<<<<< HEAD

		if (this->dimension == this->capacity) {
			this->redim();
		}

=======
		if (this->dimension == this->capacity) {
			this->redim();
		}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
		if (this->dimension == this->capacity) {
			this->redim();
		}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		items[dimension] = item;
		dimension++;
	}

	void pop_back() noexcept {
<<<<<<< HEAD
<<<<<<< HEAD

		if (dimension == 0) {
			return;
		}

=======
		if (dimension == 0) {
			return;
		}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
		if (dimension == 0) {
			return;
		}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		this->dimension--;
	}

	void erase(const int _position) {
<<<<<<< HEAD
<<<<<<< HEAD

		if (_position < 0 || _position >= dimension) {
			throw "Invalid Position";
		}

=======
		if (_position < 0 || _position >= dimension) {
			throw "Invalid Position";
		}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
		if (_position < 0 || _position >= dimension) {
			throw "Invalid Position";
		}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		if (_position == dimension - 1) {
			pop_back();
			return;
		}
<<<<<<< HEAD
<<<<<<< HEAD

		for (int i = _position; i < this->dimension - 1; i++) {
			items[i] = items[i + 1];
		}

		this->dimension--;
	}

	int size() const noexcept {
=======
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		for (int i = _position; i < this->dimension - 1; i++) {
			items[i] = items[i + 1];
		}
		this->dimension--;
	}

	int size() const noexcept{
<<<<<<< HEAD
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		return this->dimension;
	}

	void clear() noexcept {
		this->dimension = 0;
	}

	ElementType& at(const int _position) const {
<<<<<<< HEAD
<<<<<<< HEAD

		if (_position < 0 || _position >= dimension) {
			throw "Invalid Position";
		}

=======
		if (_position < 0 || _position >= dimension) {
			throw "Invalid Position";
		}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
		if (_position < 0 || _position >= dimension) {
			throw "Invalid Position";
		}
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
		return items[_position];
	}

	IteratorVector<ElementType> begin() const {
		return IteratorVector<ElementType>(*this);
	}

	IteratorVector<ElementType> end() const {
		return IteratorVector<ElementType>(*this, dimension);
	}
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======

>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
};

template< typename ElementType>
class IteratorVector {
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
=======
>>>>>>> 0e98786e1e605535b168fa2c5265bf61cf2746f9
private:
	const DynamicVector<ElementType>& vector;
	int position = 0;
	
public:
	IteratorVector<ElementType>(const DynamicVector<ElementType>& vector) : vector{ vector } {}
	IteratorVector<ElementType>(const DynamicVector<ElementType>& vector, const int position) : vector{ vector }, position{ position } {}
     
	ElementType& element() const noexcept {
		return vector.items[position];
	}

	void next() noexcept{
		position++;
	}

	ElementType& operator * () const noexcept{
		return element();
	}
	
	IteratorVector<ElementType>& operator ++ () noexcept {
		next();
		return *this;
	}

	bool operator != (const IteratorVector<ElementType>& other) const noexcept {
		return this->position != other.position;
	}
};