# PID Controller Project
Self-Driving Car Engineer Nanodegree Program

---

## Overview

The objective of this project is to understand the PID controller model, which is one of many controllers or control algorithms, used to actuate a vehicle programmatically and keep it in line with a reference trajectory.

## PID Components and Inference
In the project a simulator provides the CTE (crosstrack error) that is used by our code to generate a steering angle back to the simulator, which then steers the car accordingly. The new CTE calcuated from the the new position of the car is then returned to our code, repeating the control and measurement cycle.

I've tried significantly high values for each of the PID components and note their effects on the model in general below. This way we can draw inferences of what each parameter does.

* **P: Proportional component**
The Proportional component of PID generates a steering angle in proportion to the CTE.
By setting this parameter sufficiently high (3.0 in my case) it was noticed that the car's turning was much more responsive to changes in CTE, striving to keep the car from going astray however, the response also becomes too aggressive resulting in highly oscillating motion.
This value is best set low. Experiments proved 0.15 to be sufficient.

* **D: Differential component**
The Differential component is significant only when there is sudden change in the CTE. This makes the controller slow to respond to small changes in CTE but fast to big changes. Thus D alone cannot be used for the controller.
Another benefit of the Differential is to resist sudden changes in the steering angle output, when used in conjunction with the *P* parameter. A relatively large value (5) was experimentally found to be suitable for our purpose.

* **I: Integral component**
The purpose of this component is to neutralize the affects of any systematic bias in steering, by collecting residual CTE over time and feeding it back to the controller's output value.
On its own however (setting P and D to 0), the controller causes the car to oscillate. A small contribution from this component was found to be sufficient (0.05)

This combination of P, I and D values strives to keep the turning smooth at the same time keeping the CTE low and hence the car on the road:
**P | I | D :: 0.15 | 0.05 | 5**

**In summary,** responsiveness to the turn requirement is controlled by the *P* parameter while the *D* parameter controls excessive turns caused by the *P* while at the same time providing strong feedback for sharp turns. Finally, the *I* parameter maintains the overall CTE for the duration of the trip.

## Hyperparameters Selection
As explained above, the parameters were chosen manually to fit the requirement of keeping the CTE low and the vehicle on the road as much as possible, close to the center. Other approach to finding the parameters could have been using the Twiddle algorithm. Indirectly though, the lessons on Udacity by Sebastian and their corresponding code exercises(using twiddle) did hint on the proportion of these parameters, which made tuning them easier.

## Possible improvements
In this controller we are trying to match the expected trajectory and actuating according to the error witnessed after a time step. I believe a better approach would be to first predict the error itself for the next time step and then work towards minimizing it, instead of moving the vehicle first. This way, the turning would then be much smoother and would also minimize CTE further since we are not waiting for the CTE to get larger before acting.
  
