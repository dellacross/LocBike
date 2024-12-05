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
}

// *3*
void Tests::test_if_exists_empty_vector() {
    vector<int> empty_vector;
    assert(ifExists(1, empty_vector) == false);
}

// *4*
void Tests::test_get_bike_element_ID() {
    assert(getElementID('0') == 1);
    assert(getElementID('2') == 3);
}

void Tests::test_get_visitor_element_ID() {
    assert(getElementID('a') == 1);
    assert(getElementID('b') == 2);
}

// *5* 
void Tests::test_init_map_matrix(Map* map) {
    assert(map->dimX == 4);
    assert(map->dimY == 4);
    assert(map->numElements == 3);
}

// *6* 
void Tests::test_cell_constructor() {
    Cell *cell;
    cell = new Cell(-1, 2, false, false);
    assert(cell->obstacle == false);
    assert(cell->visited == false);
    assert(cell->bikeID == -1);
    assert(cell->visitorID == 2);
}

// *7*
void Tests::test_update_map_matrix_cell(Map* map) {
    Map* _map = map;
    _map->updateMapMatrixCell(2, 3, true, -1, -1);
    _map->updateMapMatrixCell(1, 4, false, 2, -1);
    _map->updateMapMatrixCell(0, 2, false, -1, 3);

    assert(_map->mapMatrix[2][3].obstacle == true);
    assert(_map->mapMatrix[1][4].bikeID == 2);
    assert(_map->mapMatrix[0][2].visitorID == 3);
}

// *8*
void Tests::test_check_cell_out_of_range(Map* map) {
    Map* _map = map;
    bool invalid_out_of_range_1 = _map->checkCell(11, 3);
    bool invalid_out_of_range_2 = _map->checkCell(1, 13);

    assert(invalid_out_of_range_1 == false);
    assert(invalid_out_of_range_2 == false);
}

// *9*
void Tests::test_check_cell_negative(Map* map) {
    bool invalid_negative_1 = map->checkCell(-1, 3);
    bool invalid_negative_2 = map->checkCell(1, -3);

    assert(invalid_negative_1 == false);
    assert(invalid_negative_2 == false);
}

// *10*
void Tests::test_init_visitors_preference_matrix(Map* map) {
    Map* _map = map;
    _map->initVisitorsPreferenceMatrix();
    bool _nullptr = false;
    if(_map->visitorsPreferenceMatrix == nullptr) _nullptr = true;
    assert(_nullptr == false);
}

// *11* 
void Tests::test_init_bikes_preference_matrix(Map* map) {
    Map* _map = map;
    _map->initBikesPreferenceMatrix();
    bool _nullptr = false;
    if(_map->bikesPreferenceMatrix == nullptr) _nullptr = true;
    assert(_nullptr == false);
}

// *12* 
void Tests::test_init_coord_of_bikes_vector(Map* map) {
    Map* _map = map;
    _map->initCoordOfBikesVector();
    bool _nullptr = false;
    if(_map->coordsOfBikes == nullptr) _nullptr = true;
    assert(_nullptr == false);
}

// *13* 
void Tests::test_init_coord_of_visitors_vector(Map* map) {
    Map* _map = map;
    _map->initCoordOfVisitorsVector();
    bool _nullptr = false;
    if(_map->coordsOfVisitors == nullptr) _nullptr = true;
    assert(_nullptr == false);
}

// *14* 
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

// *15* 
void Tests::test_update_visitors_preference_matrix(Map* map) {
    Map* _map = map;
    _map->initVisitorsPreferenceMatrix();
    _map->updateVisitorsPreferenceMatrix(0,0,1,1);

    pair<int,int>** _visitorsPreferenceMatrix = _map->visitorsPreferenceMatrix;

    assert(_visitorsPreferenceMatrix[0][0].first == 1);
    assert(_visitorsPreferenceMatrix[0][0].second == 1);
}

// *16*
void Tests::test_add_coord_of_bike(Map* map) {
    Map* _map = map;

    map->initCoordOfBikesVector();
    map->addCoordOfBike(0, 1, 2);

    assert(_map->coordsOfBikes[0].first == 1);
    assert(_map->coordsOfBikes[0].second == 2);
}

// *17*
void Tests::test_add_coord_of_visitor(Map* map) {
    Map* _map = map;

    map->initCoordOfVisitorsVector();
    map->addCoordOfVisitor(0, 1, 2);

    pair<int, int> *v = map->getCoordsOfVisitors();

    assert(v[0].first == 1);
    assert(v[0].second == 2);
}

void Tests::test_check_visited_cell(Map* map) {
    Map* _map = map;

    _map->mapMatrix[0][0].visited = true;

    assert(_map->checkCell(0, 0) == false);
}

void Tests::test_check_obstacle_cell(Map* map) {
    Map* _map = map;

    _map->mapMatrix[0][0].obstacle = true;

    assert(_map->checkCell(0, 0) == false);
}

void Tests::test_if_exists_element() {
    vector<int> _vector = {2, 3};

    assert(ifExists(2, _vector) == true);
    assert(ifExists(3, _vector) == true);
}

void Tests::test_if_dont_exists_element() {
    vector<int> _vector = {2, 3};

    assert(ifExists(3, _vector) == true);
    assert(ifExists(4, _vector) == false);
}

void Tests::test_constructor() {
    Map* _map = new Map(4, 4, 3);

    assert(_map->getDimX() == 4);
    assert(_map->getDimY() == 4);
    assert(_map->getNumberOfElements() == 3);
}

void Tests::test_BFS() {
    Map* map = new Map(3, 3, 1);

    map->updateMapMatrixCell(0, 0, false, 1, -1);
    map->updateMapMatrixCell(0, 1, true, -1, -1);
    map->updateMapMatrixCell(0, 2, false, -1, 1);

    int distance = map->BFS(0, 0, 0, 2);

    assert(distance == 4);
}

void Tests::test_BFS_without_pair() {
    Map* map = new Map(3, 3, 1);

    map->updateMapMatrixCell(0, 0, false, 1, -1);
    map->updateMapMatrixCell(0, 1, true, -1, -1);
    map->updateMapMatrixCell(1, 2, true, -1, -1);
    map->updateMapMatrixCell(0, 2, false, -1, 1);

    int distance = map->BFS(0, 0, 0, 2);

    assert(distance == -1);
}

void Tests::test_get_dimensions() {
    string mockFileContent = "10\n3 4\n";

    stringstream mockFile(mockFileContent);

    vector<int> result = getDimensions(mockFile);

    vector<int> expected = {10, 3, 4};

    assert(result == expected);
}

void Tests::test_set_map_matrix_cells() {
    string mockFileContent = "a**1\n--**\n*-**\nb*0*\n";
    stringstream mockFile(mockFileContent);

    Map map(4, 4, 2);
    setMapMatrixCells(mockFile, map, 4, 4, 2);

    assert(map.mapMatrix[1][0].obstacle == true);
    assert(map.mapMatrix[0][0].obstacle == false);
    assert(map.mapMatrix[0][3].bikeID == 2);
    assert(map.mapMatrix[0][0].visitorID == 1);
}

void Tests::test_preference() {
    Map map(4, 5, 5);

    map.addCoordOfBike(0, 0, 2);
    map.addCoordOfBike(1, 1, 2);
    map.addCoordOfBike(2, 1, 4);
    map.addCoordOfBike(3, 0, 3);
    map.addCoordOfBike(4, 3, 3);

    map.addCoordOfVisitor(0, 0, 4);
    map.addCoordOfVisitor(1, 2, 3);
    map.addCoordOfVisitor(2, 0, 0);
    map.addCoordOfVisitor(3, 0, 2);
    map.addCoordOfVisitor(4, 3, 4);

    map.updateBikesPreferenceMatrix();

    assert(map.preference(0, 4, 1) == false);
    assert(map.preference(2, 1, 3) == true);    
}

void Tests::test_stable_matching_output() {
    int v[] = {1, 0};
    int n = 2;
    std::string fileName = "test_file.txt";
    bool testRun = false;

    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

    stableMatchingOutput(v, n, fileName, testRun);

    std::cout.rdbuf(old);

    std::string expectedOutput = "a 1\nb 0\n";
    assert(buffer.str() == expectedOutput);
}

void Tests::test_check_free_cell(Map *map) {
    Map* _map = map;
    map->initMapMatrix();

    _map->mapMatrix[0][0].obstacle = false;
    _map->mapMatrix[0][0].visited = false;

    assert(_map->checkCell(0, 0) == false);
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
    tests.test_if_exists_empty_vector();

    // *4*
    tests.test_get_bike_element_ID();

    // *4*
    tests.test_get_visitor_element_ID();

    // *6* 
    tests.test_init_map_matrix(map);

    // *7* 
    tests.test_cell_constructor();

    // *8*
    tests.test_update_map_matrix_cell(map);

    // *9*
    tests.test_check_cell_out_of_range(map);

    // *10*
    tests.test_check_cell_negative(map);

    // *11*
    tests.test_init_visitors_preference_matrix(map);

    // *12* 
    tests.test_init_bikes_preference_matrix(map);

    // *13* 
    tests.test_init_coord_of_bikes_vector(map);

    // *14* 
    tests.test_init_coord_of_visitors_vector(map);

    // *15* 
    tests.test_all_no_visited(map);

    // *16* 
    tests.test_update_visitors_preference_matrix(map);

    // *17*
    tests.test_add_coord_of_bike(map);

    // *18*
    tests.test_add_coord_of_visitor(map);

    // *19*
    tests.test_check_visited_cell(map);

    // *20*
    tests.test_check_obstacle_cell(map);

    // *21*
    tests.test_if_exists_element();

    // *22*
    tests.test_if_dont_exists_element();
    
    // *23*
    tests.test_constructor();

    // *24*
    tests.test_BFS();

    // *25*
    tests.test_get_dimensions();

    // *26*
    tests.test_BFS_without_pair();

    // *27*
    tests.test_set_map_matrix_cells();

    // *28*
    tests.test_preference();

    tests.test_stable_matching_output();

    cout << "Success! All unit tests passed!" << "\n";

    cout << "All tests passed for '" << argv[1] << "' file!\n";
    
    return 0;
}