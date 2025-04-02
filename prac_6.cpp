#include <iostream>
#include <string>

using namespace std;

string input;
int index = 0;

bool S();
bool L();
bool L_();

bool S()
{
    if(input[index]=='(')
    {
        index++;
       bool a= L();
       if(a && input[index]==')' )
       {
        index++;
        return true;
       }
       else{
        return false;
       }


    }
    else if(input[index]=='a')
    {
        index++;
        return true;
    }
    else
    {
        return false;
    }

}

bool L()
{

    if(S() && L_())
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool L_()
{
    if(input[index]==','  )
    {
        index++;

        if(S() && L_())
        {
            return true;
        }
        else{
            return false;
        }
    }
    else
    {
        return true;
    }
}


bool validateString()
{
     index = 0;
    if (S() && index == input.length()) {
        return true;
    }
    return false;

}


int main() {
    cout << "Enter a string: ";
    cin >> input;

    if (validateString()) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }

    return 0;
}
