#include "../Utils/CSV_Reader.h"
#include "../Utils/Sort_Choice.h"

using namespace std;

class Batsman
{
    string name;
    double avg = 0;
    double stk_rate = 0;
    int sixes = 0;
    int fours = 0;
    int runs = 0;
    int hundreds = 0;
    int fifties = 0;

public:
    Batsman(string name);
    Batsman(vector<string> obj_params);
    void set_runs_4s_6s(int runs, int fours, int sixes);
    void set_avg_and_strike(double stk_rate, double avg);
    void set_100s_and_50s(int hundreds, int fifties);
    double get_avg();
    double get_sr();
    int get_total_6s_4s();
    int get_runs();
    int get_100s();
    int get_50s();
    string get_name();
    string to_string();
};

class Bowler
{
    string name;
    double avg = 0;
    double stk_rate = 0;
    double eco_rate = 0;
    int five_ws = 0;
    int four_ws = 0;
    int wkts = 0;

public:
    Bowler(string name);
    Bowler(vector<string> obj_params);
    void set_avg_sr_and_er(double avg, double stk_rate, double eco_rate);
    void set_5w_4w_and_wkts(int five_ws, int four_ws, int wkts);
    double get_avg();
    double get_sr();
    double get_ec();
    int get_total_5ws_4ws();
    int get_wkts();
    string get_name();
    string to_string();
};

class All_Rounder
{
    string name;
    double batting_avg = 0;
    double bowling_avg = 0;
    int runs = 0;
    int wkts = 0;

public:
    All_Rounder(string name);
    void set_bat_and_ball_avgs(double batting_avg, double bowling_avg);
    void set_runs_and_wkts(int runs, int wkts);
    double get_batting_avg();
    double get_bowling_avg();
    int get_runs();
    int get_wkts();
    string to_string();
};

class Batting_Model
{
    list<Batsman> batting_data;

public:
    Batting_Model();
    Batting_Model(string file_name);
    list<Batsman> get_batsman_list();
    void set_batsman_list(list<Batsman> batting_data);
};

class Bowling_Model
{
    list<Bowler> bowling_data;

public:
    Bowling_Model();
    Bowling_Model(string file_name);
    list<Bowler> get_bowlers_list();
    void set_bowlers_list(list<Bowler> bowling_data);
};

class Allrounder_Model
{
    list<All_Rounder> allrounder_data;

public:
    Allrounder_Model(list<Batsman> batsmen_data, list<Bowler> bowler_data);
    list<All_Rounder> get_allrounder_list();
};

class Sort_By_Params
{
public:
    list<Batsman> sort_batsmen(list<Batsman> batting_data, Batsman_Sort_Choice sort_choice);
    list<Bowler> sort_bowlers(list<Bowler> bowing_data, Bowler_Sort_Choice sort_choice);
    list<All_Rounder> sort_allrounders(list<All_Rounder> allrounder_data, Allrounder_Sort_Choice sort_choice);
};