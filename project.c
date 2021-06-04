
unsigned short kp;

unsigned char state = 0;
unsigned int op = 0;
unsigned char count = 0;
unsigned char secondState = 0;
unsigned char secondOp = 0;
unsigned char secondCount = 0;
unsigned char sfa = '0';
unsigned char totalSuccess = 0;
unsigned char totalMiss = 0;
int ii = 0;

unsigned char masterPass[] = "1234";
unsigned char sectionAPass[] = "2222";
unsigned char sectionBPass[] = "3333";
unsigned char baitPass[] = "9999";

unsigned char newPassM[4] = "";


const char* enterPassA[13] = {'E', 'n', 't', 'e', 'r', ' ' ,'P', 'a', 's', 's', '.', ' ', 'A'};

                               
unsigned char enteredPassword[4] = "";

char  keypadPort at PORTD;

sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

void sectA(){
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Chr(1, 1, 'S');Lcd_Chr(1, 2, 'e');Lcd_Chr(1, 3, 'c');Lcd_Chr(1, 4, 't');
     Lcd_Chr(1, 5, '.');Lcd_Chr(1, 6, ' ');Lcd_Chr(1, 7, 'A');Lcd_Chr(1, 8, ' ');
     Lcd_Chr(1, 9, 'o');Lcd_Chr(1, 10, 'p');Lcd_Chr(1, 11, 'e');Lcd_Chr(1, 12, 'n');
     Lcd_Chr(1, 13, 'i');Lcd_Chr(1, 14, 'n');Lcd_Chr(1, 15, 'g');Lcd_Chr(1, 16, '/');
     Lcd_Chr(1, 17, 'l');Lcd_Chr(1, 18, 'o');Lcd_Chr(1, 19, 'c');Lcd_Chr(1, 20, 'k');
     Lcd_Chr(1, 21, 'i');Lcd_Chr(1, 22, 'n');Lcd_Chr(1, 23, 'g');

}

void sectB(){
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Chr(1, 1, 'S');Lcd_Chr(1, 2, 'e');Lcd_Chr(1, 3, 'c');Lcd_Chr(1, 4, 't');
     Lcd_Chr(1, 5, '.');Lcd_Chr(1, 6, ' ');Lcd_Chr(1, 7, 'B');Lcd_Chr(1, 8, ' ');
     Lcd_Chr(1, 9, 'o');Lcd_Chr(1, 10, 'p');Lcd_Chr(1, 11, 'e');Lcd_Chr(1, 12, 'n');
     Lcd_Chr(1, 13, 'i');Lcd_Chr(1, 14, 'n');Lcd_Chr(1, 15, 'g');Lcd_Chr(1, 16, '/');
     Lcd_Chr(1, 17, 'l');Lcd_Chr(1, 18, 'o');Lcd_Chr(1, 19, 'c');Lcd_Chr(1, 20, 'k');
     Lcd_Chr(1, 21, 'i');Lcd_Chr(1, 22, 'n');Lcd_Chr(1, 23, 'g');
}

void wrongPassword(){
      Lcd_Cmd(_LCD_CLEAR);
      Lcd_Chr(1, 1, 'W');Lcd_Chr(1, 2, 'r');Lcd_Chr(1, 3, 'o');Lcd_Chr(1, 4, 'n');
      Lcd_Chr(1, 5, 'g');Lcd_Chr(1, 6, ' ');Lcd_Chr(1, 7, 'P');Lcd_Chr(1, 8, 'a');
      Lcd_Chr(1, 9, 's');Lcd_Chr(1, 10, 's');Lcd_Chr(1, 11, 'w');Lcd_Chr(1, 12, 'o');
      Lcd_Chr(1, 13, 'r');Lcd_Chr(1, 14, 'd');
}

void test(int op){
           if(op == 1){
                 if(strcmp(enteredPassword, masterPass) == 0){
                       sectA();
                       RC0_bit = 0;
                       RC1_bit = 1;
                       totalSuccess++;
                       state = 0;
                       op = 0;
                 }else if(strcmp(enteredPassword, sectionAPass) == 0){
                       sectA();
                       RC0_bit = 0;
                       RC1_bit = 1;
                       totalSuccess++;
                 }else if(strcmp(enteredPassword, baitPass) == 0){
                       sectA();
                       RC0_bit = 0;
                       RC1_bit = 1;
                       RA0_bit = 1;
                       totalSuccess++;
                 }else{
                       wrongPassword();
                       totalMiss++;
                       sfa++;
                 }
           }
           else if(op == 2){
                 if(strcmp(enteredPassword, masterPass) == 0){
                       sectB();
                       RC3_bit = 0;
                       RC4_bit = 1;
                       totalSuccess++;
                 }else if(strcmp(enteredPassword, sectionBPass) == 0){
                       sectB();
                       RC3_bit = 0;
                       RC4_bit = 1;
                       totalSuccess++;
                 }else if(strcmp(enteredPassword, baitPass) == 0){
                       sectB();
                       RC3_bit = 0;
                       RC4_bit = 1;
                       RA0_bit = 1;
                       totalSuccess++;
                 }else{
                       wrongPassword();
                       sfa++;
                       totalMiss++;
                 }
           }
            /*else if(op == 3){
                if(strcmp(enteredPassword, masterPass) == 0){
                            Lcd_Cmd(_LCD_CLEAR);
                            Lcd_Out(1, 1, "CP 1M 2A 3B 4T");
                     if(secondState == 0){
                            if(kp == '1'){
                                       Lcd_Cmd(_LCD_CLEAR);
                                       Lcd_Chr(1, 1, 'E');Lcd_Chr(1, 2, 'n');Lcd_Chr(1, 3, 't');Lcd_Chr(1, 4, 'e');
                                       Lcd_Chr(1, 5, 'r');Lcd_Chr(1, 6, ' ');Lcd_Chr(1, 7, 'N');Lcd_Chr(1, 8, 'e');
                                       Lcd_Chr(1, 9, 'w');Lcd_Chr(1, 10, ' ');Lcd_Chr(1, 11, 'P');Lcd_Chr(1, 12, 'a');
                                       Lcd_Chr(1, 13, 's');Lcd_Chr(1, 14, 's');Lcd_Chr(1, 15, ' ');Lcd_Chr(1, 16, 'M');
                                       Lcd_Cmd(_LCD_SECOND_ROW);
                                       secondState = 1;
                                       secondOp = 1;
                            }
                     }
                     else if(secondState == 1){
                            if(secondOp == 1){
                                 Lcd_Cmd(_LCD_MOVE_CURSOR_RIGHT);
                                 Lcd_Chr_CP('*');
                                 newPassM[count] = kp;
                                 count++;
                            }
                     }
                }
           } */
}

void test2(int op){

                if(strcmp(enteredPassword, masterPass) == 0){
                            Lcd_Cmd(_LCD_CLEAR);
                            Lcd_Out(1, 1, "CP 1M 2A 3B 4T");
                     if(secondState == 0){
                            if(kp == '1'){
                                       Lcd_Cmd(_LCD_CLEAR);
                                       Lcd_Chr(1, 1, 'E');Lcd_Chr(1, 2, 'n');Lcd_Chr(1, 3, 't');Lcd_Chr(1, 4, 'e');
                                       Lcd_Chr(1, 5, 'r');Lcd_Chr(1, 6, ' ');Lcd_Chr(1, 7, 'N');Lcd_Chr(1, 8, 'e');
                                       Lcd_Chr(1, 9, 'w');Lcd_Chr(1, 10, ' ');Lcd_Chr(1, 11, 'P');Lcd_Chr(1, 12, 'a');
                                       Lcd_Chr(1, 13, 's');Lcd_Chr(1, 14, 's');Lcd_Chr(1, 15, ' ');Lcd_Chr(1, 16, 'M');
                                       Lcd_Cmd(_LCD_SECOND_ROW);
                                       secondState = 1;
                                       secondOp = 1;
                            }
                     }
                     else if(secondState == 1){
                            if(secondOp == 1){
                                 Lcd_Cmd(_LCD_MOVE_CURSOR_RIGHT);
                                 Lcd_Chr_CP('*');
                                 newPassM[count] = kp;
                                 count++;
                            }
                     }
                }

}


void main() {
  Lcd_Init();
  Keypad_Init();

  TRISA.F0 = 0;
  RA0_bit = 0;

  TRISC = 0x00;
  RC0_bit = 0;
  RC1_bit = 0;
  RC3_bit = 0;
  RC4_bit = 0;
  
  CCP1CON = 0;
  CCP2CON = 0;
  
  state = 0;
  op = 0;
  count = 0;
  sfa = '0';
  kp = 0;
  totalSuccess = '0';
  totalMiss = '0';

  Main:

  Lcd_Cmd(_LCD_CLEAR);
  //Lcd_Cmd(_LCD_CURSOR_OFF);
  Lcd_Out(1, 1, "MAIN MENU");
  Lcd_Out(2, 1, "Enter 1 2 3 4");

  do {
    kp = 0;
    do
      kp = Keypad_Key_Click();
    while (!kp);
    switch (kp) {
      case  2: kp = 51; break; // 3
      case  3: kp = 50; break; // 2
      case  4: kp = 49; break; // 1
      case  6: kp = 54; break; // 6
      case  7: kp = 53; break; // 5
      case  8: kp = 52; break; // 4
      case 10: kp = 57; break; // 9
      case 11: kp = 56; break; // 8
      case 12: kp = 55; break; // 7
      case 14: kp = 35; break;
      case 15: kp = 48; break;
      case 16: kp = 42; break;
      default: kp = 48;

    }
    if(state == 0){
        if(kp == '1'){
             Lcd_Cmd(_LCD_CLEAR);
             for(ii = 0; ii < 13; ii++){
                Lcd_Chr(1, ii + 1, enterPassA[ii]);
             }
             state = 1;
             op = 1;
             Lcd_Cmd(_LCD_SECOND_ROW);
        }
        else if(kp == '2'){
             Lcd_Cmd(_LCD_CLEAR);
             Lcd_Chr(1, 1, 'E');
             Lcd_Chr(1, 2, 'n');
             Lcd_Chr(1, 3, 't');
             Lcd_Chr(1, 4, 'e');
             Lcd_Chr(1, 5, 'r');
             Lcd_Chr(1, 6, ' ');
             Lcd_Chr(1, 7, 'P');
             Lcd_Chr(1, 8, 'a');
             Lcd_Chr(1, 9, 's');
             Lcd_Chr(1, 10, 's');
             Lcd_Chr(1, 11, '.');
             Lcd_Chr(1, 12, ' ');
             Lcd_Chr(1, 13, 'B');
             state = 1;
             op = 2;
             Lcd_Cmd(_LCD_SECOND_ROW);
        }
        else if(kp == '3'){
             Lcd_Cmd(_LCD_CLEAR);
             Lcd_Out(1, 1, "Master P. for CP");
             state = 1;
             op = 3;
             Lcd_Cmd(_LCD_SECOND_ROW);
        }
        else if(kp == '4'){
             Lcd_Cmd(_LCD_CLEAR);
             Lcd_Chr(1, 1, totalSuccess);
             Lcd_Chr(2, 1, totalMiss);
             delay_ms(3000);
             state = 0;
             op = 0;
             goto Main;
        }
    }else if(state == 1){
        if(op == 1 && count <= 3){
              Lcd_Cmd(_LCD_MOVE_CURSOR_RIGHT);
              Lcd_Chr_CP('*');
              enteredPassword[count] = kp;
              count++;
        }else if(op == 2 && count <= 3){
              Lcd_Cmd(_LCD_MOVE_CURSOR_RIGHT);
              Lcd_Chr_CP('*');
              enteredPassword[count] = kp;
              count++;
        }else if(op == 3 && count <= 3){
              Lcd_Cmd(_LCD_MOVE_CURSOR_RIGHT);
              Lcd_Chr_CP('*');
              enteredPassword[count] = kp;
              count++;
        }
        if(count == 4){
                 enteredPassword[4] = '\0';
                 if(op == 1 || op == 2)test(op);
                 //else if(op == 3)test2(op);
        }
     }
  } while (1);
}