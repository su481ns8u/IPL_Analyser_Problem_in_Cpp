#include "../Model/Models.h"

list<Batsman> Sort_By_Params::sort(list<Batsman> batting_data)
{
    batting_data.sort([](Batsman &first, Batsman &second) {
        return first.get_avg() > second.get_avg();
    });
    return batting_data;
}