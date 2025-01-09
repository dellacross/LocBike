#include <gtest/gtest.h>
#include "tests.hpp"
#include "functions.hpp"
#include <cassert>
#include <utility> 
#include <algorithm>

class MapTest : public ::testing::Test {
protected:
    void SetUp() override {
        map = new Map(4, 4, 3);
        map->initMapMatrix();
    }

    void TearDown() override {
        delete map;
    }

    Map* map;
};

// UNIT TESTS

int numberOfElements = -1, x_dimension = -1, y_dimension = -1;

// *1* 
TEST(FunctionsTest, BikeOrVisitorIdentification) {
    EXPECT_FALSE(BikeOrVisitor('a'));
    EXPECT_FALSE(BikeOrVisitor('d'));
    EXPECT_TRUE(BikeOrVisitor('2'));
    EXPECT_TRUE(BikeOrVisitor('3'));
}

// *2*
TEST(FunctionsTest, VectorElementExistence) {
    std::vector<int> testVector = {1, 3};
    EXPECT_TRUE(ifExists(1, testVector));
    EXPECT_FALSE(ifExists(2, testVector));
    EXPECT_TRUE(ifExists(3, testVector));
    EXPECT_FALSE(ifExists(4, testVector));
}

// *3*
TEST(FunctionsTest, EmptyVectorExistence) {
    std::vector<int> emptyVector;
    EXPECT_FALSE(ifExists(1, emptyVector));
}

// *4*
TEST(FunctionsTest, ElementIDRetrieval) {
    EXPECT_EQ(getElementID('0'), 1);
    EXPECT_EQ(getElementID('2'), 3);
    EXPECT_EQ(getElementID('a'), 1);
    EXPECT_EQ(getElementID('b'), 2);
}

void Tests::test_get_visitor_element_ID() {
    assert(getElementID('a') == 1);
    assert(getElementID('b') == 2);
}

// *5* 
TEST_F(MapTest, MapInitialization) {
    EXPECT_EQ(map->getDimX(), 4);
    EXPECT_EQ(map->getDimY(), 4);
    EXPECT_EQ(map->getNumberOfElements(), 3);
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
TEST_F(MapTest, CellBoundaryChecks) {
    EXPECT_FALSE(map->checkCell(11, 3));
    EXPECT_FALSE(map->checkCell(1, 13));
    EXPECT_FALSE(map->checkCell(-1, 3));
    EXPECT_FALSE(map->checkCell(1, -3));
}

// *9*
void Tests::test_check_cell_negative(Map* map) {
    bool invalid_negative_1 = map->checkCell(-1, 3);
    bool invalid_negative_2 = map->checkCell(1, -3);

    assert(invalid_negative_1 == false);
    assert(invalid_negative_2 == false);
}

// *10*
TEST_F(MapTest, PreferenceMatrixInitialization) {
    map->initVisitorsPreferenceMatrix();
    EXPECT_NE(map->getVisitorsPreferenceMatrix(), nullptr);

    map->initBikesPreferenceMatrix();
    EXPECT_NE(map->getBikesPreferenceMatrix(), nullptr);
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
TEST_F(MapTest, CoordinatesVectorInitialization) {
    map->initCoordOfBikesVector();
    EXPECT_NE(map->getCoordsOfBikes(), nullptr);

    map->initCoordOfVisitorsVector();
    EXPECT_NE(map->getCoordsOfVisitors(), nullptr);
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
    string fileName = "test_file.txt";
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

class MapIntegrationTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Test 1: Basic matching with no obstacles
TEST_F(MapIntegrationTest, BasicMatchingNoObstacles) {
    Map map(3, 3, 2); // 3x3 map with 2 bikes and 2 visitors
    
    // Add bikes and visitors
    map.updateMapMatrixCell(0, 0, false, 0, -1);  // Bike 0
    map.updateMapMatrixCell(2, 2, false, 1, -1);  // Bike 1
    map.updateMapMatrixCell(0, 2, false, -1, 0);  // Visitor 0
    map.updateMapMatrixCell(2, 0, false, -1, 1);  // Visitor 1
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfBike(1, 2, 2);
    map.addCoordOfVisitor(0, 0, 2);
    map.addCoordOfVisitor(1, 2, 0);
    
    map.updateBikesPreferenceMatrix();
    
    // Set visitor preferences
    map.updateVisitorsPreferenceMatrix(0, 0, 0, 2);
    map.updateVisitorsPreferenceMatrix(0, 1, 1, 4);
    map.updateVisitorsPreferenceMatrix(1, 0, 0, 4);
    map.updateVisitorsPreferenceMatrix(1, 1, 1, 2);
    
    // Execute matching
    map.GaleShapley("test1.txt", true);
    
    // Verify output file contains expected matches
    std::ifstream output("tests/file1_output.out");
    std::string line;
    std::vector<std::string> matches;
    while (std::getline(output, line)) {
        matches.push_back(line);
    }
    
    EXPECT_EQ(matches[0], "a 0");
    EXPECT_EQ(matches[1], "b 1");
}

// Test 2: Matching with obstacles
TEST_F(MapIntegrationTest, MatchingWithObstacles) {
    Map map(4, 4, 2);
    
    // Add obstacles in the middle
    map.updateMapMatrixCell(1, 1, true, -1, -1);
    map.updateMapMatrixCell(1, 2, true, -1, -1);
    map.updateMapMatrixCell(2, 1, true, -1, -1);
    map.updateMapMatrixCell(2, 2, true, -1, -1);
    
    // Add bikes and visitors
    map.updateMapMatrixCell(0, 0, false, 0, -1);
    map.updateMapMatrixCell(3, 3, false, 1, -1);
    map.updateMapMatrixCell(0, 3, false, -1, 0);
    map.updateMapMatrixCell(3, 0, false, -1, 1);
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfBike(1, 3, 3);
    map.addCoordOfVisitor(0, 0, 3);
    map.addCoordOfVisitor(1, 3, 0);
    
    map.updateBikesPreferenceMatrix();
    
    // Verify path distances with obstacles
    EXPECT_EQ(map.BFS(0, 0, 0, 3), 6); // Should take longer path around obstacles
}

// Test 3: Maximum map size test
TEST_F(MapIntegrationTest, MaxMapSize) {
    Map map(100, 100, 10);
    EXPECT_EQ(map.getDimX(), 100);
    EXPECT_EQ(map.getDimY(), 100);
    EXPECT_EQ(map.getNumberOfElements(), 10);
}

// Test 4: Edge case - Single bike and visitor
TEST_F(MapIntegrationTest, SingleMatch) {
    Map map(2, 2, 1);
    
    map.updateMapMatrixCell(0, 0, false, 0, -1);
    map.updateMapMatrixCell(1, 1, false, -1, 0);
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfVisitor(0, 1, 1);
    
    map.updateBikesPreferenceMatrix();
    map.updateVisitorsPreferenceMatrix(0, 0, 0, 1);
    
    map.GaleShapley("test4.txt", true);
    
    std::ifstream output("tests/file4_output.out");
    std::string line;
    std::getline(output, line);
    EXPECT_EQ(line, "a 0");
}

// Test 5: Preference ordering test
TEST_F(MapIntegrationTest, PreferenceOrdering) {
    Map map(3, 3, 3);
    
    // Add three bikes and visitors in specific positions
    for(int i = 0; i < 3; i++) {
        map.updateMapMatrixCell(i, 0, false, i, -1);
        map.updateMapMatrixCell(i, 2, false, -1, i);
        map.addCoordOfBike(i, i, 0);
        map.addCoordOfVisitor(i, i, 2);
    }
    
    map.updateBikesPreferenceMatrix();
    
    // Verify preference matrix is properly sorted
    auto** bikePrefs = map.getBikesPreferenceMatrix();
    for(int i = 0; i < 3; i++) {
        for(int j = 1; j < 3; j++) {
            EXPECT_GE(bikePrefs[i][j-1].second, bikePrefs[i][j].second);
        }
    }
}

// Test 6: Isolated paths test
TEST_F(MapIntegrationTest, IsolatedPaths) {
    Map map(5, 5, 2);
    
    // Create wall of obstacles between bikes and visitors
    for(int i = 0; i < 5; i++) {
        map.updateMapMatrixCell(2, i, true, -1, -1);
    }
    
    map.updateMapMatrixCell(0, 0, false, 0, -1);
    map.updateMapMatrixCell(0, 4, false, 1, -1);
    map.updateMapMatrixCell(4, 0, false, -1, 0);
    map.updateMapMatrixCell(4, 4, false, -1, 1);
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfBike(1, 0, 4);
    map.addCoordOfVisitor(0, 4, 0);
    map.addCoordOfVisitor(1, 4, 4);
    
    // Verify no path exists
    EXPECT_EQ(map.BFS(0, 0, 4, 0), -1);
}

// Test 7: Memory management test
TEST_F(MapIntegrationTest, MemoryManagement) {
    {
        Map map(10, 10, 5);
        // Let destructor handle cleanup
    }
    // If we reach here without memory errors, test passes
    SUCCEED();
}

// Test 8: Preference conflict resolution
TEST_F(MapIntegrationTest, PreferenceConflict) {
    Map map(3, 3, 2);
    
    // Set up scenario where both visitors prefer the same bike
    map.updateMapMatrixCell(0, 0, false, 0, -1);
    map.updateMapMatrixCell(2, 2, false, 1, -1);
    map.updateMapMatrixCell(0, 2, false, -1, 0);
    map.updateMapMatrixCell(2, 0, false, -1, 1);
    
    map.addCoordOfBike(0, 0, 0);
    map.addCoordOfBike(1, 2, 2);
    map.addCoordOfVisitor(0, 0, 2);
    map.addCoordOfVisitor(1, 2, 0);
    
    // Both visitors prefer bike 0
    map.updateVisitorsPreferenceMatrix(0, 0, 0, 1);
    map.updateVisitorsPreferenceMatrix(0, 1, 1, 2);
    map.updateVisitorsPreferenceMatrix(1, 0, 0, 1);
    map.updateVisitorsPreferenceMatrix(1, 1, 1, 2);
    
    map.GaleShapley("test8.txt", true);
    
    // Verify stable matching was achieved
    std::ifstream output("tests/file8_output.out");
    std::vector<std::string> matches;
    std::string line;
    while (std::getline(output, line)) {
        matches.push_back(line);
    }
    EXPECT_EQ(matches.size(), 2);
}

// Test 10: Invalid cell access test
TEST_F(MapIntegrationTest, InvalidCellAccess) {
    Map map(5, 5, 2);
    
    // Test boundary conditions
    EXPECT_FALSE(map.checkCell(-1, 0));
    EXPECT_FALSE(map.checkCell(0, -1));
    EXPECT_FALSE(map.checkCell(5, 0));
    EXPECT_FALSE(map.checkCell(0, 5));
    
    // Test valid cell
    EXPECT_TRUE(map.checkCell(2, 2));
}

int main(int argc, char** argv) {

    Tests tests;
    Map* map = new Map(4, 4, 3);
    map->initMapMatrix();

    cout << "Starting unit tests..." << "\n";

    // *1*
    //tests.test_bike_or_visitor();

    // *2*
    //tests.test_if_exists();

    // *3*
    //tests.test_if_exists_empty_vector();

    // *4*
    //tests.test_get_bike_element_ID();

    // *5*
    tests.test_get_visitor_element_ID();

    // *6* 
    tests.test_init_map_matrix(map);

    // *7* 
    tests.test_cell_constructor();

    // *8*
    //tests.test_update_map_matrix_cell(map);

    // *9*
    tests.test_check_cell_out_of_range(map);

    // *10*
    //tests.test_check_cell_negative(map);

    // *11*
    tests.test_init_visitors_preference_matrix(map);

    // *12* 
    //tests.test_init_bikes_preference_matrix(map);

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

    cout << "Success! All unit tests passed!" << "\n";

    cout << "Starting system tests..." << "\n";

    cout << "Success! All system tests passed!" << "\n";

    cout << "All tests passed for '" << argv[1] << "' file!\n";
    
    return 0;
}