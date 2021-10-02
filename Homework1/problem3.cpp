
//Aliza Siddiqui; 09/10/2021
//This program will keep track of the golf ball trajectory (x and y coordinates) until it reaches the ground
//Input: initial velocity of ball, angle at which ball is pucked, initial height of the ball, distance of the golfer from the tree
//Output: x and y coordinates of the ball

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <cmath>
using namespace std;


int main(){
    const float pi = 3.141592653589793;
    float initial_vel = 25.6;   //initial velocity of the golf ball, m/s
    float angle = 35;           //Angle golf ball is hit at, degrees
    int initial_h = 2;          //initial height of the golf ball on the hill,m
    float distanceTree = 1.4;   //Distance between the golfer and the tree, m
    float y = initial_h;        //Setting initial height to y variable as initial value (vertical distance the ball travels), m


    ofstream outfile;

    outfile.open("golfBallTrajectory.txt");
    outfile << "Initial Velocity: " << initial_vel << " m/s" << endl;
    outfile << "Angle of trajectory: " << angle << " degrees" << endl;
    outfile << "Initial Height of Ball: " << initial_h << " meters" << endl;
    outfile << "Golfer's distance from the tree: " << " meters" << distanceTree << endl;

    int i = 1; //Keeps track of the iterations
    double x = 0;  //Horizontal distance the ball travels, m
    double t = 0.1; //Keeps track of the time iterations, s

    while(y > 0){   //while the ball has not reached the ground
        outfile << "Iteration " << i << endl;

        x = initial_vel*cos((angle*pi) / 180.0) * t; //x position of the ball
        outfile << "x position: " << x << endl;


        y = initial_h + (initial_vel*sin((angle*pi)/180.0)*t) - ((0.5)*(9.8)*pow(t, 2)); //y position of the ball
        outfile << "y position: " << y << endl;


        t = t + 0.1; //time interval
        outfile << "time t: " << t << endl;
        i++;
        outfile << "------------------------------------------" << endl;
    }

    return 0;
}
