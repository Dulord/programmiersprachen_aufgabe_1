#include <iostream> 

int main ()
{
    int x;
    //for x=0 bis max_int
    while(true){
        x++;
        for(int i=1; i<=20; i++){
            //bessere abbruchbedingungen
            if(x % i != 0){
                break;
            }
            if(i==20){
                std :: cout << x;
                //weg lassen = ALLE 
                return 0;
            }
        }
    }
    return 0;
}