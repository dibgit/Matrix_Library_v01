/*
 *
 * matrix.h: First update. 2026_07_18. Dibyendu Mondal
 * Update or Issue Index            Date            Short description
 */

#ifndef MATRIXLIB_MATRIX_H
#define MATRIXLIB_MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define abs(x) ((x) < 0? -(x):(x)) //Criticism: for abs(i++) expanded to ((i++) < 0? -(i++):(i++)); ===> simply replacement text.....so increases i two times
#define LIMIT_TO_ZERO	0.00000000000001
typedef long double real_t;
//typedef double real_t;


typedef struct matrix_st
{
    uint32_t m_row;
    uint32_t m_col;
    real_t  **m_data;
}matrix_t;

//"0" is correct return, anything other are error....
int8_t get_matrix_from_file(matrix_t *a_mat, char *a_file_name);
int8_t remove_substring(char *a_str, const char *a_sub);
int8_t parse_header(uint32_t *a_row, uint32_t *a_col, FILE *a_fp);
int8_t print_matrix(matrix_t a_mat);
int8_t print_inv_matrix(matrix_t a_mat, matrix_t a_inv_mat);
int8_t create_matrix(matrix_t *a_mat, uint32_t a_row, uint32_t a_col);
int8_t create_Identity_matrix(matrix_t *a_mat, uint32_t a_row, uint32_t a_col);
int8_t delete_matrix(matrix_t *a_mat);

int8_t matrix_copy(matrix_t *a_mat_to, matrix_t *a_mat_from);

int8_t matrix_transpose(matrix_t *a_matT, matrix_t *a_mat_in);
int8_t matrix_add(matrix_t *a_matR, matrix_t *a_matA, matrix_t *a_matB);
int8_t matrix_sub(matrix_t *a_matR, matrix_t *a_matA, matrix_t *a_matB); //R = A - B
int8_t matrix_multiplication(matrix_t *a_matR, matrix_t *a_matA, matrix_t *a_matB);
int8_t matrix_const_mul(real_t a_number, matrix_t *a_mat);
int8_t matrix_const_mul_row(real_t a_number, matrix_t *a_mat, uint32_t a_row);
int8_t matrix_const_mul_col(real_t a_number, matrix_t *a_mat, uint32_t a_col);
int8_t matrix_sub_rowX_const_mul_rowY(matrix_t *a_mat, uint32_t a_rowX, uint32_t a_rowY, real_t a_number); //row1 = row1-c*row2; operation inside matrix.
int8_t matrix_sub_colX_const_mul_colY(matrix_t *a_mat, uint32_t a_colX, uint32_t a_colY, real_t a_number); //row1 = row1-c*row2; operation inside matrix.
int8_t sub_matrix_from_matrix(matrix_t *a_matS, matrix_t *a_mat, uint32_t a_row, uint32_t a_col);

int8_t matrix_swap_row(matrix_t *a_mat, uint32_t a_row1, uint32_t a_row2);
int8_t matrix_swap_col(matrix_t *a_mat, uint32_t a_col1, uint32_t a_col2);
//ret: status, a_det: result determinant
int8_t matrix_determinant_by_cofactor(real_t *a_det, matrix_t *a_mat);
int8_t cofactor_matrix(matrix_t *a_mat_out, matrix_t *a_mat_in);
int8_t matrix_inverse_by_cofactor(matrix_t *a_mat_out, matrix_t *a_mat_in);

int8_t matrix_determinant_by_gaussian_elimination(real_t *a_det, matrix_t *a_mat);
int8_t matrix_inverse_by_gaussian_elimination(matrix_t *a_mat_out, matrix_t *a_mat_in);

int8_t pow_minus_one(uint32_t a_number);
int8_t swap_real_num(real_t *a_arg1, real_t *a_arg2);


/* declarations */

#ifdef __cplusplus
}
#endif

#endif /* MATRIXLIB_MATRIX_H */


