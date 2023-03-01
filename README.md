# Memory Editor for macOS

Memory Editor for macOS V 0.1

## Motivation
Windows has a fairly standard process to editing memory using their api. 
This programs aims to serve as introduction to using the macOS api.


## Features

Currenly supportes modifying int values, std::string, and char. 

## Prerequisites

C++ 11
Cmake 3.10

## Installation

Once you have downloaded the files run

```console
$./install.sh
```

## Usage

Run the program with

```console
$sudo MemoryEditor
```


## Tutorial

Navigatge to the tutorial folder.

Included in the folder is a dummy program.
To build, compile with your favorite compiler. For the sake of this tutorial we use g++

```console
$g++ dummyprogram.cpp -o dummyprogram
```

and run with ./dummyprogram

This program will display a few different data types and their memory location.

Run MemoryEditor and follow the script.


## TODO

* Support more data types
* Memory Scanner
* Add a gui
