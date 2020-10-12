#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

#include "ultra_assignment/include/bitwise_add.h"
#include "ultra_assignment/include/subset_sum.h"

template <typename InputIt>
void PrintContainer(InputIt first, InputIt last) {
    std::for_each(first, last,
                  [](const auto& element) { std::cout << element << ","; });
}

void RunLargestSumShowcase(
    const std::vector<std::pair<uint32_t, std::vector<uint32_t>>>& test_data) {
    std::size_t test_case_number{1};

    std::vector<uint32_t> result_subset{};
    uint32_t largest_sum{0};

    std::cout << "Subset sum problem simple showcase: \n";

    for (const auto& element : test_data) {
        osa::ultra::find_largest_sum(element.first, element.second,
                                     result_subset, largest_sum);
        std::cout << "Test " << test_case_number++ << ") set: ";
        PrintContainer(std::cbegin(element.second), std::cend(element.second));
        std::cout << " target: " << element.first
                  << " largest sum: " << largest_sum << " subset: ";
        PrintContainer(std::crbegin(result_subset), std::crend(result_subset));
        std::cout << std::endl;
    }
}

void BitWiseAddTest(int left, int right) {
    int right_answer{left + right};

    std::cout << "add(" << left << "," << right
              << ") = " << osa::ultra::add(left, right) << '\n';

    assert(right_answer == osa::ultra::add(left, right));
}

int main(/* int argc, char const *argv[]*/) {
    // test data: {
    //     {{target},{set}},
    //     ...
    // }
    // Constrains assumption: Sets are sorted.
    // If it's not std::sort will do the job(or a custom one).
    std::vector<std::pair<uint32_t, std::vector<uint32_t>>> test_data{
        {{13}, {1, 3, 4, 5, 6, 6, 10}},
        {{11}, {1, 2, 3, 4, 5, 6, 7}},
        {{2}, {1}},
        {{25}, {4, 5, 6, 10, 13, 16, 24}}};

    RunLargestSumShowcase(test_data);

    std::cout << "Bitwise add simple showcase: \n";
    BitWiseAddTest(25,13);
    BitWiseAddTest(std::numeric_limits<int>::max(), 1);
    std::cout << std::endl;

    return 0;
}
