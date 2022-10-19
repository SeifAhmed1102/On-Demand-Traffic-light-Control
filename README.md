# On-Demand-Traffic-light-Control
This is an On-demand Traffic light control system for the EgFWD Embedded Systems Professional NanoDegree Scholarship. This project was written in C using Microchip Studio and Proteus 8 professional. This Project aims to simulate an On-Demand traffic light control system, which has a Pedestrian button to allow them to pass when needed. 

## Demonstration

Here, I used Proteus 8 Professional in order to simulate AVR Atmega32. I have the wiring labeled below. <br></br>
[](url)
![Picture1](https://user-images.githubusercontent.com/94747268/196742527-6bdda76a-09c2-4b89-baee-a66d181868f6.png)


## System Functionality
- The system handles 6 LEDs
- Car LEDs switch every 10s (each switch includes 5s yellow light blinking interval)
- Pedestrian LEDs switch red and green lights every 10s
- `Button`: the button acts as a request for a pedestrian to cross the street
  * The system will stop cars if not already on red light as per request and turn the Pedestrian yellow light
  
  ## Details & Program Flow Chart
- You can find system details and program flow chart in project documentation [here](https://github.com/SeifAhmed1102/On-Demand-Traffic-light-Control/blob/main/On-demand%20Traffic%20light/Project_documentation.pdf)
