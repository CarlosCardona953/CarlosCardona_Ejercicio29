Curvas.png: Curvas.dat graficas.py
	python graficas.py

%.dat : a.out
	./a.out 

a.out: Ejercicio29.cpp
	g++ Ejercicio29.cpp

clean:
	rm -rf a.out Curvas.dat Curvas.png *~