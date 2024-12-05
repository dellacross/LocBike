#ifndef TESTS_HPP
#define TESTS_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "map.hpp"

class Tests
{
    public:

        Tests(){};

        ~Tests(){};

        void test_map_contructor();

        // *1*
        void test_bike_or_visitor();

        // *2*
        void test_if_exists();

        void test_if_exists_empty_vector();

        // *3*
        void test_get_element_ID();

        // *4* 
        void test_init_map_matrix(Map* map);

        // *5* 
        void test_cell_constructor();

        // *6*
        void test_update_map_matrix_cell(Map* map);

        // *7*
        void test_check_cell_out_of_range(Map* map);

        // *8*
        void test_check_cell_negative(Map* map);

        // *9*
        void test_init_visitors_preference_matrix(Map* map);

        // *10* 
        void test_init_bikes_preference_matrix(Map* map);

        // *11* 
        void test_init_coord_of_bikes_vector(Map* map);

        // *12* 
        void test_init_coord_of_visitors_vector(Map* map);

        // *13* 
        void test_all_no_visited(Map* map);

        // *14* 
        void test_update_visitors_preference_matrix(Map* map);

        // *15* 
        void test_add_coord_of_bike(Map* map);

        void test_add_coord_of_visitor(Map* map);

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

        void test_preferece();

    friend class Map;
};

#endif