var sudo = new Object();

sudo.SudoKiller = function(str)
{
          /*
           * Constructor of the SuDoku solver.
           */
          BOARD_SIZE = 16;           // Width and height of the SuDoku board
          BOX_SIZE = 4;             // Width and height of the inner boxes
          EMPTY = "";               // Empty cell marker

          //var board = new Array();  // Cells array
          // var board = new Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);  // Cells array
//        var board = new Array(-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1);  // Cells array
      var board = str.split("");
      
      
      for(i=0;i<board.length;i++)
      {
        if(board[i] == '.')
        {
          board[i] = -1;
        }
      }
      
          function check(num, row, col) {
              /*
               * Check if num is, according to SuDoku rules, a legal candidate
               * for the given cell.
               */
              var row_index, col_index, box_index;    // Indexes of the cells to check
              var r = (Math.floor(row / BOX_SIZE) * BOX_SIZE);
              var c = (Math.floor(col / BOX_SIZE) * BOX_SIZE);

              for (var i=0; i<BOARD_SIZE; i++) {
                  row_index = (row * BOARD_SIZE) + i;
                  col_index = col + (i * BOARD_SIZE);
                  box_index = (r + Math.floor(i / BOX_SIZE)) * BOARD_SIZE + c + (i % BOX_SIZE);
                  if (num == board[row_index] ||
                      num == board[col_index] ||
                      num == board[box_index])
                      return false;
              }
              return true;
          }

          function guess(index) {
              /*
               * Recursively test all candidate numbers for a given cell until
               * the board is complete.
               */
              var row = Math.floor(index / BOARD_SIZE);
              var col = index % BOARD_SIZE;
              if (index >= board.length)
                  return true;

              if (board[index] > -1 && board[index] < 16)
                  return guess(index + 1);

              for (var i=0; i<BOARD_SIZE; i++) {
                  if (check(i, row, col)) {  
			board[index] = i;
                      if (guess(index + 1))
                          return true;
                  }
              }

              board[index] = -1;
              return false;
          }
          
          
              /*
               * Get the board content and start solving the game.
               */
              //board = document.getElementsByTagName("input");
              if (!guess(0))
                  return "Sorry, solution not found!";
        else{
          var ret_str = "";
          for(i=0; i<board.length; ++i){
            
            if(board[i] == 10){
              ret_str+= 'A';        
            }
            else if(board[i] == 11){
              ret_str+= 'B';        
            }
            else if(board[i] == 12){
              ret_str+= 'C';        
            }
            else if(board[i] == 13){
              ret_str+= 'D';        
            }
            else if(board[i] == 14){
              ret_str+= 'E';        
            }
            else if(board[i] == 15){
              ret_str+= 'F';        
            }
            else{
              ret_str += board[i];
            }
              
          }
          return ret_str;
        }
         
          
}
