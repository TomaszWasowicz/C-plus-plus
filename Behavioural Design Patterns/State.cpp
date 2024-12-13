#include <iostream>
#include <memory>

// forward declaration of Context
class Context;

// State Interface
class State {
public:
	virtual ~State() = default;
	virtual void handle(Context& context) = 0; //pure virtual function to hadle behaviour
};

// context class
class Context {
private:
	std::shared_ptr<State> currentState; // current state of the Context
public:
	explicit Context(std::shared_ptr<State> state ) : currentState(std::move(state)) {}

	void setState(std::shared_ptr<State> state) {
		currentState = std::move(state); //change the state
	}

	void request() {
		if (currentState) {
			currentState->handle(*this); //delegate behaviour to the current state
		}
	}
};

//Concrete State A
class ConcreteStateA : public State {
public:
	void handle(Context& context) override {
		std::cout << "ConcreteStateA: handling the request. Transition to ConcreteStateB\n";
		context.setState(std::make_shared<ConcreteStateB>()); //change state to ConcreteStateB
	}
};

class ConcreteStateB : public State {
public:
	void handle(Context& context) override {
		std::cout << "ConcreteStateB: handling the request. Transition to ConcreteStateA\n";
		context.setState(std::make_shared<ConcreteStateA>()); //change state to ConcreteStateA
	}
};

int main()
{
	//Initialize context with ConcreteStateA
	auto initialState = std::make_shared<ConcreteStateA> ();
	Context context(initialState);

	//Request calls, triggering state of transmisions
	context.request();	// ConcreteStateA -> ConcreteStateB
	context.request(); //ConcreteStateB -> ConcreteStateA
	context.request(); //ConcreteStateA -> ConcreteStateB

	return 0;
}