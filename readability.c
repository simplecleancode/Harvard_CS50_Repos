#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//function
int count_words(string text);
int count_letters(string text);
int count_sentences(string text);

//global variables
int letters = 0;
int words = 1;
int sentences = 0;

int main(void)
{
//get the sentence
string sentence = get_string("enter sentence: ");

//call the functions

letters = count_letters(sentence);
words = count_words(sentence);
sentences = count_sentences(sentence);

printf("%d\n", letters);
printf("%d\n", words);
printf("%d\n", sentences);



//formula
float index = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;

//convert index to an int
int grade = round(index);

if (grade < 1)
{
    printf("Before Grade 1\n");
    return 0;
}

if (grade > 1 && grade < 16)
{
    printf("Grade %d\n", grade);
    return 0;
}

if (grade > 16)
{
    printf("Grade 16+\n");
    return 0;
}

// end of main
}

int count_letters(string text)
{
//iterate through string text
for(int i = 0, n = strlen(text); i < n; i++)
{
    //count the number of letters
    // if ascii value is upper or is lower update letters
    //then increment letters by 1

    if(islower(text[i]) || isupper(text[i]))
    {
        letters++;
    }


}
return letters;
//end count letters
};

int count_words(string text)
{
//iterate through string text
for(int i = 0, n = strlen(text); i < n; i++)
{
    //count the number of words
    // if text[i] is a whitespace then increment words by 1
    if (text[i] == 32)
    {
        words++;
    }

}

return words;
//end count words
};

int count_sentences(string text)
{
//iterate through string text
for(int i = 0, n = strlen(text); i < n; i++)
{
    //count the number of sentences
    // if text[i] is a whitespace then increment words by 1
    if (text[i] == 33 || text[i] == 63 || text[i] == 46)
    {
        sentences++;
    }

}

return sentences;
//end count words
};












