#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char rue[100];
    char ville[100];
    int code_postal;
} Adresse;


typedef struct {
    char nom[100];
    int age;
    Adresse adresse; 
} Personne;

void creer_personne(Personne* p) {
    
    printf("Entrez le nom de la personne : ");
    scanf("%s", p->nom);  
    if (p->nom[0] == '\0') {
        printf("Le nom ne peut pas être vide.\n");
        return; 
    }

    printf("Entrez l'âge de la personne : ");
    scanf("%d", &p->age);

    if (p->age < 0 || p->age > 120) {
        printf("L'âge doit être compris entre 0 et 120.\n");
        return; 
    }

   
    printf("Entrez la rue de l'adresse : ");
    scanf("%s", p->adresse.rue);  
   
    if (p->adresse.rue[0] == '\0') {
        printf("La rue ne peut pas être vide.\n");
        return; 
    }


    printf("Entrez la ville de l'adresse : ");
    scanf("%s", p->adresse.ville);  


    if (p->adresse.ville[0] == '\0') {
        printf("La ville ne peut pas être vide.\n");
        return; 
    }


    printf("Entrez le code postal de l'adresse : ");
    scanf("%d", &p->adresse.code_postal);

    
    if (p->adresse.code_postal <= 0) {
        printf("Le code postal doit être un nombre positif.\n");
        return; 
    }
}

void afficher_personne(Personne p) {
    printf("\nNom: %s\n", p.nom);
    printf("Âge: %d\n", p.age);
    printf("Adresse: %s, %s, %d\n", p.adresse.rue, p.adresse.ville, p.adresse.code_postal);
}

void mettre_a_jour_personne(Personne* p) {
    printf("Entrez le nouveau nom de la personne : ");
    scanf("%s", p->nom);
    printf("Entrez le nouvel âge de la personne : ");
    scanf("%d", &p->age);
    printf("Entrez la nouvelle rue de l'adresse : ");
    scanf("%s", p->adresse.rue);
    printf("Entrez la nouvelle ville de l'adresse : ");
    scanf("%s", p->adresse.ville);
    printf("Entrez le nouveau code postal de l'adresse : ");
    scanf("%d", &p->adresse.code_postal);
}




void supprimer_personne(Personne* p) {
    memset(p, 0, sizeof(Personne));  
    printf("La personne a été supprimée.\n");
}

int main() {
    
    Personne personnes[10];  
    int nombre_personnes = 0; 
    int choix;

    while (1) {
       
        printf("\n1. Créer une personne\n");
        printf("2. Afficher les informations des personnes\n");
        printf("3. Mettre à jour une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (nombre_personnes < 10) {
                    creer_personne(&personnes[nombre_personnes]);
                    if (personnes[nombre_personnes].nom[0] != '\0') {
                        nombre_personnes++;
                    }
                } else {
                    printf("Le nombre maximal de personnes a été atteint.\n");
                }
                break;
            case 2:
                if (nombre_personnes == 0) {
                    printf("Aucune personne à afficher.\n");
                } else {
                    for (int i = 0; i < nombre_personnes; i++) {
                        afficher_personne(personnes[i]);
                    }
                }
                break;
            case 3:
                {
                    int index;
                    printf("Entrez l'index (0-%d) de la personne à mettre à jour : ", nombre_personnes - 1);
                    scanf("%d", &index);
                    if (index >= 0 && index < nombre_personnes) {
                        mettre_a_jour_personne(&personnes[index]);
                    } else {
                        printf("Index invalide.\n");
                    }
                }
                break;
            case 4:
                {
                    int index;
                    printf("Entrez l'index (0-%d) de la personne à supprimer : ", nombre_personnes - 1);
                    scanf("%d", &index);
                    if (index >= 0 && index < nombre_personnes) {
                        supprimer_personne(&personnes[index]);
                        
                        for (int i = index; i < nombre_personnes - 1; i++) {
                            personnes[i] = personnes[i + 1];
                        }
                        nombre_personnes--;  
                    } else {
                        printf("Index invalide.\n");
                    }
                }
                break;
            case 5:
                printf("Au revoir!\n");
                return 0;
            default:
                printf("Choix invalide, essayez encore.\n");
        }
    }

    return 0;
}