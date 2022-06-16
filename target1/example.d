
example.o：     文件格式 elf64-x86-64


Disassembly of section .text:

0000000000000000 <.text>:
   0:	4c 8d 84 24 00 ff ff 	lea    -0x100(%rsp),%r8
   7:	ff 
   8:	49 b9 35 39 62 39 39 	movabs $0x6166373939623935,%r9
   f:	37 66 61 
  12:	4d 89 08             	mov    %r9,(%r8)
  15:	4d 31 c9             	xor    %r9,%r9
  18:	4d 89 48 08          	mov    %r9,0x8(%r8)
  1c:	4c 89 c7             	mov    %r8,%rdi
  1f:	68 fa 18 40 00       	pushq  $0x4018fa
  24:	c3                   	retq   
