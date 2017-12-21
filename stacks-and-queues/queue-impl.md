## Queue Implementations

Ops

- Enqueue
- Dequeueu 

All ops must be O(1) time.

### Array

We use fixed size array and 2 indexes: 
- **read index**, which points to the element, which will be returned on next `dequeue`
- **write index**, which points on next empty arrat cell, where a value will be places on next `enqueue` 
Indexes are moving circular.
When read & write are the same - queue is empty. 

http://www.cs.usfca.edu/~galles/visualization/QueueArray.html

### Linked List

We place next item to the back, when doing `enqueue` and returning `head`, when doing `dequeue`. We keep 
a pointer to the last item to make `enqueue` O(1) operation.

[Example]("queue.h")

http://www.cs.usfca.edu/~galles/visualization/QueueLL.html


