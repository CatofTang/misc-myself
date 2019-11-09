'''
2019-11-9 把含%的十六进制组合格式化为不含%
'''
num='%E5%8D%81%E5%85%AB%E5%B1%8A%E4%B8%89%E4%B8%AD%E5%85%A8%E4%BC%9A' #十八届三中全会
new = num.replace("%","")
print(new)
