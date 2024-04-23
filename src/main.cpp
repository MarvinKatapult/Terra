#include <stdio.h>
#include "tstring.hpp"

int main() {

    TString str( "Hello" );

    printf( "%c\n", str.character( 1 ) );

    return 0;
}
