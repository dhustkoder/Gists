	.file	"hohoho.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%ld"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movl	$.LC0, %edi
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	xorl	%eax, %eax
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	leaq	8(%rsp), %rsi
	call	__isoc99_scanf
	movq	8(%rsp), %rbp
	leaq	0(%rbp,%rbp,2), %r12
	leaq	2(%r12), %rdi
	call	malloc
	cmpq	$1, %rbp
	movq	%rax, %rbx
	jle	.L4
	leaq	-3(%rax,%r12), %rdx
	.p2align 4,,10
	.p2align 3
.L3:
	movb	$72, (%rax)
	movb	$111, 1(%rax)
	addq	$3, %rax
	cmpq	%rax, %rdx
	movb	$32, -1(%rax)
	jne	.L3
.L2:
	movq	%rbx, %rdi
	movb	$72, (%rdx)
	movb	$111, 1(%rdx)
	movb	$33, 2(%rdx)
	movb	$0, 3(%rdx)
	call	puts
	movq	%rbx, %rdi
	call	free
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore_state
	movq	%rax, %rdx
	jmp	.L2
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.ident	"GCC: (GNU) 6.2.1 20160830"
	.section	.note.GNU-stack,"",@progbits
