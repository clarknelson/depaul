# Lecture 3

**Design Model:**

1. Define the problem
2. Understand the problem
3. Define the solution

**Use case diagrams:** captures the behavior of the system from a black-box perspective. Documents how the end-user will use the system.

Each Use-case diagram has use-case text associated with it.

    Software = structure + behavior

The *system sequence diagram* implies events over time. How the end user (actor) interacts with a system over time. Events follow one another in a chain. Each event captures the logic and control flow of a program.

The diagram is vertical from top to bottom, with the top being the beginning of the program. Events pass back and forth between the end-user and the system, represented as two lines.

*Operation contracts* specify the pre-conditions and post-conditions for each event in the system sequence diagram.

###

Software Development Process describes an approach to building, deploying, and possibly maintaining software. SDP is the documentation for who can do what, how and when.

The Unified Process is a popular iterative software development process for building object-oriented systems. The Rational Unified Process is a refined approach to the UP.

The UP is very flexible and open, and encourages including skillful practices from other iterative methods, such as Extreme Programming (XP), Scrum, and so forth. Agile process are more successful for smaller to medium sized projects.

A key practice in UP and most other modern methods is iterative development. Each step in the UP is an iteration. Each iteration is three to seven weeks. Each iteration is nothing but a mini waterfall project. The goal is to have functional software at the end of each iteration.

At the end of each iteration, plan the next iteration. Each iteration is time-boxed. At the end of the time period, the iteration ends and extra requirements are passed to the next iteration. The completed requirements for the current iteration is used to set the next iteration's expected number of requirements.

As a project manager, the goal is to design an iteration that all parties can buy into, thus sharing in the success or failure.

Over time the number of requirements in an iteration reaches a more stable number. Over time the project iterations become more stable and people become more comfortable with the process.

**Benefits to Iterative Development:**

1. Less project failure
2. Early migration of rish
3. Early visual progress
4. Early feedback, user engagement, and adaptation.
5. Managed complexity, the team is not overwhelmed
6. Learn as you go

**Phases of UP:**

1. Inception
2. Elaboration
3. Construction
4. Transition

**Disciplines of UP:**

* Business Modeling
* Requirements
* Analysis & Design
* Implementation
* Testing
* Deployment
* Configuration & Change Management
* Project Management
* Environment

**Triple Constraints of Software Development:**

* Deliver on time
* Deliver within budget
* Deliver quality


### Inception:

* What is the vision and business case for this project?
* Feasible?
* Buy and/or build?
* Rough cost: $10k or $100k

Inception is *not* all about finding requirements.

Requirements are capabilities and conditions to which the system and project must conform. Requirements are constantly changing according to stakeholders.

Customer communicates with the product management team. The product manager communicates with the project management. The project manager is responsible for coordinating the implementation team. A high level management team overviews the whole process.

How to find requirements?

* Writing use cases with customers.
* Requirement workshops with developers and customers.
* Focus groups with customers
* Demo the results of each iteration with customers

Types and categories of requirements:

* Functional - features, capabilities, security
* Usability - human factors, help, documentation
* Reliability - frequency of failure, recoverability, predictability
* Performance - response times, thoughput, accuracy, availability, resource usage
* Supportability - adaptability, maintainability, internationalization, configurability

Additional requirements:

* Implementation - resource limitations, languages and tools, hardware
* Interface - constraints imposed by interfacing with external system
* Operations - system management in its operational setting
* Packaging - for example, a physical box
* Legal - licensing and so forth

How to organize requirements

* Use-Case Model - A set of typical scenarios of using a system.
* Supplementary Specification - all non-functional requirements
* Glossary - List of noteworthy terms
* Vision - High level requirements for the project
* Business Rules - Requirements or policies that are not specific to one software project.

### Requirements

What the customer wanted.

Whatever the engineer produces is worth three times as much to the end user.

* Describe customer needs and desires for the system.
* Provide the framework for defining the scope of the system
* Identify broad areas of risk, reuse and systems-level interdependencies
* Establish essential contractual obligations
* Provide foundation for testing

#### Requirements workflow

##### Project Overview Statement

Contains the scope of the project (What capabilities will and will not be included) and the Interfaces (Identify which system the program will interact with).

* Brief project description: Purpose of the project
* (Optional) Competitive analysis
* Project Objectives: Concrete accomplishments and/or deliverables
* Qualitative estimates of benefits and costs

##### Identify stakeholders

Stakeholders are people or organizations that will be affected by the system.

* Clients
* End-Users
* Developers
* Marketing / Sales

##### Understand user goals

User goals are specific, but not detailed, descriptions of what the user wants the system to do. A user goal may lead to one or more requirements. User goals provide the foundation for use-case analysis.

##### Develop a feature list

A high or mid level overview of requirements. Each feature has a number (F003), a name (as descriptive as possible), a description in the form of an explanation, associated user goal (optional), a priority (optional), visibility to the end user, and estimated implementation risk.

##### Build a system context description

A System Context is the environment in which the system is embedded. Identifies entities that are directly relevant to the system.

* Domain objects
* Domain processes
* Domain actors

These are examples of *conceptual classes* not software classes. System context acts as the foundation for the Domain Model.

**Domain objects** are the entities encountered in the world in which the system will operate.

**Example:** Medical PDA software

* "Business" objects: Patient record, appointment record, medication list, synchronization schedule.
* "Real world" objects: Touch screen, synchronization link, host PC
* "Events": Last synchronization date/time with host, create new medication record request, medication alarm notification, anything associated with time.

**Domain actors** interact in some way with the system. Users are a subset of domain actors. Actors may be *active* directly interacting with system or *passive* indirect interaction. Actors can be human or non-human.

---

**Glossary** is the repository for any terms used to describe the system. Includes items identified in the *System Context Description* as well as any terms in interfaces to the system.

**Functional requirements** are behaviors of the system. (Sound alarm). Functional requirements are a subset of the feature list. Functional requirements are *what* not *how*. Functional requirements are found based on the use-case.

Example:
* Allow real-time update of patient medication schedule

**Supplementary requirements** are those not associated with a particular functional requirement. May span multiple use cases, or none at all. Examples include security, reliability, availability, and preformance.

Example Feature/Requirement on slide 53

**Conceptual classes** are a way of helping identify domain objects, processes, and actors.

* Physical or tangible objects
* Specifications, designs, or descriptions
* Places
* Transactions
* Roles of people
* Containers
* Collaborating systems
* Abstract nouns
* Organizations
* Events
* Processes
* Rules and policies
* Catalogs
* Records

A **requirements document** can include:

* Overview statement
* Vision Statement
* Scope
* Customers
* Goals
* System functions
* System attributes
* Competitive analysis
* System Context

Requirements should be measurable and have verifiable objectives. Not "fast" but "10ms".

Requirement documentation should not include the discussion of programming or details on the hardware.

### Business rules

How a company conducts it's business. Likely to apply to several or all use-cases for a particular application

**Domain rules** are facts and information on the domain.

Examples:
* Checks must be approved by manager
* Credit cards must get approval
* Books are due in 14 days

Business rules can be organized in a Business Rule Catalog containing Number, Rule Definition, Flexibility, and Source.


## Use cases

Use cases are text stories, widely used to discover and record requirements.

Use cases are requirements, primary functional or behavioral, that indicate what the system will do.

High-level goals and use case diagrams are input to the creation of the use case text.

The use cases can in turn influence many other analysis, design, implementation, project management, and test artifacts.

**Ideal use case workflow:**

1. Find Actors
2. Find Use Cases
3. Describe Use Case Model
4. Prioritize Use cases
5. Detail Use Cases
6. Structure Use Case Model

Typical ways of modeling system behavior:
Scenarios or story boards, use cases, system sequence diagram, and object interaction diagrams.

The use case describes a set of interactions between the user and the system, possibly with several different outcomes.

A scenario describes a specific path through a use case and the outcome.

A use case represents a collection of scenarios. The primary scenario corresponds to the main system interaction or the success scenario. Alternate scenarios correspond to less frequent interactions.

A scenario is a little story, an outline of some expected sequence of events. A scenario is used to convey how things work. It usually includes at least one actor which makes requests to the system or responds to system activity.

A sequence diagram is a way of drawing a picture of a scenario.

There are three common use case formats:

* Brief - one-paragraph summary, usually of the main success scenario.
* Casual - Informal paragraph format. Multiple paragraphs that cover various scenarios.
* Fully dressed - All steps and variations are written in detail, and there are supporting sections (multiple pages)

Template of a fully dressed use case: Slide 84

Continue lecture at 1:45:00 and slide 89
