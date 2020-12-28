#pragma once

#include "GraphInterface.h"
using namespace std;

void tests() {
    int matrix_1[4][4] = {
            {0, 1, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 0},
            {1, 0, 0, 0}
    };

    int matrix_2[6][6] = {
            {0, 1, 0, 0, 1, 0},
            {1, 0, 1, 0, 1, 0},
            {0, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 1, 1},
            {1, 1, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 0}
    };

    int **matrix1 = new int*[4];
    for(int i=0; i<4; i++) {
        matrix1[i] = new int[4];
        for (int j=0; j<4; j++) {
            matrix1[i][j] = matrix_1[i][j];
        }
    }
    auto graph_1 = graph(4, matrix1);

    int **matrix2 = new int*[6];
    for(int i=0; i<6; i++) {
        matrix2[i] = new int[6];
        for (int j=0; j<6; j++) {
            matrix2[i][j] = matrix_2[i][j];
        }
    }
    auto graph_2 = graph(6, matrix2);

    int counter = 1;
    int chrom_num1 = graph_1.chromatic_number();
    if (chrom_num1 == 3)
        cout << "Test " << counter << " passed!" << endl;
    else
        cout << "Test " << counter << " failed :(" << endl;
    counter++;

    int way1 = graph_1.shortest_way(3, 1);
    if (way1 == 2)
        cout << "Test " << counter << " passed!" << endl;
    else
        cout << "Test " << counter << " failed :(" << endl;
    counter++;

    int way2 = graph_1.shortest_way(1, 3);
    if (way2 == 2)
        cout << "Test " << counter << " passed!" << endl;
    else
        cout << "Test " << counter << " failed :(" << endl;
    counter++;

    int way3 = graph_1.shortest_way(0,1);
    if (way3 == 1)
        cout << "Test " << counter << " passed!" << endl;
    else
        cout << "Test " << counter << " failed :(" << endl;
    counter++;

    int chrom_num2 = graph_2.chromatic_number();
    if (chrom_num2 == 3)
        cout << "Test " << counter << " passed!" << endl;
    else
        cout << "Test " << counter << " failed :(" << endl;
    counter++;

    int way4 = graph_2.chromatic_number();
    if (way4 == 3)
        cout << "Test " << counter << " passed!" << endl;
    else
        cout << "Test " << counter << " failed :(" << endl;
    counter++;

    int way5 = graph_2.shortest_way(0, 0);
    if (way5 == -1)
        cout << "Test " << counter << " passed!" << endl;
    else
        cout << "Test " << counter << " failed :(" << endl;
    counter++;

    int way6 = graph_2.shortest_way(0, 2);
    if (way6 == 2)
        cout << "Test " << counter << " passed!" << endl;
    else
        cout << "Test " << counter << " failed :(" << endl;

    for (int i = 0; i < 4; i++) {
        delete [] matrix1[4];
    }
    delete [] matrix1;

    for (int i = 0; i < 6; i++) {
        delete [] matrix2[6];
    }
    delete [] matrix2;
}
