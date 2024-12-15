/*
The Decorator pattern allows to dynamically add behavior to objects without modifying their code.

Explanation

1.Component: Text is the base interface for objects that can be rendered as text.
2.Concrete Component: PlainText is the core text object that provides basic functionality.
3.Decorator: TextDecorator is the base class for all decorators. It holds a reference to a Text object.
4.Concrete Decorators: BoldText, ItalicText, and UnderlineText are specific decorators 
that modify the behavior of the render method by wrapping the output in HTML-like tags.

This pattern enables you to dynamically combine behaviors at runtime 
without altering the structure of the objects being decorated.
*/

#include <iostream>
#include <memory>
#include <string>

//Component base class
class Text {
public:
	virtual ~Text() = default;
	virtual std::string render() const = 0; //pure virtual function
};

//Concrete Component
class PlainText : public Text {
	std::string content;
public:
	explicit PlainText(const std::string& text) : content(text) {}
	std::string render() const override { return content; } // Base funcitonality
};

//Base Decorator
class TextDecorator : public Text {
public:
	std::shared_ptr<Text> wrappedText; //Composition
	explicit TextDecorator(std::shared_ptr<Text> text) : wrappedText(std::move(text)) {}
};

//Concrete Decorators

class BoldText : public TextDecorator {
public:
	explicit BoldText(std::shared_ptr<Text> text) : TextDecorator(std::move(text)) {}
	std::string render() const override { return "<b>" + wrappedText->render() + "</b>"; }
};

class ItalicText : public TextDecorator {
public:
	explicit ItalicText(std::shared_ptr<Text> text) : TextDecorator(std::move(text)) {}
	std::string render() const override { return "<i>" + wrappedText->render() + "</i>"; }
};

class UnderlineText : public TextDecorator {
public:
	explicit UnderlineText(std::shared_ptr<Text> text) : TextDecorator(std::move(text)) {}
	std::string render() const override { return "<u>" + wrappedText->render() + "</u>"; }
};

int main()
{
	//Create a plain text component
	auto text = std::make_shared<PlainText>("Hello, world!");

	//Decorate the text with different decorators
	auto boldText = std::make_shared<BoldText>(text);
	auto italicText = std::make_shared<ItalicText>(text);
	auto underlineText = std::make_shared<UnderlineText>(text);

	//render the decorated text
	std::cout << "Plain text: " << text->render() << std::endl;
	std::cout << "Bold text: " << boldText->render() << std::endl;
	std::cout << "Italic text: " << italicText->render() << std::endl;
	std::cout << "Underline text: " << underlineText->render() << std::endl;

	return 0;
}

