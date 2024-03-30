#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

void test_swap_min_max_rows_1_standard_swap() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {7, 8, 9,
                                                     4, 5, 6,
                                                     1, 2, 3},3, 3);

    swap_min_max_rows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_min_max_rows_2_min_and_max_elements_equal() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                                 1, 1, 1,
                                                 1, 1, 1}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 1, 1,
                                                     1, 1, 1,
                                                     1, 1, 1},3, 3);

    swap_min_max_rows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_min_max_rows_3_min_and_max_elements_in_one_row() {
    matrix m = createMatrixFromArray((int[]) {1, 7, 1,
                                                 1, 1, 1,
                                                 1, 1, 1}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 7, 1,
                                                     1, 1, 1,
                                                     1, 1, 1},3, 3);

    swap_min_max_rows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_min_max_rows() {
    test_swap_min_max_rows_1_standard_swap();
    test_swap_min_max_rows_2_min_and_max_elements_equal();
    test_swap_min_max_rows_3_min_and_max_elements_in_one_row();
}


void test_sort_rows_by_max_element_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                                 1, 8, 1,
                                                 3, 2, 3}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {3, 2, 3,
                                                     7, 1, 2,
                                                     1, 8, 1},3, 3);

    sort_rows_by_min_element(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_rows_by_max_element_2_max_value_equal() {
    matrix m = createMatrixFromArray((int[]) {8, 2, 3,
                                                 2, 8, 2,
                                                 4, 8, 8}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {8, 2, 3,
                                                     2, 8, 2,
                                                     4, 8, 8},3, 3);


    sort_rows_by_min_element(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_rows_by_max_element() {
    test_sort_rows_by_max_element_1_standard_value();
    test_sort_rows_by_max_element_2_max_value_equal();
}


void test_sort_cols_by_min_element_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                                 2, 5, 1, 8, 2, 7,
                                                 6, 1, 4, 4, 8, 3}, 3, 6);

    matrix check = createMatrixFromArray((int[]) {5, 2, 3, 3, 3, 4,
                                                     5, 1, 2, 2, 7, 8,
                                                     1, 4, 6, 8, 3, 4},3, 6);

    sort_cols_by_min_element(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_cols_by_min_element_2_min_value_equal() {
    matrix m = createMatrixFromArray((int[]) {4, 6, 3, 2, 4, 4,
                                                 2, 6, 2, 9, 2, 8,
                                                 7, 2, 5, 5, 9, 2}, 3, 6);

    matrix check = createMatrixFromArray((int[]) {4, 6, 3, 2, 4, 4,
                                                     2, 6, 2, 9, 2, 8,
                                                     7, 2, 5, 5, 9, 2},3, 6);

    sort_cols_by_min_element(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_cols_by_min_element() {
    test_sort_cols_by_min_element_1_standard_value();
    test_sort_cols_by_min_element_2_min_value_equal();
}


void test_mul_matrices_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                  2, 1, 2,
                                                  3, 2, 1}, 3, 3);

    get_square_of_matrix_if_symmetric(&m);

    matrix check = createMatrixFromArray((int[]) {14, 10, 10,
                                                     10, 9, 10,
                                                     10, 10, 14}, 3, 3);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_mul_matrices_2_mul_to_e_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                                  0, 1, 0,
                                                  0, 0, 1}, 3, 3);

    get_square_of_matrix_if_symmetric(&m);


    matrix check = createMatrixFromArray((int[]) {1, 0, 0,
                                                     0, 1, 0,
                                                     0, 0, 1}, 3, 3);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_mul_matrices_3_mul_to_null_matrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {0, 0, 0,
                                                  0, 0, 0,
                                                  0, 0, 0}, 3, 3);

    matrix result = mul_matrices(m1, m2);


    matrix check = createMatrixFromArray((int[]) {0, 0, 0,
                                                     0, 0, 0,
                                                     0, 0, 0}, 3, 3);

    assert(areTwoMatricesEqual(&result, &check));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}

void test_mul_matrices() {
    test_mul_matrices_1_standard_value();
    test_mul_matrices_2_mul_to_e_matrix();
    test_mul_matrices_3_mul_to_null_matrix();
}


void test_transpose_if_matrix_has_not_equal_sum_of_rows_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 4, 7,
                                                     2, 5, 8,
                                                     3, 6, 9}, 3, 3);

    transpose_if_matrix_has_not_equal_sum_of_rows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_transpose_if_matrix_has_not_equal_sum_of_rows_2_not_different_sum() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 1,
                                                 2, 1, 2,
                                                 0, 0, 2}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 0, 1,
                                                     2, 1, 2,
                                                     0, 0, 2}, 3, 3);

    transpose_if_matrix_has_not_equal_sum_of_rows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_transpose_if_matrix_has_not_equal_sum_of_rows() {
    test_transpose_if_matrix_has_not_equal_sum_of_rows_1_standard_value();
    test_transpose_if_matrix_has_not_equal_sum_of_rows_2_not_different_sum();
}


void test_is_mutually_inverse_matrices_1_inverse_matrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, 1,
                                                  2, 1}, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {-1, 1,
                                                  2, -1}, 2, 2);

    bool result = is_mutually_inverse_matrices(m1, m2);

    assert(result == 1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_is_mutually_inverse_matrices_2_not_inverse_matrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, 1,
                                                  1, 4}, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {6, 1,
                                                  4, -3}, 2, 2);

    bool result = is_mutually_inverse_matrices(m1, m2);

    assert(result == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_is_mutually_inverse_matrices() {
    test_is_mutually_inverse_matrices_1_inverse_matrices();
    test_is_mutually_inverse_matrices_2_not_inverse_matrices();
}


void test_find_sum_of_maxes_of_pseudo_diagonal_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {4, 3, 6, 5,
                                                 2, 4, 7, 4,
                                                 4, 3, 2, 3}, 3, 4);

    long long int result = find_sum_of_maxes_of_pseudo_diagonal(m);

    assert(result == 25);

    freeMemMatrix(&m);
}

void test_find_sum_of_maxes_of_pseudo_diagonal_2_one_element() {
    matrix m = createMatrixFromArray((int[]) {7}, 1, 1);

    long long int result = find_sum_of_maxes_of_pseudo_diagonal(m);

    assert(result == 0);

    freeMemMatrix(&m);
}

void test_find_sum_of_maxes_of_pseudo_diagonal() {
    test_find_sum_of_maxes_of_pseudo_diagonal_1_standard_value();
    test_find_sum_of_maxes_of_pseudo_diagonal_2_one_element();
}

void test(){
    test_swap_min_max_rows();
    test_sort_rows_by_max_element();
    test_sort_cols_by_min_element();
    test_mul_matrices();
    test_transpose_if_matrix_has_not_equal_sum_of_rows();
    test_is_mutually_inverse_matrices();
    test_find_sum_of_maxes_of_pseudo_diagonal();
}

int main() {
    test();

    return 0;
}

