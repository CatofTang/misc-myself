'''
2019-11-9 字符串与16进制互转以及16进制与10进制互转
使用方法：直接把数据输入data即可
'''
def char2hex(data):
    v = data
    o = ''
    for i in v:
        o += hex(ord(i))[2:]
    return("0x" + o)

def hex2char(data):
    v = data
    o = ''
    for i in range(0,len(data)-1,2):
        o += chr(int('0x'+v[i:i+2],16))
    return(o)

def hex2int(data):
    if data[0:2] == "0x":
        return(int(int(data,16)))
    else:
        return(int(int("0x" + data,16)))

def int2hex(data):
    return(hex(data))

