/*

Explanation:
1. Base Handler (Handler):
- Defines an interface for handling requests.
- Maintains a reference to the next handler in the chain.
2. Concrete Handlers:
- Implement the request handling logic.
- Delegate requests they cannot handle to the next handler.
3. Client:
- Configures the chain by linking handlers.
- Sends requests to the first handler in the chain.

*/

#include <iostream>
#include <string>
#include <memory>

//Abstract base class for handlers
class Handler {
public:
	virtual ~Handler() = default;

	//Set the next handler in the chain
	void setNext(std::shared_ptr<Handler> nextHandler) {
		next = nextHandler;
	}

	//Handle the request or pass it along the chain
	virtual void handleRequest(const std::string& request) {
		if (next) {
			next->handleRequest(request);
		}
		else {
			std::cout << "Request '" << request << "' could not be handled.\n";
		}
	}

private:
	std::shared_ptr<Handler> next = nullptr;
};

//Concrete handler for "low-level" requests
class LowLevelHandler : public Handler {
public:
	void handleRequest(const std::string& request) override {
		if (request == "low-level") {
			std::cout << "Low-level request handled the request.\n" <<request << std::endl;
		}
		else {
			Handler::handleRequest(request);
		}
	}
};

//Concrete handler for "mid-level" requests
class MidLevelHandler : public Handler {
public:
	void handleRequest(const std::string& request) override {
		if (request == "mid-level") {
			std::cout << "Mid-level request handled the request.\n" << request << std::endl;
		}
		else {
			Handler::handleRequest(request);
		}
	}
};

//Concrete handler for "high-level" requests
class HighLevelHandler : public Handler {
public:
	void handleRequest(const std::string& request) override {
		if (request == "high-level") {
			std::cout << "High-level request handled the request.\n" << request << std::endl;
		}
		else {
			Handler::handleRequest(request);
		}
	}
};

int main()
{
	//Create the handlers
	std::shared_ptr<Handler> lowLevelHandler = std::make_shared<LowLevelHandler>();
	std::shared_ptr<Handler> midLevelHandler = std::make_shared<MidLevelHandler>();
	std::shared_ptr<Handler> highLevelHandler = std::make_shared<HighLevelHandler>();

	//Create the chain: Low-level -> Mid-level -> High-level
	lowLevelHandler->setNext(midLevelHandler);
	midLevelHandler->setNext(highLevelHandler);

	//Test the chain
	lowLevelHandler->handleRequest("low-level");
	lowLevelHandler->handleRequest("mid-level");
	lowLevelHandler->handleRequest("high-level");
	lowLevelHandler->handleRequest("unknown-level"); //no handler for "unknown-level"

	return 0;
}