/*

The Null Object Pattern provides a way to handle the absence of an object 
by using an object that implements default behavior. 
This can help avoid null pointer checks throughout the code

Let's assume we have a logging system. Normally, we log messages to a console or file, 
but sometimes we may not want to log anything (e.g., in a production environment). 
Instead of checking for a null logger, we use a NullLogger that does nothing

Explanation:

1. Logger: An abstract interface that defines the logging behavior.
2. ConsoleLogger: A concrete implementation that logs messages to the console.
3. NullLogger: A concrete implementation that does nothing, avoiding null pointer checks.
4. Application: Uses a logger without caring about the specific implementation.

This pattern eliminates the need for conditionals to check if a logger exists 
and ensures the code remains clean and maintainable.

*/

#include <iostream>
#include <memory>
#include <string>

//Abstract Logger interface
class Logger {
public:
	virtual ~Logger() = default;
	virtual void log(const std::string& message) const = 0;
};

//Concrete Logger: Logs to the console
class ConsoleLogger : public Logger {
public:
		void log(const std::string& message) const override {
			std::cout << "Console Log: " << message << std::endl;
	}
};

//Null Object: Does nothing
class NullLogger : public Logger {
public:
	void log(const std::string& message) const override {
		// Do nothing
	}
};

// Example of class using Logger
class Application {
private:
	std::shared_ptr<Logger> logger;
public:
	explicit Application(std::shared_ptr<Logger> logger) : logger(std::move(logger)){}

	void run() const {
		logger->log("Application started");
		//Application logic here...
		logger->log("Application finished");
	}
};

int main() {
	// Use ConsoleLogger
	auto consoleLogger = std::make_shared<ConsoleLogger>();
	Application appWithLogger(consoleLogger);
	appWithLogger.run();

	std::cout << "Switching to NullLogger ..." << std::endl;

	//Use NullLogger
	auto nullLogger = std::make_shared<NullLogger>();
	Application appWithoutLogger(nullLogger);
	appWithoutLogger.run();

	return 0;
}