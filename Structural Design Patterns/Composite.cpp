/*
Composite is used to treat individual objects and compositions of objects uniformly. 
It’s commonly used to represent tree structures, such as file systems or UI components.
In this example, it is represented by a simple file system with folders and files
*/

#include <iostream>
#include <vector>
#include <memory>
#include <string>

//Component base class
class FileSystemEntity {
public:
	virtual ~FileSystemEntity() = default;
	virtual void display(int indentLevel = 0)const = 0; //pure virtual function
};


//Leaf class: File
class File : public FileSystemEntity {
private:
	std::string name;
public:
	explicit File(const std::string& name) : name(name) {}
	void display(int indentLevel = 0) const override {
		std::cout << std::string(indentLevel, ' ') << name << std::endl;
	}
};

//Composite class: Folder
class Folder : public FileSystemEntity {
private:
	std::string name;
	std::vector<std::unique_ptr<FileSystemEntity>> children; //holds files and subfolders
public:
	explicit Folder(const std::string& name) : name(name) {}

	void add(std::unique_ptr<FileSystemEntity> entity) {
		children.emplace_back(std::move(entity));
	}
	void display(int indentLevel = 0) const override {
		std::cout << std::string(indentLevel, ' ') << "Folder: " << name << std::endl;
		for (const auto& entity : children) {
			entity->display(indentLevel + 2); // Indent child elements
		}
	}
};

int main() {

	//create indywidual files
auto file1 = std::make_unique<File>("file1.txt"); //create file file1.txt
auto file2 = std::make_unique<File>("file2.txt"); //create file file2.txt
auto file3 = std::make_unique<File>("file3.txt"); //create file file3.txt

//create a folder and add files to it
auto folder1 = std::make_unique<Folder>("folder1"); 
folder1->add(std::move(file1)); //add file1 to folder1
folder1->add(std::move(file2)); //add file2 to folder1 

//create a root folder and add folder1 and another file
auto root = std::make_unique<Folder>("root");
root->add(std::move(folder1)); //add folder1 to root
root->add(std::move(file3)); //add file3 to root

//display the structure
root->display(); //display the rooot
	return 0;
}