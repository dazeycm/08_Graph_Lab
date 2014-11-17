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

1. add - Running time should be constant. 
2. remove - Running time should be constant.
3. getCost - Running time should be constant.

The running times for all of the above are constant because I used pointers to find the edgeList and then used the index inside of the edgeList as the destination. 

#### 3. Exercise 12.1 from http://opendatastructures.org/ods-cpp/12_4_Discussion_Exercises.html. You may want to draw by hand, upload the picture online (Instagram, Twitter, imgur, or some place like that), and then just put a link here.

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Well, I'm a little confused overall. I originally implented this lab with the push_back method, and that worked fine, but then we had to loop through the edgelist to find nodes and when you have to do this multiple time, it's expensive. So I changed my methods to use pointers, and treated the index of the edgeList as the destination. This has the consequence of making my adjacency list act more like an adjacency matrix. I'm no longer putting the new edges at the end of the edge list, but instead putting them in the index that corresponds to the destination. This has to be wrong, right?
