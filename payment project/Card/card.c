#include <stdio.h>
#include <stdlib.h>
#include "card.h"
                            /// for removing spaces from string
char * removeSpacesFromStr(char *str)
{
    int non_space_count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            str[non_space_count] = str[i];
            non_space_count++;
        }
    }
    str[non_space_count] = '\0';
    return str;
}

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
    {  int size=0;
        printf("Enter the Card Holder Name :");
        gets(cardData->cardHolderName);
         removeSpacesFromStr(cardData->cardHolderName);
    while (cardData->cardHolderName[size] != '\0'){size++;}
        if(size ==0||size>24||size < 20){return WRONG_NAME;} else{return OK1;}    // to check the boundaries
    }

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
 {     int size=0;
       printf("Enter the card expiry date :");
       gets(cardData->cardExpirationDate);
         removeSpacesFromStr(cardData->cardExpirationDate);
       while (cardData->cardExpirationDate[size] != '\0'){size++;}

        if(size ==0||size>5||size <5) {return WRONG_EXP_DATE;}
        else if (cardData->cardExpirationDate[2]!='/' ||((int)cardData->cardExpirationDate[0]!= 48 &&(int)cardData->cardExpirationDate[0]!=49) ) {return WRONG_EXP_DATE;} // 1,0 only in month 0x 1x
        else if ((int)cardData->cardExpirationDate[0] == 1 && (int)cardData->cardExpirationDate[1]>2) { return WRONG_EXP_DATE;} // if 1x and x more than 2
        else{return OK1;}

 }


 EN_cardError_t getCardPAN(ST_cardData_t *cardData)
 {  int size=0,isalph=0;
      printf("Enter  the card's Primary Account Number :");
      gets(cardData->primaryAccountNumber);
         removeSpacesFromStr(cardData->primaryAccountNumber);
       while (cardData->primaryAccountNumber[size]!='\0'){size++;}
       for(int i =0 ;i<size;i++){if(((int)cardData->primaryAccountNumber[i] >= 97 && (int)cardData->primaryAccountNumber[i] <= 122)     // A=97     Z= 122
                              ||((int)cardData->primaryAccountNumber[i] >= 65 && (int)cardData->primaryAccountNumber[i] <= 90) ){isalph++;}} //  a= 65     z= 90

       if(size ==0||size>19||size <16) {return WRONG_PAN;}
       else if(isalph == size){return OK1;} else {return WRONG_PAN;}

 }


