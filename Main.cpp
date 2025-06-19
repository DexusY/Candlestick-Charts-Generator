#include <iostream>
#include <fstream>
#include <math.h>

#define RESOLUTION 0.5f //Resolution for Y axis
#define DISPLAY_X 200 // chart's width
#define DISPLAY_Y 50 // chart's height
#define BASE 25 //the lowest value to be displayed on the chart
#define NUMBER_OF_DAYS 200 //last n days

using namespace std;

int countLines(const char* filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return -1;
    }

    char ch;
    int lineCount = 0;

    while (file.get(ch)) {
        if (ch == '\n') {
            lineCount++;
        }
    }

    if (file.eof() && ch != '\n') {
        lineCount++;
    }

    file.close();
    lineCount--;
    return lineCount;
}

void goToLine(std::ifstream& file, int lineNum) {
    file.clear();
    file.seekg(0, std::ios::beg);

    char ch;
    int currentLine = 0;

    while (file.get(ch) && currentLine < lineNum - 1) {
        if (ch == '\n') {
            currentLine++;
        }
    }
}

void readLine(ifstream& file, char chart[DISPLAY_X + 1][DISPLAY_Y],int day) {
    float data[6] = { 0,0,0,0,0,0 };

    char ch;
    int counter = 0;
    bool point = false;
    float temp = 0;
    int precision = 0;
    while (true) {
        file.get(ch);
        if (ch == '\n') {
            break;
        }else
        if (ch == ',') {
            temp = temp / pow(10, precision);
            data[counter] += temp;
            counter++;
            temp = 0;
            precision = 0;
            point = false;
        }else
        if (ch == '.') {
            point = true;
        }else
        if (!point) {
            data[counter] *= 10;
            data[counter] += ch-'0';
        }
        else {
            temp *= 10;
            temp += ch - '0';
            precision++;
        }
    }
    cout <<day<<". " << data[1] << " " << data[2] << " " << data[3] << " " << data[4] << " " << endl;
    
    int id1 = (data[3] - BASE) / RESOLUTION;
    int id2 = (data[2] - BASE) / RESOLUTION;
    char sign = '|';
    for (int i = id1; i < id2; i++) {
        if (DISPLAY_Y - i > 0 && i > 0)
            chart[day][DISPLAY_Y - i] = sign;
    }
    
    
    id1 = (data[1] - BASE) / RESOLUTION;
    id2 = (data[4] - BASE) / RESOLUTION;
    sign = 'O';
    if (id1 > id2) {
        int temp;
        temp = id2;
        id2 = id1;
        id1 = temp;
        sign = '#';
    }

    for (int i = id1; i < id2; i++) {
        if(DISPLAY_Y -i>0 && i>0)
        chart[day][DISPLAY_Y -i] = sign;
    }
}

void init(char chart[DISPLAY_X+1][DISPLAY_Y]) {
    for (int x = 0; x < DISPLAY_X; x++) {
        for (int y = 0; y < DISPLAY_Y; y++) {
            chart[x][y] = ' ';
        }
    }
    for (int y = 0; y < DISPLAY_Y; y++) {
        chart[DISPLAY_X][y] = '\n';
    }
}

void printToFile(char chart[DISPLAY_X+1][DISPLAY_Y]) {
    fstream outfile("chart.txt", std::ios::in | std::ios::out | std::ios::trunc);
    for (int y = 0; y < DISPLAY_Y; y++) {
        for (int x = 0; x < DISPLAY_X + 1; x++) {
            outfile.put(chart[x][y]);
        }
    }
}

void generate() {
    char chart[DISPLAY_X + 1][DISPLAY_Y];
    init(chart);
    const char* filename = "intc_us_data.csv";
    int lines = countLines(filename); 
    char ch;
    ifstream file(filename);
    goToLine(file, lines - NUMBER_OF_DAYS); 
    for (int i = 0; i < DISPLAY_X; i++) {  
        readLine(file, chart, i);
    }
    printToFile(chart); 
}
int main() {
    cout << "author name" << endl;
    cout << "q - quit program" << endl;
    cout << "g - generate chart" << endl;
    char input;
    while (true) {
        cin >> input;
        if (input == 'q') {
            return 0;
        }
        if (input == 'g') {
            generate();
        }
    }
    return 0;
}
