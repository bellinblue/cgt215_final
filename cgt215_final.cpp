// cgt215_final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//If the cell is alive, then it stays alive if it has either 2 or 3 live neighbors
//If the cell is dead, then it springs to life only in the case that it has 3 live neighbors

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include <vector>
#include <list>

using namespace std;
using namespace sf;
using namespace sfp;

RenderWindow window(VideoMode(1000, 1000), "Conway's Game of Life");

int * cellData(int cell_num) {
    //Collect data about cell size & cell count across the axes.

    int cellSize_x = 20;
    int cellSize_y = 20;
    int cellCount_x = window.getSize().x / cellSize_x;
    int cellCount_y = window.getSize().y / cellSize_y;
    int data[6] = {0, (cell_num / cellCount_y) % 100, cellSize_x, cellSize_y, cellCount_x, cellCount_y};

    int len = to_string(cell_num).length();
    if (len % 10 == 4) {
        cell_num = cell_num % 100;
    }
    else if (len % 10 == 3) {
        cell_num = cell_num % 100;  
    }

    if (cell_num >= cellCount_x) {
        data[0] = cell_num - cellCount_x;
    }
    else { data[0] = cell_num; }

    return data;
}

void drawCell(int cell_num) {
    RectangleShape cell;
    cell.setFillColor(Color::White);
    cell.setSize(Vector2f(20, 20));
    
    int* data = cellData(cell_num);

    cell.setPosition(Vector2f(*(data+0) * *(data+2), *(data+1) * *(data+3)));
    window.draw(cell);
}

void drawGosper(int cells[]) {
    int toDraw[] = {200, 201, 250, 251, 210, 260, 310, 161, 361, 112, 113,
                    412, 413, 216, 266, 316, 165, 365, 264, 267, 120, 170, 
                    220, 121, 171, 221, 72, 272, 74, 274, 24, 324, 134, 135, 184, 185}; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i] + 457] = 1;
    }
}

void draw101(int cells[]) {
    int toDraw[] = { 4, 5, 12, 13, 53, 55, 62, 64, 103, 114, 150, 151, 153, 164, 
                    166, 167, 200, 201, 203, 205, 208, 209, 212, 214, 216, 217, 253, 255, 
                    257, 260, 262, 264, 303, 305, 307, 310, 312, 314, 350, 351, 353, 355, 
                    358, 359, 362, 364, 366, 367, 400, 401, 403, 414, 416, 417, 453, 464, 
                    503, 505, 512, 514, 554, 555, 562, 563 }; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i] + 866] = 1;
    }
}

void drawSpaceship(int cells[]) {
    int toDraw[] = { 33, 66, 82, 84, 106, 108, 115, 121, 122, 131, 156, 161, 166, 168, 169, 170, 
                    171, 172, 173, 178, 179, 206, 208, 209, 210, 211, 212, 213, 214, 215, 226,
                    229, 231, 232, 233, 259, 265, 273, 274, 275, 276, 281, 282, 283, 304, 
                    305, 323, 324, 325, 327, 351, 354, 355, 363, 364, 373, 374, 401, 404, 405, 
                    450, 501, 504, 551, 554, 555, 563, 564, 573, 574, 604, 605, 623, 624, 625, 
                    627, 659, 665, 673, 674, 675, 676, 681, 682, 683, 706, 708, 709, 710, 711, 
                    712, 713, 714, 715, 726, 729, 731, 732, 733, 756, 761, 766, 768, 769, 770, 
                    771, 772, 773, 778, 779, 806, 808, 815, 821, 822, 831, 866, 882, 884, 933 }; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i]] = 1;
    }
}

void drawFace(int cells[]) {
    int toDraw[] = { 20, 21, 70, 71, 119, 122, 166, 167, 169, 172, 222, 264, 265, 269, 272, 314, 
                     315, 321, 365, 367, 368, 369, 370, 371, 416, 563, 564, 565, 613, 661, 662, 
                     711, 761, 705, 706, 755, 756, 757, 803, 808, 853, 857, 907, 952, 953, 955, 
                     957, 1000, 1001, 1007, 1050, 1051, 1056, 1057, 1102, 1103, 1104, 1105 }; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i]] = 1;
    }
}

void drawLotus(int cells[]) {
    int toDraw[] = { 7, 8, 57, 59, 102, 107, 109, 110, 151, 152, 158, 200, 203, 250, 251, 252, 
                     360, 361, 362, 409, 412, 454, 460, 461, 502, 503, 505, 510, 553, 555, 604, 605 }; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i]] = 1;
    }
}

void drawDagger(int cells[]) {
    int toDraw[] = { 5, 54, 56, 103, 105, 107, 200, 153, 157, 210, 201, 203, 205, 207, 209, 250,
                     252, 258, 310, 303, 304, 305, 306, 307, 405, 454, 456, 505 }; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i]] = 1;
    }
}

void drawDiamond(int cells[]) {
    int toDraw[] = { 4, 5, 6, 7, 102, 103, 104, 105, 106, 107, 108, 109, 200, 201, 202, 203, 204,
                     205, 206, 207, 208, 209, 210, 211, 302, 303, 304, 305, 306, 307, 308, 309, 
                     404, 405, 406, 407}; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i]] = 1;
    }
}

int cellGrowth(int cell_num, int cells[2500]) {
    //Check surrounding grids for live cells and returns live and dead cells in array.

   int alive(0);
   int toChange(-1);
   int check[] = {cell_num - 51, cell_num - 50, cell_num - 49,
   cell_num - 1, cell_num + 1,
   cell_num + 49, cell_num + 50, cell_num + 51};
   
   int* data = cellData(cell_num);
   int rowNum(*(data+1));
   int rowLen = *(data+4);
   int colLen = *(data+5);
   int rowMin = rowNum * rowLen;
   int rowMax = rowMin + (rowLen-1);
   int totCells = 2499; //(sizeof(cells) / sizeof(cells[0])) - 1

   for (int i = 0; i < (sizeof(check) / sizeof(*check)); i++) {

       int checkRowNum = (check[i] / *(data+3)) % 100;

       //Check if number bleeds over northmost border of window.
       if (rowNum == 0 && check[i] >= -(rowLen+1) && check[i] < 0) {
           if (check[i] == -(rowLen+1)) {
               check[i] = totCells;
           }
           else if (check[i] == -1) {
               check[i] = totCells - rowLen;
           }
           else {
               check[i] = check[i] + totCells;
           }
       } 
       //Check if number bleeds over southmost border of window.
       else if (rowNum == (colLen-1) && check[i] >= totCells-1 && check[i] < totCells+rowLen) {
           if (check[i] == totCells-1) {
               check[i] = rowLen - 1;
           }
           else if (check[i] == totCells + rowLen) {
               check[i] = 0;
           }
           else {
               check[i] = check[i] - totCells;
           }
       }
       //Check if number bleeds over westmost border of window.
       else if (check[i] < rowMin) {
           if (checkRowNum == rowNum) { check[i] = rowMax-1; }
           else if (checkRowNum == rowNum-1) { check[i] = (rowMax-1)-rowLen; }
       }
       //Check if number bleeds over eastmost border of window.
       else if (check[i] >= rowMax) {
           if (checkRowNum == rowNum) { check[i] = rowMin; }
           else if (checkRowNum == rowNum + 1) { check[i] = rowMin + rowLen; }
       }
       
       //Check how many neighboring cells are alive.
       if (cells[check[i]] == 1) {
           alive += 1;
       }
   }

   //If alive & not 2-3 neighboring cells alive, return live cell.
   if (cells[cell_num] == 1) {
       if (alive == 2 || alive == 3) { toChange = cell_num; }
   }
   //If dead & 3 neighboring cells alive, return live cell.
   else if (cells[cell_num] == 0) {
       if (alive == 3) { toChange = cell_num; }
   }

   return toChange;

}

int main() {
    bool draw = true;
    int cellSize_x = 20;
    int cellSize_y = 20;
    int cellCount_x = window.getSize().x / cellSize_x;
    int cellCount_y = window.getSize().y / cellSize_y;
    list<int> replace{};
    int cells[2500]; //cells x * cells y
    for (int t = 0; t < (sizeof(cells) / sizeof(*cells)); t++) {
        cells[t] = 0;
    }
   
    Font fnt;
    if (!fnt.loadFromFile("SpiralBitmap-2mW.ttf")) {
        cout << "Could not load font." << endl;
        exit(3);
    }
   
    bool titleDraw = true;
    RectangleShape curtain;
    curtain.setSize(Vector2f(window.getSize().x, window.getSize().y));
    curtain.setFillColor(Color(0, 0, 0, 100));
    Text titleText;
    Text instructions;
    titleText.setFont(fnt);
    instructions.setFont(fnt);
    titleText.setString("Conway's Game of Life");
    titleText.setCharacterSize(45);
    titleText.setPosition(window.getSize().x / 14, window.getSize().y - (window.getSize().y / 4));
    instructions.setString("Press ENTER to begin automation.\n\nPress SPACE to cycle through patterns.");
    instructions.setCharacterSize(25);
    instructions.setPosition(titleText.getPosition().x, titleText.getPosition().y + 100);

    Color col(50, 50, 50);
    RectangleShape line;
    line.setFillColor(col);
    
    Clock clock;
    Time lastTime(clock.getElapsedTime());
    Time currentTime(lastTime);

    long autoTick(0);

    drawGosper(cells); //Initialize with Gosper gun.

    while (draw) {
        currentTime = clock.getElapsedTime();
        Time deltaTime = currentTime - lastTime;
        long deltaMS = deltaTime.asMilliseconds();
        if (deltaMS > 8) {
            lastTime = currentTime;
            autoTick += deltaMS;
            //Disable title draw.
            if (Keyboard::isKeyPressed(Keyboard::Enter) && titleDraw) {
                autoTick = 0;
                titleDraw = false; 
            }
            //Cycle through patterns.
            if (Keyboard::isKeyPressed(Keyboard::Space) && titleDraw) {
                autoTick = 0;
                window.clear(); 
                std::fill(cells, cells + (sizeof(cells) / sizeof(*cells)), 0);
                drawSpaceship(cells);
            }

            window.clear();

            if ((autoTick > 250) && !titleDraw) {
                for (int n = 0; n < (sizeof(cells) / sizeof(*cells)); n++) {
                    //Cycle through cells to check surrounding live and dead cells.
                    int toChange = cellGrowth(n, cells);
                    replace.push_back(toChange);
                }
                //Clean up replace array and use it to replace values in cell array.
                replace.remove(-1);
                std::fill(cells, cells + (sizeof(cells) / sizeof(*cells)), 0);
                for (int cell : replace) {
                    cells[cell] = 1;
                }
                autoTick = 0;
            }

            replace.clear();

            //Draw all live cells.
            for (int i = 0; i < (sizeof(cells) / sizeof(*cells)); i++) {
                if (cells[i] == 1) {
                    drawCell(i);
                }
            }

            //Draw columns.
            line.setSize(Vector2f(1, window.getSize().y));
            for (int x = 0; x < cellCount_x; x++) {
                line.setPosition((cellSize_x * x) - 1, 0);
                window.draw(line);
            }

            //Draw rows.
            line.setSize(Vector2f(window.getSize().x, 1));
            for (int y = 0; y < cellCount_y; y++) {
                line.setPosition(0, (cellSize_y * y) - 1);
                window.draw(line);
            }

            if (titleDraw) {
                window.draw(instructions);
                window.draw(curtain); //Cover grid & gun with half opacity curtain while in title.
                window.draw(titleText);
            }
            
            window.display();

        }
    }

    while (true);
}

