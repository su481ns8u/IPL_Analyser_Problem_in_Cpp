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

class Sort_By_Params
{
public:
    list<Batsman> sort(list<Batsman> batting_data);
};