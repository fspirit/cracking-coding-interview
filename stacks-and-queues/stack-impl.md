## Stack Implementations

### Array Of Fixed Size

We just allocate array of some fixed size and start push items to the back of that array.
We just keep track of last index, where value was placed.

http://www.cs.usfca.edu/~galles/visualization/StackArray.html

#### Pros
- All operations (Push, Top, Pop) are O(1). 

### Cons
- Too much or too little memory

### Singly Linked List

Head pointer is a top of a stack. New items are inserted at front. [Example]("stack.h")

#### Pros
- All operations (Push, Top, Pop) are O(1). 
- No problems with size 

#### Cons
- Additional memory (next item pointer) for every item

http://www.cs.usfca.edu/~galles/visualization/StackLL.html