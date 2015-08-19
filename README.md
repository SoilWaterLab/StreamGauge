#Uploading Firmware to you WildFire
##Equipment Needed
- WildFire Board
- USB A-to-microB cable
- Computer
##Process
Using [Google Chrome:](http://google.com/chrome)
1. Get an account at [GitHub](http://github.com)
2. Sign in to [analog.io](http://analog.io) using your GitHub account
3. CLick on "Create Stream"
4. Assign "Sparkfun" as the host
5. Name your data stream in the title field
6. Add a description, including GPS coordinates of your sensing station and calibration constants for its outputs
7. Enter the fields, "depth, conductivity, turbidity, temperature"
8. Enter the location of the sensing station
9. Click "OK", then refresh the page
10. Click on "My Streams" on the left column, and select the data stream you just created
11. Click on "Key Chain" on the top right
12. In a new tab, sign in to [Codebender](http://codebender.cc) using your GitHub account, and get started on the installation process
13. Connect your WildFire to your computer using the USB cable
14. Go to the [sketch page](https://codebender.cc/sketch:142332)
15. Change the PUBLIC_KEY and PRIVATE_KEY variables to match your keys from your analog.io key chain
16. Change the SSID, WiFi password, and security to that which you'll connect to (for unsecured access points/routers, just leave the password as "" and change the security to "WLAN_SEC_UNSEC")
17. Select "WildFire v3[optiboot]" for the board, and the port that you have it plugged into for the port (i.e. "COM3 or /dev/tty.usbserial-AX124")
18. Click "Run on Arduino"
19. Click "Connect" under the serial monitor and check that it has connected to WiFi
20. Check the data stream on analog.io to make certain that data is coming in