#include <stdio.h>
#include <mmatrix.hpp>

void printMatrix( MMatrix * p_matrix ) {

    printf( "Matrix %p:\n", p_matrix );

    for ( int i = 0; i < p_matrix->countFields(); i++ ) {
        printf( "%f, ", p_matrix->getValue( i ) );

        // Line break for new row
        if ( (i + 1) % p_matrix->countCols() == 0 ) printf( "\n" ); 
    }

    printf( "\n" );

}


int main() {

    float position[3] = {
        5,
        2, 
        2
    };

    float projection[6] = {
        1, 0, 0,
        0, 1, 0
    };

    MMatrix m_position( position, 3, 1 );
    MMatrix m_projection( projection, 2, 3 );

    MMatrix projected_matrix = m_projection.mult( &m_position );

    printMatrix( &projected_matrix );

    return 0;
}


