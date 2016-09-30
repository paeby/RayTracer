/*
 * Matrix.cpp
 *
 *  Created on: 29 mars 2015
 *      Author: prisca
 */

#include "Matrix.h"
#include <iostream>
#include <string>
using namespace std;

Matrix::Matrix(void) {
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++) {
			if (x == y)
				m[x][y] = 1.0;
			else
				m[x][y] = 0.0;
		}
}

Matrix::Matrix (const Matrix& mat) {
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m[x][y] = mat.m[x][y];
}

Matrix* Matrix::operator= (const Matrix* rhs) {


	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m[x][y] = rhs->m[x][y];

	return (this);
}

Point Matrix::operator* (const Point* p) {

	return (Point(m[0][0]*p->x + m[0][1]*p->y + m[0][2]*p->z + m[0][3],
			m[1][0]*p->x + m[1][1]*p->y + m[1][2]*p->z + m[1][3],
			m[2][0]*p->x + m[2][1]*p->y + m[2][2]*p->z + m[2][3]));
}

Matrix* Matrix::operator* ( Matrix* mat)  {
	Matrix* product = new Matrix();

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++) {
			double sum = 0.0;

			for (int j = 0; j < 4; j++)
				sum += m[x][j] * mat->m[j][y];

			product->m[x][y] = sum;
		}

	return (product);
}

Matrix Matrix::operator/ (const double d) {
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m[x][y] = m[x][y] / d;

	return (*this);
}

void Matrix::set_identity(void) {
    for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++) {
			if (x == y)
				m[x][y] = 1.0;
			else
				m[x][y] = 0.0;
		}
}

Matrix* Matrix::inverse(){
	    // Inversion by Cramer's rule.  Code taken from an Intel publication
	    //
	    double Result[4][4];
	    double tmp[12]; /* temp array for pairs */
	    double src[16]; /* array of transpose source matrix */
	    double det; /* determinant */
	    /* transpose matrix */
	    for (int i = 0; i < 4; i++)
	    {
	        src[i + 0 ] = m[i][0];
	        src[i + 4 ] = m[i][1];
	        src[i + 8 ] = m[i][2];
	        src[i + 12] = m[i][3];
	    }
	    /* calculate pairs for first 8 elements (cofactors) */
	    tmp[0] = src[10] * src[15];
	    tmp[1] = src[11] * src[14];
	    tmp[2] = src[9] * src[15];
	    tmp[3] = src[11] * src[13];
	    tmp[4] = src[9] * src[14];
	    tmp[5] = src[10] * src[13];
	    tmp[6] = src[8] * src[15];
	    tmp[7] = src[11] * src[12];
	    tmp[8] = src[8] * src[14];
	    tmp[9] = src[10] * src[12];
	    tmp[10] = src[8] * src[13];
	    tmp[11] = src[9] * src[12];
	    /* calculate first 8 elements (cofactors) */
	    Result[0][0] = tmp[0]*src[5] + tmp[3]*src[6] + tmp[4]*src[7];
	    Result[0][0] -= tmp[1]*src[5] + tmp[2]*src[6] + tmp[5]*src[7];
	    Result[0][1] = tmp[1]*src[4] + tmp[6]*src[6] + tmp[9]*src[7];
	    Result[0][1] -= tmp[0]*src[4] + tmp[7]*src[6] + tmp[8]*src[7];
	    Result[0][2] = tmp[2]*src[4] + tmp[7]*src[5] + tmp[10]*src[7];
	    Result[0][2] -= tmp[3]*src[4] + tmp[6]*src[5] + tmp[11]*src[7];
	    Result[0][3] = tmp[5]*src[4] + tmp[8]*src[5] + tmp[11]*src[6];
	    Result[0][3] -= tmp[4]*src[4] + tmp[9]*src[5] + tmp[10]*src[6];
	    Result[1][0] = tmp[1]*src[1] + tmp[2]*src[2] + tmp[5]*src[3];
	    Result[1][0] -= tmp[0]*src[1] + tmp[3]*src[2] + tmp[4]*src[3];
	    Result[1][1] = tmp[0]*src[0] + tmp[7]*src[2] + tmp[8]*src[3];
	    Result[1][1] -= tmp[1]*src[0] + tmp[6]*src[2] + tmp[9]*src[3];
	    Result[1][2] = tmp[3]*src[0] + tmp[6]*src[1] + tmp[11]*src[3];
	    Result[1][2] -= tmp[2]*src[0] + tmp[7]*src[1] + tmp[10]*src[3];
	    Result[1][3] = tmp[4]*src[0] + tmp[9]*src[1] + tmp[10]*src[2];
	    Result[1][3] -= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];
	    /* calculate pairs for second 8 elements (cofactors) */
	    tmp[0] = src[2]*src[7];
	    tmp[1] = src[3]*src[6];
	    tmp[2] = src[1]*src[7];
	    tmp[3] = src[3]*src[5];
	    tmp[4] = src[1]*src[6];
	    tmp[5] = src[2]*src[5];

	    tmp[6] = src[0]*src[7];
	    tmp[7] = src[3]*src[4];
	    tmp[8] = src[0]*src[6];
	    tmp[9] = src[2]*src[4];
	    tmp[10] = src[0]*src[5];
	    tmp[11] = src[1]*src[4];
	    /* calculate second 8 elements (cofactors) */
	    Result[2][0] = tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
	    Result[2][0] -= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
	    Result[2][1] = tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
	    Result[2][1] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
	    Result[2][2] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
	    Result[2][2] -= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
	    Result[2][3] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
	    Result[2][3] -= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
	    Result[3][0] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
	    Result[3][0] -= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
	    Result[3][1] = tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
	    Result[3][1] -= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
	    Result[3][2] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
	    Result[3][2] -= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
	    Result[3][3] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
	    Result[3][3] -= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];
	    /* calculate determinant */
	    det=src[0]*Result[0][0]+src[1]*Result[0][1]+src[2]*Result[0][2]+src[3]*Result[0][3];
	    /* calculate matrix inverse */
	    det = 1.0f / det;

	    Matrix* finalResult = new Matrix();
	    for (int i = 0; i < 4; i++)
	    {
	        for (int j = 0; j < 4; j++)
	        {
	            finalResult->m[i][j] = double(Result[i][j] * det);
	        }
	    }
	    return finalResult;
}

Vector3D Matrix::operator* (const Vector3D* p){
	return (Vector3D(m[0][0]*p->x + m[0][1]*p->y + m[0][2]*p->z,
				m[1][0]*p->x + m[1][1]*p->y + m[1][2]*p->z,
				m[2][0]*p->x + m[2][1]*p->y + m[2][2]*p->z));
}

Normal Matrix::operator* (const Normal* p){
	Normal n(m[0][0]*p->x + m[0][1]*p->y + m[0][2]*p->z,
			m[1][0]*p->x + m[1][1]*p->y + m[1][2]*p->z,
			m[2][0]*p->x + m[2][1]*p->y + m[2][2]*p->z);
	n.normalize();
	return n;
}
