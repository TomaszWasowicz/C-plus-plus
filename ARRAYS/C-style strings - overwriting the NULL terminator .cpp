#include <iostream>

int main()
{

    //wyswietlone beda tylko x, potem 2 razy puste pola i na koniec name
    // std::cout printuje wszystko do null terminatora

    char name[20]{ "Alex" }; 

    std::cout << "My name is: " << '\n' << name[3] << '\n' << name[4]
        << '\n' << name[5] << '\n' << name << '\n';

    return 0;
}