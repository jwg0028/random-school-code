#include <iostream>
#include <cmath>

class Triangle                                  //initializing class
{
    public:                                     //Public
        Triangle()                              //creating the default sizes of the triangle sides
        {
            side1= 3;
            side2 = 4;
            side3 = 5;
        }


        int change(int x, int y, int z)         //passes user entered variables through so that the sides can be changed
        {

            side1 = x;
            side2 = y;
            side3 = z;

            return 0;
        }

        
        int check()                             //checks to see if the triangle is a right triangle. Returns a number value that determines the answer
        {
            if(pow(side3, 2) == pow(side1, 2) + pow(side2, 2))
            {
                return 1;
            }
            else{
                return 2;
            }
        }

    private:                                    //declares private variables
    int side1, side2, side3;

};

int main()                                      //main function
{
    Triangle triang = Triangle();               //passing class into the main function
    int x, y, z;                                //just declaring variables to pass through the class


    std::cout << "enter values for the size of triangle sides (enter in one like: x y z)" << std::endl;
    std::cin >> x >> y >> z;

    triang.change(x, y, z);

    if(triang.check() == 1)                     //if statement that checks the returned number and prints the correct response
    {
        std::cout << "The triangle is a right triangle" << std::endl;
    }
    else{
        std::cout << "The triangle is not a right triangle" << std::endl;
    }

    return 0;
}