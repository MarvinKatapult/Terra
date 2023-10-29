#include <stdio.h>
#include <mmatrix.hpp>
#include <math.h>

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

    float angle = 0;

    float position[3] = {
        5,
        2, 
        2
    };

    float projection[6] = {
        1, 0, 0,
        0, 1, 0
    };


    
    for ( int i = 0; i < 10; i++ ) {
        float rotationX[9] = {
            1, 0, 0,
            sin( angle ), cos( angle ), 0,
            -cos( angle ), 0, sin( angle )
        };

        MMatrix start( position, 3, 1 );

        MMatrix m_rotation( rotationX, 3, 3 );

        printMatrix( &m_rotation );

        MMatrix m_projection( projection, 2, 3 );

        MMatrix new_position = m_rotation.mult( &start );
        MMatrix projected = m_projection.mult( &new_position );

        printMatrix( &projected );

        angle += 1;
        
    }
    

    return 0;
}

