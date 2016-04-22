# Lecture 4

**April 21, 2016**

Major stages of project planning:

* **Requirements:** Define the problem
* **Analysis:** Understanding the problem
* **Design:** Define the solution

## Analysis: Understanding the problem

Decompose requirements into pieces and then put them back together in analysis. The analysis phase bridges the requirements phase and the design phase.

The requirements stage produces a use-case model which is used as input for the analysis. The use-case model is composed of use-case diagrams and use-case text. The analysis stage is meant to produce an Analysis class diagram.

The first part of analysis is to examine your use-case model for Completeness, Correctness, and Consistency. These are the triple Cs.

The analysis model is organized into four elements. Scenario-based, Flow-oriented, Class-based, Behavioral. Some requirements or functionality is invisible when going into analysis. Similar to a rainbow, certain conditions can reveal what was invisible.

### Analysis styles

* Structured Analysis: focus of the data objects, process, and how the communicate in a system. Focuses on the flow of data throughout a system.
* Object-oriented analysis: Combines the data and functionality into a class. Focuses on contained objects and how the interact.

Always keep in mind the definition of software:

    software = structure + behavior
    software = data flow + control flow

Whatever you produce is consumed by others. All stakeholders must approve of the analysis model. The most usable ideas are the ones we re-invent.

**Domain analysis:** You are creating software for a specific environment (school, healthcare, science). Each domain has different needs and requirements.

**Data Modeling:** Focuses on data, not behavior or functionality. Computation is pointless without data to work on and a specific goal.

An object contains "attributes" or fields that store data. Typical objects can include external entities, things, events, roles, places, or structures.

**ERD: Entity Relationship Diagram:** Maps objects together.

Object-Oriented Concepts:
* Classes and objects
* Attributes and operations
* Encapsulation and Instantiation
* Inheritance

A **class diagram** represents the attributes and operations of an object.

The classes in the analysis model are conceptual class, and will influence the creation of the design model. The design classes are meant to be implemented.

Class diagrams communicate with one another through arrows. A *horizontal* left/right arrow indicates an **association** between classes. The line is labeled with the name of the association.

**Analysis model** finds the classes and their attributes, along with associations.
