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
    cout << endl;
}

void Players_View::print_bowler(list<Bowler> bowlers, int amount)
{
    int count = 0;
    for (Bowler bowler : bowlers)
    {
        cout << bowler.to_string();
        count++;
        if (count == amount)
            break;
    }
    cout << endl;
}

void Players_View::print_allrounder(list<All_Rounder> allrounders, int amount)
{
    int count = 0;
    for (All_Rounder allrounder : allrounders)
    {
        cout << allrounder.to_string();
        count++;
        if (count == amount)
            break;
    }
    cout << endl;
}