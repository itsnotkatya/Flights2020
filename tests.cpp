//
// Created by Екатерина on 18/01/2020.
//

#include "gtest/gtest.h"
#include "lib.h"
#include <fstream>

std::ifstream file ("/Users/ekaterina/CLionProjects/flights2020/input.txt");

TEST(FindWay, ShortestWay) {
    char dep_point, dest_point;
    dep_point = 'A';
    dest_point = 'D';
    EXPECT_EQ(7,FindWay(file,dep_point,dest_point));
}

TEST(FindWay, NoWay) {
    char dep_point, dest_point;
    dep_point = 'A';
    dest_point = 'F';
    EXPECT_EQ(2147483647,FindWay(file,dep_point,dest_point));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}