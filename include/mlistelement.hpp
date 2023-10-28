#pragma once

class MListElement {

	public:

	   /**
		* @brief Constructor
		*/
		MListElement( void ) {
			myNext = 0L;
			myPrev = 0L;
		}

	   /**
		* @brief Deconstructor
		*/
		~MListElement( void ) {}

		// Getter and Setter
		void * getValue( void ) { return myValue; }

		void setValue( void * value ) { myValue = value; }

		MListElement * getNext( void ) { return myNext; }
		MListElement * getPrev( void ) { return myPrev; }

		void setNext( MListElement * element ) { myNext = element; }
		void setPrev( MListElement * element ) { myPrev = element; }

	private:

		void * myValue;

		MListElement * myNext;
		MListElement * myPrev;

};
