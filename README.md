# CPP Modules 05-09

Cursus C++ avancé - Projet 42 Paris

## À propos

Ce repository regroupe les modules CPP 05 à 09 du cursus C++ de 42. Ces modules abordent les concepts avancés du C++ : exceptions, casts, templates, containers STL, et algorithmes.

Ces modules m'ont permis de maîtriser les aspects avancés du C++ et de comprendre la programmation générique avec les templates.

## Structure

```
cpp_modules_05_09/
├── module_05/    # Repetition & Exceptions
├── module_06/    # C++ Casts
├── module_07/    # C++ Templates
├── module_08/    # Templated containers, iterators, algorithms
└── module_09/    # STL
```

## Module 05 - Repetition & Exceptions

**Concepts abordés :**
- Exceptions
- Try-catch blocks
- Gestion d'erreurs
- Classes d'exception personnalisées
- Classes abstraites avec exceptions

**Exercices :**
- `ex00` : Mommy, when I grow up, I want to be a bureaucrat! - Classe Bureaucrat avec exceptions
- `ex01` : Form up, maggots! - Form avec validation et exceptions
- `ex02` : No, you need form 28B, not 28C... - Form abstraite avec différents types de formulaires
- `ex03` : At least this beats coffee-making - Intern qui crée des formulaires dynamiquement

**Ce que j'ai appris :**
- Gestion des exceptions avec `try`, `catch`, `throw`
- Création de classes d'exception personnalisées (héritant de `std::exception`)
- Propagation des exceptions et gestion de la stack unwinding
- Gestion propre des erreurs en C++ avec exceptions
- Différence entre exceptions et codes de retour
- Utilisation de `what()` pour les messages d'erreur
- Classes abstraites avec méthodes virtuelles pures
- Factory pattern avec Intern

## Module 06 - C++ Casts

**Concepts abordés :**
- Casts C++ (`static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`)
- Type safety
- Conversions de types
- Base class casting

**Exercices :**
- `ex00` : Scalar converter - Conversion de types avec casts
- `ex01` : Serialization - Sérialisation avec casts et pointeurs
- `ex02` : Identify real type - Identification du type réel avec dynamic_cast

**Ce que j'ai appris :**
- Utilisation des casts C++ au lieu des casts C
- `static_cast` pour conversions explicites sûres
- `dynamic_cast` pour conversions polymorphiques (retourne nullptr si échec)
- `const_cast` pour modifier la constance
- `reinterpret_cast` pour conversions de bas niveau (à éviter sauf cas très spécifiques)
- Conversion entre types de base et dérivés
- Sérialisation de données avec casts

## Module 07 - C++ Templates

**Concepts abordés :**
- Templates de fonctions
- Templates de classes
- Spécialisation de templates
- Paramètres de template non-types
- Template metaprogramming

**Exercices :**
- `ex00` : A few functions - Templates de fonctions
- `ex01` : Iter - Templates avec itérateurs
- `ex02` : Array - Template de classe Array

**Ce que j'ai appris :**
- Programmation générique avec templates
- Création de fonctions et classes génériques
- Spécialisation de templates pour cas particuliers
- Paramètres de template (types et valeurs)
- Compile-time polymorphism
- Templates avec itérateurs
- Création de containers génériques
- Gestion de la taille à la compilation avec templates

## Module 08 - Templated containers, iterators, algorithms

**Concepts abordés :**
- Containers STL (vector, list, map, etc.)
- Itérateurs
- Algorithmes STL
- Foncteurs et lambdas

**Ce que j'ai appris :**
- Utilisation des containers de la STL
- Différents types d'itérateurs
- Algorithmes génériques (find, sort, transform, etc.)
- Foncteurs et fonctions lambda
- Programmation fonctionnelle en C++

## Module 09 - STL

**Concepts abordés :**
- Standard Template Library complète
- Containers avancés
- Algorithmes complexes
- Allocators

**Ce que j'ai appris :**
- Maîtrise complète de la STL
- Choix du bon container selon le besoin
- Utilisation avancée des algorithmes
- Performance et complexité des opérations STL
- Allocators personnalisés

## Compilation

Chaque module et exercice a son propre Makefile :

```bash
cd module_05/ex00
make

cd module_06/ex00
make
```

## Ce que j'ai appris globalement

- **Gestion d'erreurs** : Exceptions vs codes de retour
- **Type safety** : Casts C++ pour conversions sûres
- **Programmation générique** : Templates pour code réutilisable
- **STL** : Maîtrise complète de la bibliothèque standard
- **Performance** : Comprendre la complexité et choisir les bons outils
- **Best practices** : Utilisation moderne du C++

## Progression

Ces modules représentent une progression vers le C++ moderne :
1. **Module 05** : Gestion d'erreurs avec exceptions
2. **Module 06** : Sécurité des types avec casts
3. **Module 07** : Programmation générique avec templates
4. **Module 08** : Containers et algorithmes STL
5. **Module 09** : Maîtrise complète de la STL

Chaque module construit sur les précédents pour créer une compréhension complète du C++ moderne.

---

**Projets réalisés dans le cadre du cursus 42 Paris**
