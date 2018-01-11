### Binary Representation

#### 1's complement

Leftmost bit is used to represent a sign.
```
0001 = 1
0111 = 7
```

To get negative number from positive we just invert it
```
0001 = 1
1110 = -1
```

In this representation we have to use two zeros
```
0000 = Positive zero
1111 = Negatie zero
```

To add we do standard binary addition

To substract we convert second agrument to negative and do addition
`3 - 1 is 3 + (-1) is 0011 + 1110 = 0001 and 1 carry over, we add carry over again and 0001 + 1 = 0010 = 2`

**Cons**

- Two zeroes
- We have to add carry over from sign bit again to the end


#### 2's complement

Leftmost bit is still used to represent sign.

To get negative number we invert it and add 1
```
0001 = 1
1111 = -1
```

No negative zero.
When adding negative numbers we just throw away carry over 1, if it happens.

**Pros**

- No negative zero (its one additional negative number instead)
- No additional carry over from the leftmost bit handling as in 1's comp
- Simple overflow rule - the carry overs coming in and coming out the sign bit (leftmost bit) must be the same (either 1/1 or 0/0).


#### Refs

- https://www.youtube.com/watch?v=lKTsv6iVxV4