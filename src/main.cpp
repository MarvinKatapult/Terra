
#include "tstringlist.hpp"
#include <stdio.h>
#include "tlog.hpp"

int main() {

    TList list;
    int nums[] = { 1, 2, 3, 4, 5, 6 };

    for ( int i = 0; i < 6; i++ ) {
        list.prepend( nums+i );
    }

    list.remove( 3 );
    list.remove( 2 );

    for ( int i = 0; i < list.count(); i++ ) {
        printf( "%d\n", *(int *)list.getValue( i ) );
    }

    return 0;
}
