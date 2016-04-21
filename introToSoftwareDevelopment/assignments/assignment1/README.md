# Assignment 1

**Deliverables:**

* List of actors
* Identify the most important use cases for PowerEquipmentInc
* Use-case Model/diagram
* At least one of the use-cases identified should be documented fully
* Include screenshots of diagrams
* Submit your homework as a single pdf file

## Overview

## List of actors

Actors are people or objects that interact with the system. Actors are either actively (directly) or passively (indirectly) interacting with the system. I categorized my actors into two categories, people and systems. People are communicating with one another in the store to run the business. Systems are computers or programs designed to facilitate the process. Minor systems are developed externally and used through an application protocol interface.

**People:**

* Customer
* Salesman
* Manager
* Cashier
* Driver

**Systems:**

* Inventory System - products in stock
* Transaction System - equipment bought, sold, or rented
* User System - information about customers
* Delivery System - coordinate deliveries
* Pricing System (minor) - used to find market prices
* Credit Card System (minor) - used to verify credit cards
* Email System (minor) - used to notify customers

## Use-Cases

Each potential interaction between an actor and a system is called a Use-Case. The most important use-cases are critical to obtaining a MVP (minimum viable product). Use-Cases are used to find overlap between systems and discover all potential functionality. Left-over use-cases go into a backlog and are worked on in future iterations.

### Most important use-cases

1. Buying equipment from store
2. Adding products
3. Finding equipment price
4. Checking out
5. Delivering equipment to user
<<<<<<< HEAD

### All use-cases

**Multi System**

=======

### All use-cases

**Multi System**

>>>>>>> f6c6d86daec7fecd3f89e349e503a931f7275382
* Buying equipment from store
* Selling equipment to store
* Renting equipment per day
* Renting equipment per season
* Renting equipment per year

**Inventory System**

* Adding products
* Finding equipment price
* Updating product information
* Storing discounts/rebates
* Updating sold products
* Updating rented products
* Updating storage products
* Removing discontinued products

**Transaction System**

* Checking out
* Validating credit card
* Adding a replacement plan
* Updating a replacement plan

**User System**

* Adding user information
* Updating user information
* Removing user information
* Becoming a PowerMember
* Removing a PowerMember
* Billing a PowerMember
* Sending emails to customers

**Delivery System**

* Delivering equipment to user
* Picking up equipment from user
* Delivering equipment to warehouse
* Picking up equipment from warehouse

---

## Summary of Use-Cases

Each use-case is described in a brief paragraph. They are categorized roughly by major system and contain information about associated actors.

### Multi System

**Buying equipment from store:** The customer walks into the store and talks to a salesman. The customer selects a piece of equipment that satisfies their needs, and take it to the cash register. The cashier takes the customers personal information (ID and payment), then asks the customer a few more questions. The customer is asked if they want to purchase a replacement plan, to have the equipment delivered, and if they want to become a PowerMember. If the customer requires a delivery, the delivery driver drops off the equipment. Passively, the customer information is added to the user system, the sale is recorded in the transaction system, and the equipment is removed from the inventory system.
<<<<<<< HEAD

**Selling equipment to store:** The customer brings their equipment to the store and talks to the salesman. The salesman checks for the equipment in the inventory system and the pricing system. If the equipment is desirable, the salesman can offer a price to the customer. If the customer agrees to sell, the equipment entered into the inventory system. The customer is payed in cash, check, or in-store credit. Passively, the equipment is entered into the inventory system, the purchase is recorded in the transaction system, and the customer information is stored in the user system.

**Renting equipment per day:** The customer finds a piece of equipment that suits their needs from the salesman. The customer wishes to rent the device for a short period of time. The number of days that the device has been rented out will need to be recorded to keep track of late fees. The customer's information will also need to be recorded in order to contact them at a later time. If the device needs to be delivered, the delivery driver will drop the equipment off at the appropriate location.

**Renting equipment per season:** The customer decides on a piece of equipment to rent for a season, either summer or winter, according to the salesman. The customer information will need to be recorded in order to pick up and drop off equipment. If a drop off is required, the delivery driver is in charge of dropping off the equipment. If a pick up is required at the end of the season, then the delivery driver is in charge of picking up the equipment.

**Renting equipment per year:** The customer decides with the salesman an appropriate piece of equipment for the winter and summer seasons. Information regarding the customers location, credit card, and desired equipment will need to be stored in the system. If delivery is required, a driver is responsive for picking up and dropping off the appropriate equipment.

### Inventory System

**Adding products:** When new equipment comes in from the manufacturer, or is sold to the store by a customer, it needs to be added to the inventory system. The manager is in charge of adding equipment to the inventory system. The manager is also responsible for maintaining the inventory between the storefront and the warehouse.

**Finding equipment price:** The salesman, manager, and cashier all have the ability to search for equipment in the pricing system. This information might or might not already be stored in the inventory system. The inventory system will update the estimated retail value of a piece of equipment based on the pricing system every week. The final sale price might fluctuate based on store discounts, or negotiation between the customer and salesperson.

**Updating product information:** If the information is incorrect for equipment in the inventory system, it must be updated by the manager.

**Storing discounts/rebates:** When equipment is overstocked or out-of-season, the manager should have the ability to assign a discount to the item in the inventory management system.

**Updating sold products:** If equipment is sold to a customer, it must be removed from the current inventory. This is automatically done when the cashier finalizes the sale of the equipment. The inventory system will remove one from the associated item.

**Updating rented products:** If equipment is rented to a customer, the equipment is not available at the storefront. The inventory system will remove one from the current stockpile, but note that a piece of equipment is on rent.

**Updating storage products:** If equipment is overstocked, it must be moved to the warehouse. Equipment is also moved to the warehouse if it is in the off season. The inventory system will recognize when there are no devices available at the store, but that there are devices available at the warehouse.

**Removing discontinued products:** If equipment is no longer carried by the store, it must be removed from the database. Any excess equipment should be put on sale, or disposed of properly. Removing a product should only be allowed if there are none left in the inventory system. An automatic "clean" could be created that removes all items with zero count from the system.


### Transaction System

**Checking out:** After the customer has decided on a device to buy, the cashier is responsible for entering or modifying the information in the database. This includes creating a record in the user system and transaction system. The transaction system is responsible for computing the final price and sales tax of a transaction.

**Validating credit card:** When a cashier enters a customer's credit card information into the transaction system, it should validate the credit card to ensure that the it is a valid credit card.

**Adding a replacement plan:** If the customer wishes to purchase a replacement plan for their equipment, it will be recorded in the transaction system. The type of insurance and whether or not it has been redeemed will need to be stored for each purchase.

**Updating a replacement plan:** If the replacement plan has been redeemed, the record will be updated in the transaction system. User error could also contribute to the replacement plan needing to being modified.

### User System

=======

**Selling equipment to store:** The customer brings their equipment to the store and talks to the salesman. The salesman checks for the equipment in the inventory system and the pricing system. If the equipment is desirable, the salesman can offer a price to the customer. If the customer agrees to sell, the equipment entered into the inventory system. The customer is payed in cash, check, or in-store credit. Passively, the equipment is entered into the inventory system, the purchase is recorded in the transaction system, and the customer information is stored in the user system.

**Renting equipment per day:** The customer finds a piece of equipment that suits their needs from the salesman. The customer wishes to rent the device for a short period of time. The number of days that the device has been rented out will need to be recorded to keep track of late fees. The customer's information will also need to be recorded in order to contact them at a later time. If the device needs to be delivered, the delivery driver will drop the equipment off at the appropriate location.

**Renting equipment per season:** The customer decides on a piece of equipment to rent for a season, either summer or winter, according to the salesman. The customer information will need to be recorded in order to pick up and drop off equipment. If a drop off is required, the delivery driver is in charge of dropping off the equipment. If a pick up is required at the end of the season, then the delivery driver is in charge of picking up the equipment.

**Renting equipment per year:** The customer decides with the salesman an appropriate piece of equipment for the winter and summer seasons. Information regarding the customers location, credit card, and desired equipment will need to be stored in the system. If delivery is required, a driver is responsive for picking up and dropping off the appropriate equipment.

### Inventory System

**Adding products:** When new equipment comes in from the manufacturer, or is sold to the store by a customer, it needs to be added to the inventory system. The manager is in charge of adding equipment to the inventory system. The manager is also responsible for maintaining the inventory between the storefront and the warehouse.

**Finding equipment price:** The salesman, manager, and cashier all have the ability to search for equipment in the pricing system. This information might or might not already be stored in the inventory system. The inventory system will update the estimated retail value of a piece of equipment based on the pricing system every week. The final sale price might fluctuate based on store discounts, or negotiation between the customer and salesperson.

**Updating product information:** If the information is incorrect for equipment in the inventory system, it must be updated by the manager.

**Storing discounts/rebates:** When equipment is overstocked or out-of-season, the manager should have the ability to assign a discount to the item in the inventory management system.

**Updating sold products:** If equipment is sold to a customer, it must be removed from the current inventory. This is automatically done when the cashier finalizes the sale of the equipment. The inventory system will remove one from the associated item.

**Updating rented products:** If equipment is rented to a customer, the equipment is not available at the storefront. The inventory system will remove one from the current stockpile, but note that a piece of equipment is on rent.

**Updating storage products:** If equipment is overstocked, it must be moved to the warehouse. Equipment is also moved to the warehouse if it is in the off season. The inventory system will recognize when there are no devices available at the store, but that there are devices available at the warehouse.

**Removing discontinued products:** If equipment is no longer carried by the store, it must be removed from the database. Any excess equipment should be put on sale, or disposed of properly. Removing a product should only be allowed if there are none left in the inventory system. An automatic "clean" could be created that removes all items with zero count from the system.


### Transaction System

**Checking out:** After the customer has decided on a device to buy, the cashier is responsible for entering or modifying the information in the database. This includes creating a record in the user system and transaction system. The transaction system is responsible for computing the final price and sales tax of a transaction.

**Validating credit card:** When a cashier enters a customer's credit card information into the transaction system, it should validate the credit card to ensure that the it is a valid credit card.

**Adding a replacement plan:** If the customer wishes to purchase a replacement plan for their equipment, it will be recorded in the transaction system. The type of insurance and whether or not it has been redeemed will need to be stored for each purchase.

**Updating a replacement plan:** If the replacement plan has been redeemed, the record will be updated in the transaction system. User error could also contribute to the replacement plan needing to being modified.

### User System

>>>>>>> f6c6d86daec7fecd3f89e349e503a931f7275382
**Adding user information:** When the customer is checking out, they are required to have a valid ID and credit card. The ID is used to enter basic information. The credit card is used to bill the customer as collateral. An email and phone number is recommended to contact that customer and provide notifications. The customer's PowerMember status is also recorded in the user system. The cashier is responsible for collecting all user information.

**Updating user information:** A customer's information is likely to change over time. The cashier and manager have the ability to update this information in the user system. A cashier's error could also require that a customer's information be modified.

**Removing user information:** For privacy reasons, a customer might want their personal information removed from the system. The manager is responsible for removing records from the user system.

**Becoming a PowerMember:** The customer has an option to enroll in a membership program that will provide them with a 5% discount for an up front fee. The cashier is responsible for recording this information in the user management system.

**Removing a PowerMember:** The customer may want to opt out of the membership program, the cashier should have the ability to remove membership from the customer.

**Billing a PowerMember:** Membership is reoccurring each year, so the system should have the ability to charge the customer's credit card at the beginning of a cycle.

**Sending emails to customers:** The store manager should have the ability to send electronic messages to customers notifying them of sales on overstocked or off season equipment. This requires an email being stored in the user management system.

### Delivery System

**Delivering equipment to user:** If the customer requires their equipment to be delivered, the delivery driver is responsible for dropping off the device. The delivery driver should be able to access which deliveries he or she needs to make for the day, along with the corresponding equipment and customer information. This information is stored in the delivery system.

**Picking up equipment from user:** At the end of a contract, the delivery driver might be responsible for picking up devices from a customers residence. These deliveries are stored in the delivery system.

**Delivering equipment to warehouse:** When a device is off season or overstocked, it will need to be moved to the warehouse for storage. The delivery driver is responsible for dropping off equipment at the warehouse. The manager is responsible for determining which devices are off season or overstocked.

**Picking up equipment from warehouse:** When a device is back in season or low on stock at the store front, it will need to be picked up at the warehouse. The delivery driver is responsible for picking up the devices. The manager is responsible for determining which devices need to be restocked.

---
* Use-case Model/diagram

<<<<<<< HEAD

## Fully-formed Use-case

Each fully formed case includes the following information. The assignment requires that we select one use-case and elaborate on it.

* Name - start with a verb
* Scope - systems used
* Level - high-level category
* Primary Actors - people involved
* Stakeholders - invested actors
* Preconditions - conditions for case
* Success Condition - true upon completion
* Success Scenario - description of activity
* Alternate Scenarios - failure conditions
* Special Requirements - non-functional requirements
* Technology - data formats, hardware
* Frequency - repetitiveness of case


**Use-Case Name:** Renting equipment per day
**Scope:** Inventory System, Transaction System, User System, Delivery System
**Level:** Business
**Frequency:** Daily
**Primary Actors:** Customer, Salesman, Cashier
**Stakeholders:** Customer, Manager
**Technology:** Cash Register Terminals, Inventory Management Terminals
**Preconditions:**
* Customer must be interesting in renting a piece of equipment.
* Store must be open and stocked with equipment
**Success Condition:** The customer is able to use the device for a short period of time.
**Success Scenario:** The customer walks into OutdoorPowerEquipmentRetailer looking to rent a device for a few days. After browsing the selection on the floor, a salesman greets himself to the customer looking to facilitate a sale. The customer communicates his or her needs and the salesman recommends an appropriate piece of equipment. When a device is selected, the two walk to the cashier to check out. The cashier collects the customers information to store in the user system, including phone number. A final price is determined using the pricing system and inventory system. The customer provides payment and the sale is finalized. The customer decides to have the equipment delivered, since their car is not large enough. The customer plans to frequently rent equipment from the store, so they also decide to become a PowerMember. At the end of the rental period, the customer is contacted to collect the device.

**Alternate Scenarios:**

* The customer is unable to find a suitable device, and leaves the store.
* The customer is not helped by a salesperson, and shops elsewhere.
* The customer is unable to rent a device because they do not have identification.
* The customer is unable to rent a device because their credit card is denied.
* The customer finds a piece of equipment without a salesperson.
* The customer decides to not have the equipment delivered.
* The customer decides not to buy the membership.

**Special Requirements:**

* The customer must have an ID
* The customer must be able to pay
* The store must be open
* The systems must be working






=======
>>>>>>> f6c6d86daec7fecd3f89e349e503a931f7275382
One Use-case diagram must be in fully-dressed format and follow template. (84)
