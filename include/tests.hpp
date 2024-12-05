#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Tests
{
    public:

        Tests(){};

        ~Tests(){};

        // *1*
        void test_BikeOrVisitor();

        // *2*
        void test_ifExists();

        // *3*
        void test_getElementID();

        // *4* 
        void test_InitMapMatrix(Map* map);

        // *5* 
        void test_cell_constructor();

        // *6*
        void test_UpdateMapMatrixCell(Map* map);

        // *7*
        void test_checkCell_out_of_range(Map* map);

        // *8*
        void test_checkCell_negative(Map* map);

        // *9*
        void test_initVisitorsPreferenceMatrix(Map* map);

        // *10* 
        void test_initBikesPreferenceMatrix(Map* map);

        // *11* 
        void test_initCoordOfBikesVector(Map* map);

        // *12* 
        void test_initCoordOfVisitorsVector(Map* map);

        // *13* 
        void test_allNoVisited(Map* map);

        // *14* 
        void test_updateVisitorsPreferenceMatrix(Map* map);

        // *15* 
        void test_addCoordOfBike(Map* map);

        // *16*
        void test_cell_with_obstacle();

        // *17*
        void test_map_custom_dimensions();

        // *18*
        void test_bike_preferences_initialization();

        // *19*
        void test_visitor_preferences_initialization();

        // *20*
        void test_empty_cell();

        // *21*
        void test_cell_update_with_obstacle();

        // *22*
        void test_bike_removal();

        // *23*
        void test_cell_update_with_bike();

        // *24*
        void test_bike_move();

        // *25*
        void test_cell_update_with_visitor();

        // *26*
        void test_visitor_move();

        // *27*
        void test_bike_coordinates_initialization();

        // *28*
        void test_check_valid_cell();

        // *29*
        void test_check_invalid_cell();

        // *30*
        void test_cell_reset();



    friend class Map;
};