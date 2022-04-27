# Quad-Remeshing
Implementing Reliable Feature-Line Driven Quad-Remeshing: https://dl.acm.org/doi/pdf/10.1145/3450626.3459941


# Build

## Prétraitement

### Instalation de gurobi

Suivre la procédure d'installation de Gurobi:
https://www.gurobi.com/documentation/quickstart.html

### Chemins absolus

Une fois le dossier gurobi951 récupéré, il y a des chemins absolus à remplacer:

* Dans le fichier `libs/quadwild/libs/libs.pri`: Il faut remplacer le chemin de gurobi (la ligne commançant par GUROBI_PATH). Le nouveau chemin est `/path/to/gurobi951/linux64`

* Dans le fichier `libs/quadwild/libs/quadretopology/quadretopology/include/qr_ilp.h`: Il faut remplacer le chemin de l'include de gurobi (ligne 32 normalement) par `#include "path/to/gurobi/linux64/include/gurobi_c++.h"`
