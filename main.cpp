#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;




void gotoxy(int x, int y) {
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

int showMenu(int _xoffset, int _yoffset,int _spacing, int _nItens, int _aLen,const char **_content, char *_arrow){
    // positioning variables
    int xoffset = _xoffset; // X value
    int yoffset = _yoffset; // Y value
    int spacing = _spacing; // Spacing between 2 itens
    int nItens  = _nItens;  // Number of the itens
    int aLen    = _aLen;    // Size of the indicator
    // Control variables
    bool apply = false;
    bool hasUpdate = true;
    int selected = 0;
    while(!apply){
        if(hasUpdate){
            int x = xoffset;
            int y = yoffset;
            for(int c = 0; c < nItens; c++){
                gotoxy(x-aLen,y);
                for(int c1 = 0; c1 < aLen; c1++){
                    cout << ' ';
                }
                gotoxy(x,y);
                cout << _content[c];
                y += spacing;
            }
            gotoxy(x-aLen,yoffset+selected*spacing);
            cout << _arrow;
            hasUpdate = false;
        }
        if(kbhit()){
            // w     -> 119
            // s     -> 115
            // enter -> 13
            // up    -> 72
            // down  -> 80
            // left  -> 75
            // right -> 77
            // space -> 32
            int key = getch();
            if(key == 72 || key == 80 || key == 32 || key == 119 || key == 115 || key == 13){
                if(key == 72 || key == 119)
                    if(yoffset+selected*spacing>yoffset){
                        hasUpdate = true;
                        selected--;
                    }
                if(key == 80 || key == 115)
                    if(yoffset+selected*spacing<yoffset+(nItens-1)*spacing){
                        hasUpdate = true;
                        selected++;
                    }
                if(key == 32 || key == 13){
                    apply = true;
                }
            }
        }
    }
    return selected;
}


int main()
{
    const char *teste[4] = {"First", "Second", "Thirty", "Fourth"};
    int result = showMenu(5,4,2,4,4,teste,"--> ");
    gotoxy(0,0);
    cout << "Option selected: " << result << endl;
    getch();
    return 0;
}


