#pragma once

class TString {

    public:

        /** Constructors **/
        TString( void );
        TString( const char * str );
        TString( const unsigned char * str );
        TString( char character );
        TString( int number );
        TString( long number );
        TString( const TString & str );

        /** Deconstructor **/
        ~TString( void );

        /** Modification **/
        void append( const TString & str );
        void prepend( const TString & str );
        TString remove( const TString & str, bool only_first = false );
        void insert( int position, const TString & str );
        void replace( const TString & r_str, const TString & d_str );
        void clear( void );

        /** Utils **/
        const char * ascii( void ) const;
        int toInt( void ) const;
        int length( void ) const;
        TString toLower( void ) const;
        TString toUpper( void ) const;
        bool contains( const TString & str ) const;
        int find( const TString & str ) const; // -1 if not found
        int find( int position, const TString & str ) const; // -1 if not found
        char character( int position ) const;
        char * buffer( void ) const { return myBuffer; }

        /** Operator **/
        void operator+=( const TString & str );
        TString operator+( const TString & str );
        void operator=( const TString & str );
        bool operator==( const TString & str ) const;
        char operator[]( int index ) const;

    private:

        void copyCString( const char * c_string );
        void copyUnsignedCString( const unsigned char * c_string );
        void initializeBuffer( void );
        char * convertNumberToString( long number );

        char * myBuffer;
};
