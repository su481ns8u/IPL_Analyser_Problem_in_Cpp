#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Batsman
{
    //POS,PLAYER,     Mat,Inns,NO,Runs,HS,  Avg, BF, SR,    100,50,4s,6s
    //1,David Warner ,12, 12,  2, 692, 100*,69.2,481,143.86, 1,  8,57,21

    string name;
    double avg = 0;
    double stk_rate = 0;
    int sixes = 0;
    int fours = 0;
    int runs = 0;

public:
    Batsman(string name)
    {
        this->name = name;
    }

    Batsman(vector<string> obj_params)
    {
        if (obj_params.size() >= 14)
        {
            this->name = obj_params.at(1);
            this->avg = stod(obj_params.at(7));
            this->stk_rate = stod(obj_params.at(9));
            this->sixes = stoi(obj_params.at(13));
            this->fours = stoi(obj_params.at(12));
            this->runs = stoi(obj_params.at(5));
        }
        else
            cout << "Length matching error !!!";
    }

    void set_runs_4s_6s(int runs, int fours, int sixes)
    {
        this->runs = runs;
        this->fours = fours;
        this->sixes = sixes;
    }

    void set_avg_and_strike(double stk_rate, double avg)
    {
        this->avg = avg;
        this->stk_rate = stk_rate;
    }

    string to_string()
    {
        return this->name + " " + std::to_string(this->avg) + "\n";
    }
};

class CSV_Reader
{
public:
    list<vector<string>> readFromFile(string fileName)
    {
        fstream file;
        list<vector<string>> compList;
        file.open(fileName, ios::in);
        if (file.is_open())
        {
            string line, word, temp;
            getline(file, line);
            while (!file.eof())
            {
                vector<string> row;
                getline(file, line);
                stringstream s(line);
                while (getline(s, word, ','))
                    row.push_back(word);
                compList.push_back(row);
            }
            file.close();
            return compList;
        }
        else
            cout << "Error opening file !!!";
    }
};

int main(int argc, char const *argv[])
{
    CSV_Reader csv_reader;
    list<vector<string>> demo = csv_reader.readFromFile("./Resources/MostRuns.csv");
    list<Batsman> batting;
    for (vector<string> temp : demo)
    {
        cout << temp.at(1) << " ";
        cout << temp.at(7) << " ";
        cout << temp.at(9) << " ";
        cout << temp.at(13) << " ";
        cout << temp.at(12) << " ";
        cout << temp.at(5) << " ";

        cout << endl;
    }

    for (vector<string> temp : demo)
    {
        Batsman *batsman = new Batsman(temp);
        batting.push_back(*batsman);
    }

    for (Batsman batsman : batting)
        cout << batsman.to_string();

    return 0;
}
