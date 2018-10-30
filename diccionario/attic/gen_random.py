import sys
import random
import string
from collections import OrderedDict

def gen_word(size=1, chars=string.ascii_lowercase):
    return ''.join(random.choice(chars) for _ in range(size))

random.seed(sys.argv[1]) #fijar la semilla

M = int(sys.argv[2]); # tamano del diccionario max (se puede achicar por repeticiones)
N = int(sys.argv[3]); # tamano del texto approx
L = int(sys.argv[4]); # largo max de palabras dic (largo exacto si b=0)

#opciones especiales.
b = int(sys.argv[5]); # 0 si palabras dic mismo largo, 1 si no.
basura = int(sys.argv[6]); # 0 si queremos una solucion, 1 para generar una palabra basura.
restric = int(sys.argv[7]); # 0 para dic irrestricto, 1 para dic limitado
lang = sys.argv[8]; # dic limitado.

#print(M);
#print(N);
#print(b);
#print(L);
dic0=[];
lenguaje = string.ascii_lowercase;
if(restric!=0):
	lenguaje = lang;
if(b!=0):
	for a in range(0,M):
		dic0.append(gen_word(L,lenguaje));

if(b==0):
	for a in range(0,M):
		dic0.append(gen_word(random.choice(range(1,L+1)),lenguaje));
dic = list(OrderedDict.fromkeys(dic0))
dic.sort();
M = len(dic);
S = '';
l=0;
t = random.choice(dic);
while(l+len(t) <=N):
	S=S+t;
	l+=len(t);
	t = random.choice(dic);
N = len(S);
if(basura!=0):
	S = gen_word(N);
print(M);
for d in dic:
	print(d);
print(S);

