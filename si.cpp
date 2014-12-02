#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

//menu constants 
const int menu_min_x = 10;
const int menu_min_y = 3;
const int menu_max_x = 66;
const int menu_max_y = 20;



//prototypes


void initialize(){
 //terminal graphics
 (void) initscr(); //initializes the curses library
 start_color();
 keypad(stdscr, TRUE); //enable keyboard mapping
 (void) nonl(); //tesll curses not to do NL-> CR/NL on output
 (void) cbreak(); //take input chars one at a time
 (void) noecho(); //dont echo input
 init_pair(1, COLOR_BLUE, COLOR_BLACK);
 init_pair(2, COLOR_RED, COLOR_BLACK); 

 //initialize game global variables
 float speed_shotX = 0.0; 
 float speed_shotY = 0.0005; //speed of the bullet in y dir.

 float tankVelocityX = 0.0001; 
 float tankVelocityY = 0.0;
 float tankVelocityChage = 0.0005;

 float alienVelocityX = 0.0001;
 float alienVelocityY = 0.0;
}



void makeEraseString(char buf[], int len){
  for(int i = 0; i < len; i++){
    buf[i] = ' ';
  }
  buf[len] = '\0';
  return;
}



void printWelcomeScreen(int maxy, int maxx){
  erase(); // clear screen
  attron(COLOR_PAIR(1));  //change color
  mvprintw(maxy/2, maxx/2 - 10, "Welcome to NOT PONG"); // print welcome, approximately middle of screen
  refresh(); //refresh screen
  attroff(COLOR_PAIR(1)); // go back to default colors
  sleep(1); // sleep for a second by calling the linux/unix sleep library call
  char in;
  scanf("%c", &in);	
  return;
}


void finish(int sig)
{
    endwin();
    //do your non-curses wrapup here 
    // print a nice message
    
    printf ("\nThe Game Has Ended\n");
 
    return;//    exit(0);
}



//mainfunction
int main(int argc, char *argv[]){

    //Initialize Variables
    int maxx, maxy; //maxx and maxy size of terminal

    //Start Curses
    initialize();
    getmaxyx(stdscr, maxy, maxx);      // get current screen size 
    printWelcomeScreen(maxy, maxx);    // Print welcome screen
    erase();   



attron(COLOR_PAIR(2));
mvaddch(5,5, 'x');
mvaddch(4,5, 'x');
mvaddch(3,5, 'x');
refresh(); //refresh screen
  attroff(COLOR_PAIR(1)); // go back to default colors
  char in;
  scanf("%c", &in);
	erase();   
     //Display Tittle Screen
	  printWelcomeScreen(maxy, maxx); 
scanf("%c", &in);
     //Begin Menu Loop


       //print menu screen 

	 //if '1' , show score board 

	 //else if '2' , play the game

      
      //End Curses
      finish(0);
     
      //End Program 
      return 0;

}

//draw something 
/*
attron(COLOR_PAIR(1));
mvaddch(5,5, 'x');
mvaddch(4,5, 'x');
mvaddch(3,5, 'x');
refresh(); //refresh screen
  attroff(COLOR_PAIR(1)); // go back to default colors
  sleep(1);
*/



















