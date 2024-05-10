# Subway Management System - C++ Project

This C++ program simulates a subway management system where you can create stations, lines, and manage their details.

## Features

- Add new stations with name, number of platforms, and accessibility information.
- Create new subway lines and assign names to them.
- Add existing stations to existing lines.
- Remove stations from existing lines.
- View a list of all stations and their details.
- View a list of all lines and the number of stations on each line.

## User Interface

The program presents a menu-driven interface where you can choose from various operations.

## Global Variables

- `stations_count`: Keeps track of the total number of stations created.
- `lines_count`: Keeps track of the total number of lines created.

## Classes

- `Station`: Represents a subway station with properties like name, number of platforms, and accessibility for disabled individuals.
- `Line`: Represents a subway line with a name and an array to store stations belonging to that line.
- `subwaySystem`: Not currently used in this implementation, but could be used to manage the overall subway system with multiple lines and stations.

## Functions

- `getInputString()`: Prompts the user for a string input and returns the entered string.
- `getInputInt()`: Prompts the user for an integer input and returns the entered value.
- `getInputBool()`: Prompts the user for a yes/no input (0 for no, 1 for yes) and returns a boolean value.
- `printHeader()`: Prints a decorative header line with a specified character and length.
- `printStationTopics()`: Prints table headers for displaying station details (name, platforms, accessibility).
- `printLineTopics()`: Prints table headers for displaying line details (name, number of stations).
- `showAllStations()`: Displays a list of all stations with their details.
- `showAllLines()`: Displays a list of all lines with their names and the number of stations on each line.
- `addStationToLine()`: Prompts the user to choose a line and a station, and attempts to add the station to the chosen line.
- `removeStation()`: Prompts the user to choose a station and removes it from the system.
- `removeLine()`: Prompts the user to choose a line and removes it from the system.
- `removeStationFromLine()`: Prompts the user to choose a line and a station, and removes the station from the chosen line.