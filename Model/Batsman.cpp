#include "../Model/Models.h"

Batsman::Batsman(string name)
{
    this->name = name;
}

Batsman::Batsman(vector<string> obj_params)
{
    if (obj_params.size() >= 14)
    {
        this->name = obj_params.at(1);
        this->set_avg_and_strike(stod(obj_params.at(7)), stod(obj_params.at(9)));
        this->set_runs_4s_6s(stoi(obj_params.at(5)), stoi(obj_params.at(12)), stoi(obj_params.at(13)));
    }
    else
        cout << "Length matching error !!!";
}

void Batsman::set_runs_4s_6s(int runs, int fours, int sixes)
{
    this->runs = runs;
    this->fours = fours;
    this->sixes = sixes;
}

void Batsman::set_avg_and_strike(double stk_rate, double avg)
{
    this->avg = avg;
    this->stk_rate = stk_rate;
}

double Batsman::get_avg()
{
    return this->avg;
}

string Batsman::to_string()
{
    return this->name + " " + std::to_string(this->avg) + "\n";
}