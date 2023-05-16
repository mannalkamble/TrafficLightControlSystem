.section .text
.align 2
.globl setLED
#include "memoryMap.inc"
#include "GPIO.inc"
.equ NOERROR, 0x0
.equ ERROR, 0x1
.equ LEDON, 0x1


setLED:
 addi sp, sp, -16

 sw ra, 12(sp) 

 li t0, GPIO_CTRL_ADDR 
 lw t1, GPIO_OUTPUT_VAL(t0) 
 beqz a1, ledOff 
 li t2, LEDON 
 beq a1, t2, ledOn 
 li a0, ERROR 
 j exit

ledOn:
 or t1, t1, a0 
 sw t1, GPIO_OUTPUT_VAL(t0) 
 li a0, NOERROR 
 j exit

ledOff:
 xor a0, a0, 0xffffffff

 and t1, t1, a0

 sw t1, GPIO_OUTPUT_VAL(t0) 
 li a0, NOERROR
exit:
 lw ra, 12(sp) 
 addi sp, sp, 16 
 ret

