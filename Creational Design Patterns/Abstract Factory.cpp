#include <iostream>
#include <memory>
#include <string>

class Chair {
public:
	virtual ~Chair() = default;
	virtual void sitOn() const = 0;
};

class Table {
public:
	virtual ~Table() = default;
	virtual void putOn() const = 0;
};

class ModernChair : public Chair {
public:
	void sitOn() const override {
		std::cout << "Sitting on a modern chair." << std::endl;
	}
};

class ModernTable : public Table {
public:
	void putOn() const override {
		std::cout << "Putting things on a modern table." << std::endl;
	}
};

class VictorianChair : public Chair {
public:
	void sitOn() const override {
		std::cout << "Sitting on a victorian chair." << std::endl;
	}
};

class VictorianTable : public Table {
public:
	void putOn() const override {
		std::cout << "Putting things on a victorian table." << std::endl;
	}
};

class FurnitureFactory {
public:
	virtual ~FurnitureFactory() = default;
	virtual std::unique_ptr<Chair> createChair() const = 0;
	virtual std::unique_ptr<Table> createTable() const = 0;
};

class ModernFurnitureFactory : public FurnitureFactory {
public:
	std::unique_ptr<Chair> createChair() const override {
		return std::make_unique<ModernChair>();
	}

	std::unique_ptr<Table> createTable() const override {
		return std::make_unique<ModernTable>();
	}
};

class ClassicFurnitureFactory : public FurnitureFactory {
public:
	std::unique_ptr<Chair> createChair() const override {
		return std::make_unique<VictorianChair>();
	}
	std::unique_ptr<Table> createTable() const override {
		return std::make_unique<VictorianTable>();
	}
};

class FurnitureStore {
private:
	const FurnitureFactory& factory;
public:
	explicit FurnitureStore(FurnitureFactory const& factory) : factory(factory) {}

	void displayFurniture() const {
		auto chair = factory.createChair();
		auto table = factory.createTable();
		chair->sitOn();
		table->putOn();
	}
};

int main(){

	ModernFurnitureFactory modernFactory;
	FurnitureStore modernStore(modernFactory);
	std::cout << "Modern furniture store:" << std::endl;
	modernStore.displayFurniture();

	ClassicFurnitureFactory classicFactory;
	FurnitureStore classicStore(classicFactory);
	std::cout << "Classic furniture store:" << std::endl;
	classicStore.displayFurniture();

	return 0;

}