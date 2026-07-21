# 🐉 Pokémon Battle Simulator (C++)

> *This repository isn't just the final project—it's the story of how I learned Object-Oriented Programming by building a Pokémon Battle Simulator from scratch.*

---

# 📖 About This Project

I'm a second-year B.Tech Artificial Intelligence & Data Science student who wanted to improve my C++ and OOP skills.

Instead of making small practice programs, I decided to build something larger that would force me to think about software design, class relationships, debugging, and modular programming.

This project became my first complete object-oriented application.

---

# 🎯 My Goals

I wanted to learn:

* How to design classes properly
* How objects interact with each other
* Header (`.h`) and source (`.cpp`) file separation
* Encapsulation
* Constructors
* References
* Const correctness
* Modular programming
* Basic game architecture

The goal was **not** to build a perfect Pokémon game.

The goal was to become a better programmer.

---

# 🧠 Planning Phase

Before writing code, I planned the architecture.

Instead of putting everything into one file, I divided the project into separate classes.

```
Move
        │
Pokemon
        │
Team
        │
Trainer
        │
Battle
```

Every class was given a single responsibility.

---

# 📂 Project Architecture

## Move

Stores information about a move.

* Name
* Type
* Power
* PP
* Accuracy

---

## Pokemon

Represents one Pokémon.

Stores:

* Name
* Type
* HP
* Attack
* Defense
* Special Attack
* Special Defense
* Speed
* Four Moves

Functions include:

* takeDamage()
* heal()
* isFainted()
* displayStats()

---

## Team

Represents a trainer's team.

Responsibilities:

* Store six Pokémon
* Keep track of the active Pokémon
* Switch Pokémon
* Check if usable Pokémon remain

---

## Trainer

Stores:

* Trainer Name
* Team

Acts as the owner of a Pokémon team.

---

## Battle

The heart of the project.

Responsible for:

* Running the battle loop
* Executing turns
* Calculating damage
* Handling fainted Pokémon
* Determining the winner

---

# 🚧 Problems I Faced

This project wasn't built in one attempt.

Some problems I had to solve included:

### Constructor errors

Learning how constructor initialization works.

---

### Reference member errors

Understanding why reference members must be initialized correctly.

---

### Const correctness

Learning why getter functions should be marked `const`.

Example:

```cpp
int getPower() const;
```

---

### Linker errors

I discovered that compiling only `main.cpp` causes multiple "undefined reference" errors because the linker cannot find implementations in the other `.cpp` files.

---

### File organization

Learning the difference between:

* Header files
* Source files
* Declaration
* Definition

---

### Battle logic

Designing the battle flow was one of the biggest challenges.

The sequence became:

```
Start Battle

↓

Player Turn

↓

Calculate Damage

↓

Apply Damage

↓

Check Faint

↓

Switch Pokémon

↓

Opponent Turn

↓

Repeat

↓

Winner
```

---

# ⚙️ Damage Formula

Version 1 uses a simple custom damage formula:

```
Damage = Move Power + (Attack / 2) - (Defense / 3)
```

I intentionally kept it simple so I could focus on OOP instead of Pokémon mechanics.

---

# ✨ Features

* Turn-based battle system
* Two trainers
* Six Pokémon per team
* Four moves per Pokémon
* HP tracking
* Damage calculation
* Automatic faint detection
* Automatic Pokémon switching
* Winner announcement
* Console interface

---

# 📸 Sample Output

```
Pikachu used Thunderbolt!
It dealt 91 damage!

Charizard's HP: 29/120

...

==============================
Battle Finished!
Winner : Gary
==============================
```

---

# 📚 What I Learned

This project taught me much more than syntax.

I learned how to think about software design before writing code.

Some important concepts I practiced:

* Object-Oriented Programming
* Composition
* References
* Encapsulation
* Const correctness
* Modular programming
* Debugging
* Project organization
* Separating responsibilities between classes

---

# 🚀 Future Plans

This project is Version 1.

Future improvements include:

* Type effectiveness
* Accuracy system
* PP usage
* Critical hits
* Speed deciding turn order
* Status effects
* AI opponent
* Manual Pokémon switching
* Save/Load battles
* Better console UI

---

# 🙌 Final Thoughts

This project represents my journey from writing simple C++ programs to building a complete object-oriented application.

There are many things that can still be improved, but that's the point of learning.

Every bug I fixed and every design decision I made helped me become a better programmer.

This repository marks the beginning of that journey.

---

## 👨‍💻 Author

**Aditya Shelke**

B.Tech – Artificial Intelligence & Data Science

Learning one project at a time.
