#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class CSV_Reader
{
public:
    list<vector<string>> readFromFile(string fileName);
};