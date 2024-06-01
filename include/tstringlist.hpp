#pragma once

#include "tlist.hpp"
#include "tstring.hpp"

#define PRINT_TSTRINGLIST( STR )    printf( "%s\n", STR.join( "," ).ascii() )

class TStringList : public TList {
  
    public:

        /** Deconstructor **/
        ~TStringList( void );

        /** Modification **/
        void append( const TString & str );
        void update( int position, const TString & str );
        void remove( int position );

        /** Utils **/
        TString getValue( int position ) const;
        TString join( const TString & seperator ) const;

        /** Operator **/
        void operator+=( const TString & str );
        TString operator[]( int index );
};
