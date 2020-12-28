#include <iostream>
#include "Graph.h"
#include "GraphInterface.h"
#include "Tests.h"
using namespace std;
int main() {
    cout << "Do you want to run tests? Yes(Y) or No(N)." << endl;
    string answer = interface_function_1();
    if (answer == "1")
        tests();
    answer = "1";
    auto graph_ = make_graph();
    while (answer != "4") {
        cout << "What do you want to do? (1) Find the length of shortest way. (2) Find chromatic number. (3) Find the shortest path.\n(4) Exit:" << endl;
        cin >> answer;
        while (answer != "1" && answer != "2" && answer  != "3" && answer  != "4") {
            cout << "Please enter 1, 2, 3 or 4" << endl;
            cin >> answer;
        }

        if (answer == "1") {
            int way = shortest_way(graph_);
            cout << "The length of shortest way = " << way << endl;
        }
        if (answer == "2") {
            int chrom_num = chromatic_number(graph_);
        }
        if (answer == "3") {
            shortest_way_path(graph_);
        }
    }
    return 0;
}
