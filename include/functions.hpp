#include <sstream>
#include <fstream>
#include <string>
#include "map.hpp"
#include <queue>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

bool BikeOrVisitor(char s) { // true if is bike; false if is visitor;
    return (s >= '0' && s <= '9');
}

int getElementID(char character) { // return the element's id
    if (character < 58) return character - 47;
    return character - 96;
}

bool ifExists(int x, vector<int> q) { // check if exists the element on the vector
    int size = q.size();
    if (q.empty())
        return false;
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (x == q[i])
                return true;
        }
        return false;
    }
}

vector<int> getDimensions(fstream &file) {
    string line = "";
    int xAxis, yAxis, numberOfElements;
    for (int i = 0; i < 2; i++) {
        getline(file, line);
        stringstream lineStream(line);

        if (i == 0)
            lineStream >> numberOfElements;
        else
            lineStream >> xAxis >> yAxis;
    }

    return {numberOfElements, xAxis, yAxis};
}

void setMapMatrixCells(fstream &file, Map &map, int xAxis, int yAxis, int numberOfElements) {
    string line = "";
    for (int lines = 0; lines < xAxis; lines++)
    {
        getline(file, line);

        for (int k = 0; k < yAxis; k++)
        {
            if (line[k] == '-')
                map.updateMapMatrixCell(lines, k, true, -1, -1);
            else if (line[k] == '*')
                map.updateMapMatrixCell(lines, k, false, -1, -1);
            else if (BikeOrVisitor(line[k]))
            {
                map.updateMapMatrixCell(lines, k, false, getElementID(line[k]), -1);
                map.addCoordOfBike(getElementID(line[k]) - 1, lines, k);
            }
            else if (!BikeOrVisitor(line[k]))
            {
                map.updateMapMatrixCell(lines, k, false, -1, getElementID(line[k]));
                map.addCoordOfVisitor(getElementID(line[k]) - 1, lines, k);
            }
        }
    }
}

#endif // FUNCTIONS_H
