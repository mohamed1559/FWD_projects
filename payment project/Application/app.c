#include <stdio.h>
#include <stdlib.h>
#include "app.h"
void appStart(void)
{
    ST_cardData_t carddata;
    ST_terminalData_t termData;
    ST_transaction_t transData;
   if(getCardHolderName(&carddata) == OK1)
   {
       if( getCardExpiryDate(&carddata) == OK1)
       {
           if(getCardPAN(&carddata) == OK1)
           {
               if(getTransactionDate(&termData)== OK1)
               {
                   if(isCardExpired(carddata,termData)==OK)
                   {
                       if(getTransactionAmount(&termData)==OK)
                       {
                           if(isBelowMaxAmount(&termData)== OK1)
                           {
                               if(isValidAccount(&carddata)== APPROVED)
                               {
                                   if(isAmountAvailable(&termData)== OK2)
                                   {
                                        for(int i=0;i<20;i++)
                                            {
                                                transData.cardHolderData.primaryAccountNumber[i]=carddata.primaryAccountNumber[i];
                                            }
                                                transData.terminalData.transAmount=termData.transAmount;
                                                recieveTransactionData(&transData);
                                                saveTransaction(&transData);
                                   }else{printf("LOW_BALANCE\n");}
                               }else{printf("DECLINED_STOLEN_CARD\n");}
                           }else{printf("EXCEED_MAX_AMOUNT\n");}
                       }else{printf("INVALID_AMOUNT\n");}
                   }else{printf("EXPIRED_CARD\n");}
               }else{printf("WRONG_DATE\n");}
           }else{printf("WRONG_PAN\n");}
       }else{printf("WRONG_EXP_DATE\n"); }
   }else{printf("WRONG_NAME\n");}

}

int main()
{   init();
    appStart();
    return 0;
}




