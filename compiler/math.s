	.file	"math.cpp"
	.text
	.globl	_Z3LogPKc
	.type	_Z3LogPKc, @function
_Z3LogPKc:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3LogPKc, .-_Z3LogPKc
	.section	.rodata
.LC0:
	.string	"multiply"
	.text
	.globl	_Z8multiplyii
	.type	_Z8multiplyii, @function
_Z8multiplyii:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	$.LC0, %edi
	call	_Z3LogPKc
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_Z8multiplyii, .-_Z8multiplyii
	.ident	"GCC: (GNU) 8.3.1 20190223 (Red Hat 8.3.1-2)"
	.section	.note.GNU-stack,"",@progbits
