/*
Celem Adaptera jest umo¿liwienie wspó³pracy klas o niezgodnych interfejsach 
poprzez przekszta³cenie jednego interfejsu w inny oczekiwany przez klienta. 
Adapter dzia³a jako poœrednik, który „opakowuje” istniej¹c¹ klasê, 
pozwalaj¹c jej na komunikacjê z innymi klasami bez koniecznoœci modyfikacji kodu.
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