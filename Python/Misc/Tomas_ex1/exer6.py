#Tomas, Maren T.
#Y1L - CMSC 12
#Exercise 6

# Inventory System of Convenience Store 

# productdict = {}
# productlist = []

# def addProduct
# 	print("Product ID",
# 		  "Product Name",
# 		  "Product Description",
# 		  "Product Quantity")

product ID = {"Name":"hunzil",
			  "Description":"Mocha Flavor",
			  "Quantity Stored":"Enter quantity stored: ",
			  "AUS":"Canberra",
			  "CND":"Ottawa"}
			# "PH":"Tondo" - Tondo will be printed instead of Manila
print(product ID)
print("The capital of Philippines is", product ID["Name"])
print("The capital of Australia is", product ID["Description"])

The value should be a list
containing the name, description, and quantity stored in that order.


choice = int(input("Product: "))


# if choice in ["1","2","3","4","5","6","0"]:
# 	if choice == "1":
# 		name = input("Enter product name: ")
# 		try:
# 			price = int(input("Enter product price: "))
# 			stock = int(input("Enter product stock: "))
# 			description = int(input("Enter product description: "))
# 			quantity = int(input("Enter product quantity: "))
# 		except ValueError:
# 			print("Out of stock or Input invalid. Try again by entering numeric values.")
# 	elif choice == "2":
# 		print(addProduct) 
# 	elif choice == "3":
# 		print(viewProducts)
# 	elif choice == "4":
# 		print(deleteProduct)
# 	elif choice == "5":
# 		print(restrockProduct)
# 	elif choice == "6":
# 		print(consumeProduct)

# def viewProducts
# 	print("Product ID",
# 		  "Product Name",
# 		  "Product Description",
# 		  "Product Quantity")

# def deleteProduct
# 	print("Product ID",
# 		  "Product Name",
# 		  "Product Description",
# 		  "Product Quantity")

# def deleteAllProducts
# 	print("Product ID",
# 		  "Product Name",
# 		  "Product Description",
# 		  "Product Quantity")

# def restrockProduct
# 	print("Product ID",
# 		  "Product Name",
# 		  "Product Description",
# 		  "Product Quantity")


# def calculator(x, y):
#     print("\n--- CaIcuIator ---")
#     print("[1] Add")
#     print("[2] Subtract")
#     print("[3] MuItipIy")
#     print("[4] Divide")
    
#     choice = input("Enter choice: ")

#     if choice == "1":
#         print("Answer:", add_calc(x, y))
#     elif choice == "2":
#         print("Answer:", sub_calc(x, y))
#     elif choice == "3":
#         print("Answer:", mult_calc(x, y))
#     elif choice == "4":
#         print("Answer:", div_calc(x, y))
#     else:
#         print("Invalid operation choice.")


# con_store = {}

# while True
# 	print("1. Product ID",
# 		  "2. Product Name",
# 		  "3. Product Description",
# 		  "4. Product Quantity")



#Dictionaries - composed of key value pairs 
# not ordered
# mutable

#key - any immutable object (int, float, str, bool), 
# - acts as the index 

#value - any python object (int, float, str, bool with data structures inside of it like lists or dictionaries)
# <dictionary_name> = {key:value, key:value...}

#Sample 1
# empty_dict = {}
# print(empty_dict)

# #Sample 2
# student = {"2015-1111":"Jonathan","2020-2222":"Jose"}
# print(student)
# # element - student no. and name

# #Sample 3
# numbers = { "one":1, "two":2, "three":3, "four":4, "five":5}
# print(numbers)

# #Sample 4
# capitals = {"PH":"Manila",
# 			"JPN":"Tokyo",
# 			"SK":"Seoul",
# 			"AUS":"Canberra",
# 			"CND":"Ottawa"}
# print(capitals)

# #Sample 5 
# weird = {100:"1H",5.5:"Five","String":100, True:"LOL"}
# "numbers":[1,2,3],"alphabet":{"a":"A","b":"B"} #di gumana
# print(weird)

# sample 6
# capitals = {"PH":"Manila",
# 			"JPN":"Tokyo",
# 			"SK":"Seoul",
# 			"AUS":"Canberra",
# 			"CND":"Ottawa"}
# 			# "PH":"Tondo" - Tondo will be printed instead of Manila
# print(capitals)
# print("The capital of Philippines is",capitals["PH"])
# print("The capital of Australia is",capitals["AUS"])
# # do not repeat a key

# # Sample 7 - ADD
# song_list = {"Taylor Swift":"Cruel Summer","Bruno Mars":"Just the way you are","Vice Ganda":"Boom Panes"}
# print(song_list)
# reference value - use a new key
#add a new value
# song_list["BTS"]="Run BTS"
# print(song_list)
# #try to access BTS to print added new element in dctnry
# print(song_list["BTS"])

# Sample 8 - EDIT 
# song_list = {"Taylor Swift":"Cruel Summer","Bruno Mars":"Just the way you are","Vice Ganda":"Boom Panes"}
# print(song_list)
# print("============")
# song_list["Taylor Swift"]="Enchanted"
# print(song_list)
# #update the value because meron na key ng Taylor S.
# song_list["Bruno Mars"]=["APT","Versace on the Floor","Grenade"]
# print(song_list)
# song_list["Bruno Mars"]=100
# print(song_list)

# append - 

#Sample 9 - delete
# song_list = {"Taylor Swift":"Cruel Summer","Bruno Mars":"Just the way you are","Vice Ganda":"Boom Panes"}
# print(song_list)
# del song_list["Vice Ganda"]
# print("============")
# print(song_list)

# value1 = song_list.pop("Taylor Swift") 
# #pop deletes T.S. from dictionary but saved in value1
# #value1 - store deleted value 
# print(song_list)
# print(value1)

# song_list.clear()
# print(song_list)
# song_list["Cup of Joe"] = "Multo"
# print(song_list)

# Sample 10 - check membership
# song_list = {"Taylor Swift":"Cruel Summer",
# 			 "Bruno Mars":"Just the way you are",
# 			 "Vice Ganda":"Boom Panes"}
# print(song_list)
# print("Taylor Swift" in song_list)
# print("BINI" in song_list)
# #in - bool value True

# if "Bruno Mars" in song_list:
# 	print("YEp!")
# else:
# 	print("Naur!")

# Sample 11 - Iteration / Get iterable objects 
# song_list = {"Taylor Swift":"Cruel Summer",
# 			 "Bruno Mars":"Just the way you are",
# 			 "Vice Ganda":"Boom Panes"}
# print(song_list)

# for artists in song_list.keys():
# 	print(artists)
# #.keys prints all keys in the function
# print("=========")
# for songs in song_list.values():
# 	print(songs)
# #.values prints all values in the function
# print("=========")
# for artist, song in song_list.items():
# 	print(artist,"-",song)
#.items - iterate/print both key and value

# Sample 12 - printing
# declare the dictionary

# food = {}
# print(food)
# for i in range(3): 
# 	food_name = input("Enter food:")
# 	food_price = int(input("Enter price:"))

# 	food[food_name] = food_price
# #range(3) = loop 3x

# print("=======")

# for f_n, f_p in food.items():
# 	print(f_n,"-",f_p)
# print("=======")
# print(food)
#use this if user input lahat ng value 

#viewproduct - print
#6 - update stock of product
#print - product DNE
