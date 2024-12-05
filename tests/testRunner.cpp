#include "tests.hpp"
#include "functions.hpp"
#include <cassert>
#include <utility> 
#include <algorithm>

// UNIT TESTS

int numberOfElements = -1, x_dimension = -1, y_dimension = -1;

void Tests::test_map_contructor() {
    Map* map;
    map = new Map(4,4);

    assert(map->getDimX() == 4);
    assert(map->getDimY() == 4);
}

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

void Tests::test_if_exists_empty_vector() {
    vector<int> _vector;
    assert(ifExists(1, _vector) == false);
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

void Tests::test_add_coord_of_visitor(Map* map) {
    Map* _map = map;
    _map->addCoordOfVisitor(0,2,2);
    _map->addCoordOfVisitor(1,0,3);
    _map->addCoordOfVisitor(2,3,1);

    pair<int, int> *coordsOfVisitors = map->coordsOfVisitors;

    assert(coordsOfVisitors[0].first == 2);
    assert(coordsOfVisitors[0].second == 2);
    assert(coordsOfVisitors[1].first == 0);
    assert(coordsOfVisitors[1].second == 3);
    assert(coordsOfVisitors[2].first == 3);
    assert(coordsOfVisitors[2].second == 1);
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

void Tests::test_preferece() {
    Map* map = new Map(4, 4);
    map->initVisitorsPreferenceMatrix();
    map->updateVisitorsPreferenceMatrix(0,0,0,2);
    map->updateVisitorsPreferenceMatrix(0,1,0,0);
    map->updateVisitorsPreferenceMatrix(0,2,0,1);
    map->updateVisitorsPreferenceMatrix(1,0,1,1);
    map->updateVisitorsPreferenceMatrix(1,1,1,0);
    map->updateVisitorsPreferenceMatrix(1,2,1,2);
    map->updateVisitorsPreferenceMatrix(2,0,3,0);
    map->updateVisitorsPreferenceMatrix(2,1,3,2);
    map->updateVisitorsPreferenceMatrix(2,2,3,1);

    assert(map->preference(0, 2, 0) == true);
    assert(map->preference(0, 0, 0) == false);
    assert(map->preference(1, 1, 1) == false);
    assert(map->preference(1, 0, 1) == true);
    assert(map->preference(3, 2, 3) == true);
    assert(map->preference(3, 0, 3) == false);
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

    tests.test_if_exists_empty_vector();

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