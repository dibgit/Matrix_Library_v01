#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define abs(x) ((x) < 0? -(x):(x))
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

int main(void)
{
	int l_ret = 0;
	int i;
	
    matrix_t l_test = {0};
    real_t l_det = 0;
    matrix_t l_test2 = {0};
    //real_t l_det = 0;
    matrix_t l_test3 = {0};
    matrix_t l_test4 = {0};
    matrix_t l_test5 = {0};
    matrix_t l_test6 = {0};
    matrix_t l_test7 = {0};

    if(0 == get_matrix_from_file(&l_test, "data/test_mat.txt"))
    {
    	
	    //matrix_determinant_by_gaussian_elimination(&l_det, &l_test);
	    //matrix_transpose(&l_test, &l_test);
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

int8_t matrix_inverse_by_gaussian_elimination(matrix_t *a_mat_out, matrix_t *a_mat_in)
{
	int8_t	l_ret = 0;
	int8_t	l_steps = 0;
	uint32_t i, j, k;
	uint32_t l_first = 0;
	uint32_t  l_swap = 0;
	
	real_t l_limit = LIMIT_TO_ZERO;
	real_t l_factor = 0;
	real_t l_diag_val = 0;
	
	matrix_t l_mat_inv = {0};

	if(NULL != a_mat_in->m_data && 0 != a_mat_in->m_row && 0 != a_mat_in->m_col && NULL != a_mat_out)
	{
		if(a_mat_in->m_row <= 2)//2 or 1
		{
			matrix_inverse_by_cofactor(a_mat_out, a_mat_in);
		}
		else // > 2
		{
			matrix_copy(&l_mat_inv, a_mat_in);
			create_Identity_matrix(a_mat_out, a_mat_in->m_row, a_mat_in->m_col);
			//printf("Start:\n");
			//print_inv_matrix(l_mat_inv, *a_mat_out);
			//for(l_steps = 0; l_steps < 2; l_steps ++)
			//{
				for(i = 0; i < l_mat_inv.m_row - 1; i ++) //NxN
				{
					l_first = i;
					for(j = i + 1; j < l_mat_inv.m_row; j ++) //start from 2nd row
					{
						if(abs(l_mat_inv.m_data[j][i]) > abs(l_mat_inv.m_data[i][i]))
						{
							l_first = j;
						}
				    }
					//max found
					if(abs(l_mat_inv.m_data[l_first][i]) < l_limit)
					{
						//*a_det = 0; //all element from the column is zero
						delete_matrix(&l_mat_inv);
						delete_matrix(a_mat_out);
						return 0;
					}
					else if( i != l_first)
				    {
				    	l_swap ++;
				    	matrix_swap_row(&l_mat_inv, i, l_first);
				    	matrix_swap_row(a_mat_out, i, l_first);
					}
					
					//printf("1 st print\n");
					//print_matrix(l_mat_inv);
					
					for(j = i + 1; j < l_mat_inv.m_row; j ++)//l_mat_det->m_row == l_mat_det->m_col
					{
						l_factor = l_mat_inv.m_data[j][i]/l_mat_inv.m_data[i][i];
						for(k = i; k < l_mat_inv.m_col; k ++)
						{
							l_mat_inv.m_data[j][k] = l_mat_inv.m_data[j][k] - l_factor*l_mat_inv.m_data[i][k];
						}
						for(k = 0; k < l_mat_inv.m_col; k ++)
						{
							a_mat_out->m_data[j][k] = a_mat_out->m_data[j][k] - l_factor*a_mat_out->m_data[i][k];
						}
					}
				}
				//printf("After 1st pass\n");
				//print_inv_matrix(l_mat_inv, *a_mat_out);
				//matrix_transpose(&l_mat_inv, &l_mat_inv);
				//printf("after transpose\n");
				//print_matrix(l_mat_inv);
			//}
			// ========================================================
			//PHASE 2: Backward Substitution (Turns diagonal to 1s)
			// ========================================================
			i = l_mat_inv.m_row;
			while(i > 0)
			//for (i = l_mat_inv.m_row; i > 0; i--)
			{
				uint32_t current_row = i - 1;
				//printf("current_row = %u\n", current_row);
				// Check final diagonal elements for zero
                if (abs(l_mat_inv.m_data[current_row][current_row]) < l_limit) {
                    delete_matrix(&l_mat_inv);
                    delete_matrix(a_mat_out);
                    return 0;
                }
                j = current_row;
                while(j > 0)
                //for (j = current_row; j > 0; j--)
                {
                	uint32_t target_row = j - 1;
                	//printf("target_row = %u\n", target_row);
                	l_factor = l_mat_inv.m_data[target_row][current_row] / l_mat_inv.m_data[current_row][current_row];
                	//printf("l_factor = %14.9lf\n", (double)l_factor);
                	for (k = target_row; k < l_mat_inv.m_col; k++)
					{
						l_mat_inv.m_data[target_row][k] -= l_factor * l_mat_inv.m_data[current_row][k];
					}
                	for (k = 0; k < a_mat_out->m_col; k++)
                    {
                        a_mat_out->m_data[target_row][k] -= l_factor * a_mat_out->m_data[current_row][k];
                    }
                    j--;
				}
				//printf("IIII = %u\n", i);
				//print_inv_matrix(l_mat_inv, *a_mat_out);
				// Normalize current row diagonal element to 1

                l_diag_val = l_mat_inv.m_data[current_row][current_row];
                //printf("l_diag_val = %14.9lf\n", (double)l_diag_val);
                // Normalize l_mat_inv row
				//for (k = current_row; k < l_mat_inv.m_col; k++) //Why??
				//{
				//	l_mat_inv.m_data[current_row][current_row] /= l_diag_val; //and why it is at all needed; removing anyway
				//}

                for (k = 0; k < a_mat_out->m_col; k++)
                {
                    a_mat_out->m_data[current_row][k] /= l_diag_val;
                }
                //printf("After Normalize: %u\n", i);
                //print_inv_matrix(l_mat_inv, *a_mat_out);
                i --;
			}
		}
		delete_matrix(&l_mat_inv);
		l_ret = 1; // Mark success
    }
    return l_ret;
}
int8_t create_Identity_matrix(matrix_t *a_mat, uint32_t a_row, uint32_t a_col)
{
	uint32_t l_index = 0;
	uint32_t l_min = a_row;
	if(l_min > a_col)
	{
		l_min = a_col;
	}
	
	create_matrix(a_mat, a_row, a_col);
	for(l_index = 0; l_index < l_min; l_index ++)
	{
		a_mat->m_data[l_index][l_index]= 1.0;
	}
	return 0;
}
int8_t matrix_determinant_by_gaussian_elimination(real_t *a_det, matrix_t *a_mat)
{
	int8_t	l_ret = 0;
	uint32_t i, j, k;
	uint32_t l_first = 0;
	uint32_t  l_swap = 0;
	
	real_t l_limit = LIMIT_TO_ZERO;
	real_t l_factor = 0;
	
	matrix_t l_mat_det = {0};

	*a_det = 0;
	if(NULL != a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col && NULL != a_det)
	{
		if(a_mat->m_row <= 2)//2 or 1
		{
			matrix_determinant_by_cofactor(a_det, a_mat);
		}
		else // > 2
		{
			matrix_copy(&l_mat_det, a_mat);
			for(i = 0; i < l_mat_det.m_row - 1; i ++) //NxN
			{
				l_first = i;
				for(j = i + 1; j < l_mat_det.m_row; j ++) //start from 2nd row
				{
					if(abs(l_mat_det.m_data[j][i]) > abs(l_mat_det.m_data[i][i]))
					{
						l_first = j;
					}
			    }
				//max found
				if(abs(l_mat_det.m_data[l_first][i]) < l_limit)
				{
					*a_det = 0; //all element from the column is zero
					return 0;
				}
				else if( i != l_first)
			    {
			    	l_swap ++;
			    	matrix_swap_row(&l_mat_det, i, l_first);
				}
				//print_matrix(*l_mat_det);
				
				for(j = i + 1; j < l_mat_det.m_row; j ++)//l_mat_det->m_row == l_mat_det->m_col
				{
					l_factor = l_mat_det.m_data[j][i]/l_mat_det.m_data[i][i];
					for(k = i; k < l_mat_det.m_col; k ++)
					{
						l_mat_det.m_data[j][k] = l_mat_det.m_data[j][k] - l_factor*l_mat_det.m_data[i][k];
					}
				}
				//print_matrix(*l_mat_det);
			}
			*a_det = 1;
			for(i = 0; i < l_mat_det.m_row; i ++)
				*a_det *= l_mat_det.m_data[i][i];
			*a_det *= pow_minus_one(l_swap);
			
			delete_matrix(&l_mat_det);
		}	
    }
    return l_ret;
}

int8_t matrix_swap_row(matrix_t *a_mat, uint32_t a_row1, uint32_t a_row2)
{
	int8_t l_ret = 0;
	uint32_t i = 0;

	if(NULL != a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col && a_row1 < a_mat->m_row && a_row2 < a_mat->m_row && a_row1 != a_row2)
	{
		for(i = 0; i < a_mat->m_col; i ++)
		{
			swap_real_num(&a_mat->m_data[a_row1][i], &a_mat->m_data[a_row2][i]);
		}
	}
	else
	{
		printf("check input matrices, either empty or parameter mismatch\n");
		l_ret = -5;
	}
	
	return l_ret;
}
int8_t matrix_swap_col(matrix_t *a_mat, uint32_t a_col1, uint32_t a_col2)
{
	int8_t l_ret = 0;
	uint32_t i = 0;
	if(NULL != a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col && a_col1 < a_mat->m_col && a_col2 < a_mat->m_col && a_col1 != a_col2)
	{
		for(i = 0; i < a_mat->m_row; i ++)
		{
			swap_real_num(&a_mat->m_data[i][a_col1], &a_mat->m_data[i][a_col2]);
		}
	}
	else
	{
		printf("check input matrices, either empty or parameter mismatch\n");
		l_ret = -5;
	}
	return l_ret;
}

int8_t matrix_inverse_by_cofactor(matrix_t *a_mat_out, matrix_t *a_mat_in)
{
	int8_t l_ret = 0;
	if(NULL != a_mat_in->m_data && 0 != a_mat_in->m_row && 0 != a_mat_in->m_col)
	{
		if(a_mat_in->m_row == a_mat_in->m_col)
		{
			real_t l_det = 0;
			real_t l_limit = LIMIT_TO_ZERO;
			l_ret = matrix_determinant_by_cofactor(&l_det, a_mat_in);
			//printf("determinant = %lf\n", (double)l_det);
			if(l_limit <= abs(l_det)) //Convince for a limit
			{
				real_t l_temp = 1/l_det;
				matrix_t l_matT = {0};
				cofactor_matrix(&l_matT, a_mat_in);
				//printf("cofactor_matrix\n");
				//print_matrix(l_matT);
				matrix_transpose(a_mat_out, &l_matT);
				//printf("matrix_transpose\n");
				//print_matrix(*a_mat_out);
				delete_matrix(&l_matT);
				
				matrix_const_mul(l_temp, a_mat_out);
			}
		}
		else
		{
			printf("check input matrices, dimension mismatch\n");
			l_ret = 1;
		}
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}
int8_t cofactor_matrix(matrix_t *a_mat_out, matrix_t *a_mat_in)
{
	int8_t l_ret = 0;
	if(NULL != a_mat_in->m_data && 0 != a_mat_in->m_row && 0 != a_mat_in->m_col)
	{
		if(a_mat_in->m_row == a_mat_in->m_col)
		{
			create_matrix(a_mat_out, a_mat_in->m_row, a_mat_in->m_col);
			if(1 == a_mat_in->m_row)
			{
				a_mat_out->m_data[0][0] = a_mat_in->m_data[0][0];
			}
			else if(2 == a_mat_in->m_row)
			{
				a_mat_out->m_data[0][0] = a_mat_in->m_data[1][1];
				a_mat_out->m_data[0][1] = -a_mat_in->m_data[1][0];
				a_mat_out->m_data[1][0] = -a_mat_in->m_data[0][1];
				a_mat_out->m_data[1][1] = a_mat_in->m_data[0][0];
			}
			else
			{
				uint32_t i = 0, j = 0;
				real_t l_det = 0;
				for(i = 0; i < a_mat_out->m_row; i ++)
					for(j = 0; j < a_mat_out->m_col; j ++)
					{
						matrix_t l_temp_mat = {0};
						a_mat_out->m_data[i][j] = 0;
						sub_matrix_from_matrix(&l_temp_mat, a_mat_in, i, j);
						//print_matrix(l_temp_mat);
						matrix_determinant_by_cofactor(&l_det, &l_temp_mat);
						delete_matrix(&l_temp_mat);
						//printf("l_det:= %lf\n", (double)l_det);
						a_mat_out->m_data[i][j] = pow_minus_one(i + j) * l_det;
					}
			}
		}
		else
		{
			printf("check input matrices, dimension mismatch\n");
			l_ret = 1;
		}
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}
//ret: status, a_det: result determinant
int8_t matrix_determinant_by_cofactor(real_t *a_det, matrix_t *a_mat)
{
	int8_t l_ret = 0;
	uint32_t i;

	*a_det = 0;
	
	if(NULL != a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col && NULL != a_det)
	{
		if(a_mat->m_row == a_mat->m_col)
		{
			if(1 == a_mat->m_row)
			{
				*a_det = a_mat->m_data[0][0];
			}
			else if(2 == a_mat->m_row)
			{
				*a_det = a_mat->m_data[0][0]*a_mat->m_data[1][1] - a_mat->m_data[1][0]*a_mat->m_data[0][1];
			}
			else //3 and higher
			{
				for(i = 0; i < a_mat->m_col; i ++)
				{
					matrix_t l_sub_mat = {0};
					real_t l_det = 0;
					
					sub_matrix_from_matrix(&l_sub_mat, a_mat, 0, i);
					//print_matrix(l_sub_mat);
					matrix_determinant_by_cofactor(&l_det, &l_sub_mat);
					delete_matrix(&l_sub_mat);
					if(0 != a_mat->m_data[0][i])
						*a_det += pow_minus_one(i)*a_mat->m_data[0][i] * l_det;
					//printf("*a_det = %lf\n", (double)*a_det);
				}
			}
		}
		else
		{
			printf("check input matrices, dimension mismatch\n");
			l_ret = 1;
		}
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}
int8_t sub_matrix_from_matrix(matrix_t *a_matS, matrix_t *a_mat, uint32_t a_row, uint32_t a_col)
{
	int8_t l_ret = 0;
	uint32_t i = 0, j = 0 , i2 = 0, j2 = 0;
	if(NULL != a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col && a_row < a_mat->m_row && a_col < a_mat->m_col)
	{
		create_matrix(a_matS, a_mat->m_row - 1, a_mat->m_col - 1);
		for(i2 = i = 0; i < a_mat->m_row; i ++)
		{
			if(i == a_row)
			{
				 i ++;
				 if(i >= a_mat->m_row) break;
			}
			
		    for(j2 = j = 0; j < a_mat->m_col; j ++)
		    {
		    	if(j == a_col)
				{
					 j ++;
					 if(j >= a_mat->m_col) break;
				}

			    a_matS->m_data[i2][j2] = a_mat->m_data[i][j];
			    j2 ++;
		    }
		    i2 ++;
		}
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}
int8_t matrix_sub_rowX_const_mul_rowY(matrix_t *a_mat, uint32_t a_rowX, uint32_t a_rowY, real_t a_number)
{
	//rowX = rowX-c*rowY; operation inside matrix.
	int8_t l_ret = 0;
	uint32_t i;
	if(NULL != a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col && a_rowX < a_mat->m_row && a_rowY < a_mat->m_row)
	{
		for(i = 0; i < a_mat->m_col; i ++)
			a_mat->m_data[a_rowX][i] = a_mat->m_data[a_rowX][i] - (a_number*a_mat->m_data[a_rowY][i]);
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}
int8_t matrix_sub_colX_const_mul_colY(matrix_t *a_mat, uint32_t a_colX, uint32_t a_colY, real_t a_number)
{
	//colX = colX-c*colY; operation inside matrix.
	int8_t l_ret = 0;
	uint32_t i;
	if(NULL != a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col && a_colX < a_mat->m_col && a_colY < a_mat->m_col)
	{
		for(i = 0; i < a_mat->m_row; i ++)
			a_mat->m_data[i][a_colX] = a_mat->m_data[i][a_colX] - (a_number*a_mat->m_data[i][a_colY]);
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}

int8_t matrix_const_mul_col(real_t a_number, matrix_t *a_mat, uint32_t a_col)
{
	int8_t l_ret = 0;
	uint32_t i;
	if(NULL != a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col && a_col < a_mat->m_col)
	{
		for(i = 0; i < a_mat->m_row; i ++)
			a_mat->m_data[i][a_col] = a_number*a_mat->m_data[i][a_col];
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}
int8_t matrix_const_mul_row(real_t a_number, matrix_t *a_mat, uint32_t a_row)
{
	int8_t l_ret = 0;
	uint32_t i;
	if(NULL != a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col && a_row < a_mat->m_row)
	{
		for(i = 0; i < a_mat->m_col; i ++)
			a_mat->m_data[a_row][i] = a_number*a_mat->m_data[a_row][i];
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}
int8_t matrix_const_mul(real_t a_number, matrix_t *a_mat)
{
	int8_t l_ret = 0;
	uint32_t i, j;
	if(NULL != a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col)
	{
		for(i = 0; i < a_mat->m_row; i ++)
			    for(j = 0; j < a_mat->m_col; j ++)
			    	a_mat->m_data[i][j] = a_number*a_mat->m_data[i][j];
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}
int8_t matrix_multiplication(matrix_t *a_matR, matrix_t *a_matA, matrix_t *a_matB) //R = A x B
{
	int8_t l_ret = 0;
	uint32_t i, j, k;
	if(NULL != a_matA->m_data && 0 != a_matA->m_row && 0 != a_matA->m_col && NULL != a_matB->m_data && 0 != a_matB->m_row && 0 != a_matB->m_col)
	{
		if(a_matA->m_col == a_matB->m_row)
		{
			create_matrix(a_matR, a_matA->m_row, a_matB->m_col);
			for(i = 0; i < a_matR->m_row; i ++)
			    for(j = 0; j < a_matR->m_col; j ++)
			    {
			    	a_matR->m_data[i][j] = 0;
			    	for(k = 0; k < a_matA->m_col; k ++)
			    	{
			    		a_matR->m_data[i][j] += a_matA->m_data[i][k]*a_matB->m_data[k][j];
					}
				}
		}
		else
		{
			printf("check input matrices, dimension mismatch\n");
			l_ret = 1;
		}
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}
int8_t matrix_sub(matrix_t *a_matR, matrix_t *a_matA, matrix_t *a_matB) //R = A - B
{
	int8_t l_ret = 0;
	uint32_t i,j;
	
	if(NULL != a_matA->m_data && 0 != a_matA->m_row && 0 != a_matA->m_col && NULL != a_matB->m_data && 0 != a_matB->m_row && 0 != a_matB->m_col)
	{
		if(a_matA->m_row == a_matB->m_row && a_matA->m_col == a_matB->m_col)
		{
			create_matrix(a_matR, a_matA->m_row, a_matA->m_col);
			for(i = 0; i < a_matA->m_row; i ++)
				for(j = 0; j < a_matA->m_col; j ++)
					a_matR->m_data[i][j] = a_matA->m_data[i][j] - a_matB->m_data[i][j];
		}
		else
		{
			printf("check input matrices, dimension mismatch\n");
			l_ret = 1;
		}
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}

int8_t matrix_add(matrix_t *a_matR, matrix_t *a_matA, matrix_t *a_matB)
{
	int8_t l_ret = 0;
	uint32_t i,j;
	
	if(NULL != a_matA->m_data && 0 != a_matA->m_row && 0 != a_matA->m_col && NULL != a_matB->m_data && 0 != a_matB->m_row && 0 != a_matB->m_col)
	{
		if(a_matA->m_row == a_matB->m_row && a_matA->m_col == a_matB->m_col)
		{
			create_matrix(a_matR, a_matA->m_row, a_matA->m_col);
			for(i = 0; i < a_matA->m_row; i ++)
				for(j = 0; j < a_matA->m_col; j ++)
					a_matR->m_data[i][j] = a_matA->m_data[i][j] + a_matB->m_data[i][j];
		}
		else
		{
			printf("check input matrices, dimension mismatch\n");
			l_ret = 1;
		}
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}

int8_t matrix_copy(matrix_t *a_mat_to, matrix_t *a_mat_from)
{
	int8_t l_ret = 0;
	uint32_t i,j;
	if(NULL != a_mat_from->m_data && 0 != a_mat_from->m_row && 0 != a_mat_from->m_col)
	{
		create_matrix(a_mat_to, a_mat_from->m_row, a_mat_from->m_col);
		for(i = 0; i < a_mat_from->m_row; i ++)
				for(j = 0; j < a_mat_from->m_col; j ++)
					a_mat_to->m_data[i][j] = a_mat_from->m_data[i][j];
	}
	else
	{
		printf("check input matrices, either empty or not\n");
		l_ret = -5;
	}
	return l_ret;
}

int8_t print_matrix(matrix_t a_mat)
{
	uint32_t i, j;
	double l_temp = 0;
	
	printf("dim:%ux%u\n",a_mat.m_row, a_mat.m_col);
	
	for(i = 0; i < a_mat.m_row; i ++ )
	{
		for(j = 0; j < a_mat.m_col; j ++)
		{
			l_temp = a_mat.m_data[i][j];
			printf("%14.9lf    ", l_temp);
		}
		printf("\n");
	}
	
	return 0;
}

int8_t print_inv_matrix(matrix_t a_mat, matrix_t a_inv_mat)
{
	uint32_t i, j;
	double l_temp = 0;
	
	printf("dim:%ux%u\n",a_mat.m_row, a_mat.m_col);
	
	for(i = 0; i < a_mat.m_row; i ++ )
	{
		for(j = 0; j < a_mat.m_col; j ++)
		{
			l_temp = a_mat.m_data[i][j];
			printf("%14.9lf    ", l_temp);
		}
		printf("|");
		for(j = 0; j < a_inv_mat.m_col; j ++)
		{
			l_temp = a_inv_mat.m_data[i][j];
			printf("%14.9lf    ", l_temp);
		}
		printf("\n");
	}
	
	return 0;
}

int8_t matrix_transpose(matrix_t *a_matT, matrix_t *a_mat_in)
{
	int8_t l_ret = 0;
	uint32_t l_ri, l_cj;
	
	if(NULL != a_matT && NULL != a_mat_in && NULL!= a_mat_in->m_data && 0 != a_mat_in->m_row && 0 != a_mat_in->m_col)
	{
		if(a_matT != a_mat_in)
		{
			a_matT->m_col = a_mat_in->m_row;
			a_matT->m_row = a_mat_in->m_col;
			l_ret = create_matrix(a_matT, a_matT->m_row, a_matT->m_col);
			for(l_ri = 0; l_ri < a_mat_in->m_row; l_ri ++)
	    	{
	    		for(l_cj = 0; l_cj < a_mat_in->m_col; l_cj ++)
	    		{
	    			a_matT->m_data[l_cj][l_ri] = a_mat_in->m_data[l_ri][l_cj];
	    		}
	    	}
	    	//printf("not equal\n");
	    	//print_matrix(*a_matT);
    	}
    	else if(a_mat_in->m_row == a_mat_in->m_col)
    	{
    		for(l_ri = 0; l_ri < a_mat_in->m_row; l_ri ++)
	    	{
	    		for(l_cj = l_ri + 1; l_cj < a_mat_in->m_col; l_cj ++)
	    		{
	    			swap_real_num(&a_matT->m_data[l_cj][l_ri], &a_mat_in->m_data[l_ri][l_cj]); //same matrix
	    			//printf("a_matT->m_data[l_cj][l_ri] = %lf, a_mat_in->m_data[l_ri][l_cj] = %lf\n", (double)a_matT->m_data[l_cj][l_ri], (double)a_mat_in->m_data[l_ri][l_cj]);
	    		}
	    	}
	    	//printf("equal case\n");
	    	//print_matrix(*a_mat_in);
		}
		else
		{
			return 2;
		}
	}
	else
	{
		l_ret = 1; //but all infra(allocation, etc) && logical row = 0 are consider same....anyway it could be -4 as well
	}
	return l_ret;
}
int8_t delete_matrix(matrix_t *a_mat)
{
	int8_t l_ret = 0;
	uint32_t l_row = 0;
	if(NULL != a_mat && NULL!= a_mat->m_data && 0 != a_mat->m_row && 0 != a_mat->m_col)
	{
		for(l_row = 0; l_row < a_mat->m_row; l_row ++)
		{
			if(NULL != a_mat->m_data[l_row])
			{
				free(a_mat->m_data[l_row]);
			}
			else
			{
				l_ret = -5;
				break;
			}
		}
		free(a_mat->m_data);
		a_mat->m_data = NULL;
		a_mat->m_row = 0;
		a_mat->m_col = 0;
	}
	else
	{
		l_ret = 1; //but all infra(allocation) && logical row = 0 are consider same....anyway it could be -4 as well
	}
	return l_ret;
}
int8_t create_matrix(matrix_t *a_mat, uint32_t a_row, uint32_t a_col)
{
	int8_t l_ret = 0;
	uint32_t l_ri, l_cj;
	
	if(NULL == a_mat->m_data)
	{
		if(!(0 == a_row || 0 == a_col))
		{
			a_mat->m_row = a_row;
			a_mat->m_col = a_col;
		    a_mat->m_data = (real_t **)calloc(a_mat->m_row, sizeof(real_t *)); //error check...later :)
			if(NULL == a_mat->m_data)
			{
				l_ret = -4;
				printf("Mem error: l_ret = %d\n", l_ret);
			}
			else
			{
		    	for(l_ri = 0; l_ri < a_mat->m_row; l_ri ++)
		    	{
		    		a_mat->m_data[l_ri] = (real_t *)calloc(a_mat->m_col, sizeof(real_t));
		    		if(NULL == a_mat->m_data[l_ri])
		    		{
		    			printf("Mem error at, l_ri = %d, l_ret = %d\n", l_ri, l_ret);
		    			l_ret = -5;
		    			break;
					}
				}
			}
	    }
	    else
	    {
	    	l_ret = 1; //logical error are taking +ve side
		}
    }
    else
    {
    	l_ret = -6; //allocation possible. but certain memory leak
	}
	return l_ret;
}

int8_t get_matrix_from_file(matrix_t *a_mat, char *a_file_name)
{
	int8_t l_ret = 0;
	
	uint32_t l_row = 0, l_col = 0;
	uint32_t l_ri, l_cj;

	real_t l_data;
	
    FILE *fp_in = fopen(a_file_name, "rb");
    
    l_ret = parse_header(&l_row, &l_col, fp_in);

    
    if(0 == l_ret)
    {

    	l_ret = create_matrix(a_mat, l_row, l_col);
    	if(0 == l_ret)
    	{
    		double l_temp = 0;
    		
	    	for(l_ri = 0; l_ri < a_mat->m_row; l_ri ++)
	    	{
	    		for(l_cj = 0; l_cj < a_mat->m_col; l_cj ++)
	    		{
	    			if(1 != fscanf(fp_in, "%lf", &l_temp)) {
						printf("error reading matrix\n");
						l_ret = 2;
						break;
					}
	    			//fscanf(fp_in, "%lf", &a_mat->m_data[l_ri][l_cj]);//correct up to double
	    			a_mat->m_data[l_ri][l_cj] = l_temp; // :)
	    			//printf("l_ri = %d, l_cj = %d, l_temp = %Lf \n", l_ri, l_cj, l_temp);
	    			//l_temp = 0;
	    			//l_temp = a_mat->m_data[l_ri][l_cj];
	    			//printf("l_ri = %d, l_cj = %d, a_mat->m_data[l_ri][l_cj] = %Lf \n", l_ri, l_cj, l_temp);
	    			//printf("l_ri = %d, l_cj = %d, a_mat->m_data[l_ri][l_cj] = %lf \n", l_ri, l_cj, a_mat->m_data[l_ri][l_cj]);
				}
				if(2 == l_ret) break;
				//printf("\n");
			}
			//printf("l_ri = %d, l_cj = %d\n", l_ri, l_cj);
			if(2 == l_ret)
			{
				delete_matrix(a_mat);
			}
	    }
	    else
	    {
	    	printf("error\n");
		}
	} 

    fclose(fp_in);

    return l_ret;

}
int8_t remove_substring(char *a_str, const char *a_sub)
{
    int8_t l_ret = 0;
    char *l_match;
    size_t l_len = strlen(a_sub);

    
    if (0 == l_len)
	{
	    l_ret = -1; // Nothing to remove
	}
	else
	{
		// Find the first occurrence of the substring
        l_match = strstr(a_str, a_sub);
        if (l_match != NULL)
	    {
	        // Shift everything after the substring to the left (including '\0')
	        memmove(l_match, l_match + l_len, strlen(l_match + l_len) + 1);
	    }
	    else
	    {
	    	l_ret = -2;
		}
	}

	return l_ret;
}

int8_t parse_header(uint32_t *a_row, uint32_t *a_col, FILE *a_fp)
{
    int8_t l_ret = 0;
    //uint32_t l_row = 0, l_col = 0;
    char l_line[256] ={0};
    //read header
    fgets(l_line, sizeof(l_line), a_fp);

    //printf("%s\n", l_line); //dim:12x3
    l_ret = remove_substring(l_line, "dim:");
    //printf("%s\n", l_line); //dim:12x3
    if(0 == l_ret)
    {
	    if(2 == sscanf(l_line, "%ux%u", a_row, a_col))
	    {
	        //printf("l_row = %d, l_col = %d\n", *a_row, *a_col);
	    }
	    else
	    {
	        printf("can not read\n");
	        l_ret = -3;
	    }
    }

    return l_ret;
}
int8_t pow_minus_one(uint32_t a_number)
{
	return a_number%2 ? -1:1;
}

int8_t swap_real_num(real_t *a_arg1, real_t *a_arg2)
{
	int8_t l_ret = 0;
	if(NULL != a_arg1 && NULL != a_arg2)
	{
		real_t l_temp = (*a_arg1);
		(*a_arg1) = (*a_arg2);
		(*a_arg2) = l_temp;
	}
	else
	{
		l_ret = -1;
	}
	return l_ret;
}
