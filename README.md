#ENG
Japanese Candlestick Chart Generator Overview
This project is a Japanese Candlestick Chart Generator that processes stock market data from a CSV file and generates a graphical representation of Japanese candlestick patterns in a text format. The output is saved to a chart.txt file for easy viewing. It is a simple yet effective tool for analyzing stock price movements visually.

Features
-CSV Data Parsing: Reads stock market data from a specified CSV file.

-Candlestick Chart Generation: Creates a candlestick chart representing the high, low, open, and close prices for a given number of days.

-Customizable Parameters:

-RESOLUTION: Granularity of the Y-axis.

-DISPLAY_X and DISPLAY_Y: Dimensions of the chart.
BASE: Lowest value displayed on the chart.

-NUMBER_OF_DAYS: Number of days to include in the chart.

-User Interaction: Command-based interface for generating charts.

-Output: Saves the chart to a chart.txt file for later review.


How It Works
-Input Data: The program reads data from a CSV file (intc_us_data.csv).
The CSV is expected to have the following columns: Date, Open, High, Low, Close, and Volume.

-Data Parsing:
Extracts Open, High, Low, and Close values.
Calculates the ranges for the candlestick body and wicks.

-Chart Rendering:
Uses a 2D character array to render the candlestick chart.
Candlestick body (O or #) and wicks (|) are plotted based on price data.

-File Output:
The generated chart is saved in a chart.txt file.

#PL
