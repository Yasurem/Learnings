# Exercise 06: Dictionaries

"""
Emulate a simple inventory system for a convenience store.
This convenience store wants to keep track of the products they sell and their stock quantities.
This convenience store also wants to be able to:
    - add products
    - delete products
    - restock the quantities
    - consume the quantities
"""

def display_menu():
    print("----------------------------- MENU -----------------------------")
    print("[1] Add New Product")
    print("[2] View All Product")
    print("[3] Delete a Product")
    print("[4] Delete All Products")
    print("[5] Restock a Product")
    print("[6] Consume a Product")
    print("[0] Exit")
    return int(input("Enter choice: "))


def addProduct(inventory):
    id = input("Enter product ID: ")

    attributes = []
    name = input("Enter product name: ")
    description = input("Enter product description: ")
    quantity = int(input("Enter product quantity: "))

    attributes.insert(0, name)
    attributes.insert(1, description)
    attributes.insert(2, quantity)

    inventory[id] = attributes


def viewProducts(inventory):
    for id, attributes in inventory.items():
        print(id)
        print(f"Name: {attributes[0]}")
        print(f"Description: {attributes[1]}")
        print(f"Quantity: {attributes[2]}")


def deleteProduct(inventory, id):
    if id in inventory:
        del inventory[id]
    else:
        print("The product does not exist.")


def deleteAllProducts(inventory):
    inventory.clear()


def restockProduct(inventory, id):
    restock_quantity = int(input("Enter amount to restock: "))
    inventory[id][2] += restock_quantity


def consumeProduct(inventory, id):
    consume_quantity = int(input("Enter amount to consume: "))
    if consume_quantity > inventory[id][2]:
        print("Insufficient stock.")
    else:
        inventory[id][2] -= consume_quantity
        print(f"Consumed {consume_quantity} from {inventory[id][0]}.")


#----------------------------- MAIN -----------------------------
# Initialize empty dictionary
inventory = {
    # "products_id": ["name", "description", "quantity"]
}

while True:
    choice = display_menu()
    match choice:
        case 1:
            addProduct(inventory)

        case 2:
            viewProducts(inventory)

        case 3:
            product_id = input("Enter product ID: ")
            deleteProduct(inventory, product_id)

        case 4:
            deleteAllProducts(inventory)

        case 5:
            product_id = input("Enter product ID: ")
            if product_id in inventory:
                restockProduct(inventory, product_id)
            else:
                print("Product not found.")

        case 6:
            product_id = input("Enter product ID: ")
            if product_id in inventory:
                consumeProduct(inventory, product_id)
            else:
                print("Product not found.")

        case 0:
            break