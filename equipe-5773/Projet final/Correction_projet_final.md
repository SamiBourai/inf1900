# Polytechnique Montréal

Département de génie informatique et génie logiciel

INF1900: Projet initial de système embarqué

# Grille de correction des programmes:

Identification:
+ Travail    : Panneau de controle
+ Section #  : 2
+ Équipe #   : 5773
+ Correcteur : Ahmad Faour

# LCD (Points 5)
## Le LCD affiche le bon mode d'opération en tout temps.
| Pénalité par erreur                          |            |
| -------------------------------------------- | ---------- |
| Affiche "configuration" initialement         |   (1/1.0)   |
| Affiche "Simulation" lors de la simulation   |   (1.5/1.5)   |
| Affiche "configuration" à la fin de la simul |   (1/2.5)   |
| __Résultat partiel__                         | __(3.5/5.0)__ |


# Messages (Points 10)
## Le menu principal s'affichent selon le format demandé
| Pénalité par erreur                          |   -0.75    |
| -------------------------------------------- | ---------- |
| Respecte l'indentation du format demandé     |            |
| Possède 6 options avec le bon texte          |            |
| Chaque option est numéroté selon le format   |            |
| Pas de typo dans les messages                |            |
| __Résultat partiel__                         | __(3/3.0)__ |

## Les messages de chaque option s'affichent selon le format demandé
| Pénalité par erreur                          |   -0.5     |
| -------------------------------------------- | ---------- |
| L'option 1 affiche le message demandé        |            |
| L'option 2 affiche le message demandé        |            |
| L'option 3 affiche les actions programmés    |            |
| L'option 3 indique s'il n'a aucune action    |            |
| L'option 4 affiche le message demandé        |            |
| L'option 5 affiche le message demandé        |            |
| Pas de typo dans les messages                |            |
| __Résultat partiel__                         | __(0.5/3.5)__ |

## Des messages erreurs sont affichés lorsque nécessaire.
| Pénalité par erreur                          |   -0.5     |
| -------------------------------------------- | ---------- |
| Mauvaise option au menu principal            |            |
| Mauvaise entrer pour l'option 1              |            |
| Mauvaise entrer pour l'option 2              |            |
| Mauvaise entrer pour l'option 3              |            |
| Mauvaise entrer pour l'option 4              |            |
| Mauvaise entrer pour l'option 5              |            |
| Pas de typo dans les messages                |            |
| __Résultat partiel__                         | __(3.5/3.5)__ |

# Clavier (Points 15)
## Il est possible de saisir des données via le clavier.
| Pénalité par erreur                          |            |
| -------------------------------------------- | ---------- |
| Les touches sont correctement saisies        |   (7/10.0)  |
| __Résultat partiel__                         | __(7/10.0)__|

## Les touches appuyées sont affichées à la console.
| Pénalité par erreur                          |            |
| -------------------------------------------- | ---------- |
| Les touches saisies sont affichées           |   (5/5.0)   |
| __Résultat partiel__                         | __(5/5.0)__ |

# Horloge (Points 10)
| Pénalité par erreur                          |            |
| -------------------------------------------- | ---------- |
| Définir l'heure de départ de la simulation   |   (0.5/2.0)   |
| L'horloge s'initialise en moins d'une seconde|   (0/4.0)   |
| Accélérer l'horloge avec la source de tension|   (4/4.0)   |
| __Résultat partiel__                         | __(4.5/10.0)__|

# Portes et servomoteurs (Points 20)
## Il est possible d'ouvrir et de fermer chaque porte
| Pénalité par erreur                          |            |
| -------------------------------------------- | ---------- |
| Être capable d'ouvrir chaque porte           |   (2.5/2.5)   |
| Être capable de fermer chaque porte          |   (2.5/2.5)   |
| __Résultat partiel__                         | __(5/5.0)__ |

## Ces changements d'état sont animés tel que demandé.
| Pénalité par erreur                          |            |
| -------------------------------------------- | ---------- |
| Respecter l'état initial                     |   (0/1.0)   |
| L'état final concorde avec la configuration  |   (1/1.0)   |
| L'animation doit durer 1 seconde             |   (2/2.0)   |
| Ne doit pas affecter les autres portes       |   (0/2.0)   |
| Le changement d'état se fait en 8 étapes     |   (4/4.0)   |
| __Résultat partiel__                         | __(7/10.0)__|

## Il est possible de placer chaque servomoteur à n'importe quel angle entre 0 et 180 degrés.
| Pénalité par erreur                          |            |
| -------------------------------------------- | ---------- |
| Chaque servo moteur peut aller de 0 à 180    |   (4/4.0)   |  
| L'angle est représenté sur 3 chiffres        |   (1/1.0)   |
| __Résultat partiel__                         | __(5/5.0)__ |


# Liste d'actions programmées (Points 15)
## Il est possible de programmer et de supprimer une action et de les afficher avec l'option 3
| Pénalité par erreur                          |            |
| -------------------------------------------- | ---------- |
| Capable de programmer une action             |   (5/5.0)   |   
| Respecte le format demander lors de l'ajout  |   (2/2.0)   |   
| Permettre plus d'une action à la même heure  |   (3/3.0)   |  
| Supprimer une action                         |   (2/4.0)   |  
| L'option 3 affiche les actions en ordre      |   (1/1.0)   |  
| __Résultat partiel__                         | __(13/15.0)__|

# Simulation (Points 15)
| Pénalité par erreur                          |            |
| -------------------------------------------- | ---------- |
| Simulation dure 24 heures                    |   (3/3.0)   |   
| Retourne en mode configuration après la simul|   (0/2.0)   |   
| Les actions s'exécutent au bon moment        |   (4/5.0)   |
| Les actions s'exécutent une à la fois        |   (3/3.0)   |
| Le bouton poussoir arrête la simulation      |   (2/2.0)   |
| __Résultat partiel__                         | __(12/15.0)__|


# Sonar (Points 10)
| -------------------------------------------- | ---------- |
| La simulation est mise en pause à moins de 2m|   (4/4.0)   |   
| La simulation est en cours à plus de 2m      |   (4/4.0)   |
| Le sonar fonctionne à +/- 1 cm               |   (2/2.0)   |
| __Résultat partiel__                         | __(10/10.0)__|

__Total: 79/100__
__Total des points: 15.8/20__

# Commentaires du correcteur:

## Le LCD affiche le bon mode d'opération en tout temps.
* Le mot configuration revient, mais le mot simulation ne part pas

## Il est possible de saisir des données via le clavier.
* Lorsque j'appuie sur une touche très souvent le programme pense que j'ai appuyé 2fois il faudrait un meilleur delai

## Horloge
* L'heure de départ ne s'initialise pas correctement lors de la deuxième tentative

## Ces changements d'état sont animés tel que demandé.
* Lorsque la porte est déjà fermé et que je la referme il refait son animation
* Lorsque j'ouvre la porte B et ensuite la porte A. Cela ferme la porte B

## Il est possible de programmer et de supprimer une action et de les afficher avec l'option 3
* Lorsqu'un mauvais index est donnée il supprime la dernière action ce qui n'est pas bon

## Simulation
* Lorsque l'acceleration de temps est fonctionne certaines actions sont ignorées
* Lorsque la simulation fini elle ne retourne pas en mode configuration

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