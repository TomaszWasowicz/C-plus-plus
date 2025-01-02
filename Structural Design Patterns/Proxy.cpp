/*
Explanation:
1. Subject Interface: Defines the interface shared by both RealSubject and Proxy.
2. RealSubject: Implements the actual business logic.
3. Proxy: Controls access to the RealSubject and may add extra functionality (e.g., logging, access control).
4. Client Code: Interacts with the Subject interface without knowing whether it's dealing with a RealSubject or a Proxy.

*/

#include <iostream>
#include <string>

// Subject interface
class Subject {
public:
	virtual void request() const = 0; // pure virtual function
	virtual ~Subject() = default;
};

//Real Subject
class RealSubject : public Subject {
public:
	void request() const override {
		std::cout << "RealSubject: Handling request." << std::endl;
	}
};

//Proxy
class Proxy : public Subject {
private:
	std::unique_ptr<RealSubject> realSubject; // Holds a reference RealSubject instance
	bool hasAccess;			// Flag to simulate access control

	bool checkAccess() const {
		std::cout << "Proxy: Checking access." << std::endl;
		return hasAccess;
	}

	void logAccess() const {
		std::cout << "Proxy: Logging the access." << std::endl;
	}

public:
	explicit Proxy(bool access) : hasAccess(access) {realSubject = std::make_unique<RealSubject>();}

	void request() const override {
		if (checkAccess()) {
			realSubject->request();
			logAccess();
		}else{
			std::cout << "Proxy: Access denied." << std::endl;
		}
	}
};

void clientCode(const Subject& subject) {
	subject.request();
}

int main() {

	std::cout << "Client: Using RealSubject directly" << std::endl;
	RealSubject realSubject;
	clientCode(realSubject);

	std::cout << "\nClient: Using Proxy with access:" << std::endl;
	Proxy proxyWithAccess(true);
	clientCode(proxyWithAccess);

	std::cout << "\nClient: Using Proxy without access:" << std::endl;
	Proxy proxyWithoutAccess(false);
	clientCode(proxyWithoutAccess);

	return 0;
}

