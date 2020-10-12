#ifndef ULTRA_ASSIGNMENT_INCLUDE_BITWISE_ADD_H_
#define ULTRA_ASSIGNMENT_INCLUDE_BITWISE_ADD_H_

#include <iostream>

namespace osa::ultra {

constexpr int kSignBitBitMask{1 << (sizeof(int) * 8 - 1)};

inline int add(int left, int right) {
    while (right != 0) {
        // remember places where we moving sum to next rank. E.g. 01+01 = 10,
        // moving "1" to next position(rank).
        int next_rank = left & right;

        // xor shows rest of the sum(no need to move to next rank).
        // E.g. 10+01 = 11
        left = left ^ right;

        // Moving to next rank to apply on next iteration.
        right = next_rank << 1;
    }

    return left;
}

inline bool is_add_overflow(int left, int right, int result) {
    // check if sign bit is the same
    int sign_check = ~(left ^ right);

    // If sign bit of left and right is the same overflow is possible.
    if ((sign_check & kSignBitBitMask) == kSignBitBitMask) {
        // If sign bit has changed we have overflow
        sign_check = result ^ right;
        if ((sign_check & kSignBitBitMask) == kSignBitBitMask) {
            return true;
        }
    }

    return false;
}

}  // namespace osa::ultra

#endif  // ULTRA_ASSIGNMENT_INCLUDE_BITWISE_ADD_H_
