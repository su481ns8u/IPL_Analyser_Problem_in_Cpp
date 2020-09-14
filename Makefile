all:
	g++ ./Controller/main.cpp ./Model/Batsman.cpp ./Model/Batting_Model.cpp ./Model/Bowler.cpp ./Model/Bowling_Model.cpp ./Model/Sort_List.cpp ./Utils/CSV_Reader.cpp ./View/Player_view.cpp -o Application
	./Application
	rm Application