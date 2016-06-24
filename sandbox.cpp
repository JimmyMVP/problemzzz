#include <map>
#include <iostream>

int main(int argc, char** argv) {

	int bits = 0;
    int n = 0b110010001;
    while(n != 0) {
        if((n & 1) != 0) bits++;
         n = n >> 1; 
        }   
    std::cout << std::endl << bits;  

}	