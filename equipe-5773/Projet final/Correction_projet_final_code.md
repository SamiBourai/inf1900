# Polytechnique Montréal

Département de génie informatique et génie logiciel

INF1900: Projet initial de système embarqué

# Grille de correction des programmes:

Identification:
+ Travail    : Panneau de controle - Code
+ Section #  : 2
+ Équipe #   : 5773
+ Correcteur : Ahmad Faour

# LISIBILITÉ
## En-têtes en début de programme   

| Pénalité par erreur                          | -1.5       |
| -------------------------------------------- | ---------- |
| Noms des auteurs                             |            |
| Description du programme                     |            |
| Identifications matérielles (Broches I/O)    |            |
| Table des états ou autres s'il y a lieu      |            |
| __Résultat partiel__                         | __(0/1.5)__ |

## Identificateurs significatifs (Autodocumentation)

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Absence de *chiffres magiques*               | (0.2/0.5)     |
| Noms de variables décrivent l'intention      | (0.5/0.5)     |
| Noms de fonctions décrivent l'intention      | (0.3/0.5)     |
| __Résultat partiel__                         | __(1/1.5)__ |

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
| Indentation structurée                       | (0.5/0.5)     |
| Indentation uniforme dans le programme       | (0/0.5)     |
| __Résultat partiel__                         | __(0.5/1.0)__ |


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
| __Résultat partiel__                         | __(2/4.0)__ |

# FONCTIONNALITÉS
## Git

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Fichiers aux bons endroits                   | (1.5/1.5)     |
| Absence de fichiers inutiles                 | (1.5/1.5)     |
| __Résultat partiel__                         | __(3/3.0)__ |


## Compilation    

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Absence de messages d'erreurs de compilation | (1.5/1.5)     |
| Absence de messages d'attention (*warning*)  | (0/0.5)     |
| __Résultat partiel__                         | __(1.5/2.0)__ |
   

## Évaluation boîte noire  

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Cas normal de fonctionnement                 | (/2.5)     |
| Cas limites observables                      | (/2.5)     |
| __Résultat partiel__                         | __(5/5.0)__ |

# Résultat

__Total des points: 14/20__

# Commentaires du correcteur:

## Identificateurs significatifs (Autodocumentation)
* porteLED.cpp: Chiffres magiques
* porteLED.cpp: Franglais dans le fichier dans les fonctions

## Indentation
* porteLED.cpp: indentation non structuré

## Commentaires pertinents
* Sonar.cpp: commentaire inutile
* UART.h: code mort (en commentaire)

## Bonne application des concepts de programmation et systèmes embarqués
* porteLED.cpp: L'utilisation d'un PWM et d'une interruption serait plus pratique
* Sonar.cpp: L'utilisation d'un PWM et d'une méthode de scrutation aurait été plus judicieux

# Basé sur le commit suivant
```
commit 41e4df32df91d1550a2ba9a2b8b6a8ffea93a230
Author: Mounib djellab <soheib-mounib.djellab@polymtl.ca>
Date:   Tue Dec 8 16:00:05 2020 -0500

    remise finale
```

# Fichiers indésirables
```

```

# Sortie de make dans les sous-répertoires
```
======================= Sortie de make dans /projet =============================
make: *** correction_projet_final/5773//projet: No such file or directory.  Stop.


```