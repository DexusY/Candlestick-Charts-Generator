<a id="readme-top"></a>


<br />
<div align="center">
  <h1 align="center">Candlestick Charts Generator</h1>
  <p align="center">
    A C++ program that generates ASCII candlestick charts from CSV stock data.
    <br />  
  </p>
</div>

---

## Table of Contents
- [About The Project](#about-the-project)
- [Demo](#Demo)
- [Built With](#built-with)
- [Prerequisites](#Prerequisites)
- [Installation](#Installation)
- [Usage](#Usage)


---

## About The Project

This project is a simple C++ tool that reads stock data from a CSV file and produces an ASCII candlestick chart. The output chart is saved to `chart.txt`.

Features:
- Parses CSV files with daily stock prices
- Displays Open, High, Low, Close prices as ASCII candles
- Customizable chart size and resolution constants

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---
## Demo

## Built With

| Language | Description |
|----------|-------------|
| 🟦 **C++** | Core programming language for processing CSV files and generating ASCII charts |

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---


### Prerequisites

| Requirement | Description |
|-------------|-------------|
| **C++ compiler** | Working C++ compiler (e.g. `g++`) |
| **Terminal** | Command line to compile and run the program |
| **Programming environment** | Visual Studio Code, CLion, or any other IDE for editing and testing the code |
| **Stock CSV file** | With the (Date,Open,High,Low,Close) format | 

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Installation

Prepare a CSV file with your stock data (e.g., stock_data.csv)

Clone the repository and change directory:

```bash
git clone https://github.com/DexusY/Candlestick-Charts-Generator.git
cd Candlestick-Charts-Generator
```

Open the** `main.cpp` **with text editor, put name of your CSV file in below function and save file:

```cpp
void generate() {
    char chart[DISPLAY_X + 1][DISPLAY_Y];
    init(chart);
    const char* filename = "intc_us_data.csv"; // < your CSV file name
    int lines = countLines(filename); 
    char ch;
    ifstream file(filename);
    goToLine(file, lines - NUMBER_OF_DAYS); 
    for (int i = 0; i < DISPLAY_X; i++) {  
        readLine(file, chart, i);
    }
    printToFile(chart); 
}
```
Compile the project (example for Wnidows using MinGW):

```bash
g++ main.cpp -o candlestick
```

Or open** `main.cpp` **in your preferred programming environment (e.g., Visual Studio Code) and build/run the program from there

### Usage
