#include <sstream>
#include <fstream>
#include <string>
#include "map.hpp"
#include "functions.hpp"

int main(int argc, char *argv[])
{
    fstream file(argv[1]);

    if (file)
    {
        string line = "";
        vector<int> values = getDimensions(file);

        int n = values[0], x = values[1], y = values[2];

        Map map(x, y, n);

        setMapMatrixCells(file, map, x, y, n);

        pair<int, int> vm[n][n];
        vector<int> auxV;
        for (int i = 0; i < n; i++)
        {
            int aux = 0;
            getline(file, line);
            stringstream auxLine(line);

            for (int j = 0; j < n; j++)
            {
                auxLine >> aux;
                vm[i][j].first = j;
                vm[i][j].second = aux;
            }
        }

        int g = -1, gpos = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (vm[i][k].second >= g && !ifExists(k, auxV))
                    {
                        g = vm[i][k].second;
                        gpos = k;
                    }
                }
                auxV.push_back(gpos);
                map.updateVisitorsPreferenceMatrix(i, j, gpos, g);
                g = -1;
                gpos = -1;
            }
            auxV.clear();
        }
        map.GaleShapley(argv[1], false);

        file.close();
    }
    else
        cout << "ERROR: FILE NOT FOUND!"
             << "\n";

    return 0;
}