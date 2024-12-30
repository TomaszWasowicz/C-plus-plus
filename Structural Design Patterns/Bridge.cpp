/*
Bridge Design Pattern in C++ separates an abstraction from its implementation 
so that the two can vary independently.

Explanation:
1.Implementor (Color):
- Provides the interface for the "implementation" part of the pattern.
- Concrete classes (RedColor, BlueColor) implement this interface.
2. Abstraction (Shape):
- Defines the high-level interface.
- Uses an instance of the implementor (Color) to delegate responsibilities.
3. Refined Abstraction (Circle, Square):
- Extend the Shape class to provide specific implementations.
4. Bridge:
- The color pointer in Shape acts as the bridge between the abstraction and implementation, 
allowing both to vary independently.
*/

#include <iostream>
#include <memory>
#include <string>

//Implementor - Abstract interface for implementation
class Color {
public:
	virtual ~Color() = default;
	virtual std::string fill() const = 0;
};

//Concrete Implementor A
class RedColor : public Color {
public:
	std::string fill() const override { return "Red"; }
};

//Concrete Implementor B
class BlueColor : public Color {
public:
	std::string fill() const override { return "Blue"; }
};

//Abstraction - Base class for high-level interface
class Shape {
protected:
	std::shared_ptr<Color> color;
public:
	explicit Shape(std::shared_ptr<Color> c) : color(std::move(c)) {}
	virtual ~Shape() = default;
	virtual void draw() const = 0;
};

// Refined Abstraction A
class Circle : public Shape {
public:
	explicit Circle(std::shared_ptr<Color> c) : Shape(std::move(c)) {}
	void draw() const override {
		std::cout << "Circle with color " << color->fill() << std::endl;
	}
};

// Refined Abstraction B
class Square : public Shape {
public:
	explicit Square(std::shared_ptr<Color> c) : Shape(std::move(c)) {}
	void draw() const override {
		std::cout << "Square with color " << color->fill() << std::endl;
	}
};

// Client Code
int main()
{
	// Use the bridge pattern to mix and match shapes and colors
	std::shared_ptr<Color> red = std::make_shared<RedColor>();
	std::shared_ptr<Color> blue = std::make_shared<BlueColor>();

	std::shared_ptr<Shape> circle = std::make_shared<Circle>(red);
	std::shared_ptr<Shape> square = std::make_shared<Square>(blue);

	circle->draw();		// Output: Circle with color Red
	square->draw();		// Output: Square with color Blue

	return 0;
}