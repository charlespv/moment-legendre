====================================
**************README****************
====================================
INFOS :
	Annee : 
		2015-2016
	Licence Elec : 
		L3
	UE : 
		3E103
	Etudiants: 
		Houria - Eben - Meriem - 
		Charles

	Contact : charlespv@hotmail.fr
		
===============FAQ==================

Comment utiliser lancer notre programme ? 
	Nous vous conseillons d'utiliser codeblocks pour ouvrir et faire fonctionner 
	notre programme. 
	Par ailleurs, veuillez préserver tous vos fichiers dans le même dossier.
	Cad les images .bmp, le code source (.c) et les headers (.h)
	
Le programme me propose de rentrer quelques donnée puis s'arrête de fonctionner,
que se passe-t-il ?

	Le développement du programme "main.c" n'est pas achevé par manque de temps.
	Ce programme appelle une fonction nommé Char2Int qui inclue des erreurs de segmentation
	que nous n'avons pas pu corriger avant la deadline. Nous vous prions de nous excuser
	pour ce désagrement.
	Néanmoins, une majorité des fonctions présentes dans le programme sont fonctionnelles, notamment 
	ceux présenter dans notre rapport de projet (voir fichier pdf) que pouvez tester en rédigant votre
	propre code faisant appel à nos bibliothèques.



===== Objectif de ce programme ======

Durant ce projet, nous avons décidé de travailler sur la reconnaissance de forme. Le sujet étant vaste, nous nous sommes fixés l’objectif suivant: 
concevoir un programme en C afin de reconnaître des caractères (dans le sens typographique du terme).
Ainsi, nous avons cherché à créer un programme, dans lequel l’utilisateur proposerait le chemin vers une image, au format bitmap, 
dotée d’un fond noir et d’un caractère blanc et la machine répondrait par la lettre correspondante à l’image.
La stratégie adoptée pour cette réalisation s’appuie sur une méthode d’apprentissage en deux phases.
Premièrement, nous concevons un programme capable d’analyser certains aspects d’une image, ici les formes. 
Cette analyse est sauvegardée en mémoire (sous forme de fichier texte ou binaire). 
Or, il suffit d’associer à une analyse le nom d’une lettre, et ainsi donner du sens à la donnée afin de l’exploiter dans notre stratégie. 
Nous appellerons cette phase, l’apprentissage. 
Après avoir répété l'opération sur plusieurs images (par exemple, autant de fois que de lettre dans l’alphabet, soit 26 fois), 
nous obtenons un programme qui est doté d’un “savoir” concernant les caractères. Nous appelleront ce “savoir” aussi base de donnée. 
Comme toute base de donnée, une indexation efficace des données est nécessaire pour permettre une recherche efficace dans le  “savoir”.
La seconde phase consiste à tester notre programme sur des images qu’il n’a jamais traité durant sa phase d’apprentissage, 
comme on pourrait demander à un étudiant de proposer un algorithme durant un examen. 
Tel un bon élève, le programme doit nous proposer la lettre associée à l’image proposé durant le test, en s’appuyant sur son “savoir”. 

========================================