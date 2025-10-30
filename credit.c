#include <stdio.h>
#include <cs50.h>

int main(void)
{

//output "enter card number"
long card = get_long("Number: ");

long cardExtract = card;
long cardEven = 0;
int iCard = 0;
long product = 0;
long digit = 0;
long cardOdd = 0;
long proMod = 0;
long proEven = 0;

//use for debugging the following numbers return an empty string
//long card = 369421438430814;
//long card = 4062901840;

do //checksum
{
    digit = cardExtract % 10;

    //extract even iterations multiply by 2 then add all numbers
    if(iCard % 2 != 0)
    {
        product = digit * 2;

        if (product > 9)
        {
            do
            {
                //extract the number
                proMod = product % 10;
                // add the extracted digits
                proEven += proMod;
                //update product
                product /= 10;
            }while(product);
        }
        cardEven += product;
        cardEven += proEven;
        product = 0;
        proEven = 0;

    //add all odd iterations
    }else{
        cardOdd += digit;
    }

    //update iterator
    iCard += 1;
    //update cardExtract
    cardExtract /= 10 ;

} while (cardExtract);

long result = cardEven + cardOdd;

//if the card passes the checksum
//verify if it is amex master or visa

long cardCompany = card;
long startingDigits = 0;
long startCount = 2;
long digitsAdd = 0;


long div;
for (div = 1;  div <= card ; div *= 10)
    ;

//begin verify card make
if(result % 10 == 0)
{
do
    {
    div /= 10;

    //extract the starting digits
    startingDigits = cardCompany / div;

//add digits
    digitsAdd += startingDigits;

    //verify visa
    if(digitsAdd == 4)
    {

        //if card digits = 13 or 16 and
        if(iCard == 13 || iCard == 16)
        {
        printf("VISA\n");
        };
        startCount = 0;
    };


    //verify master

    // card starts with 51 -55
    if(digitsAdd >= 6 && digitsAdd <= 10)
    {
        // if card digits = 16
        if(iCard == 16)
        {
            printf("MASTERCARD\n");
        };
    };

    //verify amex

    //if card starts with 34 or 37
    if (digitsAdd == 7 || digitsAdd == 10)
    {
        //if card digits = 15 and
        if(iCard == 15)
        {
            printf("AMEX\n");
        };
    };

    cardCompany %= div;
    startCount -= 1;

}while(startCount > 0);

//end verify visa master amex
}else{
    printf("INVALID\n");
}

//end main
}

