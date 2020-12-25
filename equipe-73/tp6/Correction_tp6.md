# Polytechnique Montréal

Département de génie informatique et génie logiciel

INF1900: Projet initial de système embarqué

# Grille de correction des programmes:

Identification:
+ Travail    : Capteurs et conversion analogique
+ Section #  : 2
+ Équipe #   : 73
+ Correcteur : Ahmad Faour

# LISIBILITÉ
## En-têtes en début de programme   

| Pénalité par erreur                          | -1.5       |
| -------------------------------------------- | ---------- |
| Noms des auteurs                             |            |
| Description du programme                     |            |
| Identifications matérielles (Broches I/O)    |            |
| Table des états ou autres s'il y a lieu      |            |
| __Résultat partiel__                         | __(1.5/1.5)__ |

## Identificateurs significatifs (Autodocumentation)

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Absence de *chiffres magiques*               | (0.5/0.5)     |
| Noms de variables décrivent l'intention      | (0.4/0.5)     |
| Noms de fonctions décrivent l'intention      | (0.4/0.5)     |
| __Résultat partiel__                         | __(1.3/1.5)__ |

## Commentaires pertinents

Bonnes raisons d'un commentaire
 + Explication d'un algorithme 
 + Procédure peu évidente (ou *hack*)
 + Référence d'extraits de code copiés d'Internet
 + Détail du POURQUOI d'un extrait de code

| Pénalité par erreur                          | -0.5       |
| -------------------------------------------- | ---------- |
| __Résultat partiel__                         | __(0/1.0)__ |


## Indentation   

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Indentation structurée                       | (/0.5)     |
| Indentation uniforme dans le programme       | (/0.5)     |
| __Résultat partiel__                         | __(1/1.0)__ |


# MODULARITÉ ET COMPRÉHENSION
## Fonctions bien définies

| Pénalité par erreur                          | -0.5       |
| -------------------------------------------- | ---------- |
| Responsabilité unique d'une fonction         |            |
| Maximum de 4 paramètres                      |            |
| Absence de code dupliqué                     |            |
| etc                                          |            |
| __Résultat partiel__                         | __(1/1.0)__ |


## Bonne application des concepts de programmation et systèmes embarqués

| Pénalité par erreur                          | -1.0       |
| -------------------------------------------- | ---------- |
| Utilisation appropriée des registres         |            |
| Machine à états codée clairement             |            |
| Délais et minuteries utilisés judicieusement |            |
| PWM bien établi                              |            |
| Scrutation et interruptions bien utilisées   |            |
| etc                                          |            |
| __Résultat partiel__                         | __(4/4.0)__ |

# FONCTIONNALITÉS
## Git

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Fichiers aux bons endroits                   | (1.4/1.5)     |
| Absence de fichiers inutiles                 | (1/1.5)     |
| __Résultat partiel__                         | __(2.4/3.0)__ |


## Compilation    

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Absence de messages d'erreurs de compilation | (/1.5)     |
| Absence de messages d'attention (*warning*)  | (/0.5)     |
| __Résultat partiel__                         | __(2/2.0)__ |
   

## Évaluation boîte noire  

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Cas normal de fonctionnement                 | (1/2.5)     |
| Cas limites observables                      | (2/2.5)     |
| __Résultat partiel__                         | __(3/5.0)__ |

# Résultat

__Total des points: 16.2/20__

# Commentaires du correcteur:

-Identificateurs significatifs (Autodocumentation):
Les constantes s'écrivent en majuscule et les fonctions commencent pas une lettre minuscule!!
-Commentaires pertinents:
Votre code doit s'autodocumenter, pas besoin de mettre plein commentaire.

-Git:
Faites un GITIGNORE!! Vous avez plein de fichiers indésirables dans vos autres dossiers. Attention il avait un espace dans votre chemin vers la solution!!

-Évaluation boîte noire:
La DEL ne devient jamais vert peu importe l'intensité de la lumière.

# Basé sur le commit suivant
```
commit 008e9cac113c4dc7d51b70b9fbababac77e0b9a4
Author: Bourai Sami <sami.bourai@polymtl.ca>
Date:   Mon Oct 19 20:24:48 2020 -0400

    tp6
```

# Fichiers indésirables
```
tp/tp3/pb1/pb1.d
tp/tp3/pb1/pb1.o
tp/tp3/pb1/tp3.hex
tp/tp3/pb2/pb2.d
tp/tp3/pb2/pb2.o
tp/tp3/pb2/tp3.hex
tp/tp4/pb1/pb1.o
tp/tp4/pb1/pb1.out
tp/tp4/pb1/pb1.out.map
tp/tp4/pb2/pb2.d
tp/tp4/pb2/pb2.hex
tp/tp4/pb2/pb2.o
tp/tp4/pb2/pb2.out
tp/tp4/pb2/pb2.out.map
tp/tp5/pb1/pb1.d
tp/tp5/pb1/pb1.hex
tp/tp5/pb1/pb1.o
tp/tp5/pb1/pb1.out
tp/tp5/pb1/pb1.out.map
```

# Sortie de make dans les sous-répertoires
```
======================= Sortie de make dans /tp/tp6/pb1 =============================
make: *** correction_tp6/73//tp/tp6/pb1: No such file or directory.  Stop.


```