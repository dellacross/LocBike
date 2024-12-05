#include "tests.hpp"
#include "functions.hpp"
#include <cassert>
#include <utility> 
#include <algorithm>

// UNIT TESTS

int numberOfElements = -1, x_dimension = -1, y_dimension = -1;

// *1* 
void Tests::test_bike_or_visitor(){
    assert(BikeOrVisitor('a') == false);
    assert(BikeOrVisitor('d') == false);    
    assert(BikeOrVisitor('2') == true);
    assert(BikeOrVisitor('3') == true);
}

// *2*
void Tests::test_if_exists() {
    vector<int> _vector;
    _vector.push_back(1);
    _vector.push_back(3);

    assert(ifExists(1, _vector) == true);
    assert(ifExists(2, _vector) == false);
    assert(ifExists(3, _vector) == true);
    assert(ifExists(4, _vector) == false);

    _vector.clear();
    assert(ifExists(4, _vector) == false);
}

// *3*
void Tests::test_get_element_ID() {
    assert(getElementID('0') == 1);
    assert(getElementID('2') == 3);
    assert(getElementID('a') == 1);
    assert(getElementID('b') == 2);
}

// *4* 
void Tests::test_init_map_matrix(Map* map) {
    assert(map->dimX == 4);
    assert(map->dimY == 4);
    assert(map->numElements == 3);
}

// *5* 
void Tests::test_cell_constructor() {
    Cell *cell;
    cell = new Cell(-1, 2, false, false);
    assert(cell->obstacle == false);
    assert(cell->visited == false);
    assert(cell->bikeID == -1);
    assert(cell->visitorID == 2);
}

// *6*
void Tests::test_update_map_matrix_cell(Map* map) {
    Map* _map = map;
    _map->updateMapMatrixCell(2, 3, true, -1, -1);
    _map->updateMapMatrixCell(1, 4, false, 2, -1);
    _map->updateMapMatrixCell(0, 2, false, -1, 3);

    assert(_map->mapMatrix[2][3].obstacle == true);
    assert(_map->mapMatrix[1][4].bikeID == 2);
    assert(_map->mapMatrix[0][2].visitorID == 3);
}

// *7*
void Tests::test_check_cell_out_of_range(Map* map) {
    Map* _map = map;
    bool invalid_out_of_range_1 = _map->checkCell(11, 3);
    bool invalid_out_of_range_2 = _map->checkCell(1, 13);

    assert(invalid_out_of_range_1 == false);
    assert(invalid_out_of_range_2 == false);
}

// *8*
void Tests::test_check_cell_negative(Map* map) {
    bool invalid_negative_1 = map->checkCell(-1, 3);
    bool invalid_negative_2 = map->checkCell(1, -3);

    assert(invalid_negative_1 == false);
    assert(invalid_negative_2 == false);
}

// *9*
void Tests::test_init_visitors_preference_matrix(Map* map) {
    Map* _map = map;
    _map->initVisitorsPreferenceMatrix();
    bool _nullptr = false;
    if(_map->visitorsPreferenceMatrix == nullptr) _nullptr = true;
    assert(_nullptr == false);
}

// *10* 
void Tests::test_init_bikes_preference_matrix(Map* map) {
    Map* _map = map;
    _map->initBikesPreferenceMatrix();
    bool _nullptr = false;
    if(_map->bikesPreferenceMatrix == nullptr) _nullptr = true;
    assert(_nullptr == false);
}

// *11* 
void Tests::test_init_coord_of_bikes_vector(Map* map) {
    Map* _map = map;
    _map->initCoordOfBikesVector();
    bool _nullptr = false;
    if(_map->coordsOfBikes == nullptr) _nullptr = true;
    assert(_nullptr == false);
}

// *12* 
void Tests::test_init_coord_of_visitors_vector(Map* map) {
    Map* _map = map;
    _map->initCoordOfVisitorsVector();
    bool _nullptr = false;
    if(_map->coordsOfVisitors == nullptr) _nullptr = true;
    assert(_nullptr == false);
}

// *13* 
void Tests::test_all_no_visited(Map* map) {
    Map* _map = map;
    _map->mapMatrix[0][0].visited = true;
    _map->mapMatrix[1][2].visited = true;
    _map->mapMatrix[1][0].visited = true;
    _map->allNoVisited();
    int x_dimension = map->dimX, y_dimension = map->dimY;
    bool ifExistVisitedCell_map = false;

    for(int i = 0; i < x_dimension; i++) {
        for(int j = 0; j < y_dimension; j++) {
            if(_map->mapMatrix[i][j].visited == true)
                ifExistVisitedCell_map = true;
        }
    }

    assert(ifExistVisitedCell_map == false);
}

// *14* 
void Tests::test_update_visitors_preference_matrix(Map* map) {
    Map* _map = map;
    _map->initVisitorsPreferenceMatrix();
    _map->updateVisitorsPreferenceMatrix(0,0,0,2);
    _map->updateVisitorsPreferenceMatrix(0,1,0,0);
    _map->updateVisitorsPreferenceMatrix(0,2,0,1);
    _map->updateVisitorsPreferenceMatrix(1,0,1,1);
    _map->updateVisitorsPreferenceMatrix(1,1,1,0);
    _map->updateVisitorsPreferenceMatrix(1,2,1,2);
    _map->updateVisitorsPreferenceMatrix(2,0,3,0);
    _map->updateVisitorsPreferenceMatrix(2,1,3,2);
    _map->updateVisitorsPreferenceMatrix(2,2,3,1);

    pair<int,int>** _visitorsPreferenceMatrix = _map->visitorsPreferenceMatrix;

    assert(_visitorsPreferenceMatrix[0][0].second == 2);
    assert(_visitorsPreferenceMatrix[0][1].second == 0);
    assert(_visitorsPreferenceMatrix[0][2].second == 1);
    assert(_visitorsPreferenceMatrix[1][0].second == 1);
    assert(_visitorsPreferenceMatrix[1][1].second == 0);
    assert(_visitorsPreferenceMatrix[1][2].second == 2);
    assert(_visitorsPreferenceMatrix[2][0].second == 0);
    assert(_visitorsPreferenceMatrix[2][1].second == 2);
    assert(_visitorsPreferenceMatrix[2][2].second == 1);
}

// *15* 
void Tests::test_add_coord_of_bike(Map* map) {
    Map* _map = map;
    _map->addCoordOfBike(0,2,2);
    _map->addCoordOfBike(1,0,3);
    _map->addCoordOfBike(2,3,1);

    pair<int, int> *coordsOfBikes = map->coordsOfBikes;

    assert(coordsOfBikes[0].first == 2);
    assert(coordsOfBikes[0].second == 2);
    assert(coordsOfBikes[1].first == 0);
    assert(coordsOfBikes[1].second == 3);
    assert(coordsOfBikes[2].first == 3);
    assert(coordsOfBikes[2].second == 1);
}

// *16*
void Tests::test_cell_with_obstacle() {
    Cell *cell;
    cell = new Cell(-1, -1, true, false);
    assert(cell->obstacle == true);
    assert(cell->visited == false);
}

// *17*
void Tests::test_map_custom_dimensions() {
    Map* map = new Map(5, 6);
    assert(map->dimX == 5);
    assert(map->dimY == 6);
}

// *18*
void Tests::test_bike_preferences_initialization() {
    Map* map = new Map(4, 4);
    map->initBikesPreferenceMatrix();
    assert(map->bikesPreferenceMatrix != nullptr);  
}

// *19*
void Tests::test_visitor_preferences_initialization() {
    Map* map = new Map(4, 4);
    map->initVisitorsPreferenceMatrix();
    assert(map->visitorsPreferenceMatrix != nullptr);  
}

// *20*
void Tests::test_empty_cell() {
    Cell *cell;
    cell = new Cell(-1, -1, false, false);
    assert(cell->obstacle == false);
    assert(cell->visited == false);
    assert(cell->bikeID == -1);
    assert(cell->visitorID == -1);
}

// *21*
void Tests::test_cell_update_with_obstacle() {
    Map* map = new Map(4, 4);
    map->mapMatrix[2][3].obstacle = true;
    assert(map->mapMatrix[2][3].obstacle == true);
}

// *22*
void Tests::test_bike_removal() {
    Map* map = new Map(4, 4);
    map->mapMatrix[2][3].bikeID = 3;  
    map->mapMatrix[2][3].bikeID = -1;  
    assert(map->mapMatrix[2][3].bikeID == -1);  
}

// *23*
void Tests::test_cell_update_with_bike() {
    Map* map = new Map(4, 4);
    map->mapMatrix[2][3].bikeID = 5;
    assert(map->mapMatrix[2][3].bikeID == 5);
}

// *24*
void Tests::test_bike_move() {
    Map* map = new Map(4, 4);
    map->mapMatrix[2][3].bikeID = 5;
    map->mapMatrix[2][3].bikeID = -1;  
    map->mapMatrix[1][2].bikeID = 5;  
    assert(map->mapMatrix[1][2].bikeID == 5);
}

// *25*
void Tests::test_cell_update_with_visitor() {
    Map* map = new Map(4, 4);
    map->mapMatrix[2][3].visitorID = 7;
    assert(map->mapMatrix[2][3].visitorID == 7);
}

// *26*
void Tests::test_visitor_move() {
    Map* map = new Map(4, 4);
    map->mapMatrix[2][3].visitorID = 7;
    map->mapMatrix[2][3].visitorID = -1;  
    map->mapMatrix[1][2].visitorID = 7;  
    assert(map->mapMatrix[1][2].visitorID == 7);
}

// *27*
void Tests::test_bike_coordinates_initialization() {
    Map* map = new Map(4, 4);
    map->initCoordOfBikesVector();
    assert(map->coordsOfBikes != nullptr);
}

// *28*
void Tests::test_check_valid_cell() {
    Map* map = new Map(4, 4);
    bool validCell = map->checkCell(1, 2);
    assert(validCell == true);  
}

// *29*
void Tests::test_check_invalid_cell() {
    Map* map = new Map(4, 4);
    bool invalidCell = map->checkCell(5, 5);
    assert(invalidCell == false);  
}

// *30*
void Tests::test_cell_reset() {
    Map* map = new Map(4, 4);
    map->mapMatrix[2][3].bikeID = 5;
    map->mapMatrix[2][3].visitorID = 8;
    map->mapMatrix[2][3].bikeID = -1;  
    map->mapMatrix[2][3].visitorID = -1; 
    assert(map->mapMatrix[2][3].bikeID == -1);
    assert(map->mapMatrix[2][3].visitorID == -1);
}

bool ascending(const pair<int, int> &x1, const pair<int, int> &x2) {
    return x1.first < x2.first || (x1.first == x2.first && x1.second < x2.second);
}

bool descending(const pair<int, int> &x1, const pair<int, int> &x2) {
    return x1.first > x2.first || (x1.first == x2.first && x1.second > x2.second);
}

// Teste da função Sort
void Tests::test_sort()
{
    const int numRows = 2;
    const int numCols = 5;

    pair<int, int> *array[numRows];
    pair<int, int> data[numRows][numCols] = {
        {{3, 2}, {1, 5}, {2, 4}, {5, 1}, {4, 3}},
        {{7, 6}, {9, 8}, {8, 7}, {10, 10}, {6, 9}}};

    for (int i = 0; i < numRows; i++){
        array[i] = data[i];
    }

    Map map;
    map.numElements = numCols;

    map.Sort(array, ascending);

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 1; j < numCols; j++)
        {
            assert(array[i][j - 1].first <= array[i][j].first);
            if (array[i][j - 1].first == array[i][j].first)
            {
                assert(array[i][j - 1].second <= array[i][j].second);
            }
        }
    }
    cout << "Teste de ordenação ascendente passou!" << endl;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            data[i][0] = {3, 2};
            data[i][1] = {1, 5};
            data[i][2] = {2, 4};
            data[i][3] = {5, 1};
            data[i][4] = {4, 3};
        }
    }

    map.Sort(array, descending);

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 1; j < numCols; j++)
        {
            assert(array[i][j - 1].first >= array[i][j].first);
            if (array[i][j - 1].first == array[i][j].first)
            {
                assert(array[i][j - 1].second >= array[i][j].second);
            }
        }
    }
    cout << "Teste de ordenação descendente passou!" << endl;
}

void Tests::test_preference() {
    // Dados de teste
    Map *map; 
    map = new Map(3, 3, 3);

    map->bikesPreferenceMatrix = new pair<int, int>*[1];
    map->bikesPreferenceMatrix[0] = new pair<int, int>[3]{
        {1, 0},  
        {2, 0},  
        {3, 0}   
    };

    int idB = 0;
    int propose = 1;
    int current = 2; 
    assert(map->preference(idB, propose, current) == true);

    propose = 3;
    current = 1;
    assert(map->preference(idB, propose, current) == false);

    propose = 4;
    current = 5;
    assert(map->preference(idB, propose, current) == false);

    for (int i = 0; i < 1; ++i) {
        delete[] map->bikesPreferenceMatrix[i];
    }
    delete[] map->bikesPreferenceMatrix;
}

void Tests::test_BFS(){
    Map *map;
    map = new Map(3, 3, 1);

    map->updateMapMatrixCell(1, 1, true, -1, -1);

    assert(map->BFS(0, 0, 2, 2) == 4);

    map->updateMapMatrixCell(0, 1, true, -1, -1);
    assert(map->BFS(0, 0, 2, 2) == 4); 
}

void Tests::test_get_dimensions() {
    stringstream simulatedFile;
    simulatedFile << "5\n";  
    simulatedFile << "10 15\n";  

    fstream file;
    file.open("/tmp/simulatedFile.txt", fstream::in | fstream::out | fstream::trunc);
    file << simulatedFile.rdbuf();
    file.seekg(0);

    vector<int> result = getDimensions(file);

    assert(result.size() == 3);
    assert(result[0] == 5);
    assert(result[1] == 10);
    assert(result[2] == 15);

    file.close();
}

bool mockBikeOrVisitor(char c) {
    return isdigit(c); // Exemplo simples para simular comportamento
}

int mockGetElementID(char c) {
    return c - '0'; // Retorna um ID baseado no caractere
}

void Tests::test_set_map_matrix_cells() {
    string testFileContent =
        "***-\n"
        "*12a\n"
        "*b--\n";
    ofstream testFile("test_map.txt");
    testFile << testFileContent;
    testFile.close();

    fstream inputFile("test_map.txt");
    assert(inputFile.is_open() == true);

    int xAxis = 3;
    int yAxis = 4;
    int numberOfElements = 2;
    Map *map;
    map = new Map(xAxis,yAxis,numberOfElements);

    setMapMatrixCells(inputFile, *map, xAxis, yAxis, numberOfElements);

    assert(map->mapMatrix[0][0].obstacle == false); 
    assert(map->mapMatrix[0][3].obstacle == true); 
    assert(map->mapMatrix[1][1].bikeID == 1); 
    assert(map->mapMatrix[1][2].visitorID == 2);

    inputFile.close();
    remove("test_map.txt");
}

int main(int argc, char** argv) {

    Tests tests;
    Map* map = new Map(4, 4, 3);
    map->initMapMatrix();

    cout << "Starting unit tests..." << "\n";

    // *1*
    tests.test_bike_or_visitor();

    // *2*
    tests.test_if_exists();

    // *3*
    tests.test_get_element_ID();

    // *4* 
    tests.test_init_map_matrix(map);

    // *5* 
    tests.test_cell_constructor();

    // *6*
    tests.test_update_map_matrix_cell(map);

    // *7*
    tests.test_check_cell_out_of_range(map);

    // *8*
    tests.test_check_cell_negative(map);

    // *9*
    tests.test_init_visitors_preference_matrix(map);

    // *10* 
    tests.test_init_bikes_preference_matrix(map);

    // *11* 
    tests.test_init_coord_of_bikes_vector(map);

    // *12* 
    tests.test_init_coord_of_visitors_vector(map);

    // *13* 
    tests.test_all_no_visited(map);

    // *14* 
    tests.test_update_visitors_preference_matrix(map);

    // *15* 
    tests.test_add_coord_of_bike(map);

    // *16*
    tests.test_cell_with_obstacle();

    // *17*
    tests.test_map_custom_dimensions();

    // *18*
    tests.test_bike_preferences_initialization();

    // *19*
    tests.test_visitor_preferences_initialization();

    // *20*
    tests.test_empty_cell();

    // *21*
    tests.test_cell_update_with_obstacle();

    // *22*
    tests.test_bike_removal();

    // *23*
    tests.test_cell_update_with_bike();

    // *24*
    tests.test_bike_move();

    // *25*
    tests.test_cell_update_with_visitor();

    // *26*
    tests.test_visitor_move();

    // *27*
    tests.test_bike_coordinates_initialization();

    // *28*
    tests.test_check_valid_cell();

    // *29*
    tests.test_check_invalid_cell();

    // *30*
    tests.test_cell_reset();

    cout << "Success! All unit tests passed!" << "\n";

    cout << "All tests passed for '" << argv[1] << "' file!\n";
    
    return 0;
}