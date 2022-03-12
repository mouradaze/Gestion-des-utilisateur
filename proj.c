#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
typedef struct utilisateur{
    char id[256],mdp[256];
};
int login (struct utilisateur x[] , char a[] , char b[]){
    int i;
	if(strcmp(x[0].id,a)==0 && strcmp(x[0].mdp,b)==0)
        return 1;
    for( i=1;i<20;i++){
        if(strcmp(x[i].id,a)==0 && strcmp(x[i].mdp,b)==0)
            return 2;
    }
     return 0;
}
void changemdp (struct utilisateur x[] , char a[] , char b[]){
    int i;
	for(i=0;i<20;i++){
        if(strcmp(x[i].id,a)==0){
            strcpy(x[i].mdp,b);
        }
    }
}
bool checkid (struct utilisateur x[] , char a[]) {
    int i;
	for(i=0;i<20;i++){
        if(strcmp(x[i].id,a)==0)
            return false;    
    }
    return true;
}
int ajout_util (struct utilisateur x[] , char a[] , char b[] , int y){
    if(y<20){
        strcpy(x[y].id,a);strcpy(x[y].mdp,b);
    }
    else return 0;
}
int supp_util (struct utilisateur x[], char a[]){
    int j,k=0;
    int i;
    for(i=0;i<20;i++){
        if(strcmp(x[i].id,a)==0){
             j=i;k=1;
        }
    }
    if(k==0)
        return 2;
    if(j==0)
        return 1;
    for(i=j;i<20;i++){
        strcpy(x[i].id,x[i+1].id);strcpy(x[i].mdp,x[i+1].mdp);
    }
    return 0;
}
void affichage (int x , struct utilisateur y[]){
    int i;
    for(i=0;i<x;i++){
        puts(y[i].id);
    }
}
int main () {
    struct utilisateur t[20];
    int cmp=1;int i;
        printf("************* ADMIN************\n");
        printf("Id : ");scanf("%s",&t[0].id);
        printf("Mot De Passe :");scanf("%s",&t[0].mdp);
        printf("\n\n");
        system("cls");
    char idlog[256],mdplog[256],mdpchange[256],idnew[256],mdpnew[256];
    int ret,dow=0,choix,l=0,aide,k=0,aide2;
        do{
        printf("************* Log In ************\n");
        printf("Id :");scanf("%s",&idlog); 
        printf("Mot De Passe : ");scanf("%s",&mdplog);
        system("cls");
        ret=login(t,idlog,mdplog);
    switch(ret){
        case 0 :
            printf("Access Denied , Retry\n");
        break;
            
        case 1 :
            do{
            printf("*********** Menu Admin **********\n");
            printf("1 - Afficher La Liste Des Utilisateures\n");
            printf("2 - Changer Le Mot De Passe\n");
            printf("3 - Ajouter Un Utilisateur\n");
            printf("4 - Supprimer Un Utilisateur\n");
            printf("5 - Changer Le Mot De Passe D'un Utilisateur\n");
            printf("6 - Log Out\n");
            printf("Votre Choix : ");scanf("%d",&choix);system("cls");
                    switch(choix){
                        case 1 :
                            printf("*********** Liste Des Utilisateurs *************\n");
                            affichage(cmp,t);
                           
                            l=0;
                        break;
                        case 2 :
                            printf("Le Nouveau Mot De Passe : ");scanf("%s",&mdpchange);
                            changemdp(t,idlog,mdpchange);
                            printf("Le Changement Est Fait Avec Success\n");
                            
                        break;
                        case 3 :
                            do{
                            printf("*********** Ajout D'un Utilisateur ***********\n");
                            printf("Id : ");scanf("%s",&idnew);
                               aide= checkid(t,idnew);
                                    if(aide==true){
                                        printf("Mot De Passe : ");scanf("%s",mdpnew);
                                        aide2=ajout_util(t,idnew,mdpnew,cmp);
                                            if(aide2!=0){
                                                printf("Ajout Avec Success\n");cmp++;
                                                k=1;
                                            }
                                            else{
                                                printf("Tableau D'utilisateures Est Plein .\n");
                                                k=1; 
                                            }
                                    }
                                    else {
                                        printf("Id Deja Utiliser Essayer Un Autre\n");
                                    }
                            }while(k!=1);
                            break;
                        case 4 :
                            printf("*********** Supprimer Un Utilisateur ***********\n");
                            printf("Id D'utilisateur A Supprimer : ");scanf("%s",&idnew);
                                   aide= supp_util(t,idnew);
                                   if(aide==1){
                                       printf("Impossible De Supprimer L'admin .\n");
                                   }
                                   else if (aide==0){
                                       printf("Suppression Avec Success .\n");
                                       cmp--;
                                   }
                                   else printf("Id Non Existent .\n"); 
                        break;   
                        case 5 :
                            printf("************ Changer MDP D'un Utilisateur **********\n");
                            printf("donnez L'id D'utilisateur : ");scanf("%s",&idnew);
                            aide = checkid(t,idnew);
                            if(aide==false){
                                printf("Le Nouveau Mot De Passe : ");scanf("%s",&mdpnew);
                                changemdp(t,idnew,mdpnew);
                                printf("Le Changement Est Fait .");
                            }
                            else{
                                printf("Id Non Existent .\n");
                            }
                            
                        break; 
                        case 6 :
                            do{
                            printf("********* Menu Log Out *********\n");
                            printf("1 - Retourner Au Log In\n");
                            printf("2 - Sortir Du Programme\n");
                            printf("Votre Choix : ");scanf("%d",&aide);system("cls");
                                if(aide == 1){
                                    l=1;aide2=1;
                                }
                                else if (aide == 2){
                                    exit (1);
                                }
                                else{
                                    printf("Choix Non Existant , Choisisez Un Autre Numero.\n");
                                }
                            }while(aide2!=1);
                            break;
                            default :
                                printf("Choix Non Existant , Choisisez Un Autre Numero.\n");
                            break;
                    }
       
            }while(l!=1);
        break;
        case 2 :
        l=0;
        do{
            printf("********* Menu Utilisateur ************\n");
            printf("1 - Afficher La Liste Des Utilisateures\n");
            printf("2 - Changer Le Mot De Passe\n");
            printf("3 - Log Out\n");
            printf("Votre Choix : ");scanf("%d",&choix);system("cls");
                switch(choix){
                    case 1 :
                        printf("*********** Liste Des Utilisateurs *************\n");
                            affichage(cmp,t);
                    break;
                    case 2 :
                    printf("Le Nouveau Mot De Passe : ");scanf("%s",&mdpchange);
                            changemdp(t,idlog,mdpchange);
                            printf("Le Changement Est Fait Avec Success\n");
                    break;
                    case 3 :
                            do{
                        printf("********* Menu Log Out *********\n");
                            printf("1 - Retourner Au Log In\n");
                            printf("2 - Sortir Du Programme\n");
                            printf("Votre Choix : ");scanf("%d",&aide);system("cls");
                                if(aide == 1){
                                    l=1;
                                }
                                else if (aide == 2){
                                    exit (1);
                                }
                                else{
                                    printf("Choix Non Existant , Choisisez Un Autre Numero.\n");
                                }
                            }while(aide2!=1);
                    break;
                    default :
                                printf("Choix Non Existant , Choisisez Un Autre Numero.\n");
                    break;
                }
        }while(l!=1);
        break;
        }
    }while(dow!=1);
}
