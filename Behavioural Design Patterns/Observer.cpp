/*
Explanation

This design ensures that the subject and observers are loosely coupled, 
promoting reusability and scalability.

The Observer pattern consists of:

1.Subject: Maintains a list of observers and notifies them of any changes.
2.Observer: Defines an interface for objects that need to be notified.
3.ConcreteSubject: Implements the Subject interface.
4.ConcreteObserver: Implements the Observer interface.
*/

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// Observer Interface
class Observer {
public:
	virtual ~Observer() = default;
	virtual void update(int value) = 0; //pure virtual function to be implemented
										//by concrete observers
};

//Subject Interface
class Subject {
public:
	virtual ~Subject() = default;
	virtual void attach(std::shared_ptr<Observer> observer) = 0;
	virtual void detach(std::shared_ptr<Observer> observer) = 0;
	virtual void notify() = 0; //notify all observers
};

//Concrete Subject
class ConcreteSubject : public Subject {
private:
	std::vector<std::shared_ptr<Observer>> observers;
	int state = 0; //example state
public:
	void setState(int newState) {
		state = newState;
		notify(); //Notify observers when the state changes
	}

	int getState() const {
		return state;
	}

	void attach(std::shared_ptr<Observer> observer) override {
		observers.push_back(observer);
	}

	void detach(std::shared_ptr<Observer> observer) override {
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}

	void notify() override {
		for (const auto& observer : observers) {
			observer->update(state);
		}
	}
};

class ConcreteObserver : public Observer {
private:
	std::string name; //observer name for indentification
	int observerState = 0; // Internal state matching the subject's state
public:
	explicit ConcreteObserver(std::string observerName) : name(std::move(observerName)) {}


	void update(int value) override {
		observerState = value;
		std::cout << "Observer" << name << " upddated with a new state: " << observerState	<< std::endl;
	}
};

int main()
{
	//Create a concrete subject
	auto subject = std::make_shared<ConcreteSubject>();

	// Create and attach observers
	auto observer1 = std::make_shared<ConcreteObserver>("1");
	auto observer2 = std::make_shared<ConcreteObserver>("2");

	subject->attach(observer1);
	subject->attach(observer2);

	//change subject state
	subject->setState(10);

	//Detach an observer and change state again
	subject->detach(observer1);
	subject->setState(20);

	return 0;
}

