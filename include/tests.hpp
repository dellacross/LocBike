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

        // *0*
        void test_map_constructor();

        // *1*
        void test_bike_or_visitor();

        // *2*
        void test_if_exists();

        // *3*
        void test_if_exists_empty_vector();

        // *4*
        void test_get_element_ID();

        // *5* 
        void test_init_map_matrix(Map* map);

        // *6* 
        void test_cell_constructor();

        // *7*
        void test_update_map_matrix_cell(Map* map);

        // *8*
        void test_check_cell_out_of_range(Map* map);

        // *9*
        void test_check_cell_negative(Map* map);

        // *10*
        void test_init_visitors_preference_matrix(Map* map);

        // *11* 
        void test_init_bikes_preference_matrix(Map* map);

        // *12* 
        void test_init_coord_of_bikes_vector(Map* map);

        // *13* 
        void test_init_coord_of_visitors_vector(Map* map);

        // *14* 
        void test_all_no_visited(Map* map);

        // *15* 
        void test_update_visitors_preference_matrix(Map* map);

        // *16* 
        void test_add_coord_of_bike(Map* map);

        // *17*
        void test_preferece();

    friend class Map;
};

#endif