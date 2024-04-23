#pragma once

class TMatrix {

	public:

	   /**
		* @Constructor
		*/
		TMatrix( void );

	   /**
		* @brief Deconstructor
		*/
		~TMatrix( void );

	   /**
		* @brief Constructor
		* @param Layout Layout of Matrix
		* @param rows Number of Rows
		* @param cols Number of Cols
		*/
		TMatrix( float layout[], int rows, int cols );
		
	   /**
		* @brief Constructor
		* @param rows Number of Rows
		* @param cols Number of Cols
		*/
		TMatrix( int rows, int cols );

	   /**
		* @brief Get Value at position
		* @param position Position of field (1 Dimensional)
		* @return Value Value of field
		*/
		float getValue( int position );

	   /**
		* @brief Get Value at position
		* @param x x-Position of field (2 Dimensional)
		* @param y y-Position of field (2 Dimensional)
		* @return Value Value of field
		*/
		float getValue( int x, int y );

	   /**
		* @brief Performs a scalar multiplication
		* @param scalar
		*/
		void mult( float scalar );

	   /**
		* @brief Returns dotproduct of both matrices
		* @param matrix Matrix to perform dot product with
		* @return matrix Resulting Matrix
		*/
		TMatrix mult( TMatrix * matrix );

	   /**
		* @brief Returns number of Rows
		* @return columns Number of Rows
		*/
		int countRows( void );

	   /**
		* @brief Returns number of Columns
		* @return columns Number of Columns
		*/
		int countCols( void );

	   /**
		* @brief Returns number of fields in matrix
		* @return fields Number of fields
		*/
		int countFields( void );

	private:

		float * myFields;

		int myNumFields;
		int myNumRows;
		int myNumCols;
};
