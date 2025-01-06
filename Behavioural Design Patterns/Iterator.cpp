/*

The Iterator design pattern provides a way to access the elements of an aggregate object 
(like a collection) sequentially without exposing its underlying representation. 

Explanation
1. Abstract Iterator (Iterator): Defines the interface for accessing elements.
2. Concrete Iterator (ConcreteIterator): Implements the interface and provides the logic for traversing the collection.
3. Abstract Aggregate (Aggregate): Declares the interface for creating an iterator.
4. Concrete Aggregate (ConcreteAggregate): Implements the Aggregate interface and provides a collection to traverse.

*/

#include <iostream>
#include <vector>

//Abstract Iterator interface
class Iterator {
public:
	virtual ~Iterator() = default;
	virtual bool hasNext() = 0;	// check if more elements exist
	virtual int next() = 0;  //move to the next element
};

//Concrete Iterator
class ConcreteItertator : public Iterator {
private:
	const std::vector<int>& collection;
	size_t index = 0;
public:
	explicit ConcreteItertator(const std::vector<int>& coll) : collection(coll) {}

	int next() override {
		if(!hasNext()) throw std::out_of_range("No more elements");
		int value = collection[index];
		++index;
		return value;

	}

	bool hasNext() override {
		return index < collection.size();
	}
};

//Abstract Aggregate interface
class Aggregate {
public:
	virtual ~Aggregate() = default;
	virtual std::unique_ptr<Iterator> createIterator() const = 0;
};

//Concrete Aggregate
class ConcreteAggregate : public Aggregate {
private:
	std::vector<int> collection;
public:
	void add(int value) {
		collection.push_back(value);
	}
	std::unique_ptr<Iterator> createIterator() const override {
		return std::make_unique<ConcreteItertator>(collection);
	}
};

int main()
{
	//Create an aggregate object and add elements
	ConcreteAggregate aggregate;
	aggregate.add(10);
	aggregate.add(20);
	aggregate.add(30);

	//Create an iterator
	std::unique_ptr<Iterator> iterator = aggregate.createIterator();

	//Iterate through the collection
	while(iterator->hasNext()) {
		std::cout << iterator->next() << " ";
	}
	std::cout << std::endl;


	return 0;
}