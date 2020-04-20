# Anemometer
A small project for measuring wind speed using rotating Anemometer.

# Contents

**[Group Members 2](#_Toc391770470)**

**[Introduction: 4](#_Toc391770471)**

**[Background studies 4](#_Toc391770472)**

**[Working procedure 5](#_Toc391770473)**

**[Mechanical design 6](#_Toc391770474)**

**[Specification: 7](#_Toc391770475)**

**[Working mechanism (Flow of work) 7](#_Toc391770476)**

**[Schematic (electrical portion only): 8](#_Toc391770477)**

**[Usability: 9](#_Toc391770478)**

**[Limitations 9](#_Toc391770479)**

**[Further Possible Upgrades 9](#_Toc391770480)**

**[Important learning from this project 9](#_Toc391770481)**

**[Algorithm of code 10](#_Toc391770482)**

**[Software and materials used 10](#_Toc391770483)**

# Introduction:

Wind speed is one of the prime measures for meteorological data. An anemometer can measure the speed of wind.

The aim of this project was to develop a low cost anemometer with local instruments and components available.

# Background studies

Natural wind in the open air is a three-dimensional vector that has the directions of north, south, east and west in addition to vertical components and magnitude (i.e., wind speed). As the vertical component is ignored for most operational meteorological purposes, surface wind is practically considered as a two-dimensional vector.

Wind blowing over the earth&#39;s surface is turbulent, and is characterized by random fluctuations of speed and direction. This can be seen in smoke drifting from a chimney, for example, as it fluctuates from quick to slow and backward, right, left, up and down. This rapid fluctuation is called gusting. Wind speed is classified into instantaneous and average types. The average wind speed is the average of the instantaneous wind speed over a ten-minute period. As described above, however, wind speed fluctuates continuously, and measured values of instantaneous wind speed are affected by anemometer response characteristics. Defined below are some basic terms and units used in wind measurement, with a focus on those related to response characteristics that affect anemometer performance.

**Cup Anemometers:**

A cup anemometer has three or four cups mounted symmetrically around a freewheeling vertical axis. The difference in the wind pressure between the concave side and the convex side of the cup causes it to turn in the direction from the convex side to the concave side of next cup. The revolution speed is proportional to the wind speed irrespective of wind direction. Wind speed signals are generated with either a generator or a pulse generator.

The cups were conventionally made of brass for its qualities of rigidity and rust resistance. In recent years, however, cups made of light alloy or carbon fiber thermo-plastic has become the mainstream, allowing significant reductions in weight. Beads are set at the edges of the cups to add rigidity and deformation resistance. They also help the cup to avoid the effects of turbulence, allowing the stable measurement of a wide range of wind speeds.

**Propeller Anemometers:**

A propeller anemometer has a sensor with a streamlined body and a vertical tail to detect wind direction and a sensor in the form of a propeller to measure wind speed integrated into a single structure. It measures wind direction and wind speed, and can indicate/record the instantaneous wind direction and wind speed in remote locations. It also measures the average wind speed using wind-passage contacts or by calculating the number of optical pulses. This type is used as the standard anemometer of the Japan Meteorological Agency (JMA).

There are generator-type and optical pulse generator-type propeller anemometers. At present, the optical pulse generator type is mainly used because its contact resistance is small over a wide range of wind speeds from weak to strong, and its measurement system can be made small and lightweight. Some anemometers are capable of measuring wind speeds from 0.4 to 90 m/s.

# Working procedure

Our working on this project was divided into two major parts.

- Building a mechanical body
- Designing and implementing an electrical circuitry to measure rotation

# Mechanical design

We choose to use cup anemometer for a couple of reason,

- It is low costly one and can be build with locally available materials
- It is easier to build
- Its response is linear to variation of wind speed.
- Calculation of speed can be done easily with less calibration

In our design we used a computer cooling fan as base of our mechanical rotator. With this base we glued a small pipe to elevate it slightly where we attached three of our cup to distant using small pieces of sticks. Our mechanical design made was around 11 inches in diameter. The picture below shows the mechanical prototype we used.

![](RackMultipart20200420-4-1tuppmk_html_366ec5a84d38a8d6.jpg)

We used 3 cups over 4 cups because we found out in experiment that 4 cups provided a less response than the 3 cup design

# Specification:

Measuring range : 0 – 10 km/h
 Dimension : 27 cm diameter at top for the mechanical part
 Weight : 100 gm approximately
 Power : 3.3V – 5V (5V preferable)
 operating at : 16 MHz
 Optional : Possibility to show speed in m/s

# Working mechanism (Flow of work)

![](RackMultipart20200420-4-1tuppmk_html_e845fb60aafa3824.jpg)

# Schematic (electrical portion only):

![](RackMultipart20200420-4-1tuppmk_html_fb3fe7d5f16e14f6.png)

# Usability:

This anemometer can be used to measure low to moderate winds in home and some commercial purpose. As it is low cost (around 500 taka) many of this can be used together to take data&#39;s around large areas without ease.

Also small farmers and can use them in fields to monitor wind speed. Alarms can also be integrated to alert for sudden rise in wind speed.

# Limitations

Although the device is much effective, there are some limitations of the design of this anemometer.

First of all the design cannot withstand large wind speeds. In such condition the mechanical body may break due to its lack to withstand high force.

# Further Possible Upgrades

This project has a scope of many further possibilities for improvement.

Possible improvements can be pointed as

- Making a solid mechanical design could improve effeciency
- Expansion with other weather data to be used as weather station
- Code can be slightly changed to make tachometer
- Measuring rotation of cars, cycle or other rotating objects
- Interrupt driven timers

**Important learning f** r **om this project**

There is much important learning from this project. These can be pointed as:-

- Interrupt operation
- ADC operation
- LCD interfacing
- Microcontroller

# Algorithm of code

**Important :** This is just a sample algorithm intended for understanding the mechanism. Actual algorithm used is slightly different from it.

A code has been written in AVR STUDIO to program the microcontroller. The algorithm of the code is as follows

_do always_

_for 4 s_

_for hall\_sensor Check interrupt;_

_if interrupt = true_

_increase count;_

_after 4 s_

_wind speed = count\*3.14\*.27\*.25\*3.6_

_display LCD_

_count=0_

# Software and materials used

**Software**

Proteus : For Real-time simulation
 AVR Studio : For Programming
 Arduino : Program downloading

**Hardware**

Microcontroller : ATMEGA328
 Oscillator : 16 Mhz
 Programmer : usbasp / Arduino
 Display : LCD (16 X 2 alphanumeric)
 Potentiometers : 103
 Hall Effect sensor : 6851
