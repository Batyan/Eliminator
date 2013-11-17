GUIEU CHRISTOPHE
================

Description
===========
+Prototype : Reseau
+Objectif  : Echanger un objet entre un serveur et plusieurs clients
+Basé sur  : Fortune server

+Serveur : Automatiquement en écoute sur le port 8080
+Client  : Automatiquement connecté a 127.0.0.1:8080

Fonctionnement
==============
Le serveur renvoie à tout ses clients chaque objet recu.
Le client affiche le dernier objet recu.

Dans le client on peut fixer une coordonnée x,y et un type.
Cliquer sur envoyer pour envoyer l'objet.

Points principaux
=================
- L'utilisation de QVariant pour la serialisation
	Ne pas oublier de declarer les types que l'ont serialise 
		1. Q_DECLARE_METATYPE(type); dans le .h
		2. qRegisterMetaTypeStreamOperators<MyWall>("MyWall"); en début de programme.
	Utiliser QVariant::QVariant(QDataStream & s) pour lire sur un socket
- Rseau en general
	L'envoi d'une information se découpe en deux parties :
		1. Le poids de ce qu'on envoie (qint8)
		2. Le message proprement dit.
	Les signaux importants :
		1. connected()
		2. disconnected()
		3. readyRead()
