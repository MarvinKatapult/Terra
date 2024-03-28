#pragma once

class TListElement {

	public:

	   /**
		* @brief Constructor
		*/
		TListElement( void ) {
			myNext = 0L;
			myPrev = 0L;
		}

	   /**
		* @brief Deconstructor
		*/
		~TListElement( void ) {}

		// Getter and Setter
		void * getValue( void ) { return myValue; }

		void setValue( void * value ) { myValue = value; }

		TListElement * getNext( void ) { return myNext; }
		TListElement * getPrev( void ) { return myPrev; }

		void setNext( TListElement * element ) { myNext = element; }
		void setPrev( TListElement * element ) { myPrev = element; }

	private:

		void * myValue;

		TListElement * myNext;
		TListElement * myPrev;

}; 

class TList {

	public:
	   /**
		* @brief Constructor
		*/
		TList();

	   /**
		* @brief Deconstructor
		*/
		~TList();
	
	   /**
		* @brief Deletes every Element in List
		*/
		void clear( void );

	   /**
		* @brief Adds element to end of the list
		* @param Element
		*/
		void append( void * element );

	   /**
		* @brief Returns value at position
		* @param Position
		* @return Value Returns value or null when out of bounds
		*/
		void * getValue( int position );

	   /**
		* @brief Updates Value at Position
		* @param Position position of element
		* @param Value new value of element
		*/
		void update( int position, void * element );

	   /**
		* @brief Removes Element at Position
		* @param Position position of element to be deleted
		*/
		void remove( int position );

	   /**
		* @brief Returns Length of List
		* @return Number of Elements in List
		*/
		int count( void ) { return myLength; }
	
	private:

	   /**
		* @brief Returns Last Element in list
		* @return Element Last Element
		*/
		TListElement * getLast( void );

	   /**
		* @brief Returns Element at Position
		* @param Position position of element
		* @return Element
		*/
		TListElement * getElement( int position );

		TListElement * myFirstElement;
		int myLength;
};
