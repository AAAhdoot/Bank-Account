#ifndef SERVER_H
#define SERVER_H

#include "utils.h"
/*use a semamphore because oracle lists it as one of the synchronization
mechanisms*/

typedef struct Account{
	char name[100];
	float balance;
	int isf; /*in session flag*/
	sem_t lock; /*lock the account while in use by client thread*/
} account;

typedef struct Bank{
	int currAccounts;
	account acc_arr[20];
	sem_t lock; /*lock the bank while printing*/
} Bank;

void alarmhandler(int sig);
void childhandler(int sig);
void inthandler(int sig);
void alarmSetup(struct sigaction* sig);
void intSetup(struct sigaction* sig);
void chldSetup(struct sigaction* sig);
int claim_port( const char * port );
void printlist();
int finish();
int findaccount(String accname);
int start(String accname);
int detrequest();
int balance();
int credit(float amount);
int debit(float amount);
void shm_setup();
int makeAccount(String name);


#endif
