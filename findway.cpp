//
// Created by Екатерина on 18/01/2020.
//
#include <iostream>
#include "lib.h"
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int FindWay (std::ifstream &file, char &dep_point, char &dest_point) {
    int edges = 0;                                    //количество ребер в графе
    int vertices = 7;                                 //количество вершин в графе
    //char dep_point, dest_point;

    std::map <char,int> verticesToIndex = {
            {'A', 1},
            {'B', 2},
            {'C', 3},
            {'D', 4},
            {'E', 5},
            {'F', 6},
            {'G', 7}
    };

    vector < vector < int >> graf(vertices, vector <int> (vertices));          // матрица
    int INF = INT_MAX;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if ((graf[i][j] == 0) && (i != j)) {
                graf[i][j] = INF;
            }
        }
        graf[i][i] = 0;
    }

    char DeparturePoint;
    char DestinationPoint;
    int value, from, to;

    string line;
    while (!file.eof()) {
        edges++;
        file >> DeparturePoint >> DestinationPoint >> value;
        //cout << DeparturePoint << DestinationPoint << value << endl;
        from = verticesToIndex.at(DeparturePoint);
        to = verticesToIndex.at(DestinationPoint);
        graf[from][to] = value;
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            for (int k = 0; k < vertices; k++) {
                if ((graf[j][i] < INF) && (graf[i][k] < INF)) {
                    graf[j][k] = min(graf[j][k], graf[j][i] + graf[i][k]);
                }
            }
        }
    }
    int i,j;
    i = verticesToIndex.at(dep_point);
    j = verticesToIndex.at(dest_point);


    (graf[i][j] != INF ? cout << graf[i][j] << " is the shortest way between ": cout
            << " there's no way between ") << dep_point << " and " << dest_point;
    cout << endl;
    return graf[i][j];


}



