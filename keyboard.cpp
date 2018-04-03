#include <iostream>
#include <cstdlib>   // for srand and rand
#include <array>

class keyboard 
{
	// Access specifier
	public:

	// Data 
	int keyboard_array[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z',' ',':','"','<','>','?'};
    int size_array=32;               
    // Member Functions()
    int  shuffle_array(int array[])
    {
    	random_shuffle(&array[0],&array[31])
    }
}