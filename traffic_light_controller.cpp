/*
 * Name: Balram Panwar
 * Email id: balram.panwar@gmail.com
 * Name of the file: traffic_light_controller.cpp
 * Win14
 * Microsoft Visual Studio
 * Designing a state machine for a traffic light controller involves defining the different states of the traffic light, 
 * the transitions between these states, and the actions taken during each state. 
 * Here’s a detailed breakdown of how to design a traffic light controller using a finite state machine (FSM).
 */


#include <stdio.h>
#include <unistd.h> // For sleep function

typedef enum {
    S_RED,
    S_GREEN,
    S_YELLOW
} TrafficLightState;

TrafficLightState currentState = S_RED;

// Function to change the traffic light
void changeTrafficLight(TrafficLightState state) {
    switch (state) {
        case S_RED:
            printf("Traffic Light: RED\n");
            break;
        case S_GREEN:
            printf("Traffic Light: GREEN\n");
            break;
        case S_YELLOW:
            printf("Traffic Light: YELLOW\n");
            break;
    }
}

void trafficLightController() {
    while (1) {
        switch (currentState) {
            case S_RED:
                changeTrafficLight(S_RED);
                sleep(30); // Red light duration
                currentState = S_GREEN; // Transition to green
                break;

            case S_GREEN:
                changeTrafficLight(S_GREEN);
                sleep(30); // Green light duration
                currentState = S_YELLOW; // Transition to yellow
                break;

            case S_YELLOW:
                changeTrafficLight(S_YELLOW);
                sleep(5); // Yellow light duration
                currentState = S_RED; // Transition to red
                break;
        }
    }
}

int main() {
    trafficLightController();
    return 0;
}
