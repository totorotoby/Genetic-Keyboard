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
    //...more maybe

};

//Keyboard class fo
class keyboard {
    // Access specifier
    public:
    //keyboard array 
    key board[32]; 
    double fitness;
    
    //constructor
    keyboard(){
        //array to be shuffled
        char to_shuffle[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 
        'w', 'x', 'y', 'z',' ',':','"','<','>','?'};
        std::random_shuffle(&to_shuffle[0],&to_shuffle[31]);

        //adding charcters  and distances to board
        for (int i = 0; i<32 ; i++){
            board[i].charcter = to_shuffle[i];
            if (i <= 3 || (i >= 6 && i<= 9))
                board[i].distance = 92;
            if (i == 4 || i == 10)
                board[i].distance = 100;
            if (i == 5)
                board[i].distance = 150;
            if ((i >= 11 && i <= 14) || (i >= 17 && i<= 20))
                board[i].distance = 0;
            if ((i >= 15 && i <= 16) || (i == 21))
                board[i].distance = 90;
            if ((i >= 22 && i <= 25) || (i >= 27 && i<= 31))
                board[i].distance = 97;               
            if (i == 26)
                board[i].distance = 155;
        }
    }
};

//just testing to see if actually worked
int main(){

    keyboard *first_keyboard = new keyboard();

}