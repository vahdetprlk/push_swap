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

## Algorithm


