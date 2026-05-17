# ⚙️ C++ Modules — 42 School OOP Series

A progressive, hands-on journey through **Object-Oriented Programming in C++**, built module by module as part of the 42 school curriculum. Each module introduces new concepts through isolated exercises — no frameworks, no magic, just C++ the way the language was designed.

---

## 🎯 What This Is

The **C++ Modules** at 42 are a series of 9 independent projects (00–08) that progressively build mastery of C++ from first principles. The constraint: **C++98 standard only** — which forces a deep understanding of the language mechanics before relying on modern conveniences.

Think of it as learning to drive a manual transmission before touching an automatic.

---

## 📚 Modules Overview

| Module | Core Concepts |
|--------|--------------|
| **00** | Namespaces, classes, member functions, I/O streams, initialization lists |
| **01** | Memory allocation, references, pointers to members, file streams |
| **02** | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form |
| **03** | Inheritance, base/derived class relationships |
| **04** | Subtype polymorphism, abstract classes, interfaces, virtual functions |
| **05** | Repetition and exceptions — `try/catch`, custom exception classes |
| **06** | C++ casts: `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast` |
| **07** | Templates — function templates, class templates, template specialization |
| **08** | STL containers, iterators, algorithms — `std::vector`, `std::list`, `std::map` |

---

## 🧠 Key C++ Skills Demonstrated

- **Orthodox Canonical Form** — Every class implements: default constructor, copy constructor, copy assignment operator, destructor
- **Memory safety** — Manual `new`/`delete`, no leaks, RAII principles
- **Polymorphism** — Both compile-time (templates, overloading) and runtime (virtual functions, abstract classes)
- **Exception handling** — Custom exception hierarchies, stack unwinding
- **STL fluency** — Containers, iterators, `std::find`, `std::sort`, algorithm library
- **Type system** — Deep understanding of C++ casting and type safety

---

## 🏗️ Project Structure

```
cpp_module/
├── module00/    # Classes, namespaces, I/O
├── module01/    # Memory, references
├── module02/    # Operator overloading, OCF
├── module03/    # Inheritance
├── module04/    # Polymorphism, interfaces
├── module05/    # Exceptions
├── module06/    # Casts
├── module07/    # Templates
└── module08/    # STL containers & algorithms
```

Each module contains:
- `ex00/`, `ex01/`, `ex02/` — Progressive exercises
- `.cpp` + `.hpp` source files
- `Makefile` for each exercise

---

## 🔧 Build & Run

```bash
cd module04/ex02
make
./program
```

All modules compile cleanly with:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

---

## 💡 Why This Matters

Unlike university courses, 42's methodology is **learn by doing under pressure**. Every module is peer-reviewed by other students — meaning the code must be readable, well-structured, and defensible in a live review session.

The C++98 constraint is intentional: if you understand why `std::auto_ptr` was deprecated or how virtual dispatch works under the hood, writing modern C++11/14/17 becomes trivial. This series proves I understand the *why*, not just the *how*.

---

## 🏫 About 42 School

[42](https://42.fr) is a global network of tuition-free engineering schools with campuses in 50+ countries. The pedagogy is entirely project-based: no teachers, no lectures, no spoon-feeding. Students learn through peer review, trial and error, and RTM (Read The Manual).

---

*Part of my journey at [42 Málaga](https://www.42malaga.com/) · [@fclaus-g](https://github.com/fclaus-g)*
