.section .text
.align 2
.globl setupGPIO
#include "memoryMap.inc"
#include "GPIO.inc"
setupGPIO:
 addi sp, sp, -16

 sw ra, 12(sp)
 li t0, GPIO_CTRL_ADDR 

li t1, PIN_12
li t2, PIN_11
or t1,t1,t2
li t2, PIN_10
or t1,t1,t2
li t2, PIN_3
or t1,t1,t2
sw t1, GPIO_INPUT_EN(t0)

 li t1, PIN_2 
 li t2, PIN_7
 or t1,t1,t2
 li t2, PIN_8
 or t1,t1,t2
 li t2, PIN_9
 or t1,t1,t2
 li t2, PIN_17 
 or t1,t1,t2
 li t2, PIN_19
 or t1,t1,t2
 li t2, PIN_18
 or t1,t1,t2
 li t2,PIN_6
 or t1,t1,t2

 sw t1, GPIO_OUTPUT_EN(t0)

 li t1,0xFFFFFFFF
 
 //li t1, PIN_0
//addi t2, zero, 0
//sw t1, GPIO_INPUT_EN(t0)
//sw t2, GPIO_OUTPUT_EN(t0)
 //sw t1, GPIO_OUTPUT_VAL(t0)
 //sw x0, GPIO_OUTPUT_VAL(t0)


 lw ra, 12(sp) 
 addi sp, sp, 16
 ret
