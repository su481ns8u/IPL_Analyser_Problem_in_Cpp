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

public:
    Batsman(string name);
    Batsman(vector<string> obj_params);
    void set_runs_4s_6s(int runs, int fours, int sixes);
    void set_avg_and_strike(double stk_rate, double avg);
    double get_avg();
    double get_sr();
    int get_total_6s_4s();
    int get_runs();
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

class Sort_By_Params
{
public:
    list<Batsman> sort_batsmen(list<Batsman> batting_data, Batsman_Sort_Choice sort_choice);
    list<Bowler> sort_bowlers(list<Bowler> bowing_data, Bowler_Sort_Choice sort_choice);
};