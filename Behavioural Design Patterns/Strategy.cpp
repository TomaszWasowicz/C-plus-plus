/*
Explanation

The Strategy pattern defines a family of algorithms, 
encapsulates each one, and makes them interchangeable. 
It allows the algorithm to vary independently from the client that uses it.

Components

1. Strategy Interface: Declares a common interface for all supported algorithms.
2. Concrete Strategies: Implement specific algorithms that adhere to the Strategy interface.
3. Context: Maintains a reference to a Strategy object and allows clients to set or change the strategy at runtime.

*/

#include <iostream>
#include <memory>

//Strategy Interface
class Strategy {
public:
	virtual ~Strategy() = default;
	virtual void execute() const = 0; // Abstract method for executing the strategy
};

//ConcreteStrategyA
class ConcreteStrategyA : public Strategy {
public:
	void execute() const override {
		std::cout << "Executing ConcreteStrategyA.\n";
	}
};

//ConcreteStrategyB
class ConcreteStrategyB : public Strategy {
public:
	void execute() const override {
		std::cout << "Executing ConcreteStrategyB.\n";
	}
};

//Context class
class Context {
private:
	std::shared_ptr<Strategy> strategy; //Current strategy

public:
	void setStrategy(std::shared_ptr<Strategy> newStrategy) {
		strategy = std::move(newStrategy); //change the strategy dynamically
	}

	void executeStrategy() const {
		if (strategy) {
			strategy->execute(); //execute the current strategy
		}
		else {
			std::cout << "No strategy set.\n";
		}
	}
};

int main() {

	//Create a context and set the initial strategy - ConcreteStrategyA
	Context context;

	// Use ConcreteStrategyA and execute
	context.setStrategy(std::make_shared<ConcreteStrategyA>()); 
	context.executeStrategy();	//Output: Executing ConcreteStrategyA.

	//Switch to ConcreteStrategyB and execute
	context.setStrategy(std::make_shared<ConcreteStrategyB>());
	context.executeStrategy();	//Output: Executing ConcreteStrategyB.

	return 0;
}