#include <stdio.h>
#include <stdlib.h>
#include "Server.h"
#include <string.h>
ST_accountsDB_t database[10];
                       ///             DATA BASE     ///
 void init()
{
   strcpy(database[0].primaryAccountNumber , "mohamedalaafarag");
    database[0].balance= 15400.00;

 strcpy(database[1].primaryAccountNumber,"alaamohamedfarag");
database[1].balance= 16000.14;

 strcpy(database[2].primaryAccountNumber,"faragalaafarag");
database[2].balance= 14500.14;

 strcpy(database[3].primaryAccountNumber,"mohamedalaamohamed");
database[3].balance= 18900.00;

 strcpy(database[4].primaryAccountNumber,"alaafaragmohamed");
database[4].balance= 174400.14;

 strcpy(database[5].primaryAccountNumber,"faragmohamedalaa");
database[5].balance= 112500.14;

 strcpy(database[6].primaryAccountNumber,"mohamedfaragalaa");
database[6].balance= 100.14;

 strcpy(database[7].primaryAccountNumber,"mohamedfaragoalaa");
database[7].balance= 15400.14;

 strcpy(database[8].primaryAccountNumber,"alaafaragalaa");
database[8].balance= 177800.14;

 strcpy(database[9].primaryAccountNumber,"faragmohamedfarag");
database[9].balance= 1000000.14;

}


                                           /// transactions database ///

ST_transaction_t trans_database[10]={0};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int i=0;
EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{  int check =0;
    for(i=0;i<10;i++)
    {

        if(strcmp(transData->cardHolderData.primaryAccountNumber,database[i].primaryAccountNumber) == 0){check=1;  break;}else{continue;} // search for the account

    }

    if(check == 0){return DECLINED_STOLEN_CARD;}
        else{if(database[i].balance <= 0){return DECLINED_INSUFFECIENT_FUND;}    // check the validation of balance & transaction amount
        else{if(transData->terminalData.transAmount > database[i].balance){return DECLINED_INSUFFECIENT_FUND;}
        else{if(transData->terminalData.transAmount <= database[i].balance)
                { printf("before:%f\n",database[i].balance);
                database[i].balance=database[i].balance - transData->terminalData.transAmount;
                printf("After:%f\n",database[i].balance);
                return APPROVED;
                }
        else {return INTERNAL_SERVER_ERROR;}
            }

        }

        }


}

EN_transState_t isValidAccount(ST_cardData_t *cardData)  // check card validation
{  int check =0;
    for(i=0;i<10;i++)
    {

        if(strcmp(cardData->primaryAccountNumber,database[i].primaryAccountNumber) == 0){check=1;  break;}else{continue;}

    }
    if(check ==1){return APPROVED;}else{return DECLINED_STOLEN_CARD;}
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData)
{

        if(database[i].balance <= 0 || termData->transAmount > database[i].balance){return LOW_BALANCE;}
        else{ return OK;}

        }






EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    int check =0;
    for(i=0;i<10;i++)
    {

        if(strcmp(transData->cardHolderData.primaryAccountNumber,database[i].primaryAccountNumber) == 0){check=1;  break;}else{continue;}

    }
    for(int j=0;j<20;j++)
                    {
                       trans_database[i].cardHolderData.primaryAccountNumber[j] =transData->cardHolderData.primaryAccountNumber[j];
                    }
                        trans_database[i].terminalData.transAmount=transData->terminalData.transAmount;

     if(check ==0){return DECLINED_STOLEN_CARD;}
     else
     {
          if(database[i].balance <= 0){return DECLINED_INSUFFECIENT_FUND;}
        else{if(trans_database[i].terminalData.transAmount> database[i].balance){return DECLINED_INSUFFECIENT_FUND;}
        else{if(trans_database[i].terminalData.transAmount<= database[i].balance)
                {
                    trans_database[i].transactionSequenceNumber++;
                    printf("PAN CODE:%s\n",trans_database[i].cardHolderData.primaryAccountNumber);
                    printf("Transaction Amount:%f\n",trans_database[i].terminalData.transAmount);
                    printf("transactionSequenceNumber:%d\n",trans_database[i].transactionSequenceNumber);
                    return OK;
                }
        else {return SAVING_FAILED;}
            }

        }

     }



}


