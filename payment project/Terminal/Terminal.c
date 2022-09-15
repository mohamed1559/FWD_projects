#include <stdio.h>
#include <stdlib.h>
#include "Terminal.h"
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{       int size=0;
        printf("Enter the transaction data :");
        gets(termData->transactionDate);
         removeSpacesFromStr(termData->transactionDate);
    while (termData->transactionDate[size] !='\0'){size++;}   // for knowing the size
    if(size ==0||size <10){return WRONG_DATE;}
    else if(termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/' ){return WRONG_DATE;}
    else if(((int)termData->transactionDate[0]<48 && (int)termData->transactionDate[0]>51) ||    // day  xn x=0,1,2,3 n=0===>9
            ((int)termData->transactionDate[0]==51 && ((int)termData->transactionDate[1]!=48 ||(int)termData->transactionDate[1]!=49))){return WRONG_DATE;}
    else if ((int)termData->transactionDate[3]!= 49 &&(int)termData->transactionDate[3]!=48 ){return WRONG_DATE;} // mm 1,0  0x  ,1x
    else if ((int)termData->transactionDate[3] == 49 && (int)termData->transactionDate[4]> 50) {return WRONG_DATE;} // if 1x and x more than 2
    else {return OK;}
}


EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
    if(cardData.cardExpirationDate[3]< termData.transactionDate[8]){return EXPIRED_CARD;}  // compare the tens of year
    else
    {if(cardData.cardExpirationDate[4]< termData.transactionDate[9]){return EXPIRED_CARD;}  // compare the ones of year
        else
        {  if(cardData.cardExpirationDate[3]==termData.transactionDate[8] && cardData.cardExpirationDate[4] ==termData.transactionDate[9])  // if this equivalent
          {
              if(cardData.cardExpirationDate[0]< termData.transactionDate[3]){return EXPIRED_CARD;}  // compare tens of month
              else {if(cardData.cardExpirationDate[1]< termData.transactionDate[4]){return EXPIRED_CARD;}else{return OK;}}  // compare ones of month
           }
        else{return OK;}

        }

    }

}



EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    printf("Enter the transaction amount :");
        scanf("%f",&termData->transAmount);
        termData->maxTransAmount= 200;  // set for the max
        if (termData->transAmount <=0){return INVALID_AMOUNT;}else {return OK;}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
    printf("Enter the MAX transaction amount :");
        scanf("%f",&termData->maxTransAmount);

         if (termData->maxTransAmount<=0){return  INVALID_MAX_AMOUNT;}else {return OK;}
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    if(termData->transAmount >termData->maxTransAmount){ return EXCEED_MAX_AMOUNT;} else {return OK;}

}




