#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Scene.h"

const char* titleImage = R"(
                      ##                                               ##    
    ##      ##     ########      ########    #####   ##       ##    ######## 
    ###    ##     ###    ###     ##    ###    ##     ##       ##    ##    #  
     ##    ##    ##       ##     ##     ##    ##     ##       ##   ##        
      ##  ##     ##        ##    ##     ##    ##     ##       ##   ##        
      ## ##     ##         ##    ##     ##    ##     ##       ##   ###       
       ####     ##         ##    ##    ###    ##     ##       ##    ###      
        ##      ##         ##    ########     ##     ##       ##     ####    
       ####     ##         ##    ##    ###    ##     ##       ##       ####  
       # ##     ##         ##    ##      ##   ##     ##       ##         ### 
      ##  ##    ###        ##    ##      ##   ##     ##       ##          ## 
     ##   ##     ##        ##    ##      ##   ##     ##       ##          ## 
     ##    ##    ###      ##     ##     ###   ##     ##      ##           ## 
    ##      ##    ####  ###      #########    ###     ###  ####    ###  ###  
   ##       ##     #######       ########    #####     ######      #######   

                                 W
                               A-+-D  --- MOVE
                                 S

                               SPACE  --- FIRE

                           PRESS S KEY TO START !!!
)";

void Scene::Title() {
	std::system("cls");
	std::cout << titleImage;
	int i; //“ü—Í
	do
	{
		i = _getch(); // ƒL[“ü—Í‘Ò‚¿
	} while ('q' != i && 's' != i);
	if ('s' == i) {
		std::cout << "\033[0;0H";
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 80; j++) {
				std::cout << ' ';
			}
			std::cout << std::endl;
		}
		Game();
	}
}