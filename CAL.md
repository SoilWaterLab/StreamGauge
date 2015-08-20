#Calibration Protocols for the Cornell Integrated Sensing Station v1 (CISSv1)

*Pete Marchetto, Postdoctoral Research Associate, Cornell Soil and Water Lab*

##Introduction
The CISSv1 is the first version of a massively deployable integrated sensing system for stream gauging. This document is a collection of five protocols to characterize and calibrate its sensors and main microcontroller board. All of these protocols should be carried out at the very least at both room temperature and the maximum and minimum temperatures that the Device Under Test (DUT) will experience in use.

The processes described in these protocols are not calibrations in and of themselves, but are actually characterizations of the sensors and sensing system. The calibration is done in post-processing, where the digital output values of the CISS will be put into the transfer functions described by these tests.

Most importantly, these protocols are scientific experiments: the hypothesis is that the DUT will function as a conglomeration of linear sensors with definable transfer functions. By doing this experiment, one can to expect to either support that hypothesis and gather data that will allow for proper mapping of the sensitivity of the DUT in each of its modalities, or to refute the hypothesis, and find that the system must be repaired.

###Equipment Needed
- DUT (CISS along with its depth sensor and sensor head)
- USB A-to-microB cable
- Laptop
- Conductivity Meter (i.e. Oakton CON 600)
- Conductivity Standards
- Turbidity Meter (i.e. Extech TB400)
- Turbidity Standards
- Surface Plate (i.e. Grizzly G9647)
- Height Gauge (i.e. Starrett 3752-24/600)
- Gauge Blocks
- 1/4" Neodymium Magnet
- Ping-pong Ball with Neodymium Magnet
- Voltage Calibrator (i.e. Extech PRC15)
- 5-1/2 Digit Multimeter (DMM, i.e. Keithley 2110)
- Balance
- Beaker
- Thermometer
- Hot Plate

**Note: All measuring devices and/or standards for each modality must be NIST traceable or equivalent (i.e. NPL, DIN, etc.)**

###Reagents and Compounds Needed
- NaCl
- DI Water
- Isopropanol
- Vegetable Oil
- Ammonia
- Soap
- Dry Ice
- Acetone

###DUT Preparation
In order to prepare the DUT for testing, serial output code should be loaded onto it, and it should be kept connected to a test system computer for the duration of all tests. This can be done by connecting the WildFire board to a computer via a USB A-to-microB cable, and loading the [AnalogRead](https://codebender.cc/sketch:143324) sketch onto it.

##Depth Sensor Characterization
###Theory of Operation
In this characterization, the output of the depth sensor will be characterized as a function of the height at which its float sits. The depth sensor is a [Sharp GP2Y0A02YK0F](https://www.sparkfun.com/datasheets/Sensors/Infrared/gp2y0a02yk_e.pdf) in the top of a PVC pipe, and is capable of measuring a range of 20 to 150 cm from the sensor head. The sensor works by bouncing IR light off of the float (usually a ping-pong ball) and reading out a voltage inversely proportional to the distance from the sensor lens to the float.

###Equipment Needed
- DUT
- USB A-to-microB cable
- Laptop
- Surface Plate
- Height Gauge
- Gauge Blocks
- Ping-pong Ball with Neodymium Magnet
- 1/4" Neodymium Magnet
- 5-1/2 Digit Multimeter

###Pre-cal Procedure
1. Begin by gently placing the height gauge on the surface plate
2. Place the 1/4" Neodymium magnet in its holder on the measuring arm of the height gauge
3. Zero the height gauge by placing its measuring arm gently on the surface plate and pressing the zero button
4. Place the 4" gauge block between the surface plate and the underside of the measuring arm and record the reading on the height gauge (in mm)
5. Place the 2" gauge block on top of the 4" gauge block and repeat the measurement
6. Place the 1" gauge block on top of the other two and repeat the measurement
7. Place the 0.5" gauge block on top of the other three and repeat the measurement
8. Put away the gauge blocks

###Characterization
1. Start the serial terminal of the DUT on the laptop
2. Attach DMM to the power pin and the ground pin, and record the input voltage
3. Attach DMM to the signal and ground pins
2. Clean the end of the depth sensor pipe
3. Insert the ping-pong ball with the neodymium magnet in it into the open end of the depth sensor pipe
4. Place the depth sensor pipe, opening down, onto the surface plate
5. Bring the height gauge alongside the pipe, and lower the measuring arm until the magnet on it attracts the one inside the sensor
6. Move the measuring arm up until the height gauge reads 100 mm, then lock the height gauge in place
7. Record the number being output from the serial terminal and the number on the DMM
8. Move the measuring arm up until the height gauge reads 200 mm, then lock the height gauge in place
9. Record the number being output from the serial terminal and the number on the DMM
10. Move the measuring arm up until the height gauge reads 400 mm, then lock the height gauge in place
11. Record the number being output from the serial terminal and the number on the DMM
12. Move the measuring arm up until the height gauge reads 550 mm, then lock the height gauge in place
13. Record the number being output from the serial terminal and the number on the DMM
15. Move the measuring arm up until the height gauge reads 400 mm, then lock the height gauge in place
16. Record the number being output from the serial terminal and the number on the DMM
17. Move the measuring arm up until the height gauge reads 200 mm, then lock the height gauge in place
18. Record the number being output from the serial terminal and the number on the DMM
19. Move the measuring arm up until the height gauge reads 100 mm, then lock the height gauge in place
20. Record the number being output from the serial terminal and the number on the DMM
21. Remove the ping-pong ball from the pipe
21. Gently remove the height gauge and put it away
22. Disconnect the DMM

###Calibration
1. Enter the data into a spreadsheet in the form: 100,1000,2.41 etc., with the height as the independent variable and the outputs as the dependent variables (first LSB, then V)
2. Find a linear regression that fits the values; make particular note of any hysteresis, as this will be directly proportional to the uncertainty of the sensor
3. Record the equations of the functions that fit, along with their R^2 values
4. Calculate the inverse functions, so LSB and V can be transformed to m

##Temperature
###Theory of Operation
The temperature characterization takes advantage of the thermodynamic stability of phase changes. By having a number of different compounds with different transition points in the same container in roughly the same volumes, multiple transition points can be reached and equilibriated at, thus making it possible to create stable thermal plateaus. This is all done as a transfer calibration with a calibrated thermometer.

###Equipment Needed
- DUT
- USB A-to-microB cable
- Laptop
- 5-1/2 Digit Multimeter
- Balance
- Beaker
- Thermometer
- Hot Plate

###Reagents and Compounds Needed
- Acetone
- DI Water
- Isopropanol
- Dry Ice

###Pre-cal Procedure
1. Place sensor head in a ziploc bag with all air pushed out in a beaker
2. Mix equal parts by weight of 10 g each powdered dry ice, DI water, isopropanol, and acetone in the same beaker
3. Place the beaker on a hot plate

###Characterization
1. Start the serial terminal of the DUT on the laptop
2. Attach DMM to the power pin and the ground pin, and record the input voltage
3. Attach DMM to the signal and ground pins
4. Insert thermometer
5. Turn on hot plate
6. Log temperature, output LSB, and output voltage before all dry ice sublimates
7. Wait until all compounds have melted, then log the temperature, output LSB, and output voltage; this is the water triple point
8. Wait until the first bubbles are seen, then check the thermometer for a temperature of about 56 °C
9. Log the temperature, output LSB, and output voltage; this is the acetone boiling point
10. Wait until the bubbling starts to have renewed vigor, then check the thermometer for a temperature of about 82.6 °C
11. Log the temperature, output LSB, and output voltage; this is the isopropanol boiling point
12. Wait until the bubbling starts to have renewed vigor, then check the thermometer for a temperature of about 100 °C
13. Log the temperature, output LSB, and output voltage; this is the water boiling point
14. Turn off the hot plate
15. Immediately place the ziploc bag containing the sensor head into cold water

###Calibration
1. Enter the data into a spreadsheet in the form: 100,1000,2.41 etc., with the temperature as the independent variable and the outputs as the dependent variables (first LSB, then V)
2. Copy the serial output data into a spreadsheet as a time series
2. Find a linear regression that fits the values
3. Record the equations of the functions that fit, along with their R^2 values
4. Calculate the inverse functions, so LSB and V can be transformed to °C

##Conductivity
###Theory of Operation
The conductivity characterization is straightforward, and merely tests the conductivity of several NaCl solutions made by weight.

###Equipment Needed
- DUT
- USB A-to-microB cable
- Laptop
- Conductivity Meter
- Conductivity Standards
- 5-1/2 Digit Multimeter
- Balance
- Beakers

###Reagents and Compounds Needed
- NaCl
- DI Water

###Pre-cal Procedure
1. Calibrate the conductivity meter using its own conductivity standards
2. Make up solutions of 0.1, 0.5, 1, 5, and 10 g/L of NaCl and DI water in separate beakers
3. Add a standard of pure DI water in a beaker
4. Fill a rinse beaker with DI water
5. Check conductivities with the conductivity meter, rinsing the probe with fresh DI water after each, from least to greatest concentration
6. Record all conductivities

###Characterization
1. Start the serial terminal of the DUT on the laptop
2. Attach DMM to the power pin and the ground pin, and record the input voltage
3. Attach DMM to the signal and ground pins
4. Immerse the sensor head in each beaker and record the serial output and voltage
5. Rinse the sensor head in between each beaker with fresh DI water
6. Move the sensor head to the next highest concentration
7. Rinse the sensor head twice with DI water

###Calibration
1. Enter the data into a spreadsheet in the form: 100,1000,2.41 etc., with the conductivity as the independent variable and the outputs as the dependent variables (first LSB, then V)
2. Copy the serial output data into a spreadsheet as a time series
2. Find a linear regression that fits the values
3. Record the equations of the functions that fit, along with their R^2 values
4. Calculate the inverse functions, so LSB and V can be transformed to S/m

##Turbidity
###Theory of Operation
The turbidity characterization is straightforward, and merely tests the turbidity of several oil and water suspensions.

###Equipment Needed
- DUT
- USB A-to-microB cable
- Laptop
- 5-1/2 Digit Multimeter
- Balance
- Beakers
- Turbidity Meter
- Turbidity Standards

###Reagents and Compounds Needed
- Vegetable Oil
- Soap
- Ammonia
- DI Water

###Pre-cal Procedure
1. Calibrate the turbidity meter using its own turbidity standards
2. Make solutions of 5%, 10%, 20%, and 50% oil to water by mass in their own beakers
3. Make an additional beaker of only water
3. Add sufficient soap to each beaker and stir until the oil is completely suspended
4. Check turbidities of each beaker with the turbidity meter and record them
5. Clean the turbidity meter with ammonia and water

###Characterization
1. Start the serial terminal of the DUT on the laptop
2. Attach DMM to the power pin and the ground pin, and record the input voltage
3. Attach DMM to the signal and ground pins
4. Immerse the sensor head in each beaker and record the serial output and voltage
5. Clean sensor head with ammonia and water

###Calibration
1. Enter the data into a spreadsheet in the form: 100,1000,2.41 etc., with the turbidity as the independent variable and the outputs as the dependent variables (first LSB, then V)
2. Copy the serial output data into a spreadsheet as a time series
2. Find a linear regression that fits the values
3. Record the equations of the functions that fit, along with their R^2 values
4. Calculate the inverse functions, so LSB and V can be transformed to NTU

##Main ADCs
###Theory of Operation
Each ADC channel is referenced to the rail voltage and ground. Since the ATMEGA1264P uses 10-bit ADCs, these need to be checked for correlation to real values of voltage.

###Equipment Needed
- DUT
- USB A-to-microB cable
- Laptop
- 5-1/2 Digit Multimeter
- Voltage Calibrator

###Characterization
1. Start the serial terminal of the DUT on the laptop
2. Unplug all four sensor signal lines, noting their order
3. Attach the voltage calibrator to A0 and ground in parallel with the DMM
4. Set the voltage calibrator for 0 V, then record the output from the serial terminal and the DMM
5. Repeat the former step at 500 mV, 1 V, 1.500 V, and 2 V
6. Repeat the former steps for A1, A2, and A3
7. Detach all instruments
8. Reattach all sensor signal lines

###Calibration
1. Enter the data into a spreadsheet in the form: 100,1000,2.41 etc., with the input voltage as the independent variable and the outputs as the dependent variables (first LSB, then V)
2. Copy the serial output data into a spreadsheet as a time series
3. Check the linearity and sensitivity of the ADCs in LSB/V both with V as measured and V as input