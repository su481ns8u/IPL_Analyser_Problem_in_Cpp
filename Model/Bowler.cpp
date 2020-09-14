#include "../Model/Models.h"

Bowler::Bowler(string name)
{
    this->name = name;
}

Bowler::Bowler(vector<string> obj_params)
{
    if (obj_params.size() >= 12)
    {
        this->name = obj_params.at(1);
        this->set_avg_sr_and_er(stod(obj_params.at(8)), stod(obj_params.at(10)), stod(obj_params.at(9)));
        this->set_5w_4w_and_wkts(stoi(obj_params.at(12)), stoi(obj_params.at(11)), stoi(obj_params.at(6)));
    }
}

void Bowler::set_avg_sr_and_er(double avg, double stk_rate, double eco_rate)
{
    this->avg = avg;
    this->stk_rate = stk_rate;
    this->eco_rate = eco_rate;
}

void Bowler::set_5w_4w_and_wkts(int five_ws, int four_ws, int wkts)
{
    this->five_ws = five_ws;
    this->four_ws = four_ws;
    this->wkts = wkts;
}

double Bowler::get_avg()
{
    return this->avg;
}

double Bowler::get_sr()
{
    return this->stk_rate;
}

double Bowler::get_ec()
{
    return this->eco_rate;
}

int Bowler::get_total_5ws_4ws()
{
    return this->five_ws + this->four_ws;
}

string Bowler::to_string()
{
    return "Name: " + this->name +
           "\nAverage: " + std::to_string(this->avg) +
           "\tStrike Rate: " + std::to_string(this->stk_rate) +
           "\tEco Rate: " + std::to_string(this->eco_rate) +
           "\n5ws: " + std::to_string(this->five_ws) +
           "\t4ws: " + std::to_string(this->four_ws) +
           "\tWickets: " + std::to_string(this->wkts) +
           "\n\n";
}