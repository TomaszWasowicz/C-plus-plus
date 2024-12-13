/*
Explanation

The Command pattern encapsulates a request as an object, 
allowing you to parameterize objects with different requests, 
delay execution of a request, or queue requests. 
It decouples the sender of a request from its receiver.

Components

1.Command Interface: Declares an interface for executing commands.
2.ConcreteCommand: Implements the command interface and defines the binding between the command and its receiver.
3.Receiver: The actual business logic that performs the actions requested by the command.
4.Invoker: Stores and executes the command.
5.Client: Creates and configures the commands and associates them with the invoker.
*/

#include <iostream>
#include <memory>
#include <vector>

// Command Interface
class Command {
public:
	virtual void execute() const = 0; // pure virtual method to execute a command
	virtual ~Command() = default;
};

//Receiver
class Receiver {
public:
	void actionA() const {
		std::cout << "Receiver: Executing Action A.\n";
	}

	void actionB() const {
		std::cout << "Receiver: Executing Action B.\n";
	}
};

//ConcreteCommandA
class ConcreteCommandA : public Command {
private:
	std::shared_ptr<Receiver> receiver; // Reference to the receiver

public:
	explicit ConcreteCommandA(std::shared_ptr<Receiver> receiver) : receiver(std::move(receiver)) {}

	void execute() const override {
		std::cout << "ConcreteCommandA: Invoking Action A.\n";
		receiver->actionA(); //Delegates action to the receiver
	}
};

//ConcreteCommandB
class ConcreteCommandB : public Command {
private:
	std::shared_ptr<Receiver> receiver; // Reference to the receiver

public:
	explicit ConcreteCommandB(std::shared_ptr<Receiver> receiver) : receiver(std::move(receiver)) {}

	void execute() const override {
		std::cout << "ConcreteCommandB: Invoking Action B.\n";
		receiver->actionB(); //Delegates action to the receiver
	}
};

//Invoker
class Invoker {
private:
	std::vector<std::shared_ptr<Command>> commandQueue; //Queue of commands

public:
	void addCommand(std::shared_ptr<Command> command) {
		commandQueue.push_back(std::move(command)); //Add command to the queue
	}

	void executeCommands(){
		for (const auto& command : commandQueue) {
			command->execute(); //Execute each command
		}
		commandQueue.clear(); //clear the queue after execution
	}
};

int main()
{
// Create a receiver 
	std::shared_ptr<Receiver> receiver = std::make_shared<Receiver>();

//and two commands
	std::shared_ptr<Command> commandA = std::make_shared<ConcreteCommandA>(receiver);
	std::shared_ptr<Command> commandB = std::make_shared<ConcreteCommandB>(receiver);

	// Create an invoker 
	Invoker invoker;

	//and add commands to the queue
	invoker.addCommand(commandA);
	invoker.addCommand(commandB);

	//Execute all commands
	invoker.executeCommands();

	return 0;
}