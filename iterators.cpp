#include "iterators.h"





void Iterator::set_BaseMatrix(matrix<base_type>& parameter_matrix)
{
	base_matrix_=&parameter_matrix;
}


int Iterator::calculate_Determinant(matrix<base_type>& parameter_matrix=base_matrix_)
{
	int determinant=0;
	int matrix_size=0;

	//We can only calculate determinant of NxN matrixes, we raise exception if the parameter is not an NxN matrix
	for(auto& curr_row : parameter_matrix)
		if(curr_row.size()!=parameter_matrix.size())
			throw notNxNMatrice(parameter_matrix);

	matrix_size=parameter_matrix.size();

	//the atom of determinant calculating (2x2), we can calculate it directly:
	if(matrix_size==2) 
	{
		determinant=parameter_matrix[0][0]*parameter_matrix[1][1]-parameter_matrix[0][1]*parameter_matrix[1][0];
		return determinant;
	}

	//HINT: Later we could optimalize this calculating by using multy threads to calculate each subdeterminant...

	for(int column=0;column<matrix_size;column++)
	{

		//This section we build up the sub_matrix in order to calculate the subdeterminants
		matrix<base_type> sub_matrix;
		for(int sub_row=0;sub_row<matrix_size;sub_row++)
		{
			std::vector<base_type> temp_row;
			for(int sub_column;sub_column<matrix_size;sub_column++)
			{
				if(sub_row!=0 && column!=i)
					temp_row.push_back(parameter_matrix[sub_row][sub_column]);
			}
			sub_matrix.push_back(temp_row);
		}


		//we are using this method recursively to calculate the sub determinants
		determinant+=this->calculate_Determinant(sub_matrix);

		if(i%2==0)
			determinant+=(-parameter_matrix[0][column])*determinant;
		else
			determinant+=parameter_matrix[0][column]*determinant;

	}

	return determinant;
}