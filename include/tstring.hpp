#pragma once

class TString {

    public:

        /** Constructors **/
        TString( const char * str );
        TString( int number );
        TString( const TString & str );

        /** Deconstructor **/
        ~TString( void );

        /** Modification **/
        void append( const TString & str );

        const char * ascii( void ) const;
        int toInt( void ) const;
        int length( void ) const;
        char * buffer( void ) const { return myBuffer; }

    private:

        void copyCString( const char * c_string );

        char * myBuffer;

};
