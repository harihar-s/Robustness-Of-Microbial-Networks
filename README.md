# Robustness of Microbial Networks

## Introduction
We test the robustness of microbial networks to different attacks.

## Running the code
To compile the code enter the following in the terminal
```sh
make
```
To run the code enter the command 
```sh
./exec attackType dataFile
```

where attackType is one of {"maxdegree", "maxstrength"} and dataFile is the name of the text file with the adjacency matrix.