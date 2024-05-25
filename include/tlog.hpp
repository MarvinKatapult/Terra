#pragma once

typedef struct _IO_FILE FILE;

class TLog {
    
    public:

        enum TLogLevel {
            Debug,
            Warning,
            Error
        };

        enum TLogColor {
            Black,
            Red,
            Green,
            Yellow,
            Blue,
            Purple,
            Cyan,
            White,
            Default
        };

        /** Constructors **/
        TLog( void );
        TLog( TLogLevel log_level, TLogColor log_color = Default );
        TLog( TLogColor log_color );
        TLog( const char * file_path, bool clear_file = true, TLogColor color = Default );

        /** Deconstructor **/
        ~TLog( void );

        /** Utils **/
        bool print( const char * format, ... ); 
        bool print( TLogColor color, const char * format, ... );
        bool print( TLogLevel level, const char * format, ... );

        static bool log( const char * format, ... );
        
    private:

        void resetColor( void );
        void setColorForLogLevel( void );
        void setColor( TLogColor color );

        FILE * myFile;
        TLogLevel myLogLevel;
        TLogColor myLogColor;
};
