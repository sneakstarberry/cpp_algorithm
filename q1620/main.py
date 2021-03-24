string_to_search = {}
line = input()
n = line.split(' ')[0]
m = line.split(' ')[1]

for i in range(1, int(n)+1):
    pokemon = input()
    string_to_search[pokemon] = i
    string_to_search[str(i)] = pokemon

for i in range(int(m)):
    question = input()
    print(string_to_search[question])
