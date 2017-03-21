	.file	"our_days_are_never_coming_back.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"LIFE IS NOT A PROBLEM TO BE SOLVED"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$.LC0, %edi
	xorl	%eax, %eax
	subq	$64, %rsp
	.cfi_def_cfa_offset 80
	leaq	12(%rsp), %rsi
	call	__isoc99_scanf
	movslq	12(%rsp), %rbx
	leaq	16(%rsp), %rdi
	movl	$.LC1, %esi
	movq	%rbx, %rdx
	call	memcpy
	leaq	16(%rsp), %rdi
	movb	$0, 16(%rsp,%rbx)
	call	puts
	addq	$64, %rsp
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (GNU) 6.3.1 20170306"
	.section	.note.GNU-stack,"",@progbits
