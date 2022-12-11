# Philosophers42

## Le principe / objectif

Philosopher est un exercice connu quand on veut apprendre a créer des thread et gérer leurs accès au variables et sortie standard nottament grâce aux mutex, qui permettent de mettre en attente les autres threads voulant faire une même action au même moment, par exemple afficher un message dans la sortie standard, si pas de gestion, les messages risque d'être mélangés.

## Sujet :
### Voici les choses à savoir si vous souhaitez réussir cet exercice :
* Des philosophes (un philosophe minimum) sont assis autour d’une table ronde au
* centre de laquelle se trouve un grand plat de spaghetti.
* • Les philosophes sont soit en train de manger, de penser ou de dormir.
* Lorsqu’ils mangent, ils ne peuvent pas penser ou dormir.
* Lorsqu’ils dorment, ils ne peuvent pas manger ou penser.
* Enfin, lorsqu’ils pensent, ils ne peuvent pas manger ou dormir.
 • Il y a également des fourchettes sur la table. Il y a autant de fourchettes que
* de philosophes.
 • Puisque servir et manger des spaghetti à l’aide d’une seule fourchette n’est pas
* chose facile, un philosophe prend la fourchette sur sa gauche et celle sur sa droite,
* soit une fourchette dans chaque main, afin de manger.
 • Quand un philosophe a fini de manger, il repose les fourchettes sur la table et se
* met à dormir. Une fois réveillé, il se remet à penser. La simulation prend fin si un
* philosophe meurt de faim.
 • Chaque philosophe a besoin de manger et ne doit pas mourir de faim.
 • Les philosophes ne communiquent pas entre eux.
 • Les philosophes ne peuvent pas savoir si l’un d’entre eux est sur le point de mourir.
 • Inutile de préciser que les philosophes ne doivent pas mourir !
* 
### Concernant les logs de votre programme :
 • Tout changement d’état d’un philosophe doit être formatté comme suit :
 ◦ timestamp_in_ms X has taken a fork
 ◦ timestamp_in_ms X is eating
 ◦ timestamp_in_ms X is sleeping
 ◦ timestamp_in_ms X is thinking
 ◦ timestamp_in_ms X died
* Remplacez timestamp_in_ms par le timestamp actuel en millisecondes
* et X par le numéro du philosophe.
 • Tout message affiché ne doit pas être mélangé avec un autre message.
 • Il ne doit pas y avoir plus de 10 ms entre la mort d’un philosophe et l’affichage du
* message annonçant sa mort.
 • Encore une fois, les philosophes doivent éviter de mourir.
