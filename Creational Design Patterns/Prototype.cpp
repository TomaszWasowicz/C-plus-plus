#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

class Shape
{
public:
	virtual ~Shape() = default;
	virtual void draw() const = 0;
	virtual std::unique_ptr<Shape> clone() const = 0;
};

class Rectangle : public Shape
{
private:
	int width;
	int height;
public:

	Rectangle(int width, int height) : width(width), height(height) {}

	std::unique_ptr<Shape> clone() const override
	{
		return std::make_unique<Rectangle>(*this);
	}

	void draw() const override
	{
		std::cout << "Rectangle::draw()" << std::endl;
	}
};

class Circle : public Shape
{
private:
	int radius;
public:
	explicit Circle(int radius) : radius(radius) {}

std::unique_ptr<Shape> clone() const override
	{
		return std::make_unique<Circle>(*this);
	}

void draw() const override
	{
		std::cout << "Circle::draw()" << radius << std::endl;
	}
};

class PrototypeManager {
private:
	std::unordered_map<std::string, std::unique_ptr<Shape>> prototypes;
public:
	void registerPrototype(const std::string& name, std::unique_ptr<Shape> prototype) {
		prototypes[name] = std::move(prototype);
	}

	std::unique_ptr<Shape> createPrototype(const std::string& name) {
		auto it = prototypes.find(name);
		if (it != prototypes.end()) {
			return it->second->clone();
		}
		//throw std::runtime_error("Prototype not found");
		return nullptr;
	}
};

int main() {
	PrototypeManager prototypeManager;

	prototypeManager.registerPrototype("Rectangle", std::make_unique<Rectangle>(10, 20));
	prototypeManager.registerPrototype("Circle", std::make_unique<Circle>(5));

	auto rectangle = prototypeManager.createPrototype("Rectangle");
	rectangle->draw();

	auto circle = prototypeManager.createPrototype("Circle");
	circle->draw();

	return 0;
}