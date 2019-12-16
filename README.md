# maze-generation

## By: Andrew Hrabowyj

This program fills a 2D vector with blank spaces and walls, and tests whether or not it's a solvable maze. The maze difficulity varies depending on the user's specification.


## Functionality

The program fills a 15 x 15 2D vector with walls "#" and blanks " ", and then using a right-wall maze traversing algorithm determines if the maze has an ending. The user is prompted to ask how difficult they would like the maze from 1-4. 1 being 66% blanks, 2 being 50% blank, 3 being 40% blank, and 4 being 33% blank.


## Testing

You can use the included Makefile to test your code. Simply run:

```
make test
```
