#include <mlist.hpp>
#include <mlistelement.hpp>

MList::MList() {
	myLength = 0;
}

MList::~MList() {
	clear();
}

void MList::clear() {

	MListElement * current = myFirstElement;
	myFirstElement = 0L;

	// Go through Elements and delete
	while ( current != 0L ) {
		MListElement * temp = current;
		current = current->getNext();
		delete( temp );
	}

	myLength = 0;
}

void MList::append( void * p_element ) {

	// Create new Element
	MListElement * new_element = new MListElement();
	new_element->setValue( p_element );	

	// If element is not first element
	if ( myLength != 0 ) {
		MListElement * last_element = getLast();

		// Chain Elements
		last_element->setNext( new_element );
		new_element->setPrev( last_element );

	// If Element is first Element
	} else myFirstElement = new_element;

	myLength++;
	
}

void * MList::getValue( int p_position ) {
	
	MListElement * current = myFirstElement;

	while( p_position != 0 ) {
		if ( current->getNext() == 0L ) return 0L;

		current = current->getNext();
		p_position--;
	}
	
	return current->getValue();

}

void MList::update( int p_position, void * value ) {

	MListElement * current = getElement( p_position );
	current->setValue( value );

}

void MList::remove( int p_position ) {

	MListElement * current = getElement( p_position );

	if ( current->getPrev() == 0L ) {

		// If First Element
		MListElement * next = current->getNext();
		next->setPrev( 0L );

	} else if ( current->getNext() == 0L ) {

		// If last element
		MListElement * prev = current->getPrev();
		prev->setNext( 0L );

	} else {

		// If not last element and not first element
		MListElement * next = current->getNext();
		MListElement * prev = current->getPrev();
		next->setPrev( current->getNext() );
		prev->setNext( current->getNext() );

	}

	myLength--;

	delete( current );
}

MListElement * MList::getLast() {

	MListElement * current = myFirstElement;

	while ( current->getNext() != 0L ) {
		current = current->getNext();
	}

	return current;
}

MListElement * MList::getElement( int p_position ) {
	
	MListElement * current = myFirstElement;

	while ( p_position != 0 ) {

		current = current->getNext();

		p_position--;
	}

	return current;

}
