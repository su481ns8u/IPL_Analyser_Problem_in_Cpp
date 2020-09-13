#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

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
    for (vector<string> temp : demo)
    {
        for (string ss : temp)
            cout << ss << " ";
        cout << endl;
    }
    return 0;
}
