	.file	"sort-c-wc.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	countWords
	.type	countWords, @function
countWords:
	mv	a5,a0
	lbu	a4,0(a0)
	beq	a4,zero,.L8
	li	a0,0
	li	a3,32
	j	.L7
.L12:
	addi	a0,a0,1
	lbu	a4,0(a5)
	beq	a4,zero,.L1
.L4:
	beq	a4,a3,.L6
	addi	a5,a5,1
	lbu	a4,0(a5)
	bne	a4,zero,.L4
.L1:
	ret
.L6:
	lbu	a4,0(a5)
	beq	a4,zero,.L11
.L7:
	bne	a4,a3,.L12
	addi	a5,a5,1
	j	.L6
.L11:
	ret
.L8:
	li	a0,0
	j	.L1
	.size	countWords, .-countWords
	.ident	"GCC: (GNU) 11.1.0"
