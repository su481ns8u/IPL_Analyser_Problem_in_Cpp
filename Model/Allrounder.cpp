#include "../Model/Models.h"

All_Rounder::All_Rounder(string name)
{
    this->name = name;
}

void All_Rounder::set_bat_and_ball_avgs(double batting_avg, double bowling_avg)
{
    this->batting_avg = batting_avg;
    this->bowling_avg = bowling_avg;
}

void All_Rounder::set_runs_and_wkts(int runs, int wkts)
{
    this->runs;
    this->wkts;
}

double All_Rounder::get_batting_avg()
{
    return this->batting_avg;
}

double All_Rounder::get_bowling_avg()
{
    return this->bowling_avg;
}

int All_Rounder::get_runs()
{
    return this->runs;
}

int All_Rounder::get_wkts()
{
    return this->wkts;
}

string All_Rounder::to_string()
{
    return "Name: " + this->name +
           "\nBatting Average: " + std::to_string(this->batting_avg) +
           "\tBowling Average: " + std::to_string(this->bowling_avg) +
           "\nRuns: " + std::to_string(this->runs) +
           "\tWickets: " + std::to_string(this->wkts) +
           "\n\n";
}