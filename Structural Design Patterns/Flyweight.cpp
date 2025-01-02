/*

Explanation:
1. Flyweight Interface: Defines the operations that all flyweights must implement.
2. Concrete Flyweight: Implements the Flyweight interface and contains intrinsic state (shared state).
3. Flyweight Factory: Manages the creation and reuse of Flyweight objects to ensure they are shared efficiently.
4. Intrinsic State: Shared state that is common across multiple flyweights.
5. Extrinsic State: Context-specific state passed to the flyweight during method calls.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

// Flyweight interface
class Flyweight {
public:
	virtual void operation(const std::string& extrinsicState) const = 0;
	virtual ~Flyweight() = default;
};

//Concrete Flyweight
class ConcreteFlyweight : public Flyweight {
private:
	std::string intrinsicState; // State shared across multiple objects
public:
	explicit ConcreteFlyweight(const std::string& state) : intrinsicState(state) {}

	void operation(const std::string& extrinsicState) const override {
		std::cout << "Flyweight ith intristic state [" << intrinsicState
			<< "] and extrinsic state [" << extrinsicState << "].\n";
	}
};

// Flyweight Factory
class FlyweightFactory {
private:
	std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights;
public:
	std::shared_ptr<Flyweight> getFlyweight(const std::string& intristicState) {
		if(flyweights.find(intristicState) == flyweights.end()) {
			std::cout << "Creating new Flyweight for state: " << intristicState << std::endl;
			flyweights[intristicState] = std::make_shared<ConcreteFlyweight>(intristicState);
		}
		else {
			std::cout << "Reusing existing Flyweight for state: " << intristicState << std::endl;
		}
		return flyweights[intristicState];
	}

	size_t flyweightCount() const { return flyweights.size(); }

};

//Client code
void clientCode(FlyweightFactory& factory, const std::string& intrinsicState, const std::string& extrinsicState) {
	std::shared_ptr<Flyweight> flyweight = factory.getFlyweight(intrinsicState);
	flyweight->operation(extrinsicState);
}

int main()
{

	FlyweightFactory factory;

	std::cout << "Creating Flyweights:\n";
	clientCode(factory, "StateA", "Context1");
	clientCode(factory, "StateA", "Context2");
	clientCode(factory, "StateB", "Context3");
	clientCode(factory, "StateB", "Context4");

	std::cout << "\nTotal Flyweights created: " << factory.flyweightCount() << std::endl;

	return 0;
}