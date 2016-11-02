/*
Constructors and Destructors
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Include iostream for output during the program.
#include <iostream>
using namespace std;
#include "../header/gun.h"

int main()
{
    // ==== THE CONST KEYWORD ====
    cout << "This example is purely in code." << endl;
    cout << "The const keyword is not about doing things." << endl;
    cout << "It is instead about preventing coding mistakes." << endl;
    cout << "For this reason, all of the examples are things that don't compile." << endl;

    // The const keyword has a very similar function in C++ to private keyword.
    // This is not so much about WHAT they are used for, as it is WHY they are used.

    // Neither of these keywords enables you to do anything.
    // Instead, these keywords are about preventing you, and others using your code from shooting yourselves in the foot.

    // Take a player class for example. They might have a pointer to a backpack object, but what if someone decides to delete that pointer from somewhere else in code.
    // Then the player tries to use it's backpack... oops.
    // If you have a lot of files, it would be very hard to find the problem. It could be anywhere.
    // Making the variable private is a partial fix for that issue.

    // Const is another solution to this kind of problem...



    {
        //      The const keyword can be used with any variable type, and makes that variable read-only.

        const int triangleSides = 3;            // It looks something like this.
        int const squareSides = 4;              // But it can also look like this... C++ is weird sometimes.
        // const float const pentagonSides = 5; // Redundant usage of const is bad (this line gives warnings in MSVC)

        //      The important thing is that you can't change the value:
        // triangleSides = 5;

        //      Constant variables also have to be initialized with a value.
        //      This doesn't work:
        // const int favoriteNumber;

        //      because then you would later have to do this:
        // favoriteNumber = 2;
    }



    {
        //      const gets even more complicated when combined with the idea of pointers:
        int a = 1;
        int* aptr = &a;
        //      This is because a pointer really represents to different pieces of information.
        //      There's the memory address itself, and then there's also the value at that location.

        //      Say we have a constant integer:
        const int b = 2;

        //      We can't just get the memory address like this:
        // int * bptr = &b;

        //      Instead, the int of the pointer must also be const:
        const int* bptr = &b;

        //      This prevents b from ever being changed, even by the pointer:
        // *bptr = 0;
    }
    {
        //      BUT WAIT! THERE'S MORE!
        //      What if I don't what someone to be able to change the pointer instead?

        //      We do that like this:
        int c = 3;
        int * const cptr = &c;

        //      Now the pointer can't be changed:
        // cptr = nullptr;

        //      but the value can:
        *cptr = 0;

        //      What about this?
        int const * cptr2 = &c;
        //      ^ This is a pointer to a (const int), not a (const pointer) to an int.

        //      Remember, these two things are the same:
        const int triangleSides = 3;
        int const squareSides = 4;

        //      As a general rule, the const always goes on the right side of the thing that's const.
        //      The only exception is when const is all the way on the left, because then it can't go to anything else.
    }
    {
        //      EVEN MORE!
        //      What if I want a const value AND a const pointer?
        const float pi = 3.14159f; // close enough

        //      Do this:
        const float * const piptr = &pi;
        //      OR this:
        float const * const piptr2 = &pi;
        //      NOT this:
        // const float const * piptr3 = &pi;    // Redundant usage of const again, pointer itself isn't const.
    }
    cin.get(); // wait

    {
        // const used in function parameters:
        Magazine mag = Magazine(3, 6);
        Gun gun = Gun(mag);


        // Sometimes you may have a situation where you have a const object, but you need to pass a pointer to it into a function for some reason.
        const int fireRate = 6;

        // How can you guarentee that the function won't change the object that you pass in?
        // const can also be used inside function parameters to take in const variables.
        // That function won't be able to modify the value.
        gun.Fire(&fireRate);                                // Take a look at the gun class to see how this is implemented.
        // The same idea also applies to constructors.



        // However, it's important to note that the base value passed into a function will always be a copy on the stack.
        // you do not need the const keyword in these kinds of situations:
        const int bullets = 2;
        const int maxBullets = 2;
        Magazine mag2 = Magazine(bullets, maxBullets);   // The values are just copied, so using const in the constructor is pointless.

        cin.get();
    }





    {
        // So now you're using const to prevent objects from being modified.
        // What happens when you have a const object, and you want to call a member function of that object?
        Magazine mag = Magazine(2, 2);
        int fireRate = 6;
        const Gun gun = Gun(mag);
        
        //      Calling a function on this object might change it:
        //      Not ok:
        // gun.Fire(&fireRate);
        //      ok:
        bool loaded = gun.IsLoaded();   // This function is marked as const in the gun class.
    
        cin.get();
    }




    {
        // const can also be used for member variables in classes (makes sense right?)
        Magazine mag = Magazine(1, 1);

        //      This value is now read only:
        // mag.capacity = 0;    // I can't let you do that Dave.

        // But remember how const variables have to be initialized with a value?
        // This means that capacity has to be set as part of the constructor.
    }





    cin.get();  // Wait for input before closing.
    return 0;   // End Program.
}