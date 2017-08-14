#ifndef ITERATOR_H
#define ITERATOR_H


#include "matrix_exceptions.h"
#include <string>
#include <vector>
#include <iostream>


//for the pow function ...
#include <math.h>

//Using type alias, so we don't have to write that much
template<typename T>
using matrix = std::vector<std::vector<T> >;
//

template<class base_type>
class Iterator
{

	public:
		Iterator(){};
		//It would be great not to copy the whole matrix all the time... So Parameter passed by reference
		void set_BaseMatrix(matrix<base_type>);
		//Not very smart solution, but a solution ...
		int calculate_Determinant(){int result; result=this->calculate_Determinant_(base_matrix); return result;}

		void get_BaseMatrix(){
			for(auto& row : base_matrix)
			{
				for(auto& element : row)
					std::cout<<element<<" ";

				std::cout<<"\n";
			}


		}

	private:
	protected:
		//In order to find out if the vector system is independent (hint: det(A)!=0 then A is independent...)
		int calculate_Determinant_(matrix<base_type>);
		//-bool is_Linear_Independent();
		//we will overload the operator '*' for this
		//matrix<base_type> matrix_multiplication(matrix<base_type>&,matrix<base_type>&);
		matrix<base_type> base_matrix ;

};

template<class base_type>
void Iterator<base_type>::set_BaseMatrix(matrix<base_type> parameter_matrix)
{
	base_matrix=parameter_matrix;
}



template<typename base_type>
int Iterator<base_type>::calculate_Determinant_(matrix<base_type> parameter_matrix)
{
	int determinant=0;
	int matrix_size=0;

	//We can only calculate determinant of NxN matrixes, we raise exception if the parameter is not an NxN matrix
	for(auto& curr_row : parameter_matrix)
	{
		if(curr_row.size()!=parameter_matrix.size())
			throw notNxNMatrix("parameter_matrix");
	}

	matrix_size=parameter_matrix.size();

	//the atom of determinant calculating (2x2), we can calculate it directly:
	if(matrix_size==2) 
	{
		determinant=parameter_matrix[0][0]*parameter_matrix[1][1]-parameter_matrix[0][1]*parameter_matrix[1][0];
		return determinant;
	}

	//HINT: Later we could optimalize this calculating by using multy threads to calculate each subdeterminant...

	matrix<base_type> sub_matrix;
	std::vector<base_type> temp_row;

	for(int column=0;column<matrix_size;column++)
	{
		sub_matrix.clear();

		//This section we build up the sub_matrix in order to calculate the subdeterminants
		

		for(int sub_row=1;sub_row<matrix_size;sub_row++)
		{
			temp_row.clear();
			for(int sub_column=0;sub_column<matrix_size;sub_column++)
			{
				//iam not sure in this line !!!!
				if(sub_row!=0 && column!=sub_column)
					temp_row.push_back(parameter_matrix[sub_row][sub_column]);
			}
			sub_matrix.push_back(temp_row);
		}

		//we are using this method recursively to calculate the sub determinants
		determinant+=pow(-1,column)*parameter_matrix[0][column]*this->calculate_Determinant_(sub_matrix);
	}

	return determinant;
}



#endif /*_ITERATOR_H_*/