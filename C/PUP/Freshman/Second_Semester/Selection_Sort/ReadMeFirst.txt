
Everything in the folder "Selection_Sort" was created by Joemarc Jr. D. Castillo for the course Computer Programming 2
 
Note:
        Non-lesson-related features such as display, interactives, and main contain the label "NLR_" 
        
        The folder "Headers" contains all the header files used in this activity                    
        
        The folder "C" contains the main file and the function definitions of the headers in the "Headers" folder

Steps to run the program:
    a. Extract the folder inside the directory where you usually program

    b. To enter a folder, use the "cd" command 
        Example: If your terminal window says "PS C:\Users\JM\", input the command "cd Downloads" to go to "C:\Users\JM\Downloads"

        To exit a folder, use the "cd ../" command which will move you outside a folder

    c. Make sure that you are in the file directory .\Selection_Sort, do so by using the "cd" commant in terminal
        Example:
            If your terminal window says "PS C:\Users\JM\Downloads" and the "Selection_Sort" folder is in the Downloads folder you must input the command "cd Selection_Sort"

        Important!
        Your terminal window must print say that you are inside the "Selection_Sort" folder
        Example: "PS C:\Users\JM\Downloads\Selection_Sort"

    d. Run these commands in the terminal in this order: 
    
        1. gcc -c C/NLR_main.c C/NLR_display.c C/NLR_interactive.c C/LR_lesson.c
        2. gcc NLR_main.o NLR_interactive.o NLR_display.o LR_lesson.o -o Complete
        3. ./Complete

That's it, hope it helps!

Note: This way of coding is similar to how DLSU teaches first years : P

    