/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class name here>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * File:			lottery.h
 * Author:			Peter Bauer
 * Due Date:		#due#
 * ----------------------------------------------------------
 * Description:
 * Header for lottery tips analysis.
 * ----------------------------------------------------------
 */
 #ifndef ___LOTTERY_H
 #define ___LOTTERY_H
 #define UUID_LEN   40
 #define TIP_SIZE   17
 #define MAX_LINE_LEN   (UUID_LEN + 1 + TIP_SIZE + 1)

 bool init_lottery(char* filename, char j);
 bool get_tip(int tip, int* array);
 bool set_drawing(int* array);
 int get_tip_result(int tip);
 int get_right_tips_count(int tip);

 #endif
