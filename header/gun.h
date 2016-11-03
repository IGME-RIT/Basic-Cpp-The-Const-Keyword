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

#pragma once        // Prevents the compiler from reading this file twice.

// Holds bullet information for the gun class.
struct Magazine
{
    // member variables
    int bullets;
    const int capacity;     // capacity is const, must be given a value in the constructor.

    // This is a constructor declaration.
    Magazine(int bulletsinitial, int bulletsCapacity);
    ~Magazine();
};

// This is a class declaration.
// A class is a type of object.
class Gun
{
    // Member variables in classes work just like they do in structs.
    // The only difference being members in classes are private by default. (they can't be directly accessed by other types)
    Magazine mag;

public:
    // This is a constructor declaration.
    // Constructors are used to create objects while giving them initial values.
    Gun(Magazine m);    // This gun object is initialized with a magazine.


    ~Gun();             // This is called a destructor. NOT a deconstructor.
                        // This code is called any time the object is removed from memory.

    void Fire(const int * numTimes);
    void Reload();
    bool IsLoaded() const;  // Mark that a memeber function doesn't modify the object by putting const at the end the declaration.
};