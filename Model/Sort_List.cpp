#include "../Model/Models.h"

list<Batsman> Sort_By_Params::sort_batsmen(list<Batsman> batting_data, Batsman_Sort_Choice sort_choice)
{
    switch (sort_choice)
    {
    case BATTING_AVERAGE:
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
    case AVERAGES_WITH_STRIKE_RATES:
        batting_data.sort([](Batsman &first, Batsman &second) {
            return (first.get_avg() > second.get_avg()) && (first.get_sr() > second.get_sr());
        });
        return batting_data;
        break;
    case MAX_RUNS_AND_AVERAGE:
        batting_data.sort([](Batsman &first, Batsman &second) {
            return (first.get_avg() > second.get_avg()) && (first.get_runs() > second.get_runs());
        });
        return batting_data;
        break;
    default:
        cout << "Invalid Choice !!!";
        break;
    }
}

list<Bowler> Sort_By_Params::sort_bowlers(list<Bowler> bowling_data, Bowler_Sort_Choice sort_choice)
{
    switch (sort_choice)
    {
    case AVERAGE:
        bowling_data.sort([](Bowler &first, Bowler &second) {
            return first.get_avg() > second.get_avg();
        });
        return bowling_data;
        break;
    case BOWLING_STRIKE_RATE:
        bowling_data.sort([](Bowler &first, Bowler &second) {
            return first.get_sr() > second.get_sr();
        });
        return bowling_data;
        break;
    case ECONOMY_RATE:
        bowling_data.sort([](Bowler &first, Bowler &second) {
            return first.get_ec() > second.get_ec();
        });
        return bowling_data;
        break;
    default:
        cout << "Invalid Choice !!!";
        break;
    }
}