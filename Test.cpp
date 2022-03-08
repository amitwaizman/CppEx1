//
// Created by USER on 07/03/2022.
//

//
// Created by USER on 06/03/2022.
//

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good input") {
            CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces(
                                                       "@@@@@@@@@\n"
                                                            "@-------@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-@---@-@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-------@\n"
                                                            "@@@@@@@@@"));
            CHECK(nospaces(mat(5, 3, '@', '-')) == nospaces(
                    "@@@@@\n"
                         "@---@\n"
                         "@@@@@"));
            CHECK(nospaces(mat(3, 5, '@', '-')) == nospaces(
            "@@@\n"
                  "@-@\n"
                  "@-@\n"
                  "@-@\n"
                  "@@@"));

            CHECK(nospaces(mat(13, 7, '@', '-')) == nospaces(
                                           "@@@@@@@@@@@@@\n"
                                                 "@-----------@\n"
                                                 "@-@@@@@@@@@-@\n"
                                                 "@-@-------@-@\n"
                                                 "@-@@@@@@@@@-@\n"
                                                 "@-----------@\n"
                                                 "@@@@@@@@@@@@@"));

            CHECK(nospaces(mat(9, 3, '@', '-')) == nospaces(
                                                       "@@@@@@@@@\n"
                                                            "@-------@\n"
                                                            "@@@@@@@@@"));

            CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));
}

TEST_CASE("Bad input (even)") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(12, 3, '$', '%'));
    CHECK_THROWS(mat(4, 3, '$', '%'));
    CHECK_THROWS(mat(16, 5, '$', '%'));
    CHECK_THROWS(mat(20, 3, '$', '%'));
    CHECK_THROWS(mat(2, 3, '$', '%'));
    CHECK_THROWS(mat(4, 4, '$', '%'));
    CHECK_THROWS(mat(2, 2, '$', '%'));
}

TEST_CASE("Input zero") {
    CHECK_THROWS(mat(0, 0, '$', '%'));
    CHECK_THROWS(mat(1, 0, '$', '%'));
    CHECK_THROWS(mat(0, 1, '$', '%'));
}

TEST_CASE("Input negative") {
    CHECK_THROWS(mat(-1, -3, '$', '%'));
    CHECK_THROWS(mat(-9, 3, '$', '%'));
    CHECK_THROWS(mat(-3, 81, '$', '%'));
    CHECK_THROWS(mat(-7, -9, '$', '%'));
    CHECK_THROWS(mat(-111, 3, '$', '%'));
    CHECK_THROWS(mat(-33, 21, '$', '%'));
}





