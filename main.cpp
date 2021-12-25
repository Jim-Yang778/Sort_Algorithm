#define CATCH_CONFIG_MAIN // NOLINT(readability-identifier-naming)
#define CATCH_CONFIG_FAST_COMPILE
#include <random>
#include <catch2/catch.hpp>
#include "algo/algos.hpp"

std::vector<int> init() {
    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<int> random_item_num{0, 50};
    std::uniform_int_distribution<int> random_num{INT_MIN, INT_MAX};

    int item_num = random_item_num(engine);
    std::vector<int> random_list = {};
    while (item_num) {
        random_list.emplace_back(random_num(engine));
        --item_num;
    }
    return random_list;
}

TEST_CASE("Bubble Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    bubbleSort(random_list);
    CHECK(tmp == random_list);
}
