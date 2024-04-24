#include <stdio.h>
#include "tstring.hpp"

int main() {

    TString str( "Halo dies ist dies das dies" );
    str.replace( "dies", "TESTAWDUWU" );
    
    printf( "%s\n", str.ascii() );

    return 0;
}
