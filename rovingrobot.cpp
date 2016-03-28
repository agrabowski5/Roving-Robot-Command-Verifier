//
//  main.cpp
//  Project 3
//
//  Created by Andrew Grabowski on 1/27/16.
//  Copyright © 2016 Andrew Grabowski. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

string lower(string commands);

bool isWellFormedCommandString (string commands)
{
    //checks for empty string
    if (commands == "")
    {
        return (false);
    }
    if(isdigit(commands[commands.size()-1]))return false; // this ensures there is no digit at end of string
                                                            // with no direction
    
    if(commands[0] != '+' && commands[0] != '-' && !isdigit(commands[0])) //checks for a valid start
    {
        return (false);
    }
    
    commands = lower(commands); // makes capitals letters lower case
    
    int i = 0;
    while (i < commands.size())
    {
        if(commands[i] == '+' || commands[i] == '-')
        {
            if(i + 1 >= commands.size()) return false;
            if(!isdigit(commands[i+1])) return false;
            i++;
        }
        
        if(isdigit(commands[i])) //checks for digits and makes sure it doesnt surpass the maximum of 3
        {
            
            if(i + 1 >= commands.size()) return false;
            {
                if(isdigit(commands[i+1]))
                {
                    if(i + 2 >= commands.size()) return false;
                
                    if(isdigit(commands[i+2]))
                    {
                        if(i + 3 >= commands.size()) return false;
                        if(!isalpha(commands[i + 3]))
                            return false;
                        i++;
                    }
                    i++;
                }
               
            }
        }

        i++;
            //start the check for letters
        if (commands[i] == 'n')
        {
            if(i+1 >= commands.size()) return true;
            if(isalpha(commands[i+1]))
            {
                if(i + 1 >= commands.size())return true;
                if(commands[i+1] != 'e' && commands[i+1] != 'w') return false;
                i++;
            }
            i++;
        }
        else if(commands[i] == 's')
        {
            if(i + 1 >= commands.size())return true;
            if(isalpha(commands[i+1]))
            {
                
                if(commands[i+1] != 'e' && commands[i+1] != 'w') return false;
                i++;
            }
            i++;
        }
        else if (commands[i] == 'w')
        {
            if(i + 1 >= commands.size())return true;
            i++;
        }
        else if(commands[i] == 'e')
        {
            if(i + 1 >= commands.size())return true;
            i++;
        }
        else
            return false;
        
    }
        
    return (true);
}
    
    






bool crossedOriginOnItsPath(string commands)
{
   if(!isWellFormedCommandString(commands))
   {
       return false;
   }
    //initiate the directions
    
    int i = 0;
    int horiz = 0;
    int vert = 0;
    commands = lower(commands);//this standarizes all direction to lowercase form
        
    while(i < commands.size())
    {
        // have three if statements for +,-, or digits
        int dim = 1;
        int moves = 0;
        
        
           
        
        
        if (commands[i]== '-')//checks for the negative direction
        {
            i++;
            if(isdigit(commands[i+1]))//checks for the size of the number, assuming the string is well formed
                
            {
                dim++;
                if(isdigit(commands[i+2]))
                    dim++;
            }
            if(dim == 1)
            {
                moves = commands[i] - '0'; // the minus '0' turns the chjar number value into the actual
                                            // integer value
                
            }
            else if (dim == 2)
            {
                moves += 10 * (commands[i]-'0');
                moves += commands[i+1]-'0';
                i++;
            }
            else if (dim == 3)
            {
                moves += 100 * (commands[i]-'0');
                moves += 10 * (commands[i+1] - '0');
                moves += commands[i+2] - '0';
                i += 2;
            }
            i++;
            
            //if statement for each direction
            
            if (commands[i] == 'n')
            {
                vert = vert - moves;//make moves in the negative n direction or s
                if (commands[i+1] == 'e' || commands[i+1] == 'w')
                i++;
            }
            if (commands[i] == 's')//This portion needs to be careful to ensure we move in right direction
            {
                vert = vert + moves;
                if (commands[i+1] == 'e' || commands[i+1] == 'w')
                    i++;
            }
            if (commands[i] == 'e')
            {
                horiz = horiz - moves;
            }
            if (commands[i] == 'w')
            {
                horiz = horiz + moves;
            }
            
           
        }
    
    

        // make things that moves i to the start of numbers and letters
        else if(commands[i] == '+')
        {
            if(isdigit(commands[i+2])) //this analyzes the size of the number, whether it is 1,2, or 3 digits
            {
                dim++;
                if(isdigit(commands[i+3]))
                    dim++;
            }
            if(dim == 1)
            {
                moves = commands[i+1] - '0';
                
            }
            else if (dim == 2)
            {
                moves += 10 * (commands[i+1] - '0');
                moves += commands[i+2] - '0';
                i++;
            }
            else if (dim == 3)
            {
                moves += 100 * (commands[i+1]- '0');
                moves += 10 * (commands[i+2] - '0');
                moves += commands[i+3] -'0';
                i += 2;
            }
            i++;
            
            //if statement for each direction
            
            if (commands[i] == 'n')
            {
                vert = vert + moves;//make moves 'n'
                if (commands[i+1] == 'e' || commands[i+1] == 'w')
                    i++;
            }
            if (commands[i] == 's')
            {
                vert = vert - moves;
                if (commands[i+1] == 'e' || commands[i+1] == 'w')
                    i++;
            }
            if (commands[i] == 'e')
            {
                horiz = horiz + moves;
            }
            if (commands[i] == 'w')
            {
                horiz = horiz - moves;
            }
            i++;
        }
        
        else if (isdigit(commands[i]))//this is the section that will take a command if it doesnt begin
                                        // with a + or -
        {
            
            if(isdigit(commands[i+1]))
            {
                dim++;
                if(isdigit(commands[i+2]))
                    dim++;
            }
            if(dim == 1)
            {
                moves = commands[i] - '0';
                
            }
            else if (dim == 2)
            {
                moves += 10 * (commands[i]-'0');
                moves += commands[i+1] - '0';
                i++;
            }
            else if (dim == 3)
            {
                moves += 100 * (commands[i] - '0');
                moves += 10 * (commands[i+1] - '0');
                moves += commands[i+2] - '0';
                i += 2;
            }
            i++;
            
            //if statement for each direction
            
            if (commands[i] == 'n')
            {
                vert = vert + moves; //make moves 'n'
                if (commands[i+1] == 'e' || commands[i+1] == 'w')
                    i++;// this will check for multi direction turns, such as "nw"
            }
            if (commands[i] == 's')
            {
                vert = vert - moves;
                if (commands[i+1] == 'e' || commands[i+1] == 'w')
                    i++;
            }
            if (commands[i] == 'e')
            {
                horiz = horiz + moves;
                i++;
            }
            if (commands[i] == 'w')
            {
                horiz = horiz - moves;
                i++;
            }
            
        }
        
        
        if (horiz == 0 && vert == 0)//this checks that after every iteration of a commands the rover doesnt
                                    //cross the origin
        {
            return true;
        }
        i++;
}

    return false;
}

string lower(string commands)
{
    //convert uppercase letters to lower case
    string t;
    for (size_t j = 0; j < commands.size(); ++j)
    {
        t += tolower(commands[j]);
    }
    commands = t;
    return (commands);
}


bool crossedOriginOnItsPath(string commands);
bool isWellFormedCommandString(string commands);

int main()
{

    assert(isWellFormedCommandString("9w-9w"));
    assert(crossedOriginOnItsPath("9e9w"));
    cerr << "All tests succeeded" << endl;
    return(0);
}
