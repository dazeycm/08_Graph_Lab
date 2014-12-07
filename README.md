08_Graph_Lab
============

Implement a simple graph class

Requirements
------------

1. Implement all methods of the `Graph` class.

Reading
=======
"Open Data Structures," Chapter 12, the whole chapter. http://opendatastructures.org/ods-cpp/12_Graphs.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. add - It works. It adds an edge between two nodes with the given cost.
2. remove - Remove works. It removes the edge between to two nodes.
3. getCost - getCost successfully gets the cost between two nodes.

#### 2. For each of your methods, what is the worst-case running time? You may write your answer in terms of `n` (the number of vertices), `m` (the number of edges), `d` (the maximum degree of any node in the graph), or any combination of these. Try to give the most informative bound that you can.

1. add - O(1) because you simply have to add the edge to the back of the vector. 
2. remove - O(d) because you have to move through possibly every edge for a certain node.
3. getCost - Once again O(d) time because you go to a node and iterate through its edge list to find a the destination node and get its cost. 

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

http://i.imgur.com/aCFdzS2.png 

Should have just screen capped it. 

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I would make sure that you're actually implementing an adjacency matrix, because it's easy to assume that the index represents a connection, when really it's the value in the array. 
