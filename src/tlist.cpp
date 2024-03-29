#include <tlist.hpp>

TList::TList() {
	myLength = 0;
}

TList::~TList() {
	clear();
}

void TList::clear() {
	TListElement * current = myFirstElement;
	myFirstElement = 0L;

	// Go through Elements and delete
	while ( current != 0L ) {
		TListElement * temp = current;
		current = current->getNext();
		delete( temp );
	}
	myLength = 0;
}

void TList::append( void * p_element ) {
	// Create new Element
	TListElement * new_element = new TListElement();
	new_element->setValue( p_element );	

	// If element is not first element
	if ( myLength != 0 ) {
		TListElement * last_element = getLast();
		// Chain Elements
		last_element->setNext( new_element );
		new_element->setPrev( last_element );

	// If Element is first Element
	} else myFirstElement = new_element;
	myLength++;
}

void * TList::getValue( int p_position ) {
	TListElement * current = myFirstElement;
	while( p_position != 0 ) {
		if ( current->getNext() == 0L ) return 0L;
		current = current->getNext();
		p_position--;
	}
	
	return current->getValue();
}

void TList::update( int p_position, void * p_value ) {
    getElement( p_position )->setValue( p_value );
}

void TList::remove( int p_position ) {
	TListElement * current = getElement( p_position );

	if ( current->getPrev() == 0L ) {
		// If First Element
		TListElement * next = current->getNext();
		if ( next != 0L ) next->setPrev( 0L );
	} else if ( current->getNext() == 0L ) {
		// If last element
		TListElement * prev = current->getPrev();
		if ( prev != 0L ) prev->setNext( 0L );
	} else {
		// If not last element and not first element
		TListElement * next = current->getNext();
		TListElement * prev = current->getPrev();
		next->setPrev( current->getNext() );
		prev->setNext( current->getNext() );
	}
	myLength--;
	delete( current );
}

TListElement * TList::getLast() {
	TListElement * current = myFirstElement;
	while ( current->getNext() != 0L ) {
		current = current->getNext();
	}

	return current;
}

TListElement * TList::getElement( int p_position ) {
	TListElement * current = myFirstElement;
	while ( p_position != 0 ) {
		current = current->getNext();
		p_position--;
	}

	return current;
}
