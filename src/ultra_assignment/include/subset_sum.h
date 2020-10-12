#ifndef ULTRA_ASSIGNMENT_INLUDE_SUBSET_SUM_H_
#define ULTRA_ASSIGNMENT_INLUDE_SUBSET_SUM_H_

#include <cstdint>
#include <vector>

namespace osa::ultra {

inline void find_largest_sum(uint32_t target_value,
                             const std::vector<uint32_t>& int_set,
                             std::vector<uint32_t>& largest_sum_subset,
                             uint32_t& largest_sum) {
    largest_sum_subset.clear();
    largest_sum = 0;
    if (target_value <= 0 || int_set.empty()) {
        // Corner cases:
        // 1) If target value less or equal to 0, an empty subset gives 0 sum
        // which is our answer.
        // 2) Empty set has only one subset and it is also
        // empty with 0 sum.
        largest_sum = 0;
        return;
    }

    // Creating structure which helps keeping results of sub-task.
    // subtask_results_matrix[][0..J] indexes represent all sums.
    // subtask_results_matrix[0..I][] indexes represent our initial set.
    // we fill matrix with True or false depending if we have a subset with
    // element j with sum i.
    std::vector<std::vector<bool>> subtask_results_matrix(
        int_set.size() + 1, std::vector<bool>(target_value + 1, false));

    // As we always have emty subset with sum = 0 we put True for
    // subtask_results_matrix[0][0..J]=0.
    for (auto& i : subtask_results_matrix) {
        i[0] = true;
    }

    // With the bottom-up Dynamic programming approach(to avoid using recursion
    // - top-down), we are solving sub-tasks from simplest to hardest reusing
    // results of previous tasks.
    for (std::size_t i{1}; i < subtask_results_matrix.size(); ++i) {
        for (std::size_t j{1}; j < subtask_results_matrix.front().size(); ++j) {
            // If the element itself is equal to the current sum we mark an
            // interception element - sum with True If one element less than sum
            // value, we are looking for previous(smaller) elements to fill the
            // gap. Basically, we are reusing results from previously solved
            // sub-tasks.
            if (int_set[i - 1] < j) {
                subtask_results_matrix[i][j] =
                    (subtask_results_matrix[i - 1][j]) ||
                    (subtask_results_matrix[i - 1][j - int_set[i - 1]]);
            } else if (j == int_set[i - 1]) {
                subtask_results_matrix[i][j] = true;
            } else {
                subtask_results_matrix[i][j] = subtask_results_matrix[i - 1][j];
            }
        }
    }

    // Searching for the first True from right side of the bottom row.
    // Index of it is our largest sum.
    for (std::size_t i{subtask_results_matrix.back().size() - 1};
         i < subtask_results_matrix.back().size(); --i) {
        if (subtask_results_matrix.back()[i]) {
            largest_sum = i;
            break;
        }
    }

    // If largest sum is "0" return with empty subset.
    if (largest_sum == 0) {
        return;
    }

    // Pathing from the bottom right corner of our structure and completing the
    // subset we used to compose a sum.
    for (std::size_t j{largest_sum}; j < largest_sum + 1;) {
        for (std::size_t i{subtask_results_matrix.size() - 1};
             i < subtask_results_matrix.size(); --i) {
            if (int_set[i - 1] == j) {
                largest_sum_subset.push_back(int_set[i - 1]);
                return;
            }

            if (!subtask_results_matrix[i - 1][j]) {
                largest_sum_subset.push_back(int_set[i - 1]);
                j = j - int_set[i - 1];
            }
        }
    }
}

}  // namespace osa::ultra

#endif  // ULTRA_ASSIGNMENT_INLUDE_SUBSET_SUM_H_
