#ifndef MEMORYGAME_H
#define MEMORYGAME_H
/*
Row A is at line number 3.
Row B is at line number 5.
Row C is at line number 7.
Row D is at line number 9.

Cell A std::cout <<"\033[7A";
Cell B std::cout <<"\033[5A";
Cell C std::cout <<"\033[3A";
Cell D std::cout <<"\033[1A";

*/

#include <iostream>
#include <stdlib.h>
class MemoryGame
{
    char m_CurrentValues[4][5];
    char m_DefaultValues[4][5];
    int m_nTries;

  public:
    MemoryGame()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
                m_DefaultValues[i][j] = '@';
        }
        m_nTries = 0;
    }
    void DispGameBoard()
    {
        system("clear");
        std::cout << "\t\t1\t2\t3\t4\t5\n";
        std::cout << "\n\tA\t@\t@\t@\t@\t@\n";
        std::cout << "\n\tB\t@\t@\t@\t@\t@\n";
        std::cout << "\n\tC\t@\t@\t@\t@\t@\n";
        std::cout << "\n\tD\t@\t@\t@\t@\t@\n\t";
        //std::cout <<"\033[1A";
    }
    void ChangeCell()
    {
        char cell[2];
        std::cout << "Enter the Cell number to be opened: ";
        std::cin >> cell[0] >> cell[1];
        cell[0] = toupper(cell[0]);
    }
};
#endif //MEMORYGAME_H