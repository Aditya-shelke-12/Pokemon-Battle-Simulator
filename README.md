# Pokémon Battle Simulator (C++)

A turn-based Pokémon Battle Simulator built in **Modern C++** to practice **Object-Oriented Programming, clean software architecture, and game logic**.

The goal of this project is not to recreate the entire Pokémon game, but to progressively build a battle engine while following good software engineering practices such as version control, modular design, and iterative development.

---

## Features

### Battle System

* Turn-based battle system
* Speed determines move order
* Speed tie resolved randomly
* Manual Pokémon switching
* Automatic switching after a Pokémon faints
* Win/Loss detection

### Battle Mechanics

* Type Effectiveness (18-type matrix)
* Dual-Type Pokémon support
* STAB (Same Type Attack Bonus)
* Accuracy & Miss system
* Critical Hits
* PP (Power Points)
* Damage calculation
* Immunities
* Super Effective / Not Very Effective messages

### AI

* Basic AI opponent
* Random move selection
* Random Pokémon switching after fainting

### Input Validation

* Invalid menu input handling
* Cannot switch to active Pokémon
* Cannot switch to fainted Pokémon
* Prevents using moves with no PP

---

## Project Structure

```text
Pokemon-Battle-Simulator
│
├── include/
│   ├── Battle.h
│   ├── Trainer.h
│   ├── Team.h
│   ├── Pokemon.h
│   ├── Move.h
│   ├── PokemonType.h
│   ├── TypeChart.h
│   └── Action.h
│
├── src/
│   ├── Battle.cpp
│   ├── Trainer.cpp
│   ├── Team.cpp
│   ├── Pokemon.cpp
│   ├── Move.cpp
│   ├── TypeChart.cpp
│   └── main.cpp
│
└── README.md
```

---

## Technologies

* C++17
* Object-Oriented Programming
* Git & GitHub
* Console Application

---

## Concepts Practiced

* Classes & Objects
* Encapsulation
* Composition
* Enums
* Static Members
* References & Const Correctness
* Modular Programming
* Separation of Responsibilities
* Random Number Generation
* Version Control using Git

---

## Current Architecture

```text
Battle
│
├── Turn Management
├── Damage Calculation
├── Move Selection
├── Battle UI
├── AI Decisions
└── Winner Detection

Trainer
└── Owns Team

Team
└── Owns Pokémon

Pokemon
└── Owns Moves

Move
└── Battle Move Data

TypeChart
└── Type Effectiveness Matrix
```

---

## Version History

### Version 1

* Basic turn-based battle
* Damage calculation
* Pokémon switching
* Winner detection

### Version 2

* Type chart matrix
* Dual types
* STAB
* Critical hits
* Accuracy system
* PP system
* Battle formatting
* Battle menu
* AI opponent
* Random AI move selection
* Random AI Pokémon switching
* Refactored battle architecture
* Code cleanup and const-correctness

---

## Planned Features (Version 3)

* Smarter AI
* Status Conditions (Burn, Poison, Sleep, Paralysis)
* Physical / Special Split
* Held Items
* Abilities
* Weather Effects
* Move Effects
* Saving & Loading Battles

---

## Build

Compile using:

```bash
g++ src/*.cpp -Iinclude -std=c++17 -O2 -o PokemonBattleSimulator
```

Run:

```bash
./PokemonBattleSimulator
```

On Windows (PowerShell):

```powershell
g++ src/*.cpp -Iinclude -std=c++17 -O2 -o PokemonBattleSimulator.exe
.\PokemonBattleSimulator.exe
```

---

## Learning Goals

This project is being developed incrementally to improve:

* C++ Programming
* Object-Oriented Design
* Software Architecture
* Clean Code Practices
* Git Workflow
* Problem Solving

Each major improvement is developed on a separate Git branch before being merged into the main branch.

---

## Author

**Aditya Shelke (Surya)**

B.Tech – Artificial Intelligence & Data Science

This project is part of my journey to strengthen my C++ and software engineering skills by building increasingly complex systems from scratch.
