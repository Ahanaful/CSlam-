/*Md. Ahanaful Alam 1002143421*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define NUMBEROFREROLLS 3
#define NUMBEROFFACES 6
#define NUMBEROFDICE 5

void RollDice(int dice[]) // roll any number of dice with any number of faces
{
    for (int i =0; i<NUMBEROFDICE; i++)
    {
        dice[i] = rand() % NUMBEROFFACES + 1;
    }
}

void PrintRoll(int dice[]) // printing out a dice roll
{
    
    for (int i = 0; i < NUMBEROFDICE; i++)
    {
        printf("%d ", dice[i]);
        
    }
}

int HowManyFaces(int dice[], int SearchFace)
{
    int NumberOfFaces = 0;
    for(int i=0; i < NUMBEROFDICE; i++)
    {
        if (dice[i] == SearchFace)
        {
            NumberOfFaces++;
        }
    }
    return NumberOfFaces;
}

int main()
{
    int dice[NUMBEROFDICE], howMany[NUMBEROFFACES];
    int numberOfRolls = 0, numberOfReRolls = NUMBEROFREROLLS, ofAkind = 0, FullHouse = 0, TwoPair = 0, CSlam = 0, LargeStraight = 0, SmallStraight = 0, i=0;
    char Answer = 'n';
    
    srand(time(0));
    do
    {   
        RollDice(dice); // rolling dice
        printf("You Rolled\n");
        numberOfRolls++;
        printf("Roll#%d\n\n", numberOfRolls);
        PrintRoll(dice); // printing dice
        printf("\n");
        
        for(i=0; i < NUMBEROFFACES; i++)
        {
            howMany[i] = HowManyFaces(dice, i+1); // 
        }
        for (i=0; i< NUMBEROFFACES; i++)
        {
            if(howMany[i] == 3)
            {
                FullHouse+=3;
            }
            if(howMany[i] == 2)
            {
                FullHouse +=2;
                TwoPair++;
            }
            if(howMany[i] == NUMBEROFDICE)
            {
                CSlam += 1;
            }
            if(howMany[i] == 1)
            {
                LargeStraight++;
            }
            else if(howMany[i]==0 && LargeStraight >0 && LargeStraight < 5)
            {
                LargeStraight = 0;
            }
            if (howMany[i] >= 1)
            {
                SmallStraight++;
            }
            else if(howMany[i] == 0 && SmallStraight > 0 && SmallStraight < 4)
            {
                SmallStraight =0;
            }
            if(howMany[i] == 4)
            {
                ofAkind = 4;
            }
            if(howMany[i] == 3)
            {
                ofAkind = 3;
            }
        }

        if (LargeStraight == 5)
        {
            printf("LargeStraight\n");
        }
        else if(SmallStraight >= 4)
        {
            printf("SmallStraight\n");
        }
        else if(FullHouse == 5)
        {
            printf("Full House\n");
        }
        else if(CSlam == 1)
        {
            printf("CSlam!!\n");
        }
        else if(ofAkind == 4)
        {
            printf("Four of a kind\n");
        }
        else if(ofAkind ==3)
        {
            printf("Three of a kind\n");
        }
        else if(TwoPair == 2)
        {
            printf("Two Pair\n");
        }
        else
        {
            printf("\nYou have nothing \n");
        }
        if(numberOfRolls != NUMBEROFREROLLS)
        {
            
            printf("\n\nDo you want to reroll?\n");
            scanf(" %c", &Answer);
        }
        ofAkind = 0;
        FullHouse = 0;
        TwoPair = 0;
        CSlam = 0;
        LargeStraight = 0;
        SmallStraight = 0;
    } 
    while (Answer == 'y' && numberOfRolls < numberOfReRolls);
    


    return 0;
}