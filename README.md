# Lem_in

The goal of this project is to find the quickest way to get n ants across the farm

HOW IT WORKS

1. Compile all files (jus print make at the root of repository) it is create binary file "lem-in"
2. Then type, for example [./lem-in < lem-in_maps/100_map_0]. You can chose different map from (lem-in_maps) directory.

![](https://github.com/tt1m0n/Lem_in/blob/master/Lemin_1.gif)

-----------------------------------------------------------------------------------------------------------

• This project will only be corrected by actual human beings. You are therefore free to organize and name your files as you wish, 
although you need to respect some requirements listed below.

• The executable file must be named lem-in.

• You must submit a Makefile. That Makefile needs to compile the project and

must contain the usual rules. It can only recompile the program if necessary.

• If you are clever, you will use your library for your lem-in. Also submit your folder libft including its own Makefile at the root of your repository. 
Your Makefile will have to compile the library, and then compile your project.

• Your project must be written in C in accordance with the Norm.

• You have to handle errors in a sensitive manner. In no way can your program quit

in an unexpected manner (Segmentation fault, bus error, double free, etc).

• Your program cannot have memory leaks.

• You’ll have to submit at the root of your folder, a file called author containing your username followed by a ’\n’

• Within your mandatory part you are allowed to use the following functions:

◦ malloc

◦ free

◦ read

◦ write

◦ strerror 

◦ perror

--------------------------------------------------------------------------------------

• Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). 
They will also need to avoid traffic jams as well as walking all over their fellow ants.

• At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible. 

• Each room can only contain one ant at a time. (except at ##start and ##end which can contain as many ants as necessary.)

• We consider that all the ants are in the room ##start at the beginning of the game.

• At each turn you will only display the ants that moved.

• At each turn you can move each ant only once and through a tube (the room at the receiving end must be empty).

