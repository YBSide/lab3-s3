#pragma once
#include "Graph.h"
#include <random>

using namespace std;
random_device rd;
mt19937 gen(rd());
discrete_distribution<> d({50, 50});
graph make_graph() {
    int size;
    cout << "Enter size of graph: ";
    cin >> size;
    while (size <= 0) {
        cout << "Enter correct size" << endl;
        cin >> size;
    }
    int** matrix = new int*[size];
    for (int i=0; i<size; i++) {
        matrix[i] = new int[size];
    }

    int arc;

    string answer;
    cout << "Random graph(0) or your(1)?" << endl;
    cin >> answer;
    while (answer != "0" && answer != "1") {
        cout << "Enter 0 or 1" << endl;
        cin >> answer;
    }
    if (answer == "1") {
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                if (i != j) {
                    cout << "We had arc between " << i << " and " << j << " vertices?(1 or 0):" << endl;
                    cin >> arc;
                    while (arc != 1 && arc != 0) {
                        cout << "Enter 1 or 0" << endl;
                        cin >> arc;
                    }
                }
                else {
                    arc = 0;
                }
                matrix[i][j] = arc;
            }
        }
    }
    else {
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                if (i != j) {
                    arc = d(gen);
                }
                else {
                    arc = 0;
                }
                matrix[i][j] = arc;
            }
        }
    }
    auto graph_ = graph(size, matrix);
    cout << "Adjacency table of your graph:" << endl;
    graph_.show_graph();
    return graph_;
}

int shortest_way(graph graph_) {
    int first, second;
    cout << "Enter vertices to find shortest way\n" << "First:";
    cin >> first;
    cout << "Second:";
    cin >> second;
    while (first < 0) {
        cout << "First:" << endl;
        cin >> first;
    }
    while (second < 0) {
        cout << "Second:" << endl;
        cin >> second;
    }
    int way;
    way = graph_.shortest_way(first, second);
    return way;
}

int chromatic_number(graph graph_) {
    cout << "Chromatic number = " << graph_.chromatic_number() << endl;
    return graph_.chromatic_number();
}

void shortest_way_path(graph graph_) {
    int first, last;
    cout << "Enter first vertex:" << endl;
    cin >> first;
    cout << "Enter last vertex:" << endl;
    cin >> last;
    auto way = graph_.shortest_way_path(first, last);
    for (int i=0; i<graph_.shortest_way(first, last) + 1; i++) {
        cout << way[i] << " - ";
    }
    cout << "path" << endl;
    delete [] way;
}

string interface_function_1() {
    string a;
    while (a != "YES" || a != "NO" || a != "n" || a != "y" || a != "N" || a != "Y") {
        cin >> a;

        if (a == "YES" || a == "Y" || a == "y")
            return "1";

        if (a == "NO" || a == "N" || a == "n")
            return "0";

        cout << "Incorrect answer! Please, use YES(y) or NO(n)" << endl;

    }
    return "00";
}
