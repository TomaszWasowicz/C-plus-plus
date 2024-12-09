#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Car {
private:
	std::string engine;
	std::string body;
	std::vector<std::string> accessories;
public:
void setEngine(const std::string& engine) {
	this->engine = engine;
}
void setBody(const std::string& body) {
	this->body = body;
}
void addAccessories(const std::string& accessory) {
	accessories.push_back(accessory);
}
void display() const {
	std::cout << "Engine: " << engine << std::endl;
	std::cout << "Body: " << body << std::endl;
	std::cout << "Accessories: " << std::endl;
	for (const auto& accessory : accessories) {
		std::cout << accessory << std::endl;
	}
	std::cout << std::endl;
}
};

class CarBuilder {

public:
	virtual ~CarBuilder() = default;

	virtual void buildEngine() = 0;
	
	virtual void buildBody() = 0;

	virtual void addAccessories() = 0;

	virtual std::unique_ptr<Car> getCar() = 0;
};

class SportsCarBuilder : public CarBuilder {
private:
	std::unique_ptr<Car> car;

public:
	SportsCarBuilder() {
		car = std::make_unique<Car>();
	}

	void buildEngine() override {
		car->setEngine("Sports engine");
	}

	void buildBody() override {
		car->setBody("Sports body");
	}

	void addAccessories() override {
		car->addAccessories("Sports tires");
		car->addAccessories("Sports sunroof");
		car->addAccessories("Sports windshields");
	}

	std::unique_ptr<Car> getCar() override {
		return std::move(car);
	}
};

class FamilyCarBuilder : public CarBuilder {
private:
	std::unique_ptr<Car> car;

public:
	FamilyCarBuilder() {
		car = std::make_unique<Car>();
	}

	void buildEngine() override {
		car->setEngine("Family engine");
	}

	void buildBody() override {
		car->setBody("Family body");
	}

	void addAccessories() override {
		car->addAccessories("Family tires");
		car->addAccessories("Family sunroof");
		car->addAccessories("Family windshields");
	}

	std::unique_ptr<Car> getCar() override {
		return std::move(car);
	}
};

class CarDirector {
private:
	CarBuilder& builder;

public:
	explicit CarDirector(CarBuilder& builder) : builder(builder) {}

	std::unique_ptr<Car> buildCar() {
		builder.buildEngine();
		builder.buildBody();
		builder.addAccessories();
		return builder.getCar();
	}
};

int main() {
	SportsCarBuilder sportsCarBuilder;
	CarDirector sportsCarDirector(sportsCarBuilder);
	auto sportsCar = sportsCarDirector.buildCar();
	sportsCar->display();

	FamilyCarBuilder familyCarBuilder;
	CarDirector familyCarDirector(familyCarBuilder);
	auto familyCar = familyCarDirector.buildCar();
	familyCar->display();

	return 0;
}

