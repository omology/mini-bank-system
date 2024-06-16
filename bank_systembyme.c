#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// structure  liste chainee :
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
    int ID_accont= 0; 
    
    account* new_account  = malloc( sizeof(new_account));
    if (new_account == NULL){
        printf("erreure de creation l'account \n");
        exit(1);
    }
    printf(" inserez votre nom  : \n");
    gets(new_account->name);
    getchar();// elimination d espace
    printf("inserez votre nom de utilisateur :\n");
    gets(new_account->username);
    getchar();// elimination d espace
    printf("inserez votre password :\n");
    scanf("%d", &new_account->password);
    // getting data:
    new_account->ID_compt = ID_accont ;
    new_account->balance = 0.0 ;
    new_account->next_element = NULL;
    ID_accont++;
     // alert message :
    printf("votre Account est cree correctement ");
    //ajoute account a liste chainee
    account* tmp = head_list;
    while(tmp->next_element != NULL ){
        tmp = tmp->next_element;
    }
    tmp= new_account;
    return head_list;
 }
 // function ajoute balance : 
 void ajoute_salaire( account* head){
    int password;
    float adding_ballance;
    char username[50];
    reset_username: 
    printf("========================== entrez votre compt : =======================");
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
 // getting money : 
 void getting_money( account* head){
    int password;
    float removing_ballance;
    char username[50];
    reset_username: 
    printf("========================== entrez votre compt : =======================");
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
    printf(" ===================== transmition d argent : ====================== \n");

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
        printf("invalide nom de utilisateur !");
        goto reset_username_destinataire;
    }
    ajoute_balance:
    // log in account ; 
    printf("========================== entrez votre compt : =======================");
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
                printf(" mot de pass incorrect");
                goto reset_password;
            }
        }
        tmp2 = tmp2->next_element;
    }
    // si nom  de utilisateure incorrect : 
    if ( tmp2->next_element == NULL){
        printf("nom de utilisateur incorrect ! ");
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
        printf(" votre sold insufaisant pour faire c est action : \n");
    }
 }
int main () {


    return 0 ; 
}
