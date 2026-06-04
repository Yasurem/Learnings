#Tomas, Maren T.
#Y1L 
#Exercise 5

# Strings - collection of characters
# char - stores one character sa other language
# name = "Maren" #pwedeng single quote or double basta same lahat
# school = "UPLB"
# subject = "CMSC 12"

# # string length
# print(len(name))
# print(len(school))
# print(len(subject))

# #Indexing = indiv elements of the string; starts sa zero
# fruit = "Strawberry"#letter S has index 0 so 3 is a
# print(fruit[3]) #a
# print(fruit[9]) #y
#pag negative, right to left start pero -1 magstart

# STRING SLICING
# msg = "I love programming"
# msg = "Strawberry" #-#start ay inclusive,end ay exlusive
# slicer = msg[4:len(msg)]
# slicer = msg[2:6]
# print(slicer)
# print("msg:",len(msg))
# slicer = msg[4:-1]
# print(slicer)
# slicer = msg[-10:4]
# print(slicer)

#if slicer has a missing value, gusto natin ay kasama hanggang dulong value
# slicer = msg[2:]
# print(slicer)
# slicer = msg[:6]
# print(slicer)
#indexing pag wala colon, slicing pag meron

#string concatenation 
# vegl = "Pechay"
# veg2 = "carrot"
# print(vegl, veg2)
# print(vegl+veg2)
# print(vegl+"OK"+veg2)
# print(vegl+"OK"+veg2+"20")
#pplicable lang plus sa string na pinagdidikit,  #not ang 20 kasi integer

#string repetition
# string1 = "Woah!"
# print(string1*3)
# print(string1*(3+2))
# print(string1*(-3))

# string looping
# msg = "Pupunta ako sa agro"
# # for letter in msg: #letter is just a variable, in msg nagsasabi ng string
# # 	print(letter, end="+")  
# 	# print(letter, end="") #\n new line ibig sabihin sa gitna ng ""
# 	# print(letter)
# # sinasabi ng code na ito na every letter sa message ay ipiprint

# for i in range(0,len(msg)):
# 	print("i:",i,msg[i])
# 	# print(msg[i])

# msg = "Pupunta ako sa Mars!"
# i = 0
# while i < len(msg):
# 	print(msg[i])
# 	i = i + 1
#more examples sa pic ng for, while, at range

# Other String Methods
# string2 = "I like adobo and sisig."
# string3 = "menudo"
# string4 = "kaldereta"
# # print(string3.capitalize()) #if it encounters a small letter sa simula, gagwin lng niya capital

# #uppercase

# print(string4.upper())
# print(string4.lower())
# print("replace")
# print(string2.replace("i","I"))
# print(string2.replace("s","$"))
# print(string2.replace("o","ooo"))
# print(string2.replace("adobo", "milkshake"))
# x = "si" - hihig

# index built in f(x)
# string2 = "I like adobo and sisig."
# string3 = "menudo"
# string4 = "kaldereta"

# print(string3.index("u")) #3
# print(string4.index("a")) #1 nearest instance
# print(string2.index("adobo")) #7 kasi 0 start ng count

#isdigit, isupper, islower - return a bolean value
# string3 = "kangkong"
# print(string3.isdigit()) #strict na all numbers dapat
# print(string3.isupper())
# print(string3.islower())

# mutability
# msg = "I love comsci"
# # msg[0] = "A" # error
# msg = msg[msg.index("I")+1:len(msg)] #itong message ay may slicing, inside the slice ay may dalawang number, hanapin mmo yung may i tapos plus 1 so length of message

# msg = "I love comsci"
# msg = "We" + msg[msg.index("I")+1:len(msg)]
# print(msg)
# #may tinuro sa replacement, nasa gallery

#Lists - similar sa ?
# list1 = list() #empty list
# list2 = [1,2,0,1.2,45.5, "nari"] #collection of values
# print(list2)
# print(list1)

# List length - kung ilang elements inside the list, sa string ay characters
# list2 = [1,0,1.2,45.5, "nari"] 
# print(len(list2))

# list indexing
# list2 = [1,0,1.2,45.5,"nari"] 
#another list inside the list
# list2 = [1,0,1.2,45.5,"nari", ["a","bcd",100]]
# print(list2[4])
# print(list2[2])
# # pwede rin iindex ang string
# print(list2[4][2])
# print(list2[5][2])

# list slicing
# list2 = [1,0,1.2,45.5,"nari", ["a","bcd",100]]
# print(list2[:3])
# print(list2[:-3])

# list concatenation
# nasa gallery

# list repetition
# list3 = [1,2,3]
# list4 = ["a", "b", "c"]

#list looping
#nasa gallery

# i = i + 1 para di mag infinite loop

# list append
# pokemon = ["mudkip","piplup","pikachu"]
# print(pokemon)
#if we use append method
# pokemon = ["mudkip","piplup","pikachu"]
# print(pokemon)
# pokemon.append("charizard")
# print(pokemon) #if di ka naglagay ng another print, di madadagdag charizard
# pokemon.append("charizard")
# pokemon.append("charizard")
# pokemon.append("charizard")
# pokemon.append("charizard")
# print(pokemon)

# # list count
# print(pokemon.count("charizard"))
# # print(pokemon.count("mudkip"))|


# #list insert
# print(pokemon)
# pokemon.insert("squirtle")
# print(pokemon)

# #list remove

# #list index
# print(pokemon.index("squirtle"))

#list sort - integers or float works

#list reverse

#lists are pwede baguhin value
# mutability
# msg = "I love comscIII"
# msg[0] = "A" 

# list6 = [100,200,300,400]
# list6[2] = "banana"
# print(list6)

# # bonus discussion 
# list7 = ["red", "blue", "yellow"]
# print(list7[1])
# print(list7[1][2])