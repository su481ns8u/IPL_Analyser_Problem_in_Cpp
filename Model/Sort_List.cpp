#include "../Model/Models.h"

list<Batsman> Sort_By_Params::sort(list<Batsman> batting_data, Sort_Choice sort_choice)
{
    switch (sort_choice)
    {
    case AVERAGE:
        batting_data.sort([](Batsman &first, Batsman &second) {
            return first.get_avg() > second.get_avg();
        });
        return batting_data;
        break;
    case STRIKING_RATES:
        batting_data.sort([](Batsman &first, Batsman &second) {
            return first.get_sr() > second.get_sr();
        });
        return batting_data;
        break;
    case MAX_6S_AND_4S:
        batting_data.sort([](Batsman &first, Batsman &second) {
            return first.get_total_6s_4s() > second.get_total_6s_4s();
        });
        return batting_data;
        break;
    case STRIKE_RATES_WITH_6S_AND_4S:
        batting_data.sort([](Batsman &first, Batsman &second) {
            return (first.get_total_6s_4s() > second.get_total_6s_4s()) && (first.get_sr() > second.get_sr());
        });
        return batting_data;
        break;
    default:
        cout << "Invalid Choice !!!";
        break;
    }
}