#include "../Model/Models.h"

using namespace std;

class Players_View
{
    Batting_Model batting_model;

public:
    Players_View();
    void print_batsmen(list<Batsman> batsmen, int amount);
    void print_bowler(list<Bowler> bowlers, int amount);
};