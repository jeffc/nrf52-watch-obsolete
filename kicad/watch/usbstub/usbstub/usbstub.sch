EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:USB_C_Receptacle_USB2.0 J1
U 1 1 5E4B4C50
P 1350 1600
F 0 "J1" H 1455 2467 50  0000 C CNN
F 1 "USB_C_Receptacle_USB2.0" H 1455 2376 50  0000 C CNN
F 2 "Connector_USB:USB_C_Receptacle_Palconn_UTC16-G" H 1500 1600 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1500 1600 50  0001 C CNN
	1    1350 1600
	1    0    0    -1  
$EndComp
Text GLabel 2200 1000 2    50   Input ~ 0
VBUS
Wire Wire Line
	2200 1000 1950 1000
$Comp
L Device:R R1
U 1 1 5E4B4D1C
P 2200 1200
F 0 "R1" V 2150 1350 50  0000 C CNN
F 1 "5.1k" V 2200 1200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2130 1200 50  0001 C CNN
F 3 "~" H 2200 1200 50  0001 C CNN
	1    2200 1200
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5E4B4DD5
P 2200 1300
F 0 "R2" V 2150 1450 50  0000 C CNN
F 1 "5.1k" V 2200 1300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2130 1300 50  0001 C CNN
F 3 "~" H 2200 1300 50  0001 C CNN
	1    2200 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	1950 1200 2050 1200
Wire Wire Line
	1950 1300 2050 1300
$Comp
L power:GND #PWR0101
U 1 1 5E4B4E49
P 2500 1250
F 0 "#PWR0101" H 2500 1000 50  0001 C CNN
F 1 "GND" V 2505 1122 50  0000 R CNN
F 2 "" H 2500 1250 50  0001 C CNN
F 3 "" H 2500 1250 50  0001 C CNN
	1    2500 1250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2350 1200 2500 1200
Wire Wire Line
	2500 1200 2500 1250
Wire Wire Line
	2500 1250 2500 1300
Wire Wire Line
	2500 1300 2350 1300
Connection ~ 2500 1250
Text GLabel 2150 1500 2    50   Input ~ 0
DN
Wire Wire Line
	2150 1500 2050 1500
Wire Wire Line
	1950 1600 2050 1600
Wire Wire Line
	2050 1600 2050 1500
Connection ~ 2050 1500
Wire Wire Line
	2050 1500 1950 1500
Text GLabel 2150 1700 2    50   Input ~ 0
DP
Wire Wire Line
	2150 1700 2050 1700
Wire Wire Line
	1950 1800 2050 1800
Wire Wire Line
	2050 1800 2050 1700
Connection ~ 2050 1700
Wire Wire Line
	2050 1700 1950 1700
NoConn ~ 1950 2100
NoConn ~ 1950 2200
$Comp
L power:GND #PWR0102
U 1 1 5E4B53D3
P 1200 2600
F 0 "#PWR0102" H 1200 2350 50  0001 C CNN
F 1 "GND" H 1205 2427 50  0000 C CNN
F 2 "" H 1200 2600 50  0001 C CNN
F 3 "" H 1200 2600 50  0001 C CNN
	1    1200 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2600 1050 2600
Wire Wire Line
	1050 2600 1050 2500
Wire Wire Line
	1350 2500 1350 2600
Wire Wire Line
	1350 2600 1200 2600
Connection ~ 1200 2600
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5E4B5808
P 3950 1250
F 0 "J2" H 3977 1226 50  0000 L CNN
F 1 "Conn_01x04_Female" H 3977 1135 50  0000 L CNN
F 2 "Connector_JST:JST_SH_SM04B-SRSS-TB_1x04-1MP_P1.00mm_Horizontal" H 3950 1250 50  0001 C CNN
F 3 "~" H 3950 1250 50  0001 C CNN
	1    3950 1250
	1    0    0    -1  
$EndComp
Text GLabel 3600 1150 0    50   Input ~ 0
VBUS
Text GLabel 3600 1250 0    50   Input ~ 0
DN
Text GLabel 3600 1350 0    50   Input ~ 0
DP
$Comp
L power:GND #PWR0103
U 1 1 5E4B5880
P 3600 1500
F 0 "#PWR0103" H 3600 1250 50  0001 C CNN
F 1 "GND" H 3605 1327 50  0000 C CNN
F 2 "" H 3600 1500 50  0001 C CNN
F 3 "" H 3600 1500 50  0001 C CNN
	1    3600 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 1500 3600 1450
Wire Wire Line
	3600 1450 3750 1450
Wire Wire Line
	3750 1350 3600 1350
Wire Wire Line
	3600 1250 3750 1250
Wire Wire Line
	3750 1150 3600 1150
$EndSCHEMATC
