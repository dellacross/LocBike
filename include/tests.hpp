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

        // *1*
        void test_bike_or_visitor();

        // *2*
        void test_if_exists();

        // *3*
        void test_if_exists_empty_vector();

        // *4*
        void test_get_bike_element_ID();

        // *5*
        void test_get_visitor_element_ID();

        // *6* 
        void test_init_map_matrix(Map* map);

        // *7* 
        void test_cell_constructor();

        // *8*
        void test_update_map_matrix_cell(Map* map);

        // *9*
        void test_check_cell_out_of_range(Map* map);

        // *10*
        void test_check_cell_negative(Map* map);

        // *11*
        void test_init_visitors_preference_matrix(Map* map);

        // *12* 
        void test_init_bikes_preference_matrix(Map* map);

        // *13* 
        void test_init_coord_of_bikes_vector(Map* map);

        // *14* 
        void test_init_coord_of_visitors_vector(Map* map);

        // *15* 
        void test_all_no_visited(Map* map);

        // *16* 
        void test_update_visitors_preference_matrix(Map* map);

        // *17*
        void test_add_coord_of_bike(Map* map);

        // *18*
        void test_add_coord_of_visitor(Map* map);

        // *19*
        void test_check_visited_cell(Map* map);

        // *20*
        void test_check_obstacle_cell(Map* map);

        // *21*
        void test_if_exists_element();

        // *22*
        void test_if_dont_exists_element();

        // *23*
        void test_constructor();

        // *24*
        void test_BFS();

        // *25*
        void test_get_dimensions();

        // *26*
        void test_BFS_without_pair();

        // *27*
        void test_set_map_matrix_cells();

        // *28*
        void test_preference();

        // *29*
        void test_stable_matching_output();

        // *30*
        void test_change_map_matrix_cell(Map* map);

        // *1*
        void test_basic_matching_no_obstacles();

        // *2*
        void matching_with_obstacles();

        // *3*
        void max_map_size();

        // *4*
        void single_match();

        // *5*
        void preference_ordering();

        // *6*
        // *7*
        // *8*
        // *9*
        // *10*

    friend class Map;
};

#endif