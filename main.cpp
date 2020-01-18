#include <fstream>
#include <stdexcept>
#include <stdio.h>
#include "lib.h"
#include <iostream>

using namespace std;
int main() {
   char dep_point, dest_point;

    ifstream file("/Users/ekaterina/CLionProjects/flights2020/input.txt");  //создаю файловый поток и связываю его с файлом

    if (!file) {
        throw std::invalid_argument( "File is not open" );
    }

    cout << "Inter departure point: ";
    cin >> dep_point;
    cout << "Inter destination point: ";
    cin >> dest_point;
    //int i, j;

    //cout << FindWay(file, dep_point, dest_point) << " is the shortest way between " << dep_point << " and " << dest_point;
    FindWay(file, dep_point, dest_point);
    return 0;
}
