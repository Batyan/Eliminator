GUIEU CHRISTOPHE - MIRETTI YOAN
===============================

Description
-----------
+ Prototype : Reseau
+ Objectif  : Echanger un objet entre un serveur et plusieurs clients
+ Base sur  : Fortune server

+ Serveur : Automatiquement en ecoute sur le port 8080
+ Client  : Automatiquement connecté a 127.0.0.1:8080

Fonctionnement
--------------
Le serveur renvoie a tout ses clients chaque objet recu.
Le client affiche le dernier objet recu.

Dans le client on peut fixer une coordonnee x,y et un type.
Cliquer sur envoyer pour envoyer l'objet.

Points principaux
-----------------
### L'utilisation de QVariant pour la serialisation

Ne pas oublier de declarer les types que l on serialise

+ Q_DECLARE_METATYPE(type) dans le .h
+ qRegisterMetaTypeStreamOperators<MyWall>("MyWall") en debut de programme.

Utiliser QVariant::QVariant(QDataStream & s) pour lire sur un socket

### Reseau en general

L'envoi d'une information se découpe en deux parties :

+ Le poids de ce qu'on envoie (qint8)
+ Le message proprement dit.

Les signaux importants :

+ connected()
+ disconnected()
+ readyRead()
