#include "matrixlib\include\matrix.h"

int main(void)
{
	int l_ret = 0;
	int i,j;
	
    matrix_t l_test = {0};
    real_t l_det = 0;
    matrix_t l_test2 = {0};
    //real_t l_det = 0;
    matrix_t l_test3 = {0};
    matrix_t l_test4 = {0};
    matrix_t l_test5 = {0};
    matrix_t l_test6 = {0};
    matrix_t l_test7 = {0};

real_t evil_10x10_data[10][10] = {
    {1000000001.0000000000L, 1000000000.0000000000L,  999999999.9999999999L,  999999999.9999999998L,  999999999.9999999997L,  999999999.9999999996L,  999999999.9999999995L,  999999999.9999999994L,  999999999.9999999993L,  999999999.9999999992L},
    {1000000000.0000000000L, 1000000001.0000000000L, 1000000000.0000000000L,  999999999.9999999999L,  999999999.9999999998L,  999999999.9999999997L,  999999999.9999999996L,  999999999.9999999995L,  999999999.9999999994L,  999999999.9999999993L},
    {1000000000.0000000000L, 1000000000.0000000000L, 1000000001.0000000000L, 1000000000.0000000000L,  999999999.9999999999L,  999999999.9999999998L,  999999999.9999999997L,  999999999.9999999996L,  999999999.9999999995L,  999999999.9999999994L},
    {1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000001.0000000000L, 1000000000.0000000000L,  999999999.9999999999L,  999999999.9999999998L,  999999999.9999999997L,  999999999.9999999996L,  999999999.9999999995L},
    {1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000001.0000000000L, 1000000000.0000000000L,  999999999.9999999999L,  999999999.9999999998L,  999999999.9999999997L,  999999999.9999999996L},
    {1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000001.0000000000L, 1000000000.0000000000L,  999999999.9999999999L,  999999999.9999999998L,  999999999.9999999997L},
    {1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000001.0000000000L, 1000000000.0000000000L,  999999999.9999999999L,  999999999.9999999998L},
    {1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000001.0000000000L, 1000000000.0000000000L,  999999999.9999999999L},
    {1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000001.0000000000L, 1000000000.0000000000L},
    {1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000000.0000000000L, 1000000001.0000000000L}
};
    //if(0 == get_matrix_from_file(&l_test, "data/test_mat.txt"))
    {
    	printf("real_t: %d\n", sizeof(real_t));
    	printf("sizeof(long double) = %zu\n", sizeof(long double));
		printf("LDBL_MANT_DIG = %d\n", LDBL_MANT_DIG);
		printf("LDBL_DIG      = %d\n", LDBL_DIG);
    	/*
    	
	    //matrix_determinant_by_gaussian_elimination(&l_det, &l_test);
	    //matrix_transpose(&l_test, &l_test);
	    create_matrix(&l_test, 10, 10);
	    for(i = 0; i < 10; i ++)
	    for(j = 0; j < 10; j ++)
	    l_test.m_data[i][j] = evil_10x10_data[i][j];
	    
	    printf("Input\n");
	    print_matrix(l_test);
	    matrix_inverse_by_gaussian_elimination(&l_test2, &l_test);
	    printf("matrix_inverse_by_gaussian_elimination\n");
	    print_matrix(l_test2);
	    printf("A_Inverse x A\n");
	    matrix_multiplication(&l_test3, &l_test2, &l_test);
	    print_matrix(l_test3);
	    //printf("Input Matrix\n");
	    //print_matrix(l_test);
	    //printf("output Matrix\n");
	    //print_matrix(l_test2);
	    //print_matrix(l_test2);
	    //matrix_multiplication(&l_test3, &l_test2, &l_test);
	    //print_matrix(l_test3);
	    //printf("matrix_determinant_by_gaussian_elimination() : %0.9lf\n", (double)l_det);
	    //matrix_determinant_by_cofactor(&l_det, &l_test);
	    //printf("matrix_determinant_by_cofactor() : %0.9lf\n", (double)l_det);
	    //print_matrix(l_test);
	    //matrix_determinant_by_cofactor(&l_det, &l_test);
	    //printf("l_det = %lf\n", (double)l_det);
	    //cofactor_matrix(&l_test2, &l_test);
	    matrix_inverse_by_cofactor(&l_test4, &l_test);
	    printf("matrix_inverse_by_cofactor of the matrix\n");
	    print_matrix(l_test4);
	    printf("A_Inverse x A\n");
	    matrix_multiplication(&l_test5, &l_test4, &l_test);
	    print_matrix(l_test5);
	    
	    //matrix_multiplication(&l_test3, &l_test2, &l_test);
	    //printf("Identity matrix after multiplication- A^-1xA\n");
	    //print_matrix(l_test3);
	    //matrix_multiplication(&l_test4, &l_test, &l_test2);
	    //printf("Identity matrix after multiplication-AxA^-1\n");
	    //print_matrix(l_test4);
	    printf("SUB=GI - CI\n");
	    matrix_sub(&l_test6, &l_test2, &l_test4);
	    print_matrix(l_test6);
	    printf("SUB x A\n");
	    matrix_multiplication(&l_test7, &l_test6, &l_test);
	    print_matrix(l_test7);
	    */
	    
    }
    //sub_matrix_from_matrix(&l_test2, &l_test, 2, 0);
    //print_matrix(l_test2);
    //matrix_const_mul(123.1234, &l_test);
    //print_matrix(l_test);
    //matrix_transpose(&l_test2, &l_test);
    //print_matrix(l_test2);
    
    //matrix_multiplication(&l_test3, &l_test, &l_test2);
    //print_matrix(l_test3);
    
    //l_ret = delete_matrix(&l_test);
    //printf("l_ret1 = %d\n", l_ret);
    
    //l_ret = delete_matrix(&l_test2);
    //printf("l_ret2 = %d\n", l_ret);

    return 0;
}

