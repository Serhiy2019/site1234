 #include <windows.h>
 #include <iostream>
 #include <conio.h> 
  
 void init_board(void); // чистить дошку
 void draw_board(void); // ≥н≥ц≥ал≥зац≥€ дошки
 int user_first(void);  // запитуЇ, даЇ виб≥р ходити першим чи другим
 void play_game(void);  // комп. ≥ людина ход€ть по черз≥
 int play_again(void);  // запит дл€ повтору гри
 void computer_move(void); // х≥д комп'ютера
 void player_move(void);  // х≥д людини
 int find_win(char);   // знаходить переможц€
 int find_diagonal(void);  //перев≥р€Ї д≥агональ
 int find_around(void);     //  перев≥Ї по колу   
 int symbol_won(char);   // €кий символ перем≥г
 int square_valid(int);  // д≥ючий квадрат
 void clearscreen(void); // чистить дошку
 void with_person(void);  //гра з людиною
 void with_computer(void); // гра з комп'юером
 void play_game_persons(void);  //гра двух людей по черз≥
 void player2_move(void);     // друга людина ходить  
 
 
 char board[4][4];

 char computer, user,player2; 
 
 int k_wins=0, p_wins=0, ties=0;
 int X_wins=0, O_wins=0, ties2=0;
 void winner_statistics(void);      // статистика переможц≥в 
 
 
void clearscreen(void){         
     for(int i = 0; i<19; i++){
            printf("\n");
  }  }
   
int main(void) { 
    
  clearscreen();
      printf("********************************\n");
      printf("  WELCOME TO TIC TAC TOE 4x4\n");
	     printf("********************************\n");

	  printf(" - Human VS Computer - 1 \n");
	  printf("           \n");
	  printf(" - Human VS Human    - 2 \n");
	   printf("           \n");
	 
	  printf(" - Exit -            - 3    \n");
	  printf("           \n");
	  printf("********************************\n");

	    winner_statistics();
	
	 char res;
	 do{ 
   printf(" Make your choice:");   
   res = getch();
 
	if(res == '3')exit(0);
	if((res != '1') && (res != '2'))printf("\n");printf("\n Wrong input!\n");

  if(res == '1') {
	   with_computer();
        }
	    if(res== '2')   {
	    	  	 with_person();
       }
		
  }while((res != '1') && (res != '2'));
	 
	  winner_statistics();
	  clearscreen();
	    } 
		  
void winner_statistics(void){ 
 	if(k_wins>0||p_wins>0||ties>0||X_wins>0||O_wins>0||ties2>0){
 		 printf("**************************************************************\n");
	 printf("                                 WINNER STATISTICS\n");
 	printf("                             \n"); }
 	if( k_wins>0||p_wins>0||ties>0){
	  printf(" Human VS Computer  >>  human:    %i;  computer:  %i;  ties: %i;\n",p_wins,k_wins,ties);
	 printf("                             \n");  }
	if( X_wins>0||O_wins>0||ties2>0){	
	  printf(" Human VS Human     >>  human'X': %i;  human'O':  %i;  ties: %i;\n",X_wins,O_wins,ties2);}
	  if(k_wins>0||p_wins>0||ties>0||X_wins>0||O_wins>0||ties2>0){
	  
	  printf("                             \n");
	    printf("**************************************************************\n");}
	}	  
	    
void with_computer(void){ 
	 while(1){   
	   init_board();
		if (user_first()){			       
		  						   
		  computer = 'O';					    
		  user = 'X';				       
		}else{       				     
	      computer = 'X';				      
		  user = 'O';}				    
			   
		play_game(); 
		if (!play_again())  main(); 
			}   	
		} 
					
void init_board(void) { 
   int row, col; 

    for (row = 0; row < 4; row++) 
       for (col = 0; col < 4; col++)
	     board[row][col] = ' '; 
 
  return;
   } 
 
void draw_board(void){     
//board[1][3] = 'x';
    int row, col;
	 clearscreen();
    char num[4][16] = {" 1 | 2 | 3 | 4 "," 5 | 6 | 7 | 8 "," 9 | 10| 11| 12"," 13| 14| 15| 16"};
    char line[16] = "---|---|---|---";
 
    printf("\n"); 
  
    for (row = 0; row < 4; row++)   
	  {      
	   printf("  %c | %c | %c | %c %26s\n ", board[row][0], board[row][1], board[row][2],
	   board[row][3],num[row]); 
	   
	     if (row != 3) 
			 printf("---|---|---|---%26s\n", line);
			     } 
			     
	for (row = 0; row < 4; row++)  
		printf("\n");
			return; }   
				    
				  			
int user_first(void) {
   char response; 
  draw_board();
    
     do{ printf(" Do you want to go first? (y/n)");
	 
	  response = getch();
     
    if ((response != 'y') && (response != 'n')){
    printf("            \n");	
	printf("\n Wrong input!\n");}
     
	      } while ((response != 'y') &&(response != 'n') ); 
	      
         if (response == 'y')   
      return 1; 
	    else 
	      return 0;
	      
     } 
	    
void play_game(void){		 
   int turn; 
   
   for (turn = 1; turn <= 16; turn++){
 	    
     if (turn % 2 == 1){
	      if (computer == 'X') computer_move(); 
          else  player_move(); }
		      
	 else{if (computer == 'O') computer_move();
		  
		  else player_move(); }
		  
		       draw_board(); 
		       
		if (symbol_won(computer)){			  
	   printf(" \n YOU LOSE !!! COMPUTER WINS!!! \n\n ");
	   k_wins++;
	       return;
	    	} 
	    else if (symbol_won(user)) 
	    { 
       printf("\n CONGRATULATIONS!!! YOU WIN!!!  ");
       p_wins++;
		   return;
			}
				 } 
       printf("\n TIE!!! FRIENDSHIP  WINS)))  ");
       ties++;
		   return;
					 }
		  
int play_again(void){

  char response; 
 								  
	do{ printf(" Do you want to play again? (y/n) " );
	 
	  response = getch();
     
    if ((response != 'y') && (response != 'n')) {printf("\n");printf("\n Wrong input!\n");}
     
	      } while ((response != 'y') &&(response != 'n') ); 
	      
         if (response == 'y')   
      return 1; 
	    else 
	      return 0;
		   }
		    
				
void computer_move(void)    // ходить комп'ютер
	 {  
	   int square;
	   int row, col; 			
				 			 
	       square = find_win(computer);
	      if (!square)     square = find_win(user);
		 
		  if (!square)     square = find_diagonal();
		  if (!square)     square = find_around(); 

  printf("\n I am choosing square %d!\n", square); 

     row = (square - 1) / 4;
     col = (square - 1) % 4; 

   Sleep(1000);
   Beep(523,500);
 
   board[row][col] = computer; 
 
   return;
   } 
   
   
   
int find_win(char symbol) 
   {  
     int square, row, col; 
     int result = 0; 
 
	for (square = 1; square <= 16; square++) { 
	    row = (square - 1) / 4; 
		col = (square - 1) % 4; 
 
      if (board[row][col] == ' ') 
	   {board[row][col] = symbol;  
	     if (symbol_won(symbol)) result = square;
		board[row][col] = ' ';  } } 
 
    return result;
   } 
 	   
int find_diagonal(void) 
	{  
	 if (board[0][0] == ' ') 
		return 1;
	 if (board[1][1] == ' ')  
		return 6; 
	 if (board[2][2] == ' ') 
		return 11; 
     if (board[3][3] == ' ')   
		return 16;  
	 if (board[3][0] == ' ') 
		 return 13; 
	 if (board[2][1] == ' ') 
		return 10;
	 if (board[1][2] == ' ')  
	    return 7; 											     											     										     
     if (board[0][3] == ' ') 					  										     
        return 4; 
      return 0;
     }

int find_around(void){
  
    if (board[2][0] == ' ') 
        return 9;  
    if (board[1][0] == ' ')  
	    return 5; 
	if (board[0][1] == ' ')   
		return 2;  
	if (board[0][2] == ' ')  
		return 3;  
	if (board[1][3] == ' ')  
		return 8; 
	if (board[2][3] == ' ') 
		return 12;  
	if (board[3][2] == ' ')
	    return 15; 
    if (board[3][1] == ' ') 
		return 14;
																	   
		return 0; 
		} 																		    
																				    																			    																			    
  
 int symbol_won(char symbol)
  { 
    int row, col; 
 
  for (row = 0; row < 4; row++){ 
        
	      if ((board[row][0] == symbol) && (board[row][1] == symbol) && 
		  (board[row][2] == symbol) && (board[row][3] == symbol)) 
		   return 1;     } 
 
  for (col = 0; col < 4; col++){ 
   
    if ((board[0][col] == symbol) && (board[1][col] == symbol) &&
	(board[2][col] == symbol)&& (board[3][col] == symbol)) 
	  return 1;    
		    } 
 
   if ((board[0][0] == symbol) && (board[1][1] == symbol) && 
   (board[2][2] == symbol) && (board[3][3] == symbol)) 
      return 1; 
 
   if ((board[0][3] == symbol) && (board[1][2] == symbol) && 
   (board[2][1] == symbol) && (board[3][0] == symbol))   
    return 1;
	   return 0;
	    } 
 
void player_move(void) {
   int square; 
   int row, col; 
   
int n;

char num [16];
do{ 

    printf("\n Enter a square: ");
 
	scanf("%s",&num);
	n=strlen(num);
	for(int i=0;i<n;i++){	
	
	 if(num[i]<'0'|| num[i]>'9') break;}
	 	
	sscanf(num,"%i",&square);
	if(square > 16 || square < 1 || (!square_valid(square)))printf("\n Wrong input!\n");
	
 }while(square > 16 || square < 1 ||(!square_valid(square)) ) ;
 
		     row = (square - 1) / 4;
			 col = (square - 1) % 4; 

	Sleep(1000);		 
 Beep(323,450);
  board[row][col] = user; 
  
  return; 
  } 
  
int square_valid(int square){  

 int row, col; 
 
  row = (square - 1) / 4;
  col = (square - 1) % 4; 
 
  if ((square >= 1) && (square <= 16)) {  
           
	if (board[row][col] == ' ')  
	return 1; 
	   } 
 
  return 0;
   }   
   
void with_person(void){ 
	 while(1){   
	   init_board();
	   draw_board();
		printf(" The player 'X' goes first!\n");		       
		  						   
		  player2 = 'X';					    
		  user = 'O';				       
				    	   
		play_game_persons(); 
		if (!play_again()) main(); 
			}   
		 
		} 
void play_game_persons(void){		 
   int turn; 
   
   for (turn = 1; turn <= 16; turn++){
 	
     if (turn % 2 == 1){
	      if (player2 == 'X') player2_move(); 
          else  player_move(); }
		      
	 else{if (player2 == 'O') player2_move();
		  
		  else player_move(); }
		  
		       draw_board(); 
		       
		if (symbol_won(player2)){			  
	   printf(" \n CONGRATULATIONS!!! Player 'X' WINS!!! \n\n ");
	   X_wins++;
	       return;
	    	} 
	    else if (symbol_won(user)) 
	    { 
       printf("\n CONGRATULATIONS!!! Player '0' WINS!!!  ");
       O_wins++;
		   return;
			}
				 } 
       printf("\n TIE!!! FRIEDSHIP IS WIN)))  ");
       ties2++;
		   return;
					 }
					 
void player2_move(void) {
   int square; 
   int row, col; 
 
    int n;

char num [16];
do{ 

    printf("\n Enter a square: ");
 
	scanf("%s",num);
	n=strlen(num);
	for(int i=0;i<n;i++){	
	
	 if(num[i]<'0'|| num[i]>'9') break;}
	 	
	sscanf(num,"%i",&square);
	if(square > 16 || square < 1 || (!square_valid(square)))printf("\n Wrong input!\n");
	
 }while(square > 16 || square < 1 ||(!square_valid(square)) ) ;
 
		     row = (square - 1) / 4;
			 col = (square - 1) % 4; 
			
	Sleep(1000);		 
 Beep(323,450);
  board[row][col] = player2; 

  return; 
  } 
   
