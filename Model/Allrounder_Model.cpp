#include "../Model/Models.h"

Allrounder_Model::Allrounder_Model(list<Batsman> batting_data, list<Bowler> bowling_data)
{
    for (Batsman batsman : batting_data)
        for (Bowler bowler : bowling_data)
            if (batsman.get_name() == bowler.get_name())
            {
                All_Rounder allrounder(batsman.get_name());
                allrounder.set_bat_and_ball_avgs(batsman.get_avg(), bowler.get_avg());
                allrounder.set_runs_and_wkts(batsman.get_runs(), bowler.get_wkts());
                allrounder_data.push_back(allrounder);
            }
}

list<All_Rounder> Allrounder_Model::get_allrounder_list()
{
    return allrounder_data;
}