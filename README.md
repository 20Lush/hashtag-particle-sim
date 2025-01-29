```
You are given a matrix of characters representing a big box. Each cell of the matrix contains one of three characters:
'.', which means that the cell is empty;
'*', which means that the cell contains an obstacle;
'#', which means that the cell contains a small box.
You decide to rotate the big box clockwise to see how the small boxes will fall under the gravity. After rotating, each small box falls down until it lands on an obstacle, another small box, or the bottom of the big box.
Given box, a matrix representation of the big box, your task is to return the state of the box after rotating it clockwise.
Example
For
box = [['#', '#', '.', '.', '.', '.', '.'],
       ['#', '#', '#', '.', '.', '.', '.'],
       ['#', '#', '#', '.', '.', '#', '.']]

the output should be
solution(box) = [['.', '.', '.'],
                 ['.', '.', '.'],
                 ['.', '.', '.'],
                 ['#', '.', '.'],
                 ['#', '#', '.'],
                 ['#', '#', '#'],
                 ['#', '#', '#']]
                 
                 
box = [['#', '#', '.', '.', '.', '#', '.'],
       ['#', '#', '#', '.', '.', '*', '.'],
       ['#', '#', '#', '*', '.', '#', '.']]

the output should be
solution(box) = [['#', '.', '.'],
                 ['#', '.', '.'],
                 ['#', '#', '.'],
                 ['*', '#', '.'],
                 ['.', '#', '#'],
                 ['.', '*', '#'],
                 ['#', '.', '#']]

```
# Solution

see ./executable/src/main.cpp

# Usage
1. Launch my dev container
2. cd to ./scripts/
3. run ./get_dependencies.sh
4. run ./compile.sh
5. exec installed executable

compiled in gcc, dev container lacks gdb debugger though :(

# Expected output:

```
# # . . . . . 
# # # . . . . 
# # # . . # . 

. # # . . . . 
. # # # . . . 
. # # # . . # 

. . # # . . . 
. . # # # . . 
. . # # # . # 

. . . # # . . 
. . . # # # . 
. . . # # # # 

. . . . # # . 
. . . . # # # 
. . . # # # # 

. . . . . # # 
. . . . # # # 
. . . # # # # 

. . . 
. . . 
. . . 
# . . 
# # . 
# # # 
# # # 
Successfully computed solution 1

# # . . . # . 
# # # . . * . 
# # # * . # . 

. # # . . . # 
. # # # . * . 
# # # * . . # 

. . # # . . # 
. . # # # * . 
# # # * . . # 

. . . # # . # 
. . # # # * . 
# # # * . . # 

. . . . # # # 
. . # # # * . 
# # # * . . # 

# . . 
# . . 
# # . 
* # . 
. # # 
. * # 
# . # 
Successfully computed solution 2
```
