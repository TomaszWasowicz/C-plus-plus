/*

The Mediator design pattern defines an object that encapsulates 
and coordinates how a set of objects interact.
This pattern promotes loose coupling by keeping objects 
from referring to each other explicitly and instead relying on a mediator.

Explanation:
1. Mediator Interface (Mediator):
- Defines an interface for communication between colleagues.
- Encapsulates the interaction logic.
2. Concrete Mediator (ConcreteMediator):
- Implements the mediator interface.
- Manages communication between colleagues.
3. Abstract Colleague (Colleague):
- Defines a base class for objects that interact through the mediator.
4. Concrete Colleagues (ConcreteColleague1, ConcreteColleague2):
- Communicate with each other through the mediator instead of directly.
5. Communication Flow:
- Colleagues send messages to the mediator.
- The mediator forwards these messages to other colleagues.

*/

#include <iostream>
#include<string>
#include<vector>
#include <memory>

//Forward declaration of Mediator to break circular dependency
class Mediator;

//Abstract Colleague
class Colleague {
private:
	Mediator* mediator;

protected:
	//Protected accessor method to allow derived classes to interact with the mediator
	Mediator* getMediator() const { return mediator; }
public:
	explicit Colleague(Mediator* med): mediator(med){}
	virtual ~Colleague() = default;

	virtual void sendMessage(const std::string& message) = 0;
	virtual void receiveMessage(const std::string& message) = 0;
};

//Mediator Interface
class Mediator {
public:
	virtual ~Mediator() = default;
	virtual void notify(Colleague* sender, const std::string& message) = 0;
};

//Concrete Colleague 1
class ConcreteColleague1 : public Colleague {
public:
	using Colleague::Colleague;

	void sendMessage(const std::string& message) override {
		std::cout << "Colleague1 sending a message: " << message << std::endl;
		getMediator()->notify(this, message);
	}

	void receiveMessage(const std::string& message) override {
		std::cout << "Colleague1 received a message: " << message << std::endl;
	}
};

//Concrete Colleague 2
class ConcreteColleague2 : public Colleague {
public:
	using Colleague::Colleague;

	void sendMessage(const std::string& message) override {
		std::cout << "Colleague2 sending a message: " << message << std::endl;
	}

	void receiveMessage(const std::string& message) override {
		std::cout << "Colleague2 received a message: " << message << std::endl;
		getMediator()->notify(this, message);
	}
};

//Concrete Mediator
class ConcreteMediator : public Mediator {
private:
	std::vector<Colleague*> colleagues;
public:
	void addColleague(Colleague* colleague) {
		colleagues.push_back(colleague);
	}

	void notify(Colleague* sender, const std::string& message) override {
		for (auto* colleague : colleagues) {
			if (colleague != sender) {		//Avoid sending the message back to the sender
				colleague->receiveMessage(message);
			}
		}
	}
};

int main() {

	//Create the mediator
	ConcreteMediator mediator;

	//Create colleagues and register them with the mediator
	ConcreteColleague1 colleague1(&mediator);
	ConcreteColleague2 colleague2(&mediator);

	mediator.addColleague(&colleague1);
	mediator.addColleague(&colleague2);

	//Colleagues communicate via the mediator
	colleague1.sendMessage("Hello, Colleague2!");
	colleague2.sendMessage("Hi, Colleague1!");

	return 0;
}