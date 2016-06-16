## IS NOT A WORKING CODE
## DOES NOT WORK

# (a|b)*abb
transitiontable = dict(
    0 = dict( a = [0, 1], b = [0], epsilon = [] ),
    1 = dict( a = [], b = [2], epsilon = [] ),
    2 = dict( a = [], b = [3], epsilon = [] ),
    3 = dict( a = [], b = [], epsilon = [] ),
 )

finaltable = [3]

s = []

def epsilonclosure (state):
    for news in transitiontable[state]['epsilon']:
        s.append(news)

print(transitiontable)
