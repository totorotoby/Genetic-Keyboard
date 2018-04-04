#include <iostream>
#include <cstdlib>   
#include <algorithm>
#include <stdio.h>
#include <random>


// Key class one for each position on the keyboard
class key{

    public:
    char charcter;
    int distance;
    //...more

};

//Keyboard class fo
class keyboard {
    // Access specifier
    public:
    //keyboard array 
    key board[32];           
    
    keyboard(){

        char to_shuffle[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 
        'w', 'x', 'y', 'z',' ',':','"','<','>','?'};
        std::random_shuffle(&to_shuffle[0],&to_shuffle[31]);

        for (int i = 0; i<32 ; i++){
            board[i].charcter = to_shuffle[i];
        }
    }
};


int main(){

    keyboard *first_keyboard = new keyboard();

    for (int i = 0; i<32 ; i++){
            printf("charc is: %c\n",first_keyboard->board[i].charcter);
        }

}