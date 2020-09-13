#include "../View/Players_View.h"

using namespace std;

class Controller
{
    Batting_Model *batting_model;
    Players_View *players_view;

public:
    Controller(string file_path)
    {
        this->batting_model = new Batting_Model(file_path);
        this->players_view = new Players_View();
    }

    void sort_and_display(int amount, Sort_Choice sort_choice)
    {
        Sort_By_Params sort_by_param;
        list<Batsman> sorted_list = sort_by_param.sort(batting_model->get_batsman_list(), sort_choice);
        players_view->print_batsmen(sorted_list, amount);
    }
};

int main(int argc, char const *argv[])
{
    string batting_file_path = "./Resources/MostRuns.csv";
    Controller controller(batting_file_path);
    controller.sort_and_display(2, AVERAGE);
    controller.sort_and_display(4, STRIKING_RATES);
    return 0;
}
