import random as r


f = open("ascsorted.txt", "w")

for i in range(1, 10**5+1):
    f.write(str(i) + " ")

f = open("descsorted.txt", "w")

for i in range(10**5, 0, -1):
    f.write(str(i) + " ")

f = open("random.txt", "w")

for i in range(1, 10**5+1):
    f.write(str(r.randint(1, 10**5)) + " ")

f = open("nearlysorted.txt", "w")
for i in range(1, 10**5+1):
    if i > 100 and i < 150:
        f.write(str(r.randint(1, 10**5)) + " ")
    else:
        if i > 860 and i < 900:
            f.write(str(r.randint(1, 10**5)) + " ")
        else:
            if i > 430 and i < 512:
                f.write(str(r.randint(1, 10**5)) + " ")
                
            else:
                f.write(str(i) + " ")