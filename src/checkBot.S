.section .text
.align 2
.globl checkBot
#include "GPIO.inc"
#include "memoryMap.inc"
.equ ON, 0x1
.equ OFF, 0x0
checkBot:
  addi sp, sp, -16
  sw ra, 12(sp)

  li t3, GPIO_CTRL_ADDR
  lw t4, GPIO_INPUT_VAL(t3)

  # Check PIN_12
  li t5, PIN_12
  and t5, t4, t5
  bnez t5, pinON

  # Check PIN_11
  li t5, PIN_11
  and t5, t4, t5
  bnez t5, pinON

  # Check PIN_10
  li t5, PIN_10
  and t5, t4, t5
  bnez t5, pinON

  # Check PIN_3
  li t5, PIN_3
  and t5, t4, t5
  bnez t5, pinON

  li a0, OFF
  j exit

pinON:
  li a0, ON
  j exit

exit:
  lw ra, 12(sp)
  addi sp, sp, 16
  ret
