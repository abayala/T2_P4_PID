# CarND-Controls-PID
---
Self-Driving Car Engineer Nanodegree Program

The objective of this project is to implement a PID controler that tries to drive a car in the center of the road, in a smooth manner and without getting off track.

The provided simulation contains sharp turns and straight parts in the track. 
The cross track error, is provided by the simulator, and represents the discrepancy of the position of the car in the road with respect to the center of the road. 
As taught in the lessons the PID controller implemented can have the form:

car_steering_angle = -kp*cte - ki*cumulative_cte - kd*differential_error



## Variable explanations:
kp: Is the proportional gain, and for our case it will affect how strong we steer or react to reach the center fo the lane

cte : is the provided cross track error described before

ki: Is the integral gain, and will affect the performance when there is a bias of the system, for example when the wheels are not aligned and causes a missmatch between steering angle command and actual steering angle of the car. For our case, the simulator is assumed to have a perfect wheel alignment

cumulative_cte: Is the summ of the cte over time

kd: Is the differential gain, and will smooth the approach to the goal, this means it will potentialize the correction input. As soon as the car starts correctiong the whole term kd*differential_error will apport information and will smooth the steering strength. 

differential_error: is the difference betweent the previous iteration and the current iteration


## Gain values selection

The most fancy way to perform this is to implement the twiddle algorithm shown in class, probably over a fix number of cycles using the simulator. Optimizing one parameter at a time and fixing the others. Unfrotunatley due to time constrains on my side, I could not implement it, I hope I have time to come back to this. 
For now I tried different values of the Kd and Kp, leaving ki =0, since we assume the simulator has a perfect wheel alignment.
First I choose kp = 1.0 and Kd =1.0, unfortunately the car was performing very aggressive steering wheel movements and getting off track. I lowered the values to kp=0.25 and kd=0.75. In which it drove without getting of track but making aggressive moves and oscilating most of the times from one side to another of the lane. For this reason I decided to be less agressive in the steering reaction and set kp = 0.1, and to set a bit higher the feedback gain kd =0.85. This made the car go smoothly thtough all the track. It is a bit smooth in the sharp turns and almost goes out of road, but performs good. 

