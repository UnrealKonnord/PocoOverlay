//
// Created by desrumaux on 16/07/2020.
//

#include <gtest/gtest.h>

/**
 * Run the google test framework
 *
 * @param argc
 * @param argv
 *
 * @return test status code
 */
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}