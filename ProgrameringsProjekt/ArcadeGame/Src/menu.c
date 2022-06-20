#include "menu.h"

int32_t word1Y = 5;
int32_t word2Y = 25;
int32_t word3Y = 45;
int32_t word4Y = 65;
int32_t word5Y = 85;
int32_t word6Y = 102;



void menuMove(int8_t joystickWay, int8_t *sel){

	if(joystickWay == 1){ // Pil øverst
		menu('m',1,'o',0, *sel);
		*sel = 1;
	}
	if(joystickWay == 2){ // Pil nederst
		menu('m',2, 'n',0, *sel);
		*sel = 2;
	}
}

void menuSelect(int8_t button, int8_t *sel, int8_t *game){
	if(*sel == 1 && button == 1){
		//Remove main menu
		playerRemove(15,word2Y-1);
		playerRemove(110,word2Y-1);
		wordText(26,word2Y, 0, 0); 	//ARCADE
		wordText(39,word3Y, 1, 0); 	//PLAY
		wordText(39,word4Y, 2, 0); 	//HELP
		signText(13, word3Y, 3, 0); // ->

		buzz(1,0, 0);
		TIM2->CR1 = 0x0000; // Disable timer

		while(*sel == 1){
			//The game starts
			*game = 3;
			break;
		}
	}
	if(*sel == 2 && button == 1){
		//Remove Main menu
		button = 0;
		playerRemove(15,word2Y-1);
		playerRemove(110,word2Y-1);
		wordText(26,word2Y, 0, 0); 	//ARCADE
		wordText(39,word3Y, 1, 0); 	//PLAY
		wordText(39,word4Y, 2, 0); 	//HELP
		signText(13, word4Y, 3, 0); // ->

		//Help menu shows
		menu('h',0,'o',0, *sel);
		*sel = 0;

		while(*sel == 0){
			button = buttonRead();
			if(button == 1){
				*sel = 1;
				buzz(1,0, 0);
				TIM2->CR1 = 0x0000; // Disable timer
				break;
			}
		}

		//Remove Help menu
		playerRemove(15,word1Y-1);
		wordText(28, word1Y, 1, 0);	// PLAY-
		wordText(80, word1Y, 9, 0); //-ER
		playerRemove(115,word1Y-1);

		enemyRemove(20,word2Y+7);
		wordText(35, word2Y, 10, 0); // ENEMY
		enemyRemove(112,word2Y+7);

		astroidRemove(8,word3Y+3);
		wordText(18, word3Y, 11, 0); // ASTEROID
		astroidRemove(128,word3Y+3);

		wordText(3, word4Y, 3, 0); 	// JOYSTIC H L
			signText(3+112,word4Y,2, 0); //    /

		wordText(17, word5Y, 4, 0); // FIRE RED

		wordText(13, word6Y, 5, 0); //POWER WHT

		//show main menu
		menu('m',1,'o',0, *sel);
	}




}

void menu(char q, int8_t pil, char overstNederst, int16_t points, int8_t *sel){
	if(q == 'm'){

		wordText(26, word2Y, 0, 2); // ARCADE
		playerDraw(15,word2Y-1);	// Ship left
		playerDraw(110,word2Y-1);	// Ship right

		wordText(39, word3Y, 1, 2);	// PLAY

		wordText(39, word4Y, 2, 2); // HELP

		if(pil == 1 || overstNederst == 'o' ){
		signText(13,word3Y,3, 13);  // ->
		signText(13,word4Y,3, 0);  // ->
		buzz(1,0, 0);
		TIM2->CR1 = 0x0000; // Disable timer
		}

		if(pil == 2 || overstNederst == 'n'){
		signText(13,word3Y,3, 0);  	// ->
		signText(13,word4Y,3, 13);  	// ->
		buzz(1,0, 0);
		TIM2->CR1 = 0x0000; // Disable timer
		}
	}
	if(q == 'h'){

		buzz(1,0, 0);
		TIM2->CR1 = 0x0000; // Disable timer

		playerDraw(15,word1Y-1);
		wordText(28, word1Y, 1, 2);	// PLAY-
		wordText(80, word1Y, 9, 2); //-ER
		playerDraw(115,word1Y-1);

		enemyDraw(20,word2Y+7);
		wordText(35, word2Y, 10, 2); // ENEMY
		enemyDraw(112,word2Y+7);

		astroidDraw(8,word3Y+3);
		wordText(18, word3Y, 11, 2); // ASTEROID
		astroidDraw(128,word3Y+3);

		wordText(3, word4Y, 3, 2); 	// JOYSTIC H L
			signText(3+112,word4Y,2, 13); //    /

		wordText(17, word5Y, 4, 1); // FIRE RED

		wordText(13, word6Y, 5, 15); //POWER WHT



	}
	if(q == 'e'){
		wordText(22, word1Y, 6, 2); // END GAME


		wordText(5, word2Y, 7, 2); // HIGH SCORE

		signText(26,word3Y,0, 5); 	 	// !
		signText(91,word3Y,0, 5); 	 	// !
		boxText(25,word3Y, 1);			// Boks

		wordText(5, word4Y, 8, 2); // YOUR SCORE

		boxText(26,word5Y, 1);  // Points boks


		//Points udregning

		int16_t yourPoints = points;
		static 	int16_t highPoints;

		if(highPoints <= yourPoints){
			highPoints = yourPoints;
		}
		int8_t xTal, yTal, i, j;
		char highScore[5];
		char yourScore[5];

		sprintf(highScore,"%04d",highPoints);
		sprintf(yourScore,"%04d",yourPoints);

		for(i=0; i<=3; i++){
			for(j=48; j<58; j++){
				if(highScore[i] == j ){
					numberText(39+(13*i),word3Y,j, 5);
				}
			}
		}
		for(i=0; i<=3; i++){
			for(j=48; j<58; j++){
				if(yourScore[i] == j ){
					numberText(39+(13*i),word5Y,j, 5);
				}
			}
		}
		playerDraw(26,word6Y-1);
		playerDraw(39,word6Y-1);
		playerDraw(52,word6Y-1);
		playerDraw(65,word6Y-1);
		playerDraw(78,word6Y-1);
		playerDraw(91,word6Y-1);
		playerDraw(104,word6Y-1);

		enemyDraw(26,word6Y+18);
		enemyDraw(39,word6Y+18);
		enemyDraw(52,word6Y+18);
		enemyDraw(65,word6Y+18);
		enemyDraw(78,word6Y+18);
		enemyDraw(91,word6Y+18);
		enemyDraw(104,word6Y+18);

		buzz(1,0, 0);
		TIM2->CR1 = 0x0000; // Disable timer

	}
}


