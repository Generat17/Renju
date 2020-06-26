#include "renju.h"

// Игра рендзю с упрощенными правилами.
// В этой игре не запрещнных ходов. 

int main()
{
    system("chcp 1251"); system("cls");

    renju first;
    first.start_game();

    system("pause");
    return 0;
}
