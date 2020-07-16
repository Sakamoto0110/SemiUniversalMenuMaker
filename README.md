(WINDOWS ONLY, FOR NOW) 
Required headers:
windows.h
conio.h

Required function declaration:

void gotoxy(int x, int y);


declaration:
  int showMenu(startX, startY, spacing, numberOfItens, indicatorSize, arrayOfStrings, arrowString);

Simple menu creator for windows console, how to use:

  -Use W,S, DownKey or UpKey for move between options;
  
  -Use Space or Enter for confirm;
  
  -The function will return the number of the selected item;
  
  -The arrayOfStrings is a constant pointer char array, exemple: " const char *teste[4] = {"First", "Second", "Thirty", "Fourth"}; ";
  
  -The size of the arrayOfStrings MUST be the same number/size of numberOfItens var;
  
  -The arrowString is the indicator of actual pre-selected item, like: "-->" ;
  
  -The indicatorSize MUST be the number of characters in arrowString, blank characters DO COUNT as characters. Exemple: "--> " has 4 characters
  
  
TODO
  -Add linux suppport
