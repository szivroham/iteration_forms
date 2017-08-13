#ifndef _H_GAUSS_EXP_H
#define _H_GAUSS_EXP_H


#include <exception>
#include <iostream>
#include <cstring>
#include <cstdio>

const int MAX_EXCEPTION_MESSAGE_LEN=512;

class notNxNMatrix : public std::exception
{

public:
	notNxNMatrix (const char* matrix_name)
	{
		strncpy(matrix_name_,matrix_name,MAX_EXCEPTION_MESSAGE_LEN);
		matrix_name_[MAX_EXCEPTION_MESSAGE_LEN-1]='\0';
		snprintf(msgText_,MAX_EXCEPTION_MESSAGE_LEN,"The given Matrix (%s) not an NxN matrix",matrix_name_);
		msgText_[MAX_EXCEPTION_MESSAGE_LEN]='\0';

	}

	const char* what()
	{
		return msgText_;
	}
	const char* getMatrix() { return matrix_name_;}


private:
	char msgText_[MAX_EXCEPTION_MESSAGE_LEN];
	char matrix_name_[MAX_EXCEPTION_MESSAGE_LEN];

};

class ZeroINDiag : public std::exception
{
public:
	ZeroINDiag ()
	{	
		snprintf(msgText_,MAX_EXCEPTION_MESSAGE_LEN,"We found a zero div in the diagonal!");
		msgText_[MAX_EXCEPTION_MESSAGE_LEN]='\0';

	}
	const char* what()
	{
		return msgText_;
	}



private:

	char msgText_[MAX_EXCEPTION_MESSAGE_LEN];
};


#endif //_H_GAUSS_EXP_H