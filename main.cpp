#include <iostream>
#include "iterators.h"



int main()
{

	std::cout<<"Hello world!"<<std::endl;
	Iterator<int> first_test;
	std::vector<std::vector<int> > my_vec(3,std::vector<int>(3));
	my_vec={{1,3,0},
			{2,2,4},
			{5,-5,7}};

	std::cout<<my_vec.size()<<" "<<my_vec[0].size()<<my_vec[1].size()<<my_vec[2].size()<<std::endl;
	
	first_test.set_BaseMatrix(my_vec);


	std::cout<<"A base matrixa... :"<<std::endl;
	first_test.get_BaseMatrix();
	try{
	std::cout<<"A determinans erteke: "<<first_test.calculate_Determinant()<<std::endl;
}catch(notNxNMatrix& e)
{
	std::cout<<e.what()<<std::endl;
}

	return 0;
	}