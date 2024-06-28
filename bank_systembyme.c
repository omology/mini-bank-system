#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// define boolean value : 
#define true 1 
#define false 0
// structure  liste chainee :
//To be created at the user's birth time : 
typedef struct time {
    unsigned int anne;  // from 1920 to now ;
    unsigned int mois; //between 1 and 12;
    unsigned int jour ; // between 1 and 31 ;
}time;
// creating account structure  :
typedef struct account {
    int ID_compt;
    char username[50];
    char name[50];
    int password;
    float balance;
    struct account* next_element;

}account;

// function Creat account :
 account*  Creat_Account( account* head_list){
     
    account* new_account  = malloc( sizeof(new_account));
     // cheking memory issue : 
    if (new_account == NULL){
        printf("erreure de creation l'account \n");
        exit(1);
    }
     // get data from user : 
    printf(" inserez votre nom  : \n");
    gets(new_account->name);
    getchar();// elimination space
    printf("inserez votre nom de utilisateur :\n");
    gets(new_account->username);
    getchar();// elimination space
    printf("inserez votre password :\n");
    scanf("%d", &new_account->password);
    // setting data:
    new_account->balance = 0.0 ;
    new_account->next_element = NULL;
     // alert message :
    printf("votre Account est cree correctement \n");
    //ajoute account a liste chainee
    account* tmp = head_list;
     //adding account to list of accounts
    while(tmp->next_element != NULL ){
        tmp = tmp->next_element;
    }
    tmp= new_account;
    return head_list;
 }
 // login funtion : 
 int log_in_to_account(account* head){
    int password;
    float adding_ballance;
    char username[50];
    reset_username: 
    printf("========================== entrez votre compt : ======================= \n ");
    printf(" inserez nom de utilisateur : \n");
    gets(username);
    getchar();// elimination d espace
    system("cls");
    reset_password:
    printf(" inserez votre mot de pass :  \n");
    account* tmp = head;
    while (tmp->next_element != NULL){
        if ( username == tmp->username ){
            if ( password == tmp->password){
                printf(" login succes ! ");
                goto add_ballance;
                break;
            }
            else {
                printf(" mot de pass incorrect");
                goto reset_password;
            }
        }
    }
    if ( tmp->next_element == NULL){
        printf("nom de utilisateur incorrect ! ");
        goto reset_username;
    }
    add_ballance :
    printf(" inserez nombre veul ajouter : \n");
    scanf("%d", &adding_ballance);
    tmp->balance = tmp->balance + adding_ballance;

 }
 // 1 show balance : 
 void show_balance (account* head ){
    // log in account : 
    int password;
    float removing_ballance;
    char username[50];
    reset_username: 
    printf("========================== entrez votre compt : ======================= \n ");
    printf(" inserez nom de utilisateur : \n");
    gets(username);
    getchar();// elimination d espace
    system("cls");
    reset_password:
    printf(" inserez votre mot de pass :  \n");
    account* tmp = head;
    while (tmp->next_element != NULL ){
        if ( username == tmp->username ){
            if ( password == tmp->password){
                printf(" login succes ! ");
                return true ;
                break;
            }
            else {
                printf(" mot de pass incorrect ");
                goto reset_password;
            }


        }
    }
    return false; 
 }

 // function ajoute balance : 
 void ajoute_salaire( account* head){
    int password;
    float adding_ballance;
    char username[50];
    reset_username: 
    printf("========================== entrez votre compt : ======================= \ns");
    printf(" inserez nom de utilisateur : \n");
    gets(username);
    getchar();// elimination d espace
    system("cls");
    reset_password:
    printf(" inserez votre mot de pass :  \n");
    account* tmp = head;
    while (tmp->next_element != NULL){
        if ( username == tmp->username ){
            if ( password == tmp->password){ // go to add balance : 
                printf(" login succes ! ");
                goto add_ballance;
                break;
            }
            else { // reset password  :
                printf(" mot de pass incorrect");
                goto reset_password;
            }
        }
    }
    if ( tmp->next_element == NULL){
        printf("nom de utilisateur incorrect ! ");
        goto reset_username;
    }
    add_ballance :
    printf(" inserez nombre veul ajouter : \n");
    scanf("%d", &adding_ballance);
    tmp->balance = tmp->balance + adding_ballance;

 }
 // getting money : 
 void getting_money( account* head){
    int password;
    float removing_ballance;
    char username[50];
    reset_username: 
    printf("========================== entrez votre compt : =======================\n");
    printf(" inserez nom de utilisateur : \n");
    gets(username);
    getchar();// elimination d espace
    system("cls");
    reset_password:
    printf(" inserez votre mot de pass :  \n");
    account* tmp = head;
    while (tmp->next_element != NULL){
        if ( username == tmp->username ){
            if ( password == tmp->password){
                printf(" login succes ! ");
                goto add_ballance;
                break;
            }
            else {
                printf(" mot de pass incorrect \n");
                goto reset_password;
            }
        }
    }
    if ( tmp->next_element == NULL){
        printf("nom de utilisateur incorrect ! \n");
        goto reset_username;
    }
    add_ballance :
    printf(" inserez nombre veul ajouter : \n");
    scanf("%d", &removing_ballance);
    tmp->balance = tmp->balance - removing_ballance;
 }
 // transfer argent : 
 void transfer_argent( account* head ){
    char destination_money[50];
    int destination_Id;
    account *tmp = head; 
    account* login_account;
    float transmition;
    int password;
    char username[50];
    system("cls");
    printf(" ===================== transmition d'argent : ====================== \n");

    reset_username_destinataire :
    printf("entrez nom de utilisteur \n");
    gets(destination_money);
    getchar();// elimination d espace

    reset_id_destinataire : 
    printf("inserez numero de compt de destinataire : \n");
    scanf("%d", &destination_Id);
    while ( tmp->next_element != NULL){
        if ( destination_money == tmp->username){
            if(destination_Id == tmp->ID_compt){
                printf("compt exist");
                goto ajoute_balance;
                break;
            }
            else {
                printf (" id compt incorrect ! \n");
                goto reset_id_destinataire;
            }
        }
        tmp = tmp->next_element; 
    }
    if ( tmp == NULL) {
        printf("invalide nom de utilisateur ! \n");
        goto reset_username_destinataire;
    }
    ajoute_balance:
    // log in account ; 
    printf("========================== entrez votre compt : =======================\n");
    reset_username : 
    printf(" inserez nom de utilisateur : \n");
    gets(username);
    getchar();// elimination d espace
    system("cls");
    reset_password:
    printf(" inserez votre mot de pass :  \n");
    account* tmp2 = head;
    while (tmp2->next_element != NULL){
        if ( username == tmp->username ){
            if ( password == tmp->password){
                printf(" login succes ! ");
                goto faire_transmition;
                break;
            }
            else {
                printf(" mot de pass incorrect\n");
                goto reset_password;
            }
        }
        tmp2 = tmp2->next_element;
    }
    // si nom  de utilisateure incorrect : 
    if ( tmp2->next_element == NULL){
        printf("nom de utilisateur incorrect ! \n");
        goto reset_username;
    }
    login_account = tmp2 ;
    faire_transmition:
    system("cls");
    printf("=================== transmition ======================= \n");
    printf("inserez valeur de transsmition :");
    scanf("%f", &transmition);
    if ( login_account->balance >= transmition ){
        tmp->balance = tmp->balance + transmition; 
        login_account->balance = login_account->balance - transmition;
    }
    else {
        printf(" votre sold insufaisant pour faire c'est action : \n");
    }
 }

int main () {
account *list = malloc(sizeof(account));
if ( list == NULL){
    exit (0);
}
system("cls");
system("color a");
int choix; 
printf(" ================== bank system : ======================= \n");
printf("[1]: creat account :              \n ");
printf("[2]: show balance :               \n ");
printf("[3]: add sold to account:         \n ");
printf("[4]: get sold from account:       \n ");

 enter_nombre:
 scanf("%d", &choix);

    while(choix != 5 ){
        switch( choix){
            case 1:
                system("cls");
                Creat_Account(list); 
                // break; 
            case 2 :
                system("cls");
                show_balance(list);
                // break;
            case 3 :
                ajoute_salaire(list);
                system("cls");
                // break;
            case 4 : 
                getting_money(list);
                system("cls");
                // break; 
            default :
            printf("enter a valid nombre ");
            goto enter_nombre;
            // break;
            }
    }
    return 0 ; 
}
