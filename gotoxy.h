#include <iostream>
#include <iomanip>
void gotoxy(int x, int y)
{
    std::cout << std::setw(x);
    for(; y>0; y--)
    std::cout << std::endl;
}