#include "tests.hpp"
#include "functions.hpp"
#include <cassert>
#include <utility> 
#include <algorithm>
#include <array>

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

    assert(_map->visitorsPreferenceMatrix[0][0].first == 1);
    assert(_map->visitorsPreferenceMatrix[0][0].second == 1);
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

    _map->initCoordOfVisitorsVector();
    _map->addCoordOfVisitor(0, 1, 2);

    pair<int, int> *v = _map->getCoordsOfVisitors();

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
    string fileName = "test_file1.in";
    bool testRun = false;

    stringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());

    stableMatchingOutput(v, n, fileName, testRun);

    cout.rdbuf(old);

    string expectedOutput = "a 1\nb 0\n";
    assert(buffer.str() == expectedOutput);
}

void Tests::test_change_map_matrix_cell(Map* map) {
    Map* _map = map;

    _map->updateMapMatrixCell(2, 3, true, -1, -1);
    _map->updateMapMatrixCell(1, 4, false, 2, -1);
    _map->updateMapMatrixCell(0, 2, false, -1, 3);

    assert(_map->mapMatrix[2][3].obstacle == true);
    assert(_map->mapMatrix[1][4].bikeID == 2);
    assert(_map->mapMatrix[0][2].visitorID == 3);

    _map->updateMapMatrixCell(2, 3, false, 2, -1);
    _map->updateMapMatrixCell(1, 4, true, -1, -1);

    assert(_map->mapMatrix[1][4].obstacle == true);
    assert(_map->mapMatrix[2][3].bikeID == 2);
}

void Tests::test_set_map_matrix_cells_comprehensive() {
    string testInput = "4\n4 4\n*-1a\n2-*b\nc3*-\n4d**\n";
    stringstream inputStream(testInput);
    
    string line;
    getline(inputStream, line);  
    getline(inputStream, line); 
    
    Map testMap(4, 4, 4);
    setMapMatrixCells(inputStream, testMap, 4, 4, 4);
    
    assert(testMap.getMapMatrix()[0][0].obstacle == false);
    assert(testMap.getMapMatrix()[0][0].bikeID == -1);
    assert(testMap.getMapMatrix()[0][0].visitorID == -1);
    
    assert(testMap.getMapMatrix()[0][1].obstacle == true);
    
    assert(testMap.getMapMatrix()[0][2].bikeID == 2); 
    assert(testMap.getMapMatrix()[0][2].obstacle == false);
    
    assert(testMap.getMapMatrix()[0][3].visitorID == 1); 
    assert(testMap.getMapMatrix()[0][3].obstacle == false);
}

void Tests::empty_vector() {
    vector<int> q = {};
    assert(ifExists(5, q) == false);
}

void Tests::element_exists() {
    vector<int> q = {1, 2, 3, 4, 5};
    assert(ifExists(3, q) == true);
}

void Tests::element_does_not_exist() {
    vector<int> q = {1, 2, 3, 4, 5};
    assert(ifExists(6, q) == false); 
}

void Tests::single_element_exists() {
    vector<int> q = {10};
    assert(ifExists(10, q) == true);
}

void Tests::single_element_does_not_exist(){
    vector<int> q = {20};
    assert(ifExists(10, q) == false); 
}

//--------------------------------------------------------------------------------------------------------------------//

// SYSTEM/INTEGRATION TESTS

//*1*
void Tests::test_basic_matching_no_obstacles() {
    Map map(3, 3, 2);
    map.initMapMatrix();
    
    map.updateMapMatrixCell(0, 0, false, 0, -1);  
    map.updateMapMatrixCell(2, 2, false, 1, -1);  
    map.updateMapMatrixCell(0, 2, false, -1, 0);  
    map.updateMapMatrixCell(2, 0, false, -1, 1);  
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfBike(1, 2, 2);
    map.addCoordOfVisitor(0, 0, 2);
    map.addCoordOfVisitor(1, 2, 0);
    
    map.updateBikesPreferenceMatrix();
    
    map.updateVisitorsPreferenceMatrix(0, 0, 0, 2);
    map.updateVisitorsPreferenceMatrix(0, 1, 1, 4);
    map.updateVisitorsPreferenceMatrix(1, 0, 0, 4);
    map.updateVisitorsPreferenceMatrix(1, 1, 1, 2);
    
    map.GaleShapley("test1.in", true);
    
    ifstream output("tests/file1_output.out");
    string line;
    vector<string> matches;
    while (getline(output, line)) {
        matches.push_back(line);
    }
    
    assert(matches[0] == "a 1");
    assert(matches[1] == "b 0");
}

//*2*
void Tests::matching_with_obstacles() {
    Map map(4, 4, 2);
    map.initMapMatrix();
    
    map.updateMapMatrixCell(1, 1, true, -1, -1);
    map.updateMapMatrixCell(1, 2, true, -1, -1);
    map.updateMapMatrixCell(2, 1, true, -1, -1);
    map.updateMapMatrixCell(2, 2, true, -1, -1);
    
    map.updateMapMatrixCell(0, 0, false, 0, -1);
    map.updateMapMatrixCell(3, 3, false, 1, -1);
    map.updateMapMatrixCell(0, 3, false, -1, 0);
    map.updateMapMatrixCell(3, 0, false, -1, 1);
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfBike(1, 3, 3);
    map.addCoordOfVisitor(0, 0, 3);
    map.addCoordOfVisitor(1, 3, 0);
    
    map.updateBikesPreferenceMatrix();
    
    assert(map.BFS(0, 0, 0, 3) == 3);
}

//*3*
void Tests::max_map_size() {
    Map map(100, 100, 10);
    assert(map.getDimX() == 100);
    assert(map.getDimY() == 100);
    assert(map.getNumberOfElements() == 10);
}

//*4*
void Tests::single_match() {
    Map map(2, 2, 1);
    map.initMapMatrix();
    
    map.updateMapMatrixCell(0, 0, false, 0, -1);
    map.updateMapMatrixCell(1, 1, false, -1, 0);
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfVisitor(0, 1, 1);
    
    map.updateBikesPreferenceMatrix();
    map.updateVisitorsPreferenceMatrix(0, 0, 0, 1);
    
    map.GaleShapley("test4.in", true);
    
    ifstream output("tests/file4_output.out");
    string line;
    getline(output, line);

    assert(line == "a 0");
}

// *5*
void Tests::preference_ordering() {
    Map map(3, 3, 3);
    map.initMapMatrix();
    
    for(int i = 0; i < 3; i++) {
        map.updateMapMatrixCell(i, 0, false, i, -1); 
        map.updateMapMatrixCell(i, 2, false, -1, i);
        map.addCoordOfBike(i, i, 0);
        map.addCoordOfVisitor(i, i, 2);
    }
    
    map.updateBikesPreferenceMatrix();
    
    pair<int, int> **bikePrefs = map.getBikesPreferenceMatrix();
    
    for(int i = 0; i < 3; i++) {
        vector<pair<int, int>> distances; 
        for(int visitor = 0; visitor < 3; visitor++) {
            int dist = map.BFS(i, 0, i, 2);  
            distances.push_back({visitor, dist});
        }
        
        sort(distances.begin(), distances.end(), 
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });
        
        for(int j = 0; j < 3; j++) {
            assert(bikePrefs[i][j].first == distances[j].first);
        }
    }
}

//*6*
void Tests::isolated_paths() {
    Map map(5, 5, 2);
    map.initMapMatrix();

    for(int i = 0; i < 5; i++) map.updateMapMatrixCell(2, i, true, -1, -1);
    
    map.updateMapMatrixCell(0, 0, false, 0, -1);
    map.updateMapMatrixCell(0, 4, false, 1, -1);
    map.updateMapMatrixCell(4, 0, false, -1, 0);
    map.updateMapMatrixCell(4, 4, false, -1, 1);
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfBike(1, 0, 4);
    map.addCoordOfVisitor(0, 4, 0);
    map.addCoordOfVisitor(1, 4, 4);
    
    assert(map.BFS(0, 0, 4, 0) == -1);
}


//*7*
void Tests::memory_management() {
    {
        Map map(10, 10, 5);
        map.initMapMatrix();
    }
    // If it reach here without memory errors, test passes
    assert(true);
}


//*8*
void Tests::preference_conflict() {
    Map map(3, 3, 2);
    map.initMapMatrix();
    
    map.updateMapMatrixCell(0, 0, false, 0, -1);
    map.updateMapMatrixCell(2, 2, false, 1, -1);
    map.updateMapMatrixCell(0, 2, false, -1, 0);
    map.updateMapMatrixCell(2, 0, false, -1, 1);
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfBike(1, 2, 2);
    map.addCoordOfVisitor(0, 0, 2);
    map.addCoordOfVisitor(1, 2, 0);
    
    map.updateVisitorsPreferenceMatrix(0, 0, 0, 1);
    map.updateVisitorsPreferenceMatrix(0, 1, 1, 2);
    map.updateVisitorsPreferenceMatrix(1, 0, 0, 1);
    map.updateVisitorsPreferenceMatrix(1, 1, 1, 2);
    
    map.GaleShapley("test8.in", true);
    
    ifstream output("tests/file8_output.out");
    vector<string> matches;
    string line;
    while (getline(output, line)) {
        matches.push_back(line);
    }

    assert(matches.size() == 2);
}

//*9*
void Tests::all_cells_no_visited_after_bfs() {
    Map map(4, 4, 2);
    map.initMapMatrix();
    
    map.updateMapMatrixCell(1, 1, true, -1, -1);
    map.updateMapMatrixCell(1, 2, true, -1, -1);
    map.updateMapMatrixCell(2, 1, true, -1, -1);
    map.updateMapMatrixCell(2, 2, true, -1, -1);
    
    map.updateMapMatrixCell(0, 0, false, 0, -1);
    map.updateMapMatrixCell(3, 3, false, 1, -1);
    map.updateMapMatrixCell(0, 3, false, -1, 0);
    map.updateMapMatrixCell(3, 0, false, -1, 1);
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfBike(1, 3, 3);
    map.addCoordOfVisitor(0, 0, 3);
    map.addCoordOfVisitor(1, 3, 0);
    
    map.updateBikesPreferenceMatrix();

    map.BFS(0, 0, 0, 3);
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            assert(map.getMapMatrix()[i][j].visited == false);
        }
    }
}

// *10*
void Tests::invalid_cell_access() {
    Map map(5, 5, 2);
    map.initMapMatrix();

    assert(map.checkCell(-1, 0) == false);
    assert(map.checkCell(0, -1) == false);
    assert(map.checkCell(5, 0) == false);
    assert(map.checkCell(0, 5) == false);
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

    // *5*
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

    // *29*
    tests.test_stable_matching_output();

    // *30*
    tests.test_change_map_matrix_cell(map);

    tests.test_set_map_matrix_cells_comprehensive();

    tests.empty_vector();

    tests.element_exists();

    tests.element_does_not_exist();

    tests.single_element_exists();

    tests.single_element_does_not_exist();

    cout << "Success! All unit tests passed!" << "\n";

    cout << "Starting system/integration tests..." << "\n";

    // *1*
    tests.test_basic_matching_no_obstacles();

    // *2*
    tests.matching_with_obstacles();

    // *3*
    tests.max_map_size();

    // *4*
    tests.single_match();

    // *5*
    tests.preference_ordering();

    // *6*
    tests.isolated_paths();

    // *7*
    tests.memory_management();

    // *8*
    tests.preference_conflict();

    // *9*
    tests.all_cells_no_visited_after_bfs();

    // *10*
    tests.invalid_cell_access();

    cout << "Success! All system/integration tests passed!" << "\n";
    
    return 0;
}