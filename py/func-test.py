def outer():
    x = 2
    dic = {"dog":"gou"}
    def inner():
        print(x, dic)
        dic["pig"] = "zhu"
    inner()
    print(x, dic)

outer()

x,y = 2,1
def outer_2():
    dic = {"dog":"gou"}
    def inner():
        global x, y
        x += 1
        y += 1
        print(x, y, dic)
        dic["pig"] = "zhu"
        print(x)
    inner()
    print(x, dic)
    
st = '''23 



212
1 3'''

print(st.split())
