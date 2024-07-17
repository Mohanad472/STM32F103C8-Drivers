#include "student.h"

char roll_number_found(FIFO_Buf_t *fifo, int roll_entered);
void show_student_info(element_type *temp);
element_type* temp_increment(FIFO_Buf_t *fifo, element_type *temp);