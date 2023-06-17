# push_swap

This project aims to sort the given data on a stack using a limited set of instructions.
In addition, it is aimed to achieve this with the least possible number of transactions.

## Introduction

The push_swap project, which is included in the curriculum of 42 Schools, is a project that focuses on the sorting of data. In the project, an array of integer values, two stacks and instructions to manipulate these stacks were used. Our goal is writing a C program called `push_swap` that calculates and displays the smallest path to sort the given integers.

## Goals

The goals of this project include developing a sorting algorithm, gaining experience in complexity analysis, and practicing basic algorithms using the C programming language.

## Usage

You can find instruductions about how to execute the project in bellow down:

1. In first step, copy the project to a local directory.

2. Next, compile the project by using `make all` command.

3. After the compile process, execute `push_swap` program and give an array of integer as a argument.

`./push_swap 4 2 7 1 5`

This command will print the smallest instruduction list will use for to sort given integer list.

4. In addition, you can check the truth of sorting by use `checker` program. `checker` program is going to recieve the list of instruductions produced by the `push_swap` program and check the integer list by using this instruductions.

`./push_swap 4 2 7 1 5 | ./checker 4 2 7 1 5`

If the integer list has sorted correctly, `OK` message will be displayed. Otherwise, You take `KO` message.

## Algorithm and Data Structure

"Quick Sort" algorithm were used in this push_swap project. Also two stack were used that create with doubly linked list.

- Quick Sort: This algorithm sorts the data by dividing it around a pivot element. First, a pivot element is selected. Later, those smaller than the pivot element are collected in one stack, while those larger than the pivot element are collected in the other stack. This process is repeated until the separation process is complete in both batches. Then, the decomposed stacks are sorted and combined in the same process.

- Stacks: These stack structures are created using a Double Linked List. Each node has a structure with references to both the previous node and the next node. This feature provides both forward and backward navigation on the list and works first in, last out (FILO).


