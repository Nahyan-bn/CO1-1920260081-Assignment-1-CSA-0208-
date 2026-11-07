	.file	"type_conversion.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC1:
	.ascii "Integer division loss: %.2f vs Explicit cast: %.2f\12\0"
	.align 4
LC2:
	.ascii "Original value: %lld | Truncated to short: %d\12\0"
LC5:
	.ascii "Rupees: %.2f -> Paise: %ld\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$112, %esp
	call	___main
	movl	$150, 108(%esp)
	movl	108(%esp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 40(%esp)
	fildl	40(%esp)
	fstpl	96(%esp)
	fildl	108(%esp)
	fldl	LC0
	fdivrp	%st, %st(1)
	fstpl	88(%esp)
	fldl	88(%esp)
	fstpl	12(%esp)
	fldl	96(%esp)
	fstpl	4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$70000, 80(%esp)
	movl	$0, 84(%esp)
	movl	80(%esp), %eax
	movw	%ax, 78(%esp)
	movswl	78(%esp), %eax
	movl	%eax, 12(%esp)
	movl	80(%esp), %eax
	movl	84(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC2, (%esp)
	call	_printf
	fldl	LC3
	fstpl	64(%esp)
	fldl	64(%esp)
	fldl	LC0
	fmulp	%st, %st(1)
	fldl	LC4
	faddp	%st, %st(1)
	fnstcw	46(%esp)
	movzwl	46(%esp), %eax
	movb	$12, %ah
	movw	%ax, 44(%esp)
	fldcw	44(%esp)
	fistpl	60(%esp)
	fldcw	46(%esp)
	movl	60(%esp), %eax
	movl	%eax, 12(%esp)
	fldl	64(%esp)
	fstpl	4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.section .rdata,"dr"
	.align 8
LC0:
	.long	0
	.long	1079574528
	.align 8
LC3:
	.long	858993459
	.long	1076409139
	.align 8
LC4:
	.long	0
	.long	1071644672
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
