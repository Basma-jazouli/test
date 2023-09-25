#include <stdio.h>
#include <string.h>
#include <time.h>



// global variable
int c = 0;
int i , j;
int jour1 , mois1 ;
int day , month ;
int status;

// stucture
struct todo
{
    int id;
    char title[30];
    char description[500];
    char status[50];

// deadline structure
struct deadline
{
    int jour;
    int mois;
    int annee;

} deadline;

} todo[100];

// pour ajouter une tache
void ajouterTache() // fonction 1
{
    todo[c].id = c + 1;                      // id
    printf("\t\t\t\t\t Ajouter le titre: "); // output
    scanf("%s", &todo[c].title);             // input

    printf("\t\t\t\t\t Ajouter la description: "); // output
    scanf("%s", &todo[c].description);             // input
    printf("\t\t\t\t\t                                   \n");
    printf("\t\t\t\t\t=======Ajouter un deadline======\n "); // output
    printf("\t\t\t\t\t                                   \n");
    printf("\t\t\t\t\t Ajouter le jour: "); // le jour de la tache
    scanf("%d", &todo[c].deadline.jour);
    printf("\t\t\t\t\t Ajouter le mois: "); // le mois de la tache
    scanf("%d", &todo[c].deadline.mois);
    do
    {
    printf("\t\t\t\t\t                                    \n");
    printf("\t\t\t\t\t =======Ajouter votre status========= \n");
    printf("\t\t\t\t\t 1-a realiser\n");
    printf("\t\t\t\t\t 2-en cours de realisation \n");
    printf("\t\t\t\t\t 3-finalisee \n");
    printf("\t\t\t\t\t ================================== \n");
    printf("\t\t\t\t\t Entrer votre choix: ");
    scanf("%d",&status);

    switch (status)
    {
    case 1:
    strcpy(todo[c].status,"a realiser");
        break;
    case 2:
    strcpy(todo[c].status,"en cours de realisation");
        break;
    case 3:
    strcpy(todo[c].status,"finalisee");
        break;

    default:
    printf("ce choix est unvalide \n");
        break;
    }

    }while (status != 0 && status != 1 && status != 2 && status != 3 );

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    jour1 = tm.tm_mday;
    mois1 = tm.tm_mon+1;

    day = todo[c].deadline.jour - jour1;
    month = (todo[c].deadline.mois - mois1)*31;

    todo[c].deadline.jour = day;
    todo[c].deadline.mois = month;

    todo[c].deadline.jour = todo[c].deadline.jour + todo[c].deadline.mois;

    c++;
}

// pour ajouter une nouvelle tache
void ajouterNouvellesTaches() // fonction 2
{
    int nt = 1;
    while (nt)
    {
    ajouterTache();
    printf("\t\t\t\t\t Pour arreter ecrire 0: \n");
    printf("\t\t\t\t\t Pour continuer ecrire 1: \n");
    printf("\t\t\t\t\t Entrer votre choix: ");
    scanf("%d", &nt);
    }
}

// fonction tableau
void tableaux()
{
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-30s | %-15s | %-12s | %-20s |\n", "Titre", "Description", "deadline (jours)", "Identifiant", "Statut");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}

// Fonction pour afficher les details de la tache dans le tableau formate
void tableauCase()
{
    int i;
    for (i = 0; i < c; i++)
    {
    printf("| %-20s | %-30s | %-15d |  %-12d | %-20s |\n", todo[i].title, todo[i].description, todo[i].deadline.jour, todo[i].id, todo[i].status);
    }
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}
// Fonction Affichage
void ajouterAfficherTache()
{
    int x;
    int reponse,exist = 0;
    struct todo alphabet;
    struct todo deadline;

    printf("entrez le nombre de choix : \n");
    printf(" 1 - Trier les taches par ordre alphabetique\n");
    printf(" 2 - Trier les taches par deadline\n");
    printf(" 3 - Afficher les taches dont le deadline est dans 3 jours ou moins\n");
    scanf("%d",&x);

    switch(x)
    {
    case 1 :
    // Trier les taches par ordre alphabetique par titre


        for(i = 0 ; i < c ; i++)
        {
            for (j = i + 1 ; j < c ; j++)
            {
                if(strcmp(todo[i].title, todo[j].title)>0)
                {
                    alphabet = todo[i];
                    todo[i] = todo[j];
                    todo[j] = alphabet;
                }
            }
        }
        tableaux();
        tableauCase();
        break ;

    case 2 :
    // trier par ordre deadline

        for(i = 0 ; i < c ; i++)
        {
            for( j = i + 1 ; j < c ; j++)
            {
                if(todo[i].deadline.jour > todo[j].deadline.jour)
                {
                   deadline = todo[i] ;
                    todo[i] = todo[j] ;
                    todo[j] = deadline;
                }
            }
        }
        tableaux();
        tableauCase();
        break ;

    case 3 :
    //trier les tache inferieur ou egal a 3 jours

        for( i = 0 ; i < c ; i++)
        {
            if(todo[i].deadline.jour <= 3)
            {
                tableaux();
                 printf("| %-20s | %-30s | %-15d | %-12d | %-20s |\n", todo[i].title, todo[i].description, todo[i].deadline.jour, todo[i].id, todo[i].status);
                 printf("--------------------------------------------------------------------------------------------------------------------\n");
            }
            else if(todo[i].deadline.jour > 3)
            {
                printf("\t\t !!! Il n'y a pas de taches de moins de 3 jours !!! \n\n");
                break;
            }
        }
    }
}

//pour modifier une tache
void ajouterModifierTache() // fonction 5
{
    tableaux();
    tableauCase();
    int N;

    printf("\t\t\t\t\t Entrer l'identifiant de la Tache pour modifier: ");
    scanf("%d",&N);

    for (i = 0; i < c; i++)
    {
      if (todo[i].id == N)
       {
        todo[i].id = c + 1; //id

    printf("\t\t\t\t\t Ajouter le titre: "); // output
    scanf("%s", &todo[i].title);// input
    printf("\t\t\t\t\t Ajouter la description: "); // output
    scanf("%s", &todo[i].description);             // input
    printf("\t\t\t\t\t                                   \n");
    printf("\t\t\t\t\t=======Ajouter un deadline======\n "); // output
    printf("\t\t\t\t\t                                   \n");
    printf("\t\t\t\t\t Ajouter le jour: "); // le jour de la tache
    scanf("%d", &todo[i].deadline.jour);
    printf("\t\t\t\t\t Ajouter le mois: "); // le mois de la tache
    scanf("%d", &todo[i].deadline.mois);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    jour1 = tm.tm_mday;
    mois1 = tm.tm_mon+1;

    day = todo[i].deadline.jour - jour1;
    month = (todo[i].deadline.mois - mois1)*31;

    todo[i].deadline.jour = day;
    todo[i].deadline.mois = month;

    todo[i].deadline.jour = todo[i].deadline.jour + todo[i].deadline.mois;

       }

    }

}

// pour supprimer une tache
void ajouterSurpprimerTache() // fonction 6
{
    int Sid;
    printf("\t\t\t\t\t Entrer l'identifiant de la Tache que tu veux supprimer: ");
    scanf("%d",&Sid);

    for ( i = 0; i < c; i++)
    {
      if (todo[i].id == Sid)
      {
        todo[i] = todo[i+1];

      }
      c --;
    }
}

// rechercher une tache par son identifiant
void RechecherTachesbyID() // fonction 7
{
    int Yid;
    printf("\t\t\t\t\t Entrer l'identifiant de la Tache : "); //output
    scanf("%d", &Yid); //input

    for (i = 0; i < c; i++)
    {
        if (todo[i].id == Yid)
        {
          tableaux();
          printf("| %-20s | %-30s | %-15d | %-12d | %-20s |\n", todo[i].title, todo[i].description, todo[i].deadline.jour, todo[i].id, todo[i].status);
          printf("--------------------------------------------------------------------------------------------------------------------\n");

          break;
        }
    }

}

// rechercher une tache par son titre
void RechercherbyTitle() //fonction 8
{
    char Ytitle[30];
    printf("\t\t\t\t\t Entrez le titre de la Tache : "); //output
    scanf("%s", &Ytitle); //input

    for (int i = 0; i < c; i++)
    {
        if (strcmp(todo[i].title, Ytitle) == 0)
        {
            tableaux();
            printf("| %-20s | %-30s | %-15d | %-12d | %-20s |\n", todo[i].title, todo[i].description, todo[i].deadline.jour, todo[i].id, todo[i].status);
            printf("--------------------------------------------------------------------------------------------------------------------\n");

            break;
        }
    }
}

// statistiques de taches
void ajouterStatistiques() // fonction 9
{
    int temp = c ;
    char incomplete[50] = "a realiser";
    char complete [50] =   "finalisee";
    int longeure=0, longeure2=0;

    printf("\t\t\t\t\t ------------------------------------------------ \n");
    printf("\t\t\t\t\t         le nombre des taches est : %d           \n",temp);
    printf("\t\t\t\t\t ------------------------------------------------ \n\n\n");
    for(i =0 ; i < c ; i++)
    {
        if(strcmp(complete, todo[i].status)==0)
        {
            longeure++;
        }
    }
    for(i =0 ; i < c ; i++)
    {
        if(strcmp(incomplete, todo[i].status)==0)
        {
            longeure2++;
        }
    }
        printf("\t\t\t\t\t ------------------------------------------------ \n");
        printf("\t\t\t\t\t         le nombre des taches complete : %d           \n",longeure);
        printf("\t\t\t\t\t ------------------------------------------------ \n\n\n");
        printf("\t\t\t\t\t ------------------------------------------------ \n");
        printf("\t\t\t\t\t         le nombre des taches incomplete : %d           \n",longeure2);
        printf("\t\t\t\t\t ------------------------------------------------ \n\n\n");

    for (i = 0 ; i < c ; i++){
        printf("\t\t\t\t\t------------------------------------------------------\n");
        printf("\t\t\t\t\t|     %-12s      |     %-15s        |\n","Identifiant","Deadline (jours)");
        printf("\t\t\t\t\t------------------------------------------------------\n");

        printf("\t\t\t\t\t|     %-12d      |   %-15d jour      |\n",todo[i].id,todo[i].deadline.jour);
        printf("\t\t\t\t\t------------------------------------------------------\n");
    }
}

    int main()
    {
        int choice;
        do
        {
            printf("\t\t\t\t\t________________________________________\n");
            printf("\t\t\t\t\t                                        \n");
            printf("\t\t\t\t\t               **MENU**                 \n");
            printf("\t\t\t\t\t________________________________________\n");
            printf("\t\t\t\t\t 1-Ajouter une nouvelle tache. \n");
            printf("\t\t\t\t\t 2-Ajouter plusieurs nouvelles taches. \n");
            printf("\t\t\t\t\t 3-Afficher la liste de toutes les taches. \n");
            printf("\t\t\t\t\t 4-Modifier une tache. \n");
            printf("\t\t\t\t\t 5-Supprimer une tache par identifiant. \n");
            printf("\t\t\t\t\t 6-Rechercher une Tache par son ID.\n");
            printf("\t\t\t\t\t 7-Rechercher une Tache pas son Titre.\n");
            printf("\t\t\t\t\t 8-Statistiques.\n");
            printf("\t\t\t\t\t________________________________________\n");
            printf("\t\t\t\t\t Entrez votre choix: ");
            scanf("%d", &choice);
            system("cls");


            switch (choice)
            {
            case 1:
                ajouterTache();
                break;

            case 2:
                ajouterNouvellesTaches();
                break;

            case 3:
                ajouterAfficherTache();
                break;

            case 4:
                ajouterModifierTache();
                break;

            case 5:
                ajouterSurpprimerTache();
                break;

            case 6:
                RechecherTachesbyID();
                break;

            case 7:
                RechercherbyTitle();
                break;

            case 8:
                ajouterStatistiques();
                break;

            default:
                printf("Ce choix est unvalide \n");
            }

        } while (choice != 0);

        return 0;
    }
