#include <iostream>
#include <array>
#include <iterator>
#include <vector>

int main()
{

     char myarray[]{"dog"};

     for (int i:  myarray)
        std::cout << i << '\n'; // ostatni element c-style string dla intow to 0 !
     std::cout << sizeof(myarray) << '\n';     //rozmiat c-style string







    int* array2 = new int[5]{ 9, 7, 5, 3, 1 };

    

    std::cout << "int array[]{ 9, 7, 5, 3, 1 }" << '\n';
    std::cout << "array =  " << array2 << '\n';
    std::cout << "sizeof(array) =  " << sizeof(array2) << '\n';

    std::cout << "&array  = " << &array2 << '\n';
    std::cout << "*array = " << *array2 << '\n';     //derefencja skonwertowanej tablicy we wskaznik zwraca pierwszy element tablicy
    std::cout << "*(array + 1) = " << *(array2 + 1) << '\n';
    std::cout << "*array + 1 = " << *array2 + 1 << '\n';

    std::cout << *array2++ << '\n';  //9
    std::cout << *++array2 << '\n';  //5
    std::cout << *array2++ << '\n';  //5
    std::cout << *array2++ << '\n';  //3

    std::cout << *array2++ + 1 << '\n';  // 2 = 1 + 1

    
    

    


    /*
    int* ptr{ array };
    std::cout << "sizeof(ptr) =  " << sizeof(ptr) << '\n';
    std::cout << "sizeof(*ptr) =  " << sizeof(*ptr) << '\n';

    std::cout << "*ptr = " << *ptr << '\n';
    std::cout << "ptr = " << ptr << '\n';	 // type int*, prints 009DF9D4
    std::cout << "ptr = " << &ptr << '\n';	 // type int**, prints 009DF9C8

    char name[]{ "Tomek" };
    std::cout << "char name[]{ 'Tomek' }" << '\n';
    std::cout << "*name = " << *name << '\n';
    */

    return 0;
}
// h/t to reader PacMan for this example