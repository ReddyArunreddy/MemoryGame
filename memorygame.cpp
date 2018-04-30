#include "gotoxy.h"
#include "memorygame.h"
void AboutGame(void)
{
    system("clear");
    std::cout << "\t\tThis game contains 20 cells in 4x5 matrix.\n";
    std::cout << "\t\tIn which 10 cells have unique numbers.\n";
    std::cout << "\t\tAnd other cells are duplicates of 10 cells.\n";
    std::cout << "\t\tYou have to open cell(Ex. A3).\n";
    std::cout << "\t\tIf the two continous opened cells are same.\n";
    std::cout << "\t\tThey will be opened otherwise will be closed(i.e default values, @)\n";
    std::cout << "\n\t\tPress Enter to continue.";
}
void PlayGame()
{
    char cell[2];
    MemoryGame m_Gmae;
    m_Gmae.DispGameBoard();
    std::cout << "Enter the Cell number to be opened: ";
    std::cin >> cell[0] >> cell[1];
    cell[0] = toupper(cell[0]);
    std::cout << cell << std::endl;
    
}
int main()
{
    char choice;
    while (1)
    {
        system("clear");
        std::cout << "\n\t\tWelCome To Memory Game!\n";
        std::cout << "\t\t01.Play Game.\n";
        std::cout << "\t\t02.About Game.\n";
        std::cout << "\t\t03.Exit.\n\t\t";
        std::cin >> choice;
        switch(choice)
        {
            case '1':
            PlayGame();
            break;
            case '2':
            AboutGame();
            case '3':
            return 0;
        }
        //std::cout <<"\033[8A";
        std::cin.get();
        std::cin.get();
    }
    return 0;
}