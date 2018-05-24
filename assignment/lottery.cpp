#include <stdio.h>
#include "lottery.h"

static char* file_name;
static char seperator;
static int* drawed;
static bool check = false;

bool init_lottery(char* filename, char j){
    FILE* file= fopen(filename, "r");
    seperator = j;
    check = false;
    file_name = filename;
    if(file == NULL)return false;
    fclose(file);
    return true;
}
bool get_tip(int tip, int* array){
    FILE* file= fopen(file_name, "r");
    char input[MAX_LINE_LEN] = {0};
    int number_of_counts = 0;
    if(tip < 0 || file == 0){
      fclose(file);
      return false;
    }
    char* output = fgets(input, MAX_LINE_LEN, file);
    while(output != NULL && number_of_counts < tip){
        output = fgets(input, MAX_LINE_LEN, file);
        number_of_counts++;
        if(output != input){
            fclose(file);
            return false;
        }
    }
    if(ftell(file) == EOF){
        fclose(file);
        return false;
    }
    int pos = 0;
    while(input[pos] !=seperator && pos < UUID_LEN){
        pos++;
    }

    int insertionpos = 0;
    int tip_number = 0;
    while(insertionpos < 6){
        pos++;
        if(input[pos]<= '9' && input[pos]>= '0'){
            tip_number = tip_number *10 + (input[pos] - '0');
        }
        else{
            array[insertionpos] = tip_number;
            tip_number = 0;
            insertionpos++;
        }
    }
    fclose(file);
    return true;
}
bool set_drawing(int* array){
    check = true;
    drawed = array;
    return false;
}
int get_tip_result(int tip){
    if(!check )return -1;
    int checktip[6];
    if(!get_tip(tip, checktip))return -2;
    int count = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if(checktip[i] == drawed[j])count++;
        }
    }
    return count;
}
int get_right_tips_count(int tip){
    if(!check|| tip < 0 || tip > TIP_SIZE)return -1;
    int tip_pos = 0;
    int count_right_tips = 0;
    int check_tip = 0;
    while(check_tip != -2&& check_tip != -1){
        check_tip = get_tip_result(tip_pos);
        if(check_tip == tip)count_right_tips++;
        tip_pos++;
    }
    return count_right_tips;
}
