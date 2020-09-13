#include "../View/Players_View.h"

Players_View::Players_View() {}

void Players_View::print_batsmen(list<Batsman> batsmen, int amount)
{
    int count = 0;
    for (Batsman batsman : batsmen)
    {
        cout << batsman.to_string();
        count++;
        if (count == amount)
            break;
    }
}