'''
2019-11-9 把含%的十六进制组合格式化为不含%
'''
num='%48%65%6c%6c%6f%57%6f%72%6c%64' #十八届三中全会
new = num.replace("%","")
print(new)
