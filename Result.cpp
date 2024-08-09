#include <iostream>
#include <conio.h>
#include "Scene.h"

const char* gameOverImage = R"(



       ####      #      #      #    ####        ###   #      #  ####   ###    
     ### ##     ##     ###     ##  #####      ### ##  ##    ## #####  ######  
    ##          ###    ###    ###  ##        ##     #  #    #  ##     ##   #  
    #          ## #    # #    # #  ##        #      #  #    #  ##     ##   #  
    #          #  #    # ##  ## #  #####     #      ## ##  ##  #####  ##   #  
    #   ####   #  ##   #  #  #  #  #####     #      ##  #  #   #####  #####   
    #     ##  ######   #  #  #  #  ##        #      ##  #  #   ##     ##  #   
    ##    ##  #    ##  #  ####  #  ##        ##     #   ####   ##     ##  ##  
     ##   ##  #     #  #   ##   #  ##         #    ##    ##    ##     ##   #  
      ###### #      #  #   ##   #  ######      #####     ##    ###### ##   ## 



                          THANK YOU FOR PLAYING !!!

                            PRESS C KEY TO TITLE
)";

const char* clearImage = R"(
            ########  ##         #########       ##        ########   
          ####   ##   ##         ########       ###        #########  
          ##          ##         ##             ####       ##     ### 
         ##           ##         ##            ## ##       ##      ## 
         ##           ##         ##            ##  ##      ##      ## 
        ###           ##         ##            ##  ##      ##     ### 
        ##            ##         ########     ##   ##      ##     ##  
        ##            ##         ########     ##    ##     ########   
        ##            ##         ##          ###    ##     #######    
        ###           ##         ##          ##########    ##   ###   
         ##           ##         ##          ##      ##    ##    ##   
         ##           ##         ##         ##       ##    ##     ##  
          ##          ##         ##         ##        ##   ##     ##  
          #########   #########  ########   ##        ##   ##      ## 
            #######   #########  ######### ##         ##   ##      ###


                          THANK YOU FOR PLAYING !!!

                            PRESS C KEY TO TITLE
)";

void Scene::Result() {
	std::system("cls");
	if (score < 50) {
        std::cout << gameOverImage;
	}
	else {
        std::cout << clearImage;
	}
	std::cout << "\n\n You've destroyed " << score << " enemies." << std::endl;
	int i; //入力
	do
	{
		i = _getch(); // キー入力待ち
	} while ('c' != i);
	Title();
}