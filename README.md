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

# Usage
Launch & attach dev container
cd to ./scripts/
run ./compile.sh
exec installed executable


1.          VV here
{"#", "#", ".", ".", ".", ".", "."}
{"#", ".", "#", ".", ".", ".", "."} <- drops the particle

2.     VV here
{"#", ".", "#", ".", ".", ".", "."}
{".", "#", "#", ".", ".", ".", "."} <- drops the particle

