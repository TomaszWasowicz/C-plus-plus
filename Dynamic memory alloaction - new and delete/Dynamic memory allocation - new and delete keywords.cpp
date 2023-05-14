#include <iostream>

int main()
{
    new int{};   //allocated from the heap, normal variables form the heap
    int* ptr{ new int }; // dynamiczna alokacja i dolaczenie adresu do wskaznika,
    //by mozna go wyblo uzyc pozniej

    *ptr = 7; // dolaczenie wartosci 7 do wskaznika



    std::cout << new int << '\n';

    std::cout << *ptr << '\n';

    std::cout << &ptr << '\n';
 


    delete ptr;         //zwrocenie pamieci wskzazywanej przez wskaznik
                        //do systemu operacyjnego

    ptr = nullptr;      //ustaw wskaznik, bu byl zerowym wskaznikiem

    //std::cout << *ptr; blad odwolanie do nieinstejacego wskaznika


    return 0;
}

