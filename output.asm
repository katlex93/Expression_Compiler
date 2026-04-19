mov rax, 7
mov [y], rax
mov rax, 4
push rax
mov rax, [y]
pop rbx
add rax, rbx
mov [x], rax
mov rax, [y]
call print_int
mov rax, [y]
mov [x], rax
