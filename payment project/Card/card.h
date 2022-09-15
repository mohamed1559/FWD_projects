#ifndef CARD_H
#define CARD_H
//#include "..\Terminal\Terminal.h"
//#include "..\Server\Server.h"
typedef unsigned char uint8_t ;
 typedef struct ST_cardData_t
 {
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
 }ST_cardData_t;

typedef enum EN_cardError_t
 {
    OK1, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
 }EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);
char * removeSpacesFromStr(char *str);

#endif // CARD_H
