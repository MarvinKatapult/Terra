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
