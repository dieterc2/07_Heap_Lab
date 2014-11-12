07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. TODO
2. TODO

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1 Adding seven to the heap would first place it as the left child of 16, and then would have it bubble up until it would be the right child of six. For three, it would start out
	as the right child of seven, then bubble up to end up being the new root. 
10.2 To remove six, it would first be replaced with 55, the last element of the array, and then 55 would trickle down until it would be the left child of 50. To remove 8, it would be 
	switched with 55 again and trickle down to be the left child of 16.

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.4	
#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Make sure the logic within the bubble up and trickledown fucntions are sound as they are the main work-doers of the program and the data structure will be incorrect without it.