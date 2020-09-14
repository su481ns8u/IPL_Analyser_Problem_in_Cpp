#include "../Model/Models.h"

Bowling_Model::Bowling_Model() {}

Bowling_Model::Bowling_Model(string file_name)
{
    CSV_Reader csv_reader;
    list<vector<string>> demo = csv_reader.readFromFile(file_name);
    for (vector<string> temp : demo)
        bowling_data.push_back(*(new Bowler(temp)));
}

list<Bowler> Bowling_Model::get_bowlers_list()
{
    return bowling_data;
}

void Bowling_Model::set_bowlers_list(list<Bowler> bowling_data)
{
    this->bowling_data = bowling_data;
}