//cgt215_final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//A game that simulates cell growth depending on two rules:
//A live cells stays alive if it has either 2 or 3 live neighbors.
//A dead cell is revived if it has 3 live neighbors.

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include <vector>
#include <list>
#include <SFML/Audio.hpp>

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

    //Determine the x axis.
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
    
    //Grab data for the given cell.
    int* data = cellData(cell_num);

    //Set position & draw cell.
    cell.setPosition(Vector2f(*(data+0) * *(data+2), *(data+1) * *(data+3)));
    window.draw(cell);
}

void drawGosper(int cells[]) {
    int toDraw[] = {200, 201, 250, 251, 210, 260, 310, 161, 361, 112, 113,
                    412, 413, 216, 266, 316, 165, 365, 264, 267, 120, 170, 
                    220, 121, 171, 221, 72, 272, 74, 274, 24, 324, 134, 135, 184, 185}; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i] + 857] = 1;
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
        cells[toDraw[i] + 707] = 1;
    }
}

void drawFace(int cells[]) {
    int toDraw[] = { 20, 21, 70, 71, 119, 122, 166, 167, 169, 172, 222, 264, 265, 269, 272, 314, 
                     315, 321, 365, 367, 368, 369, 370, 371, 416, 563, 564, 565, 613, 661, 662, 
                     711, 761, 705, 706, 755, 756, 757, 803, 808, 853, 857, 907, 952, 953, 955, 
                     957, 1000, 1001, 1007, 1050, 1051, 1056, 1057, 1102, 1103, 1104, 1105 }; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i] + 513] = 1;
    }
}

void drawLotus(int cells[]) {
    int toDraw[] = { 7, 8, 57, 59, 102, 107, 109, 110, 151, 152, 158, 200, 203, 250, 251, 252, 
                     360, 361, 362, 409, 412, 454, 460, 461, 502, 503, 505, 510, 553, 555, 604, 605 }; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i] + 818] = 1;
    }
}

void drawDagger(int cells[]) {
    int toDraw[] = { 5, 54, 56, 103, 105, 107, 200, 153, 157, 210, 201, 203, 205, 207, 209, 250,
                     252, 258, 260, 303, 304, 305, 306, 307, 405, 454, 456, 505 }; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i] + 819] = 1;
    }
}

void drawDiamond(int cells[]) {
    int toDraw[] = { 4, 5, 6, 7, 102, 103, 104, 105, 106, 107, 108, 109, 200, 201, 202, 203, 204,
                     205, 206, 207, 208, 209, 210, 211, 302, 303, 304, 305, 306, 307, 308, 309, 
                     404, 405, 406, 407}; //Grid IDs

    for (int i = 0; i < sizeof(toDraw) / sizeof(*toDraw); i++) {
        cells[toDraw[i] + 869] = 1;
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

       int checkRowNum = (check[i] / *(data+3)) % 100; //Is the checked cell in the same row as the origin cell?

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
    int pattern(0);
    string patternName[7] = { "Gosper gun", "Spaceship", "Lotus", "Dagger", "(@m@)", "Diamond", "101"};
    int cellSize_x = 20;
    int cellSize_y = 20;
    int cellCount_x = window.getSize().x / cellSize_x;
    int cellCount_y = window.getSize().y / cellSize_y;
    list<int> replace{};
    int cells[2500]; //cells x * cells y
    for (int t = 0; t < (sizeof(cells) / sizeof(*cells)); t++) {
        cells[t] = 0;
    }
   
    SoundBuffer nextBuffer;
    if (!nextBuffer.loadFromFile("next.ogg")) {
        cout << "Could not load SFX audio" << endl;
        exit(5);
    }
    Sound nextSound;
    nextSound.setBuffer(nextBuffer);

    SoundBuffer startBuffer;
    if (!startBuffer.loadFromFile("title.ogg")) {
        cout << "Could not load SFX audio" << endl;
    }
    Sound startSound;
    startSound.setBuffer(startBuffer);

    Music music;
    if (!music.openFromFile("bgm.ogg")) {
        cout << "Failed to load music";
    }
    music.play();

    Font fnt;
    if (!fnt.loadFromFile("SpiralBitmap-2mW.ttf")) {
        cout << "Could not load font." << endl;
        exit(3);
    }
   
    //Title text
    bool titleDraw = true;
    RectangleShape curtain;
    curtain.setSize(Vector2f(window.getSize().x, window.getSize().y));
    curtain.setFillColor(Color(0, 0, 0, 100));
    Text titleText;
    Text instructions;
    titleText.setFont(fnt);
    instructions.setFont(fnt);
    instructions.setFillColor(Color(255, 255, 255, 155));
    titleText.setString("Conway's Game of Life");
    titleText.setCharacterSize(45);
    titleText.setPosition(window.getSize().x / 20, window.getSize().y - (window.getSize().y / 5));
    instructions.setString("Press ENTER to begin or pause automation.\nPress ESC to exit.");
    instructions.setCharacterSize(25);
    instructions.setPosition(titleText.getPosition().x, titleText.getPosition().y + 75);

    //Pattern text
    Text patternsHead;
    Text patternsInfo;
    patternsHead.setFont(fnt);
    patternsInfo.setFont(fnt);
    patternsInfo.setFillColor(Color(255, 255, 255, 155));
    patternsHead.setString("Press SPACE to cycle through patterns.");
    patternsHead.setCharacterSize(30);
    patternsHead.setPosition(window.getSize().x / 20, window.getSize().y / 22);
    patternsInfo.setString(patternName[0]);
    patternsInfo.setCharacterSize(25);
    patternsInfo.setPosition(patternsHead.getPosition().x, patternsHead.getPosition().y + 30);

    //Create grid line
    Color col(50, 50, 50);
    RectangleShape line;
    line.setFillColor(col);
    
    Clock clock;
    Time lastTime(clock.getElapsedTime());
    Time currentTime(lastTime);
    long autoTick(0);
    long cycleTick(0);
    long bufferTick(0);
    bool cycle = false;
    bool buffer = false;

    drawGosper(cells); //Initialize with Gosper gun.

    while (draw) {
        currentTime = clock.getElapsedTime();
        Time deltaTime = currentTime - lastTime;
        long deltaMS = deltaTime.asMilliseconds();
        if (deltaMS > 8) {
            lastTime = currentTime;
            autoTick += deltaMS;

            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                exit(0);
            }

            //Create a time buffer so users can't spam button.
            if (bufferTick >= 250) { buffer = false; bufferTick = 0; }
            if (buffer) { bufferTick += deltaMS; }
            //Start and pause simulation.
            if (!buffer) {
                if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    if (titleDraw) { titleDraw = false; }
                    else { titleDraw = true; }
                    startSound.play();
                    buffer = true; //Trigger time buffer.
                }
            }

            //Create a time buffer so users can't spam button.
            if (cycleTick >= 250) { cycle = false; cycleTick = 0; }
            if (cycle) { cycleTick += deltaMS; }
            //Cycle through patterns.
            if (!cycle) {
                if (Keyboard::isKeyPressed(Keyboard::Space)) {
                    nextSound.play();
                    window.clear();
                    std::fill(cells, cells + (sizeof(cells) / sizeof(*cells)), 0);
                    pattern += 1;
                    if (pattern > (sizeof(patternName) / sizeof(*patternName))-1) { pattern = 0; }
                    switch (pattern) {
                    case 0:
                        drawGosper(cells);
                        patternsInfo.setString(patternName[0]);
                        break;
                    case 1:
                        drawSpaceship(cells);
                        patternsInfo.setString(patternName[1]);
                        break;
                    case 2:
                        drawLotus(cells);
                        patternsInfo.setString(patternName[2]);
                        break;
                    case 3:
                        drawDagger(cells);
                        patternsInfo.setString(patternName[3]);
                        break;
                    case 4:
                        drawFace(cells);
                        patternsInfo.setString(patternName[4]);
                        break;
                    case 5:
                        drawDiamond(cells);
                        patternsInfo.setString(patternName[5]);
                        break;
                    case 6:
                        draw101(cells);
                        patternsInfo.setString(patternName[6]);
                        break;
                    }
                    cycle = true; //Trigger time buffer.
                }
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
                window.draw(curtain); //Cover grid & patterns with half opacity curtain while in title.
                window.draw(titleText); //Title only draws when simulation is paused.
            }

            window.draw(instructions);
            window.draw(patternsHead);
            window.draw(patternsInfo);

            window.display();

        }
    }

    while (true);
}

