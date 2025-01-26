# SMP2 - TP6 : Création d'un Monopoly

## Sommaire
- [SMP2 - TP6 : Création d'un Monopoly](#smp2---tp6--création-dun-monopoly)
  - [Sommaire](#sommaire)
  - [1. Préambule - Création du repository Git](#1-préambule---création-du-repository-git)
  - [2. Règles du jeu](#2-règles-du-jeu)
    - [2.1. Tour de jeu](#21-tour-de-jeu)
    - [2.2. Options à chaque tour](#22-options-à-chaque-tour)
    - [2.3. Double au dé](#23-double-au-dé)
    - [2.4. 🏦 Règles spéciales](#24--règles-spéciales)
      - [2.4.1. Case Départ](#241-case-départ)
      - [2.4.2. Case Prison](#242-case-prison)
      - [2.4.3. Taxes et impôts](#243-taxes-et-impôts)
      - [2.4.4. Propriétés hypothéquées](#244-propriétés-hypothéquées)
    - [2.5. 🏘️ Construction](#25-️-construction)
    - [2.6. 💰 Faillite](#26--faillite)
    - [2.7.🏆 Fin du jeu](#27-fin-du-jeu)
  - [3. Travail à faire](#3-travail-à-faire)
    - [3.1. Spécifications](#31-spécifications)
    - [3.2. Conception (Diagrammes)](#32-conception-diagrammes)
    - [3.3. Algorithmes](#33-algorithmes)
    - [3.4. Jeux d’essais](#34-jeux-dessais)
      - [3.4.1. Classe Case](#341-classe-case)
        - [Description](#description)
        - [Exemples de tests](#exemples-de-tests)
  - [4. Conclusion](#4-conclusion)

---

## 1. Préambule - Création du repository Git
Pour réaliser ce TP, commencez par créer un repository Git en suivant les consignes suivantes :
- Donnez à votre groupe un nom de la forme **NOM1-NOM2-NOM3-NOM4**.
- Ajoutez un fichier `README.md` listant les membres de l’équipe.
- Partagez vos livrables : code, diagrammes, description des choix de conception, algorithmes et jeux d'essais.

## 2. Règles du jeu
### 2.1. Tour de jeu
Chaque joueur joue à son tour dans le sens des aiguilles d’une montre :
   - Lancez les **deux dés** et avancez votre pion du nombre indiqué.
   - Appliquez l’effet de la case sur laquelle vous arrivez.

### 2.2. Options à chaque tour
- **Acheter une propriété** : 
   - Si vous arrivez sur une propriété non possédée, vous pouvez l’acheter au prix indiqué sur la case.
   - Si vous refusez, le banquier met la propriété aux enchères.
- **Payer un loyer** : 
   - Si vous arrivez sur une propriété appartenant à un adversaire, vous payez le loyer indiqué sur le titre de propriété (modifié si des maisons ou hôtels sont construits).
- **Piocher une carte** :
   - Si vous tombez sur une case **"Chance"** ou **"Caisse de Communauté"**, piochez une carte et suivez ses instructions.
- **Construire des maisons ou hôtels** (si applicable) :
   - À votre tour, vous pouvez acheter des maisons/hôtels sur vos propriétés si vous possédez tout un groupe de couleur.

### 2.3. Double au dé
- Si vous faites un double (deux dés identiques), jouez à nouveau.
- Si vous faites **trois doubles consécutifs**, vous allez directement en prison.

---

### 2.4. 🏦 Règles spéciales

#### 2.4.1. Case Départ
- Chaque fois que vous passez ou atterrissez sur la case "Départ", recevez **200 M$**.

#### 2.4.2. Case Prison
- Vous allez en prison si :
   - Vous tombez sur la case "Allez en prison".
   - Vous piochez une carte "Allez en prison".
   - Vous faites trois doubles consécutifs.
- Pour sortir de prison :
   - Payez **50 M$** au début de votre tour.
   - Utilisez une carte **"Sortie de prison"**.
   - Faites un double en lançant les dés (vous avancez alors du total des dés).

#### 2.4.3. Taxes et impôts
- Payez le montant indiqué si vous atterrissez sur une case taxe (Impôt sur le revenu, Taxe de luxe, etc.).

#### 2.4.4. Propriétés hypothéquées
- Une propriété peut être hypothéquée pour obtenir de l’argent de la banque.
- Vous devez payer la valeur de l’hypothèque + 10 % pour lever l’hypothèque.

---

### 2.5. 🏘️ Construction

1. **Conditions pour construire** :
   - Vous devez posséder **toutes les propriétés d’un groupe de couleur**.
   - Les constructions doivent être **équilibrées** : vous ne pouvez pas construire une deuxième maison sur une propriété tant que toutes les propriétés du groupe n’ont pas une maison.
2. **Prix** :
   - Indiqué sur le titre de propriété.
3. **Hôtels** :
   - Une fois 4 maisons construites sur une propriété, vous pouvez les échanger contre un hôtel.

---

### 2.6. 💰 Faillite

- Si vous devez payer plus que ce que vous possédez, vous êtes en faillite.
- Vous devez alors céder vos propriétés et votre argent à votre créancier.
- Si vous êtes en faillite envers la banque, toutes vos propriétés sont remises aux enchères.

---

### 2.7.🏆 Fin du jeu

- Le jeu continue jusqu’à ce qu’un seul joueur reste en lice, tous les autres étant en faillite.
- **Option** : Fixez une limite de temps. Le joueur le plus riche à la fin gagne.

---

## 3. Travail à faire
### 3.1. Spécifications
Décrivez les fonctionnalités attendues et les règles du jeu implémentées. Listez les classes et leurs relations.

### 3.2. Conception (Diagrammes)
Réalisez des diagrammes UML pour modéliser le jeu :
- Diagrammes de classes pour représenter les joueurs, le plateau, et les cartes.
- Diagrammes de séquence pour illustrer les interactions principales.

### 3.3. Algorithmes
Expliquez les choix algorithmiques pour la gestion des actions de jeu :
- Lancer les dés.
- Gérer l’achat, les enchères, ou la construction.
- Implémenter les conditions de victoire.

### 3.4. Jeux d’essais
Fournissez des exemples de tests :
- Scénarios simples : Achat de propriété, paiement de loyer.
- Scénarios complexes : Construction d’hôtels, faillite d’un joueur.

#### 3.4.1. Classe Case 

##### Description
Réalisation des jeux d'essaies sur la classe Case 

##### Exemples de tests
1. **joueur qui tombe sur une case Impots** :
   - **Entrée** : un joueur tombe sur une case Impots.
   - **Action attendue** : Le joueur perd 200 mono. 
   - **Résultat** :
   ![résultat](img/case_Impots.png)

2. **joueur qui tombe sur une case Taxe de luxe** :
   - **Entrée** : un joueur tombe sur une case taxe de luxe .
   - **Action attendue** : Le joueur perd 200 mono. 
   - **Résultat** :
   ![résultat](img/taxe_de_luxe.png)

3. **joueur qui tombe sur une case Chance** :
   - **Entrée** : un joueur tombe sur une case Chance
   - **Action attendue** : Le joueur gagne 200 mono ou perd 200 mono.
   - **Résultat** :
   ![résultat](img/chance.png)
   ![résultat](img/case_chance.png)

4. **joueur qui tombe sur une case Communauté** :
   - **Entrée** : un joueur tombe sur une case Communauté
   - **Action attendue** : Le joueur gagne 250 mono ou perd 200 mono. 
   - **Résultat** :
   ![résultat](img/com.png)
   ![résultat](img/case_com.png)




## 4. Conclusion
Ce projet permet d’appliquer les concepts d’objet, d’héritage, et de gestion de projet en équipe. Le rendu final comprend :
- Code commenté.
- Diagrammes UML.
- Documentation des choix de conception.
- Jeux de tests montrant le bon fonctionnement.

---
