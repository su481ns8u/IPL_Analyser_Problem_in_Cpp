#include "../Utils/CSV_Reader.h"

list<vector<string>> CSV_Reader::readFromFile(string fileName)
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