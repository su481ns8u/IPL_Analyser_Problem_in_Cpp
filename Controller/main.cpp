#include "../View/Players_View.h"

using namespace std;

class Controller
{
    Batting_Model *batting_model;
    Bowling_Model *bowling_model;
    Players_View *players_view;

public:
    Controller(string batting_file_path, string bowling_file_path)
    {
        this->batting_model = new Batting_Model(batting_file_path);
        this->bowling_model = new Bowling_Model(bowling_file_path);
        this->players_view = new Players_View();
    }

    void sort_and_display_batsmen(int amount, Batsman_Sort_Choice sort_choice)
    {
        Sort_By_Params sort_by_param;
        list<Batsman> sorted_list = sort_by_param.sort_batsmen(batting_model->get_batsman_list(), sort_choice);
        players_view->print_batsmen(sorted_list, amount);
    }

    void sort_and_display_bowlers(int amount, Bowler_Sort_Choice sort_choice)
    {
        Sort_By_Params sort_by_param;
        list<Bowler> sorted_list = sort_by_param.sort_bowlers(bowling_model->get_bowlers_list(), sort_choice);
        players_view->print_bowler(sorted_list, amount);
    }
};

int main(int argc, char const *argv[])
{
    string batting_file_path = "./Resources/MostRuns.csv";
    string bowling_file_path = "./Resources/MostWickets.csv";

    Controller controller(batting_file_path, bowling_file_path);

    controller.sort_and_display_batsmen(1, BATTING_AVERAGE);
    controller.sort_and_display_batsmen(1, STRIKING_RATES);
    controller.sort_and_display_batsmen(1, MAX_6S_AND_4S);
    controller.sort_and_display_batsmen(1, STRIKE_RATES_WITH_6S_AND_4S);
    controller.sort_and_display_batsmen(1, AVERAGES_WITH_STRIKE_RATES);
    controller.sort_and_display_batsmen(1, MAX_RUNS_AND_AVERAGE);

    controller.sort_and_display_bowlers(1, AVERAGE);
    controller.sort_and_display_bowlers(1, BOWLING_STRIKE_RATE);
    controller.sort_and_display_bowlers(1, ECONOMY_RATE);

    return 0;
}
