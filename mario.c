#include <stdio.h>
#include <cs50.h>

int main(void)
{
int userInput = 0;
// output "how many bricks to print?"
do
{
//output instructions
userInput = get_int("how many bricks to print?\n");

} while (userInput < 1 || userInput > 8);
//output variables
int myVar = userInput;

const string strSpace = " ";
const string strHash = "#";
int firstSpaces = myVar -1;
const string secondSpaces = "  ";
int countHash = 1;



// create rows

for ( int h = myVar; h > 0; h--)
{

//create columns

    //print firstSpaces
for( int i = firstSpaces; i > 0; i--)
{
    printf("%s", strSpace);
}
    //print first hash
for( int j = 0; j < countHash; j++)
{
    printf("%s", strHash);
}
    //print second spaces
    printf("%s", secondSpaces);

    //print second hashes
    for( int j = 0; j < countHash ; j++)
{
    printf("%s", strHash);
}
    //print new line
    printf("\n");

    //decrement first spaces by 1 increment countHash by 1
    firstSpaces -= 1;
    countHash += 1;

}
}
