# project

The Near Neighbor Algorithm (or k-NN for short) is an unparalleled local classification and regression algorithm. 
In both cases the input depends on the k closest observations in the feature space. 
k-NN can be used for classification or regression: k-NN for classification: Given the input of a new example, the algorithm belongs to the group. 
The example is associated with the most common class among k nearest neighbors (where k is defined as an integer, usually a small number). 
If k = 1 the object is associated with the class of the nearest single neighbor. k-NN for Regression: Given a new example, the algorithm returns a sample property value.
This value is the average of the k values of the nearest neighbors.

In the first part of our project we made a basic model, as a beginning to the project, of the classifier. 
In the second part of the project, we made a server, that runs the KNN algorithm on TCP or UDP protocol. 
In this part, the third and last part, we made a CLI that has some functions that the KNN can do.
We also changed our classifier to work with 3 optional types of distance - EUC, MAN and CHE.

We made two directories. Client and Server.
These directories aren't related to each other, so the server doesn't know what happens in the client directory, and the client doesn't know what the server does.

We used the Command design pattern, to simplify the calls to the commands. 
The base Command class is abstract, and the commands implement it. 
The commands are stored in a vector of Command*, and when the server gets a number to call, it calls the command in the index of the number(-1) in the vector.

The communication protocol is TCP.
For our port we chose 55755.
our buffer size is 4096.
Our project begins with k=5 and distanceType=EUC, which can be changed easily in the command number 2: In this command, after the client gets the settings, 
he can change them with a number and a string (we assumed the client will give a input in this way), or press "enter" and keep the settings.

We also added a timeout. after 60 seconds without the client connecting, the server stops.
Our project supports some clients and creates a socket for each.
In task 3, the long task that takes time, we used multithreading, in order to make the program faster.

In order to run the project, Clone the git and download our two implemented directories, including two mains, and the classes Iris.cpp, Iris.h, and the CMakeList.txt.

first, in order to make a directory "build" and compile, these are the commands :
mkdir build
cd build
cmake ..
make

Then you should run the server with:
cd server
./Server

And at last, to run the clients use:
cd client
./Client

Good luck !
