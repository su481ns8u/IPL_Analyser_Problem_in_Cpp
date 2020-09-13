#include "../Model/Models.h"

Batting_Model::Batting_Model() {}

Batting_Model::Batting_Model(string file_name)
{
    CSV_Reader csv_reader;
    list<vector<string>> demo = csv_reader.readFromFile(file_name);
    for (vector<string> temp : demo)
        batting_data.push_back(*(new Batsman(temp)));
}

void Batting_Model::set_batsman_list(list<Batsman> batting_data)
{
    this->batting_data = batting_data;
}

list<Batsman> Batting_Model::get_batsman_list()
{
    return this->batting_data;
}