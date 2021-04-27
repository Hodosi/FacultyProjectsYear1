#pragma once

template< typename ElementType>
class IteratorVector;

template< typename ElementType>
class DynamicVector {

	friend class IteratorVector<ElementType>;

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

public:
	// constructor
	DynamicVector<ElementType>() noexcept {

		this->capacity = 1;
		this->items = new ElementType[this->capacity];
		this->dimension = 0;
	}

	// destructor
	~DynamicVector<ElementType>() {
		delete[] this->items;
	}

	// copy constructor
	DynamicVector<ElementType>(const DynamicVector<ElementType>& other) {

		this->capacity = other.capacity;
		this->dimension = other.dimension;
		this->items = new ElementType[other.capacity];

		for (int i = 0; i < other.dimension; i++) {
			this->items[i] = other.items[i];
		}
	}

	// copy assignment operator
	const DynamicVector<ElementType>& operator=(const DynamicVector<ElementType>& other) {
		
		if (this == &other)
			return *this;

		delete[] this->items;
		this->items = new ElementType[other.capacity];
		this->capacity = other.capacity;
		this->dimension = other.dimension;

		for (int i = 0; i < other.dimension; i++) {
			this->items[i] = other.items[i];
		}

		return *this;
	}

	void push_back(const ElementType& item) {

		if (this->dimension == this->capacity) {
			this->redim();
		}

		items[dimension] = item;
		dimension++;
	}

	void pop_back() noexcept {

		if (dimension == 0) {
			return;
		}

		this->dimension--;
	}

	void erase(const int _position) {

		if (_position < 0 || _position >= dimension) {
			throw "Invalid Position";
		}

		if (_position == dimension - 1) {
			pop_back();
			return;
		}

		for (int i = _position; i < this->dimension - 1; i++) {
			items[i] = items[i + 1];
		}

		this->dimension--;
	}

	int size() const noexcept {
		return this->dimension;
	}

	void clear() noexcept {
		this->dimension = 0;
	}

	ElementType& at(const int _position) const {

		if (_position < 0 || _position >= dimension) {
			throw "Invalid Position";
		}

		return items[_position];
	}

	IteratorVector<ElementType> begin() const {
		return IteratorVector<ElementType>(*this);
	}

	IteratorVector<ElementType> end() const {
		return IteratorVector<ElementType>(*this, dimension);
	}
};

template< typename ElementType>
class IteratorVector {

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