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
    case MAX_100S_AND_BAT_AVERAGES:
        batting_data.sort([](Batsman &first, Batsman &second) {
            return (first.get_100s() > second.get_100s()) && (first.get_avg() > second.get_avg());
        });
        return batting_data;
        break;
    case NO_100_AND_50S_BUT_GOOD_AVG:
    {
        list<Batsman> temp_list;
        for (Batsman batsman : batting_data)
            if (batsman.get_100s() == 0 && batsman.get_50s() == 0)
                temp_list.push_back(batsman);
        temp_list.sort([](Batsman &first, Batsman &second) {
            return first.get_avg() > second.get_avg();
        });
        return temp_list;
    }
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
    case SR_WITH_5W_AND_4W:
        bowling_data.sort([](Bowler &first, Bowler &second) {
            return (first.get_sr() > second.get_sr()) && (first.get_total_5ws_4ws() > second.get_total_5ws_4ws());
        });
        return bowling_data;
        break;
    case AVERAGE_WITH_STRIKE_RATE:
        bowling_data.sort([](Bowler &first, Bowler &second) {
            return (first.get_sr() > second.get_sr()) && (first.get_avg() > second.get_avg());
        });
        return bowling_data;
        break;
    case MAX_WKTS_WITH_AVG:
        bowling_data.sort([](Bowler &first, Bowler &second) {
            return (first.get_wkts() > second.get_wkts()) && (first.get_avg() > second.get_avg());
        });
        return bowling_data;
        break;
    default:
        cout << "Invalid Choice !!!";
        break;
    }
}

list<All_Rounder> Sort_By_Params::sort_allrounders(list<All_Rounder> allrounders_data, Allrounder_Sort_Choice sort_choice)
{
    switch (sort_choice)
    {
    case BATTING_AND_BOWLING_AVG:
        allrounders_data.sort([](All_Rounder &first, All_Rounder &second) {
            return (first.get_batting_avg() > second.get_batting_avg()) && (first.get_bowling_avg() > second.get_bowling_avg());
        });
        return allrounders_data;
        break;
    case MOST_RUNS_AND_WICKETS:
        allrounders_data.sort([](All_Rounder &first, All_Rounder &second) {
            return (first.get_runs() > second.get_runs()) && (first.get_wkts() > second.get_wkts());
        });
        return allrounders_data;
        break;
    default:
        cout << "Invalid choice !!!";
        break;
    }
}