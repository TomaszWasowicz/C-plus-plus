/*
Celem Adaptera jest umo�liwienie wsp�pracy klas o niezgodnych interfejsach 
poprzez przekszta�cenie jednego interfejsu w inny oczekiwany przez klienta. 
Adapter dzia�a jako po�rednik, kt�ry �opakowuje� istniej�c� klas�, 
pozwalaj�c jej na komunikacj� z innymi klasami bez konieczno�ci modyfikacji kodu.
*/

#include <iostream>
#include <string>

class INewPrinter {
public:
	virtual void print(const std::string& text) = 0;
	virtual ~INewPrinter() = default;
};

class LegacyPrinter {
public:
	void printText(const std::string& text) const {
		std::cout << "Legacy Printer: " << text << std::endl;
	}
};

class PrinterAdapter : public INewPrinter {
private:
	LegacyPrinter* legacyPrinter; // pointer on an object to adapt
public:
	explicit PrinterAdapter(LegacyPrinter* printer) : legacyPrinter(printer){}

	void print(const std::string& text) override {
		//transformation of the interface
		legacyPrinter->printText(text);
	}
};

int main()
{
	LegacyPrinter legacyPrinter;
	PrinterAdapter adapter(&legacyPrinter);

	INewPrinter* newPrinter = &adapter;
	newPrinter->print("Hello, Adapter Pattern!");

	return 0;

}