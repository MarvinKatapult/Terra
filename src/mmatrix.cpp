#include <mmatrix.hpp>
#include <stdio.h>

MMatrix::MMatrix( float * p_layout, int p_rows, int p_cols ) {

	// Set attributes
	myNumRows = p_rows;
	myNumCols = p_cols;
	myNumFields = myNumRows * myNumCols;

	myFields = new float[myNumFields];

	for ( int i = 0; i < myNumFields; i++ ) {
		myFields[i] = p_layout[i];
	}

}

float MMatrix::getValue( int p_position ) {
	return myFields[p_position];
}

float MMatrix::getValue( int p_x, int p_y ) {
	return myFields[p_x + p_y * myNumCols];
}

void MMatrix::mult( float p_scalar ) {
	for ( int i = 0; i < myNumFields; i++ ) {
		myFields[i] *= p_scalar;
	}
}

MMatrix MMatrix::mult( MMatrix * p_matrix ) {

    float * new_layout = new float[myNumRows * p_matrix->countCols()];

    // Perform Matrix multiplication
    for (int i = 0; i < myNumRows; i++) {
        for (int j = 0; j < p_matrix->countCols(); j++) {
			float new_field = 0;

            for (int k = 0; k < p_matrix->countRows(); k++) {
                new_field += this->getValue( i, k ) * p_matrix->getValue( k, j );
            }

			new_layout[j + i * p_matrix->countCols()] = new_field;

        }

    }

	MMatrix new_matrix( new_layout, myNumRows, p_matrix->countCols() );

	delete[] new_layout;

	return new_matrix;

}

int MMatrix::countRows() {
	return myNumRows;
}

int MMatrix::countCols() {
	return myNumCols;
}

int MMatrix::countFields() {
	return myNumFields;
}

MMatrix::~MMatrix() {

	delete[] myFields;

}
